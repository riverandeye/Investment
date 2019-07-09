# Interface Segregation Principle

- 클라이언트가 자신이 이용하지 않는 메서드에 의존하지 않아야 한다.
- 클라이언트는 오직 클라이언트가 필요한 메서드만 제공받아야 한다.
- 이 원칙을 지키기 위해서는 적절한 Abstraction이 필요하고, Single Interface에 많은 기능을 넣는 것을 피해야 한다.<br>

예시를 통해 알아보겠습니다.

```c++
struct Document;

struct IMachine
{
 virtual void print(Document& doc) = 0;
 virtual void fax(Document& doc) = 0;
 virtual void scan(Document& doc) = 0;
};

struct MFP : IMachine
{
 void print(Document& doc) override;
 void fax(Document& doc) override;
 void scan(Document& doc) override;
};

struct Scanner : Imachine
{
 void print(Document& doc) override; // ??
 void fax(Document& doc) override; // ??
 void scan(Document& doc) override;	
};
```

어떤 문서를 다루는 여러 도구들의 클래스를 정의하기 위해서, IMachine이라는 Abstract Class라는 Interface를 만들었습니다. 그리고, Multi-Function Printer를 IMachine을 상속하여 각 함수를 override 하여 구현하는 상황입니다.<br>

위와 같은 상황은 전혀 문제가 되지 않습니다. Abstract class의 Virtual 함수들을 모두 정의 할 수 있기 때문이죠. 하지만 그냥 Scanner나 Fax를 정의하고 싶은 경우엔, 각 기기에 대해 불필요한 기능들이 abstract 되어 있는 걸 확인할 수 있습니다.<br>

위와 같이 Abstract에 불필요한 함수를 포함하는 건 **client에게 올바르지 않은 정보를 제공하는 행위** 입니다. 고로 각 **Interface** 들을 분리(**Segregate)**해주어야 합니다.<br>

```c++
struct IPrinter{
	virtual void print(Document& doc) = 0;
};

struct IScanner{
	virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter{
	void print(Document& doc) override;
};

struct Scanner : IScanner{
	void scan(Document& doc) override;
};
```

위 코드는 Print와 scan Interface를 각각 IPrinter, Iscanner로 구성하고 있습니다. Interface를 분리함으로써 각각 Printer와 Scanner는 불필요한 Interface를 공백으로 남겨둘 필요 없이 필요한 Interface를 override 할 수 있습니다.

```c++
struct IMachine : IPrinter, IScanner{};

struct Machine : IMachine{
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner)
		: printer(printer),
		scanner(scanner)
	{
	}

	void print(Document& doc) override {
		printer.print(doc);
	}
	void scan(Document& doc) override;
};

```

또한 위와 같이 각 Interface를 합친 Machine이라는 Interface를 이용하여 여러 기능을 하는 Machine 또한 정의할 수 있습니다. Interface 를 분리해야 하는 이유를 이젠 아시겠죠? (매우 어색한 마무리)