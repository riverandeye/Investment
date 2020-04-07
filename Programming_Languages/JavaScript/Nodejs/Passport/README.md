# Passport js



### 인증

**Authentication** : 내가 어떤 사용자인지 확인하는 과정 (허가 요청)

**Authorization** : 사용자가 해당 리소스에 접근 권한이 있는지 확인하는 것



### Oauth

인증 표준

[https://oauth.net](https://oauth.net/)

https://opentutorials.org/course/3405

공부하지.



### 쿠키와 세션을 이용한 인증

- 세션 DB는 인메모리, Permanent DB를 나누는거.
- 패스워드는 복호화 할수 없는 해시로 해야 한다.
- Post로 로그인
  - ID와 PW를 받아 user DB를 뒤져본다.
  - 사용자 PW를 암호화 -> 로그인됬으면 세션에 저장
- 로그아웃은 세션에서 지우고 쿠키에서 지우면 된다. (clearCookie)
- 세션저장소는 보통 Redis, MainCached, MongoDB
  - 세션 DB를 써야하는 경우는 서버 죽어서 회원 연결정보가 날라가면 안되는 경우 (세션이 사라지면 안되는 경우)
  - 서버 이중화일때 (세션 공유해야됨.)



### Passport

**설치**

```
npm install passport
npm install passport-local
```



**예제코드**

```js
passport.use(new Strategy(
    function(username, password, cb) {
        db.users.findByUsername(username, function(err, user) {
            if (err) { return cb(err); }
            if (!user) { return cb(null, false); }
            if (user.password != password) { return cb(null, false); }
            return cb(null, user);
        });
    }));
```

db.users.findByUsername 는 user Model에서 username을 가져오라 (ORM 스러움)

가져온 뒤, err면 에러, user가 아니면 오류



### 회원가입

- Passport는 가입 자체는 관여하지 않음
- Oauth는 추가적인 구현이 필요함.



### Autheticate

- 로그인 요청시 호출되는 미들웨어

```js
app.post('/login', 
         passport.authenticate('local', {successRedirect : '/', failureRedirect : 												'/login'}), 
         (req, res)=> {
    res.redirect('/users/' + req.user.username)
})
```



### serializeUser, deserializeUser

- 인증 성공시 serializeUser() 호출, 세션에 필요한 정보를 넘겨준다.
  - serializeUser -> 저장한 데이터를 송신할 수 있게 serial 하게 변경하는 것을 의미함.
- deserializeUser(), 세션 정보를 이용해 추가적인 정보를 얻어 올 수 있다. 호출 이후 해당 값은 req.user 값에 저장됨.

```js
passport.serializeUser(function(user,done){
    done(null, user.id);
})

passport.deserializeUser(function(id, done){
    User.findByID(id, function(err, user){
        done(err,user);
    })
})
```

- 예시이긴 하지만, 매번 User.findByID로 DB에 접근해야 함.
- 일반적으로 DOM에 user.ID 를 저장하여 판단해서 사용한다.



### 로그인 여부 확인

```js
app.get('/profile', (req,res)=>{
    if(req.isAuthenticated()){
        return res.json({status:'ok', user:req.user});
    }
    return res.status(401).json({status : 'unauthorized'});
})
```



### 로그아웃

```js
app.get('/', function(req, res){              
  req.logout();
  res.redirect('/login');
});
```



### 참고할 것 

https://opentutorials.org/course/3402



http://www.passportjs.org/docs/