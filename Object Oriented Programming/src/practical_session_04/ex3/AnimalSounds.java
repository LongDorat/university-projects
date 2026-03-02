package practical_session_04.ex3;

public class AnimalSounds {
    public static void main(String[] args) {
        Cow cow = new Cow("Holstein", "Short", "Black and White", 5, 1500);
        Goat goat = new Goat("Nubian", "Short", "Brown", 3, 120);
        Pig pig = new Pig("Yorkshire", "Short", "Pink", 2, 300);

        cow.sound();
        goat.sound();
        pig.sound();
    }
}
