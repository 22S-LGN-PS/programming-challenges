import java.util.*;

public class test {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
            while (sc.hasNextInt()) {
                int size = sc.nextInt();
                int[] numbers = new int[size];

                for (int i = 0; i < size; i++) {
                    numbers[i] = sc.nextInt();
                }

                boolean contains = true;
                boolean[] allDiffs = new boolean[size];

                for (int i = 0; i < size - 1; i++) {
                    int diff = numbers[i] - numbers[i + 1];
                    if (diff < 0) {
                        diff = -diff;
                    }
                    if (diff < size) {
                        allDiffs[diff] = false;
                    }
                }

                for (int i=1; i<allDiffs.length; i++) {
                    if (!allDiffs[i]) {
                        contains = false;
                        break;
                    }
                }

                if (!contains) {
                    System.out.println("Not jolly");
                } else {
                    System.out.println("Jolly");
                }
            }
        System.exit(0);
    }
}