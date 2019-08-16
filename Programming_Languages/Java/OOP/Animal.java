package OOP;

public class Animal {
    private String name; // attribute는 private
    private String voice;

    public void sleep(){
        System.out.println(String.format("%s is sleeping", this.name));
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){ // method는 public
        return this.name;
    }

    public void setVoice(String voice){
        this.voice = voice;
    }

    public String getVoice(){
        return this.voice;
    }
}
