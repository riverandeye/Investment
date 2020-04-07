# Nest js

> Nest js 에 대해 설명합니다.



### Introduction





#### Getting Started

- 설치 및 초기화

```shell
$ npm i -S @nestjs/cli
$ npx nest new project-name
$ cd project-name 
$ npm run start
```

실행시 localhost:3000 으로 접속하면 좌상단에 Hello World를 볼 수 있다. 



```
src
ㄴapp.controller.ts
ㄴapp.module.ts
ㄴapp.service.ts
ㄴmain.ts
```

각각의 내부 코드를 살펴보자.



```typescript
// main.ts
import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);
  await app.listen(3000);
}
bootstrap();
```

nest start 를 통해 시작되는 프로젝트의 진입점 코드이다. NestFactory.create는 AppModule을 받아서 INestFactory 인스턴스를 프로미스 형태로 반환한다. 그럼 AppModule을 보자.



```typescript
//app.module.ts
import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';

@Module({
  imports: [],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
```

앱 모듈에선 컨트롤러와 프로바이더를 이용해 데코레이터를 만들고 이를 AppModule에 감싸 리턴하는 것을 볼 수 있다. 어쨌뜬 앱모듈이 컨트롤러와 프로바이더를 통해 만들어졌다는 것을 알 수 있겠다. 



```typescript
//app.service.ts
import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getHello(): string {
    return 'Hello World!';
  }
}
```

service.ts 에선 어떤 결과값을 리턴하는 클래스가 정의된 것을 볼 수 있다.



```typescript
//app.controller.ts
import { Controller, Get } from '@nestjs/common';
import { AppService } from './app.service';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getHello(): string {
    return this.appService.getHello();
  }
}
```

controller.ts 에선 정의한 AppService를 입력받아 내부에서 사용하는 것을 확인할 수 있다.



대충 봤을땐 service와 같은 개별적인 로직을 Controller에서 병합하고, service와 Controller 를 Module로 병합하고 이 appmodule을 라우팅하도록 해주는 것 같다. 서비스가 모델이고 컨트롤러가 컨트롤러면, View는 어디에 있어야 하는지 아직은 감이 잘 안온다.



HTTP 프레임워크로는 default로 express가 사용된다고 한다. 



#### Controller

컨트롤러는 request와 response를 담당하는데, NestJS에서는 Controller Decorator를 이용하여 리퀘스트를 그에 맞는 컨트롤러로 바인딩할 수 있다.

각 컨트롤 내에선 개별 리퀘스트 데코레이터 메소드를 이용하여 HTTP 리퀘스트에 대한 endpoint를 지정할 수 있다. 역시 그냥 코드를 보는게 이해가 빠르다.

```typescript
import { Controller, Get } from '@nestjs/common';

@Controller('cats')
export class CatsController {
  @Get()
  findAll(): string {
    return 'This action returns all cats';
  }
}
```

여기에 get /cats 요청을 날리면 This action returns all cats 를 받게 되는 것이다. 각 요청에 대한 데코레이터가 개별적으로 정의되어 있기 때문에, @Put(), @Delete() 그냥 위에 붙이면 해당 요청의 endpoint가 되는 것이다.



요청에 대해 response를 할 때 status code를 지정해주고 싶으면, @HttpCode 데코레이터를 지정해주면 된다.

```typescript
@Post()
@HttpCode(204)
create() {
  return 'This action adds a new cat';
}
```

각 Endpoint에 대해 request, response 객체에 직접 접근해서 사용할 수 있는데, 꼭 그럴 필요 없이 위에처럼 데코레이터를 이용하면 명시적으로 지정이 가능하다.



redirect는 이렇게 해주면된다.

```typescript
@Get()
@Redirect('https://nestjs.com', 301)
```



로직에 따라 Redirect 하는 위치를 다르게 하고 싶으면, url과 statusCode가 담긴 Object를 Redirect 밑에 정의된 함수에서 리턴하면 된다.

```typescript
@Get('docs')
@Redirect('https://docs.nestjs.com', 302)
getDocs(@Query('version') version) {
  if (version && version === '5') {
    return { url: 'https://docs.nestjs.com/v5/' };
  }
}
```



**Route Parameter**

dynamic path를 지정하여 params 로 접근해야 한다면 이렇게 하면 된다. 함수의 인자로  @Params 데코레이터를 이용하여 params를 넣어준 후 함수 내에서 사용하면 된다.

```typescript
@Get(':id')
findOne(@Param() params): string {
  console.log(params.id);
  return `This action returns a #${params.id} cat`;
}
```

굳이 params Object로 하지 않고, 입력되는 param을 명시하는 쪽으로 하는 것이 더 좋을 것이다.

```typescript
@Get(':id')
findOne(@Param('id') id): string {
  return `This action returns a #${id} cat`;
}
```



**DTO**

Post로 입력을 받을 때 body가 어떻게 오는지에 대한 인터페이스를 지정해주기 위해서 dto를 정의해주어야 한다.

```typescript
export class CreateCatDto {
  readonly name: string;
  readonly age: number;
  readonly breed: string;
}
```

이런식으로 설정해주고

```typescript
@Post()
async create(@Body() createCatDto: CreateCatDto) {
  return 'This action adds a new cat';
}
```

body 데코레이터 변수에 해당 class를 타입으로 지정해주면 된다. 



#### Provider

Provider는 @Injectable 이란 데코레이터로 annotated 된 class이고, 의존성을 주입할 수 있는 대상들을 의미한다. 

**Dependency Injection** 은 객체간의 관계를 설정 할 때 선언할때 하는것이 아닌 동적으로 주입하는 방법을 의미하는데, 일반적으로 생성자에서 이루어진다. 다음에 나오는 예시도 이 방식을 채택한다.

```typescript
import { Injectable } from '@nestjs/common';
import { Cat } from './interfaces/cat.interface';

