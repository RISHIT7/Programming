package CWHPrac;

import java.util.Scanner;

public class CGPA {
    public static void main(String[] args) {
        try (Scanner S = new Scanner(System.in)) {
            int m1 = S.nextInt();
            int m2 = S.nextInt();
            int m3 = S.nextInt();
            int m4 = S.nextInt();
            int m5 = S.nextInt();
            double percen = (m1+m2+m3+m4+m5)/500.0;
            System.out.println(percen);
        }
    }
}
