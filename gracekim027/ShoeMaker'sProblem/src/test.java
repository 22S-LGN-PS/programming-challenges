import java.util.*;

public class test {
    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {

            int tasks = sc.nextInt();
            HashMap<Integer, orderedPair> taskMap = new HashMap<>();

            for (int j=0; j<tasks; j++){
                orderedPair task = new orderedPair(j+1, sc.nextInt(), sc.nextInt());
                taskMap.put(j, task);
            }

            sb.append(command(taskMap));
        }

        System.out.println(sb.toString().trim());
        System.exit(0);

    }

    public static String command(HashMap<Integer, orderedPair> taskMap){
        for(int x=0; x<taskMap.size()-1; x++){
            for(int y=0; y<taskMap.size()-x-1;y++){
                if(taskMap.get(y).getDays()*taskMap.get(y+1).getFine() > taskMap.get(y+1).getDays()*taskMap.get(y).getFine()){
                    orderedPair tmp = taskMap.get(y);
                    taskMap.replace(y, taskMap.get(y+1));
                    taskMap.replace(y+1, tmp);
                }
            }

        }

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<taskMap.size(); i++){
            sb.append(taskMap.get(i).getNum()).append(" ");
        }
        return sb.toString();
    }
}

class orderedPair{
    int taskNum;
    int numDays;
    int fine;

    public orderedPair(int taskNum, int numDays, int fine){
        this.taskNum = taskNum;
        this.numDays = numDays;
        this.fine = fine;
    }

    public int getNum(){return taskNum;}
    public int getDays(){return numDays;}
    public int getFine(){return fine;}
}

