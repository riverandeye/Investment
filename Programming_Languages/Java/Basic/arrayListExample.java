package Basic;

import java.util.ArrayList;

public class arrayListExample {
    public static void main(String[] args){
        ArrayList pitches = new ArrayList(); // without Generic (no type binding)

        // add method

        pitches.add("123");
        pitches.add(123);

        // get method
        System.out.println(pitches.get(0).getClass().getName()); // java.lang.String
        System.out.println(pitches.get(1).getClass().getName()); // java.lang.Integer

        // size method
        System.out.println(pitches.size()); // 2

        // contains
        System.out.println(pitches.contains(123)); // true
        System.out.println(pitches.contains("124")); // false

        // remove
        System.out.println(pitches.remove("123")); // true (return deleted or not)
        System.out.println(pitches.remove("124")); // false

        //
    }
}
