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

    public static String command(int num){

        //step 1: get reverse int of current num
        //step 2: make addition in int form
        //step 3: send the added int in array form to isPalin
        //step 4: repeat until isPalin is true, save the result int
        int times = 0;

        while (!isPalin(String.valueOf(num).toCharArray())){
            int length = String.valueOf(num).length();
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<length; i++){
                sb.append(String.valueOf(num).charAt(length-1-i));
            }
            num = Integer.parseInt(sb.toString()) + num;
            times = times + 1;
        }

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