import java.util.Scanner;
public class wave {
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        int[][] arr = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
        };
        int[][] ans = new int[arr.length][arr[0].length];
        wave_1(arr, ans);
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans[0].length; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void wave_1(int[][] arr, int[][] ans) {
        for (int r = 0; r < arr.length; r++) {
            if (r % 2 == 0) {
                for (int c = 0; c < arr[0].length; c++) {
                    ans[r][c] = arr[r][c];
                }
            } else {
                for (int c = arr[0].length - 1; c >= 0; c--) {
                    ans[r][c] = arr[r][c];
                }
            }
        }
    }
}