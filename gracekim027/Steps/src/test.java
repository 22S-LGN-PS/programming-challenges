import java.util.*;

public class test {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            sb.append(command(start, end));
            sb.append('\n');
        }
        System.out.println(sb.toString().trim());
        System.exit(0);
    }

    public static int command(int start, int end) {
        int maxSteps = 1;
        int times = 0;
        int stepsLeft = end-start;

        while (stepsLeft >= maxSteps*2){
            start = start + maxSteps;
            end = end - maxSteps;
            stepsLeft = stepsLeft - 2*maxSteps;
            maxSteps += 1;
            times += 2;
        }

        if (stepsLeft < 2*(maxSteps) && stepsLeft > maxSteps && stepsLeft > 0){
            times += 2;
        }else if (stepsLeft <= maxSteps && stepsLeft > 0){
            times += 1;
        }
        return times;
    }
}


