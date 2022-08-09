import java.util.*;

public class test {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextInt()){
            StringBuilder sb = new StringBuilder();
            sb.append(command(sc.nextInt()));
            System.out.println(sb);
        }
        System.exit(0);
    }

    public static int command(int num) {
       boolean flag = true;
       int result = 1;
       long p = 1;
       while (flag && num != 1){
           if ((p*10 + 1) % num == 0){
               result = result + 1;
               flag = false;
           }else{
               result = result + 1;
               p = p*10 + 1;
           }
       }
       return result;
    }
}
