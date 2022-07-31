import java.util.*;
public class test {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int i=0; i<cases; i++){
            sb.append(command(sc.nextInt())).append("\n");
        }
        System.out.println(sb.toString().trim());
        System.exit(0);
    }

    public static String command(long num){
        int times = 0;

        do{
            int length = String.valueOf(num).length();
            StringBuilder sb = new StringBuilder();

            //get reverse int of current num
            for (int i=0; i<length; i++){
                sb.append(String.valueOf(num).charAt(length-1-i));
            }

            //make addition in long form
            num = Long.parseLong(sb.toString()) + num;

            times = times + 1;

            //send the added long in array form to isPalin
            //repeat until isPalin is true, save the result long
        }while(!isPalin(String.valueOf(num).toCharArray()));

        return times + " " + num;

    }

    public static boolean isPalin(char[] numArray){
        boolean isPalin = true;
        for (int i=0; i<numArray.length/2; i++){
            if (!Objects.equals(numArray[i], numArray[numArray.length - i - 1])){
                isPalin = false;
                break;
            }
        }
        return isPalin;
    }
}