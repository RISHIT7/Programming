public class Datatypeconversions {
    public static void main(String[] args) {
        int number1 = 5;
        double number2 = number1;
        System.out.println(number2);
        // 5.0

        // but a double to integer is not possible directly
        // but is possible byt using
        double num1 = 5.8;
        int num2 = (int)num1;
        System.out.println(num2);
    }
}
