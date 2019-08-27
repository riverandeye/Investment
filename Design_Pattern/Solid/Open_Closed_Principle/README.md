# Open Closed Principle

- 소프트웨어의 개체는 확장에 대해 열려있고, 수정에 대해서는 닫혀 있어야 한다.
- 여러 모듈 중 하나를 수정하게 되면 다른 모듈을 줄줄이 수정해야 되게 된다.
- Open Closed Principle을 지키면, 기능을 추가하거나 변경해야 할 때 원래 코드를 변경하지 않아도 새로운 코드를 추가함으로써 기능의 추가나 변경이 가능하다.
- C++ 에서는 Template을 이용한 Generic Programming이 이를 지원한다.



예제를 통해 알아봅시다.

```c++
enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
	string name;
	Color color;
	Size size;
};
```

Color와 Size가 정해져 있는 Product를 선언한다. 그 후 우리는 이런 Product를 Color와 Size에 대해 필터링 하고 싶어서, ProductFilter를 정의하였다.

```c++
struct ProductFilter
{
	typedef vector<Product*> Items;

	Items by_color(Items items, const Color color){
		Items result;
		for (auto& i : items)
			if (i->color == color)
				result.push_back(i);
		return result;
	}

	Items by_size(Items items, const Size size){
		Items result;
		for (auto& i : items)
			if (i->size == size)
				result.push_back(i);
		return result;
	}

	Items by_size_and_color(Items items, const Size size, const Color color){
		Items result;
		for (auto& i : items)
			if (i->size == size && i->color == color)
				result.push_back(i);
		return result;
	}
};
```

이러한 코드의 문제는, Filter 해야 하는 기준이 많아질수록, 수정해야 할 코드가 늘어난다. 무엇보다 client에게 새로 추가된 수많은 함수들에 적응해야 한다는 점에 큰 문제가 있다. 곧, 기준을 추가할 때 마다 기존에 생성했던 코드를 매번 수정해야 하며, 이는 OCP에 어긋난다.

Open Closed Principle을 지키려면, 기능을 추가할 때 기존 코드를 변경할 필요가 없어야 한다. 

```c++
template <typename T> struct Specification{
	virtual ~Specification() = default;
	virtual bool is_satisfied(T* item) const = 0;
}

template <typename T> struct Filter
{
	virtual vector<T*> filter(vector<T*> items,
		Specification<T>& spec) = 0;
};

struct newFilter : Filter<Product>
{
	vector<Product*> filter(vector<Product*> items,
		Specification<Product>& spec) override
	{
		vector<Product*> result;
		for (auto& p : items)
			if (spec.is_satisfied(p))
				result.push_back(p);
		return result;
	}
};
```

Specification 은, Template T에 해당하는 인스턴스가 특정 기준을 만족하는가에 대해 알려주는 Abstract class 이다. Filter는 template T에 해당하는 인스턴스의 vector 들 중 특정 기준을 만족하는 것들만 리턴하게끔 구성하였다. 그 후 newFilter를 정의하여 함수를 오버라이딩 하여 정의하였다. 

여기서 주목해야 할 부분은, Filter에서 특정 Specification이 input으로 들어간다는 점이다. DIP를 만족시키기 위하여 input으로 들어가는 spec을 Pure abstract class로 구성한 것을 확인 할 수 있다. 

이렇게 구성할 시 장점은, 마치 정수기의 소켓을 넣는 것 처럼, 개별적으로 구성된 Specification을 Filter에 input으로 넣어주기만 하면, 그 기준에 대해서 filtering을 해주는 것이다. 모듈화된 아름다운 코드이다. 

이제 실제로 특정 기준에 따라 Specification 하는 클래스를 만들어야 한다.

```c++
struct ColorSpecification : Specification<Product>
{
	Color color;

	ColorSpecification(Color color) : color(color) {}

	bool is_satisfied(Product* item) const override {
		return item->color == color;
	}
};

struct SizeSpecification : Specification<Product>
{
	Size size;

	explicit SizeSpecification(const Size size)
		: size{ size }
	{
	}


	bool is_satisfied(Product* item) const override {
		return item->size == size;
	}
};

template <typename T> struct AndSpecification : Specification<T>
{
	const Specification<T>& first;
	const Specification<T>& second;

	AndSpecification(const Specification<T>& first, const Specification<T>& second)
		: first(first), second(second) {}

	bool is_satisfied(T* item) const override {
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};
```

위와 같이, Specification을 상속하여 필터에 넣을 Specification을 만들어 줄 수 있으며, 2가지 경우 모두를 기준으로 하고 싶은 경우 Andspecification 과 같이 2개의 Specification을 필요로 하는 새로운 클래스를 형성해주면 된다.

```C++
template <typename T> AndSpecification<T> operator&&
(const Specification<T>& first, const Specification<T>& second){
	return { first, second };
}
```

편하게 사용하기 위해서 && operator를 override 해주어, 독립된 specification을 구성한 후 and operator로 붙여서 andspecification을 리턴받으면 된다.

<br>

위와 같이 코드를 구성할 시 병합을 위해 이전 코드를 수정할 필요가 없을 뿐더러 조건을 추가하는 일 이 수월해진다. 이러한 코드가 Open_Closed_Principle을 만족한 것이라고 할 수 있다.