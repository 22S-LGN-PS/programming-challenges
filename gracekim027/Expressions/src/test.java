import java.io.BufferedReader;
import java.io.InputStreamReader;


public class test {
    public static void main(String args[]) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        while (true){
            try{
                String input = br.readLine();
                if (input.isEmpty()){
                    break;
                }
                int length = Integer.parseInt(input.split("\\s+")[0]);
                int depth = Integer.parseInt(input.split("\\s+")[1]);
                System.out.println(command(length, depth));

            }catch (Exception e){
                System.out.println(e);
            }
        }

        System.out.println(sb.toString().trim());
        System.exit(0);
    }

    public static int command(int length, int depth) {
       // () --> length 2 depth 1
        // (()) --> length 4 depth 2
        //if everything is inside of everything the max length is 2*depth
        //so if length > depth, then (length-depth)/2 pairs have to be single
        //뭐야 그냥 inside + single 배열 개수 구하는거네

        if (length == depth*2){
            return 1;
        }else{
            int singles = (length-depth)/2;
            //multiples = (length - 2*singles)/2
            int multiples = (depth)/2;
            return factorial(singles+multiples)/(factorial(singles)*factorial(multiples));

        }
    }

    public static int factorial(int num){
        int result = 1;
        while (num > 1){
            result = result * num;
            num = num-1;
        }
        return result;
    }
}
