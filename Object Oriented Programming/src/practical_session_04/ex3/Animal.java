package practical_session_04.ex3;

public class Animal {
    String breed;
    String coat;
    String color;
    int age;
    int weight;

    public Animal(String breed, String coat, String color, int age, int weight) {
        this.breed = breed;
        this.coat = coat;
        this.color = color;
        this.age = age;
        this.weight = weight;
    }

    public void sound() {
        System.out.println("Animal makes a sound");
    }
}
