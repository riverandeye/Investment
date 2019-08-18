package Basic;

import java.util.HashMap;

public class MapExample {
    public static void main(String[] args){
        HashMap noGeneric = new HashMap(); // Generic 미설정
        HashMap<String, String> mymap = new HashMap(); // Generic 설정 (java 8)

        // put method
        noGeneric.put(1, "hello");
        noGeneric.put("World", 2); // 다른 형식의 Key value pair 설정 가능
        mymap.put("hello", "world");
        mymap.put("1", "2");
        // mymap.put(1, 2) // error 발생

        // get method
        System.out.println(noGeneric.get(1));
        System.out.println(noGeneric.get("World"));
        System.out.println(mymap.get("1").getClass().getName());

        // LinkedHashmap -> 입력된 순으로 hash 정렬
        // Treemap -> key의 순서대로 hash 정렬
    }
}
