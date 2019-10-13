#include "Player.h"

int main()
{
    {
        Player kwanhun; // Local 객체로 만들어짐.
    
        kwanhun.set_name("kwan_hun");

        // scope를 벗어나면 자동으로 distruct 된다
    }

    {
        Player jinny;
        jinny.set_name("Jinny");

        Player Ben("Ben"); // overloading 했던 메소드는 이렇게 쓰시면 됩니다.
        Ben.set_name("Ben");

        Player Young("Young", 100, 12);
        Young.set_name("Young");
    }

    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *boss = new Player("Boss", 10000, 3000);
    boss->set_name("Boss");

    delete boss;
    delete enemy ; // 포인터로 해준 경우엔 힙영역에 동적할당되니 꼭 delete 해주자.

    return 0;
}