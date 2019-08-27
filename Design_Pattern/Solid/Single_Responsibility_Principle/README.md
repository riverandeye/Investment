# Single Responsibility Principle

- 각 Responsibility를 오직 하나의 클래스에만 지정하는 것.

- 물론 responsibility를 분리하는것은 어렵다. 그래서 잘 해야 한다.

- 클래스는 해당 Responsibility를 완전히 Encapsulate 해야한다.

  <br>

예제를 통해 알아봅시다.

```c++
struct Journal {
	string title;
	vector<string> entries;

	Journal(const string& title) : title(title) {}

	void add_entry(const string& entry) {
		static int count;
		entries.push_back(lexical_cast<string>(count++) + ": " + entry);
	}

	void save(const string& filename) {
		ofstream ofs(filename);
		for (auto& e : entries)
			ofs << e << endl;
	}
};
```

일기를 작성하기 위해 Journal이라는 class를 만들어 Journal 내 string 벡터인 entries 를 통해Journal을 저장한다. add_entry 를 통해 일기에 한줄씩 추가하며, Save를 통해 file에 해당 entries를 저장한다.

여기서 적합하지 않은 것은, save 메소드를 Journal 내에 저장해준 것에 있다. Journal 이 아니라 Magazine, 대자보 등 새로운 클래스가 등장할 때 마다, 그것을 저장하는 save 함수를 각각에 만들어주어야 하는 단점이 있다.

이러한 "저장"이라는 기능을 "매체"와 독립적으로 구성하기 위해서 PersistentManager 라는 클래스를 두어, 해당 객체가 저장을 관장하게끔 할 수 있다. 이는 다음과 같다.

```c++
struct PersistentManager {
	static void save(const Journal& j, const string& filename) {
		ofstream ofs(filename);
		for (auto& e : j.entries)
			ofs << e << endl;
	}
};
```

여기선 class를 Journal만 input으로 받게 했는데, "매체" 와 같은 Abstract class를 따로 정의하여 인터페이스로 이용한다면 OCP(Open Closed Principle)를 지킬 수 있을 것이다.

이러한 방식으로 해당 클래스가 하나의 역할을 하게끔 하면 불필요한 코드 생산을 막을 수 있고 기능 추가에 유연해질 수 있다.