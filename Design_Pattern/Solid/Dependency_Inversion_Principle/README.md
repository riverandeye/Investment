# Dependency Inversion Principle

- 하이레벨 모듈이 로우레벨 모듈에 의존해서는 안된다 -> 로우 레벨 모듈의 변경이 하이 레벨 모듈의 변경을 요구하는 경우가 발생하면 안된다.
- Abstraction이 detail에 의존해서는 안된다. detail이 Abstraction에 의존해야 한다.
- 프레임워크 개발의 기본이 됩니다

<br>

예제 코드를 통해 이해해 봅시다.

```c++
enum class Relationship
{
	parent,
	child,
	sibling
};

struct Person
{
	string name;
};

struct Relationships// low-level (Person 간의 관계 이므로)
{
	vector<tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child)
	{
		relations.push_back({ parent, Relationship::parent, child });
		relations.push_back({ child, Relationship::child, parent });
	}
};

struct Research // high-level
{
	 Research(const Relationships& relationships)
	 {
	   auto& relations = relationships.relations;
	   for (auto&& [first, rel, second] : relations)
	   {
	     if (first.name == "John" && rel == Relationship::parent)
	     {
	       cout << "John has a child called " << second.name << endl;
	     }
	   }
	 }
};
```

위 예시 코드는 Person 개체에 대해 누가 누구의 부모고 자식인지에 대한 관계를 나타내는 Relationship 이라는 Person의 하위 개체, 연구를 나타내는 Research라는 Person의 상위 개체를 예시로 듭니다. <br>

상위 개체인 Research는, Constructor 단에서 하위 개체인 Relationship을 input으로 받아, 직접 부모 자식 여부를 if 문을 통하여 확인하는 것을 볼 수 있습니다. 이는 SRP를 어기는 것 뿐만 아니라(Research가 해야 할 여러 일들을 생각하면), 로우레벨인 Relationships 개체의 변화 시 하이레벨의 Research 도 수정을 가해야 하며, 이는 DIP를 위배합니다.<br>

예를 들어, Relationships 의 relations 를 Private로 변경한다면..(소름)<br>

이를 위해, Relationship은 상위 레벨에게 정보를 제공할 abstraction을 따로 마련하여, 해당 추상화를 매개로 정보를 전달해야 합니다. (말이 좀 어려운데, 밑에 코드를 참고하시면 이해하기 쉽습니다.)

<br>

```c++
struct RelationshipBrowser
{
	virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser // low-level
{
	vector<tuple<Person, Relationship, Person>> relations;

	void add_parent_and_child(const Person& parent, const Person& child)
	{
		relations.push_back({ parent, Relationship::parent, child });
		relations.push_back({ child, Relationship::child, parent });
	}

	vector<Person> find_all_children_of(const string& name) override
	{
		vector<Person> result;
		for (auto&& [first, rel, second] : relations)
		{
			if (first.name == name && rel == Relationship::parent)
			{
				result.push_back(second);
			}
		}
		return result;
	}
};

struct Research // high-level
{
	Research(RelationshipBrowser& browser)
	{
		for (auto& child : browser.find_all_children_of("John"))
		{
			cout << "John has a child called " << child.name << endl;
		}
	}
}
```

위 코드에선, Research가 RelationshipBrowser를 input으로 받고, RelationshipBrowser가 제공하는 함수를 통해 결과를 수행합니다. <br>

RelationshipBrowser 라는 Abstract class 를 Relationship이 상속받고, 상위 클래스인 Research에 대해서는 Abstract class를 주고받음으로써, 클래스 간의 의사 소통의 방식을 마련한 것이라고 이해할 수 있습니다. Abstract class가 존재한 덕분에, Research 입장에선 RelationshipBrowser의 인스턴스화 가능한 하위 클래스 중 어떤 클래스의 개체든 input으로 받는다 이해하고, Relationship 입장에선 목표하는 결과를 Person vector로 전달하면 된다고 이해할 수 있습니다.  (일종의 중개자를 마련했다고 볼 수 있습니다)<br>

이와 같은 구성을 통해 상위 클래스인 Research가 하위 클래스인 Relationship의 변화에 관련 없이 작동하게 됩니다.<br>

