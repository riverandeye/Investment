# Liskov Substitution Principle

- 어떠한 경우에도 Derived Class는, Parent Class가 들어가는 곳에 무조건 대체될 수 있어야 한다.
- Derived Class에서 Parent Class의 method를 올바르게 Override 해야 한다. 
- 애초부터 자녀 클래스는 부모 클래스의 메서드를 손상시키면 안되고, 잘 보존해야 함.<br>

예제를 통해 알아봅시다.

```c++
class Rectangle{
protected:
	int width, height;
public:
	Rectangle(const int width, const int height)
		: width{ width }, height{ height } { }

	int get_width() const { return width; }
	virtual void set_width(const int width) { this->width = width; }
	int get_height() const { return height; }
	virtual void set_height(const int height) { this->height = height; }

	int area() const { return width * height; }
};

void process(Rectangle& r){
	int w = r.get_width();
	r.set_height(10);

	std::cout << "expected area = " << (w * 10)
		<< ", got " << r.area() << std::endl;
}
```

직사각형 클래스를 정의하였고, 클래스의 interface를 구성하였다. 그리고 나서, process 라는 함수를 통하여 해당 직사각형의 height를 10으로 바꾸고 넓이를 구하였다.<br>

```c++
class Square : public Rectangle
{
public:
	Square(int size) : Rectangle(size, size) {}
	void set_width(const int width) override {
		this->width = height = width;
	}
	void set_height(const int height) override {
		this->height = width = height;
	}
};
```

그 후 정사각형 클래스는 Rectangle 클래스를 Base class로 하여 상속하였고, 정사각형은 width와 height가 같으므로 set width, height를 override 하여 가로 세로 길이를 같도록 만들었다.<br>

근데 이 부분에서 문제가 발생한다. 기존 process 함수에 Rectangle을 넣었을 떄는 잘 작동하지만, Square를 넣으면, set_height()함으로써 width와 height가 동시에 변하기 때문에 예상된 결과가 나오지 않는다. **Base class인 Rectangle의 자리를 Square가 대체하지 못하므로** 이는 Liskov Substitution Principle을 위배하는 코드 작성이다.<br>

이건 무엇보다 우선순위의 문제이다. 상위 클래스를 위한 함수들이 하위 클래스에서 동일하게 작동하지 않아 상위 클래스의 함수를 대체할 수 없다면, 객체지향의 이점을 잃게 된다.<br>

```c++
struct RectangleFactory
{
	static Rectangle create_rectangle(int w, int h);
	static Rectangle create_square(int size);
};
```

위 코드의 문제 해결 방법은 여러가지가 있겠지만, 가장 단순한 방법은 위와 같이 Rectangle을 만드는 객체와 인터페이스를 따로 설정해주는 것이 대표적이다. <br>