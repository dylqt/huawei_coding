import java.util.Scanner;

/**
 * Created by fxd on 2017/4/17.
 */
public class Main {
    public static void main(String[] args) {
        Scanner ac = new Scanner(System.in);
        String str = ac.nextLine();
        work(str);
    }

    private static void work(String str) {
        int englishChar = 0;
        int blankChar = 0;
        int numberChar = 0;
        int otherChar = 0;
        for(int i = 0; i < str.length(); i++) {
            if(Character.isDigit(str.charAt(i))) {
                numberChar++;
            } else if(str.charAt(i) == ' ') {
                blankChar++;
            } else if(Character.isLetter(str.charAt(i))) {
                englishChar++;
            }else {
                otherChar++;
            }
        }
        System.out.println(englishChar);
        System.out.println(blankChar);
        System.out.println(numberChar);
        System.out.println(otherChar);
        return;
    }
}
