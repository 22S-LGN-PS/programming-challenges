import javafx.util.Pair;

import java.util.*;

//QUESTION: 순서를 어떻게 보존하지..?

/*
public class test {
    public static void main(String args[]) {
        //structure with key value and order??
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            int tasks = sc.nextInt();
            HashMap<Integer, Pair> taskMap = new LinkedHashMap<>();
            ArrayList<Pair> taskList = new ArrayList<>();

            for (int j=0; j< tasks; j++){
                Pair task = new Pair<>(sc.nextInt(), sc.nextInt());
                taskMap.put(j, task);
                taskList.add(task);
            }

            sb.append(command(taskMap, taskList));
        }

        System.out.println(sb.toString().trim());
        System.exit(0);
    }

    public static String command(HashMap<Integer, Pair> taskMap, ArrayList<Pair> taskList){
        //taskMap 의 key 는 i, value 는 <num of days, fine per day>
        for(int x=1; x<taskMap.size(); x++){
            for(int y=0; y<taskMap.size()-x;y++){
                if((int)taskMap.get(y).getKey()*(int)taskMap.get(y+1).getValue() > (int)taskMap.get(y+1).getKey()* (int)taskMap.get(y).getValue()){
                    Pair tmp = taskMap.get(y);
                    System.out.println("replaced");
                    taskMap.replace(y, taskMap.get(y+1));
                    taskMap.replace(y+1, tmp);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        ArrayList<Integer> keySet = new ArrayList<>(taskMap.keySet());
        for(int i=0; i<taskMap.size(); i++){
            sb.append(keySet.get(i) +1).append(" ");
        }
        return sb.toString();
    }
}
*/
