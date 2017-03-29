import java.util.Scanner;

/**
 * Created by fxd on 2017/3/29.
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(Main.reverseString(sc.nextLine()));
    }

    private static String reverseString(String str) {
        return new StringBuffer(str).reverse().toString();
    }
}
