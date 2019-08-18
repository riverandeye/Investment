package Basic;

public class forEachExample {
    public static void main(String[] args){
        String[] numbers = {"one", "two", "three"};
        for(String number: numbers) { // forEach (number 변수에 array 값이 그대로 전달)
            System.out.println(number);
        }
    }
}
