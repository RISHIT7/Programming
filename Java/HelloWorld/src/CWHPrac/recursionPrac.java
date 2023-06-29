package CWHPrac;

import java.util.Scanner;

public class recursionPrac {
    public static void main(String[] args) {
        try (Scanner S = new Scanner(System.in)) {
            int n = S.nextInt();
            int n_fact = Factorial(n);
            System.out.println(n_fact);
        }   
        ;
    }

    public static int Factorial(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n * Factorial(n - 1);
        }
    }

}