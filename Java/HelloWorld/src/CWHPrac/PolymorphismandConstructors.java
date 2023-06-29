package CWHPrac;

public class PolymorphismandConstructors {
    public static void main(String[] args) {
        Student s1 = new Student("Aman", 24);
        s1.getInfo(24);
        s1.getInfo("Rohit", 24);
    }
}

class Student {
    String name;
    int age;

    Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void getInfo(String name) {
        System.out.println(this.name);
    }

    public void getInfo(int age) {
        System.out.println(age);
    }

    public void getInfo(String name, int age) {
        System.out.println(name);
        System.out.println(age);
    }
}
