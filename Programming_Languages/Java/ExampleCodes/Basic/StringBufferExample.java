package Basic;

public class StringBufferExample {

    // method append
    private static StringBuffer appendexample(){ // StringBuffer에 문자열을 추가함으로써 합친다.
        StringBuffer sb = new StringBuffer();
        sb.append("hello");
        sb.append(" ");
        sb.append("World");
        return sb;
    }

    // method substring
    private static String substringexample(StringBuffer input){
        return input.substring(0,8);
    }

    // method insert
    private static void insertexample(StringBuffer input){
        input.insert(0, "Inserted ");
    }

    public static void main(String[] args){
        StringBuffer a = appendexample();
        System.out.println(a.toString());
        insertexample(a);
        System.out.println(a.toString());
        String b = substringexample(a);
        System.out.println(b);
    }
}