@Injectable()
export class CatsService {
  private readonly cats: Cat[] = [];

  create(cat: Cat) {
    this.cats.push(cat);
  }

  findAll(): Cat[] {
    return this.cats;
  }
}
```

위의 예시는 injectable한 CatsService 클래스를 정의한다. Service에서는 실제 데이터들이 변경되고 리턴되는 모델의 역할을 한다. 이제 이러한 `service`를 Controller에 inject 하여, 해당 컨트롤러가 그러한 모델을 조작할 수 있게 해주어야 한다.



```typescript
import { Controller, Get, Post, Body } from '@nestjs/common';
import { CreateCatDto } from './dto/create-cat.dto';
import { CatsService } from './cats.service';
import { Cat } from './interfaces/cat.interface';

@Controller('cats')
export class CatsController {
  constructor(private readonly catsService: CatsService) {}

  @Post()
  async create(@Body() createCatDto: CreateCatDto) {
    this.catsService.create(createCatDto);
  }

  @Get()
  async findAll(): Promise<Cat[]> {
    return this.catsService.findAll();
  }
}
```

여기서는 constructor 단에서 CatsService를 입력받아 컨트롤러를 생성하기 때문에, 컨트롤러가 생성되는 시점에서 의존성이 주입되는 것이다.



만약 의존성 주입이 선택적으로 이루어지는 경우엔 Optional 데코레이터를 사용하면 된다.

```typescript
import { Injectable, Optional, Inject } from '@nestjs/common';

@Injectable()
export class HttpService<T> {
  constructor(
    @Optional() @Inject('HTTP_OPTIONS') private readonly httpClient: T
  ) {}
}
```



Module을 형성할 때 의존성 주입은 @Module 데코레이터가 해준다. 

```typescript
import { Module } from '@nestjs/common';
import { CatsController } from './cats/cats.controller';
import { CatsService } from './cats/cats.service';

@Module({
  controllers: [CatsController],
  providers: [CatsService],
})
export class AppModule {}
```



#### Module

![](https://docs.nestjs.com/assets/Modules_1.png)

네스트는 모듈과 모듈을 합쳐서 하나의 Root 모듈을 만들고, 이를 NestFactory.create에 넣어 어플리케이션을 만든다. 모듈 데코레이터를 사용할 때 module에 대한 object를 입력한다.

provider, controller 를 입력하여 모듈을 생성하고, 생성되어있는 모듈을 import export 할 수 있다. 구체적으로 어떻게 작동하는지는 직접 짜봐야 이해할 수 있을 것 같다.



#### Middleware

express 미들웨어와 개념이 동일하다. 클래스 메소드로 이용할 수 있다.

```typescript
import { Injectable, NestMiddleware } from '@nestjs/common';
import { Request, Response } from 'express';

@Injectable()
export class LoggerMiddleware implements NestMiddleware {
  use(req: Request, res: Response, next: Function) {
    console.log('Request...');
    next();
  }
}
```

이제 이 미들웨어를 적용하기 위해선 모듈 클래스의 configure 메소드를 이용한다.



```typescript
import { Module, NestModule, RequestMethod, MiddlewareConsumer } from '@nestjs/common';
import { LoggerMiddleware } from './common/middleware/logger.middleware';
import { CatsModule } from './cats/cats.module';

@Module({
  imports: [CatsModule],
})
export class AppModule implements NestModule {
  configure(consumer: MiddlewareConsumer) {
    consumer
      .apply(LoggerMiddleware)
      .forRoutes({ path: 'cats', method: RequestMethod.GET });
  }
}
```

configure 메소드는 async 함수로 정의할 수 있어서 



#### 번외

**Progressive Web App**

[왜 PWA인가?]( [https://altenull.github.io/2018/02/25/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%A0%88%EC%8B%9C%EB%B8%8C-%EC%9B%B9-%EC%95%B1-Progressive-Web-Apps-%EB%9E%80/](https://altenull.github.io/2018/02/25/프로그레시브-웹-앱-Progressive-Web-Apps-란/) ) 이 글에 정리가 잘 되어 있다. 핵심은 네이티브 앱과 같은 사용자 경험을 제공하는 것입니다. 

[PWA MDN 문서]( [https://developer.mozilla.org/ko/docs/Web/Progressive_web_apps/%EC%86%8C%EA%B0%9C](https://developer.mozilla.org/ko/docs/Web/Progressive_web_apps/소개) ) 에 PWA에 필요한 요소들이 잘 정리가 되어있다.



### Reference

