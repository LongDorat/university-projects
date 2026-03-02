package practical_session_04.ex3;

public class Pig extends Animal {
    public Pig(String breed, String coat, String color, int age, int weight) {
        super(breed, coat, color, age, weight);
    }

    @Override
    public void sound() {
        System.out.println("Pig says: Oink!");
    }
}
