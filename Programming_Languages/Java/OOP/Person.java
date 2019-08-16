package OOP;

public class Person extends Animal {
    private String job;

    public Person(){} // default Constructor

    public Person(String name){ // Overloaded Constructor
        this.setName(name);
    }

    public void sleep(int time){
        System.out.println(String.format("%s is sleeping %d times", this.getName(), time));
    }

    public void setJob(String job){
        this.job = job;
    }

    public String getJob(){
        return this.job;
    }

    public String getVoice(){ // method overriding
        return String.format("제 이름은 %s입니다.", this.getName());
    }

    public static void main(String[] args){
        Animal KwanHun = new Person();
        Person Jini = new Person();
        KwanHun.setName("KwanHun");
        Jini.setName("Jini");

        // overrided getVoice
        System.out.println(KwanHun.getVoice());
        System.out.println(Jini.getVoice());

        // overloaded sleep
        KwanHun.sleep();
        Jini.sleep(3); // Overloading은 Person 으로 선언된 클래스에서만 사용 가능하다.
    }
}