package OOP;

public class Zookeeper {
    public void feed(Predator predator) {
        System.out.println("feed "+predator.getFood()); // getFood 메소드 : Interface에 명시된 메소드
    }

    public static void main(String[] args) {
        Zookeeper zooKeeper = new Zookeeper();
        Tiger tiger = new Tiger();
        Lion lion = new Lion();
        zooKeeper.feed(tiger);
        zooKeeper.feed(lion);
    }
}