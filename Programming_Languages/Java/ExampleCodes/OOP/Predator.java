package OOP;

public interface Predator {
    public String getFood();
}

// 추상클래스는 abstract랑 메소드 둘다 추가할 수 있다.

//public abstract class Predator extends Animal {
//    public abstract String getFood(); -> 애는 interface
//
//    public boolean isPredator() { -> 애는 모든 하위 클래스에서 사용될 공통된 함수
//        return true;
//    }
//}