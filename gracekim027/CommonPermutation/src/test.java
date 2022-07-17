import java.util.*;

public class test{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()){
            String first = sc.nextLine();
            String second = sc.nextLine();
            System.out.println(command(first, second).trim());
        }
        System.exit(0);
    }

    public static String command(String first, String second){
        char[] second_chars = second.toCharArray();
        ArrayList<Character> result = new ArrayList<>();

        for (int i=0; i<first.length(); i++){
            for (int j=0; j<second.length(); j++){
                if (first.charAt(i)==second.charAt(j)){
                    //make it an empty space
                    second_chars[j] = 0;
                    result.add(first.charAt(i));
                    break;
                }
            }
        }

        char[] result_array = new char[result.size()];

        for (int i=0; i<result_array.length; i++){
            result_array[i] = result.get(i);
        }

        Arrays.sort(result_array);
        StringBuilder sb = new StringBuilder();
        for (char c : result_array) {
            sb.append(c);
        }

        return sb.toString();
    }
}

