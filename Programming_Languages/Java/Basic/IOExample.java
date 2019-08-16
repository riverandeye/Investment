package Basic;
import java.util.Scanner;

public class IOExample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(sc.next()); // get one token, type : String
        // input : "Hello world" => output : "Hello"

        System.out.println(sc.nextLine().getClass()); // get all Line, type : String
        // input : "Hello world" => output : "Hello"

        // type에 따라 서로 다른 자료형으로 불러올 수 있다.
        System.out.println(sc.nextInt());
        System.out.println(sc.nextDouble());
    }
}