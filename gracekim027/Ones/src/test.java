import java.io.BufferedReader;
import java.io.InputStreamReader;

public class test {
    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while(true){
            try{
                String input = br.readLine();
                if (input.isEmpty()){
                    break;
                }
                sb.append(command(Integer.parseInt(input))).append("\n");
            }catch (Exception e){
                System.out.println(e);
            }
        }
        System.out.println(sb.toString().trim());
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
