import java.util.*;
import java.util.LinkedList;

public class test {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int cases = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < cases; i++) {
            int turtles = Integer.parseInt(sc.nextLine());
            LinkedList<String> original = new LinkedList<>();
            LinkedList<String> finalStack = new LinkedList<>();
            for (int j = 0; j < turtles; j++) {
                original.add(sc.nextLine());
            }
            for (int j = 0; j < turtles; j++) {
                finalStack.add(sc.nextLine());
            }
            sb.append(command(original, finalStack));
            sb.append('\n');
        }
        System.out.println(sb.toString().trim());
        System.exit(0);
    }

    public static String command(LinkedList<String> original, LinkedList<String> finalStack) {
        LinkedList<String> changed = new LinkedList<>();

        //그냥 아래서 하나씩 비교는 반복해야해서 안됨.
        /*for (int i = finalStack.size() - 1; i > 0; --i) {
            if (original.indexOf(finalStack.get(i)) > i) {
                System.out.println("changed");
                changed.add(finalStack.get(i));
                original.remove(finalStack.get(i));
                original.add(0, finalStack.get(i));
            }
        }*/

        for (int i = finalStack.size() - 1; i > 0; --i) {
            if (original.indexOf(finalStack.get(i-1)) > original.indexOf(finalStack.get(i))) {
                changed.add(finalStack.get(i-1));
                original.remove(finalStack.get(i-1));
                original.add(0, finalStack.get(i-1));
            }
        }
        StringBuilder sb = new StringBuilder();
        for (String turtle : changed) {
            sb.append(turtle).append("\n");
        }
        return sb.toString();
    }
}

