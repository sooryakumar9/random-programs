// Program to perfrom matrix addition where input of size of matrix is given on compilation of the program.

import java.util.Scanner;
public class MatrixAddition 
{
    public static void main(String[] args)
    {
        if(args.length != 2)
        {
            System.out.println("Usage Java MatrixAddition <order M><order N>");
            return;
        }
        int M = Integer.parseInt(args[0]);
        int N = Integer.parseInt(args[1]);
        int[][] matrix1 = new int[M][N];
        int[][] matrix2 = new int[M][N];
        int[][] sum = new int[M][N];
        Scanner input = new Scanner(System.in);
        System.out.println("Enter elements of Matrix 1: ");
        inputMatrix(matrix1, input);
        System.out.println("Enter elements of Matrix 2: ");
        inputMatrix(matrix2, input);
        addMatrices(matrix1,matrix2,sum);
        displayMatrix(sum);
        input.close();
    }

    public static void inputMatrix(int[][] matrix, Scanner input)
    {
        for(int i = 0;i<matrix.length;i++)
        {
            for(int j = 0;j<matrix[0].length;j++)
            {
                System.out.println("Enter element at position("+i+","+j+"): ");
                matrix[i][j] = input.nextInt();
            }
        }
    }

    public static void addMatrices(int[][] matrix1,int[][] matrix2,int[][] sum)
    {
        for(int i = 0;i<matrix1.length;i++)
        {
            for(int j = 0;j<matrix1[0].length;j++)
            {
                sum[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    public static void displayMatrix(int[][] matrix)
    {
        for(int i = 0;i<matrix.length;i++)
        {
            for(int j = 0;j<matrix[0].length;j++)
            {
                System.out.print(matrix[i][j]+" ");
            }
            System.out.println();
        }
    }
}
