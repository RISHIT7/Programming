package CWHPrac;

public class arraysPrac {
    public static void main(String[] args) {
        int[][] mat1 = new int[2][3];
        mat1[0][0] = 0;
        mat1[0][1] = 1;
        mat1[0][2] = 2;
        mat1[1][0] = 3;
        mat1[1][1] = 4;
        mat1[1][2] = 5;

        int[][] mat2 = new int[2][3];
        mat2[0][0] = 5;
        mat2[0][1] = 4;
        mat2[0][2] = 3;
        mat2[1][0] = 2;
        mat2[1][1] = 1;
        mat2[1][2] = 0;

        int[][] mat3 = new int[2][3];
        mat3[0][0] = mat1[0][0] + mat2[0][0];
        mat3[0][1] = mat1[0][1] + mat2[0][1];
        mat3[0][2] = mat1[0][2] + mat2[0][2];
        mat3[1][0] = mat1[1][0] + mat2[1][0];
        mat3[1][1] = mat1[1][1] + mat2[1][1];
        mat3[1][2] = mat1[1][2] + mat2[1][2];

    }    
}
