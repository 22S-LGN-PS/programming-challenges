import java.util.*;

public class test{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()){
            StringBuilder result = new StringBuilder();
            int first = sc.nextInt();
            int second = sc.nextInt();
            result.append(command(first, second)).append("\n");
            System.out.println(result.toString().trim());
        }
        System.exit(0);
    }

    public static String command(int first, int last){
        int start = first;
        int end = last;
        if (first>last) {
            start = last;
            end = first;
        }
        StringBuilder output = new StringBuilder();
        int maxCycle = 1;
        for (int i = start; i<=end; i++){
            if (search(i) > maxCycle) {
                maxCycle = search(i);
            }
        }

        output.append(first).append(" ").append(last).append(" ").append(maxCycle);
        return output.toString();
    }

    public static int search(int num){
        int numCycle = 1;
        while (num != 1) {
            if (num % 2 == 0) {
                num = num/2;
            }else{
                num = num*3 +1;
            }
            numCycle ++;
        }
        return numCycle;
    }
}
