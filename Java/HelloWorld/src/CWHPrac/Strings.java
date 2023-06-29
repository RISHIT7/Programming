package CWHPrac;

public class Strings {
    public static void main(String[] args) {
        String name = new String("Harry");
        System.out.print(name); // no new line characters
        System.out.println(name); // new line added
        System.out.printf("%s", name); // like C
        /*
        other types are
        name.length();
        name.toLowerCase();
        name.toUpperCase();
        name.trim();
        name.Substring(int Start);
        name.Substring(int Start, int end);
        name.equals("Harry");
        name.equalsIgnoreCase("harry");
        */ 
    }
}
