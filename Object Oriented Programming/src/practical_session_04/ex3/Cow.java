package practical_session_04.ex3;

public class Cow extends Animal {
    public Cow(String breed, String coat, String color, int age, int weight) {
        super(breed, coat, color, age, weight);
    }
    
    public void sound() {
        System.out.println("Cow says: Moo!");
    }
    
}
