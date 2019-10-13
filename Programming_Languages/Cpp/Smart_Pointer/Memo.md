# Smart Pointer



Smart pointer란 

- C++ Template class로 정의됨.
- 자동적으로 delete call

#include <memory> 로 불러옴.

raw pointer를 다루는 Wapper이다. 
Dereference, Member selection 을 overload 했고,
그러다보니 Pointer arithmetics를 쓰지 않음.

custom deleter를 가질 수 있음.

std::smart_pointer<Some_class> ptr = ...
ptr->method();
cout << *ptr << endl;

ptr는 자동적으로 사라진다!

RAII - Resource Acquisition Is Initialization
: 일반적으로 사용되는 패턴
: 기본적으로 스택에 저장
: 파일을 열고, 메모리를 할당하고, lock을 건다.
: 초기화는 Object Constructor 시간에 acquire된다

RAII 패턴은 C++ 같이 개발자가 직접 resource 관리를 해주어야 하는 언어에서 leak 을 방지하기 위한 중요한 기법으로
해당 리소스의 사용 scope이 끝날 경우에 자동으로 해제를 해주며 exception이 발생하거나 하는 경우에도 획득한 자원이 해제됨을 보장하여
안전한 코드를 작성할 수 있다.