import java.util.Scanner;

/**
 * Created by fxd on 2017/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(Main.pick7(sc.nextInt()));
    }

    private static int pick7(int N) {
        int ans = 0;
        for(int i = 7; i <= N; i++) {
            if(tryMultiple7(i) || tryContain7(i)) {
                ans++;
            }
        }
        return ans;
    }

    private static boolean tryMultiple7(int N) {
        return N % 7 == 0;
    }

    private static boolean tryContain7(int N) {
        while(N != 0) {
            if(N % 10 == 7) {
                return true;
            } else {
                N = N / 10;
            }
        }
        return false;
    }
}
