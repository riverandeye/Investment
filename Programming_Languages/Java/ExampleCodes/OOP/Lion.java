package OOP;

public class Lion extends Animal implements Predator {
    public String getFood(){ // Interface의 메소드를 override
        return "Lion Food";
    };
}
