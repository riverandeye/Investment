package Basic;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.FileReader;

public class fileIOExample {
    public static void main(String[] args) throws IOException {
        FileOutputStream output = new FileOutputStream("./out.txt"); // true를 인자로 붙이지 않으면 새로 생성한다.
        for(int i=1; i<11; i++) {
            String data = i+" 번째 줄입니다.\r\n"; // 윈도우라서 \r 문자를 추가함. unix는 그렇지 않아도 된다.
            output.write(data.getBytes()); // FileOutputStream의 write 메소드를 쓰는 경우 byte 형식으로 변경해주어야 한다.
        }

        output.close();

        FileWriter fw = new FileWriter("./out.txt", true);
        for(int i=1; i<11; i++) {
            String data = i+" 번째 줄입니다그닥.\r\n"; // 여전히 \r\n을 붙여야 함
            fw.write(data); // 대신 바이트로 바꾸지 않아도 된다.
        }
        fw.close();

        PrintWriter pw = new PrintWriter(new FileWriter("./out.txt", true)); // 위와 다르다.
        // append 하고 싶은 경우엔 FileWriter를 넣어줘야한다
        // 그렇지 않으면 궂이 넣어주지 않아도 된다.
        for(int i=1; i<11; i++) {
            String data = i+" 번째 줄입니다리.";
            pw.println(data); // 콘솔처럼 출력하는데 파일로 감, \r\n 이랑 Byte변환 안해도 된다.
        }
        pw.close();

        // read file example
        BufferedReader br = new BufferedReader(new FileReader("./out.txt"));
        while(true) {
            String line = br.readLine();
            if (line==null) break;
            System.out.println(line);
        }
        br.close();
    }
}
