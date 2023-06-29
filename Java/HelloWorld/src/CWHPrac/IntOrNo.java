package CWHPrac;

import java.util.Scanner;

public interface IntOrNo {
    public static void main(String[] args) {
        try (Scanner S = new Scanner(System.in)) {
            float a = S.nextFloat();
            if ((a*10)%10 == 0) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        ;
    }
}
