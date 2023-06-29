package CWHPrac;

import java.util.Scanner;

public class stringsPrac {
    public static void main(String[] args) {
        try (Scanner S = new Scanner(System.in))
        {
            String name = S.nextLine();
            for (int i = 0; i < name.length(); i++) {
                if (name.charAt(i) == ' ')
                {
                    name = name.substring(0, i) + '_' + name.substring(i+1, name.length());
                }
            }
            System.out.println(name);
        };
    }
}
