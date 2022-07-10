import javafx.util.Pair;

import java.util.*;

public class test {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int roundCount = 0;
        int[] oneRound = new int[15];

                while (sc.hasNextInt()) {
                    StringBuilder result = new StringBuilder();
                    int[] round = new int[5];
                    int[] diceValue = new int[6];
                    round[0] = sc.nextInt();
                    round[1] = sc.nextInt();
                    round[2] = sc.nextInt();
                    round[3] = sc.nextInt();
                    round[4] = sc.nextInt();

                    for (int i=0; i<round.length; i++) {
                        diceValue[round[i]-1] += 1;
                    }

                    Pair<Integer, Integer> max = command(round, diceValue);
                    oneRound[max.getKey()] += max.getValue();
                    roundCount += 1;

                    if (roundCount == 13) {
                        for (int j : oneRound) {
                            result.append(j).append(" ");
                        }

                        System.out.println(result);
                        roundCount = 0;
                        oneRound = new int[13];
                    }

                }

                System.exit(0);
            }

    public static Pair<Integer, Integer> command(int[] round, int[] diceValue){
      int[] funcValue = new int[13];
      int chance = chance(diceValue);
      funcValue[6] = chance;
      int three_kind = three_kind(diceValue);
      funcValue[7] = three_kind;
      int four_kind = four_kind(diceValue);
      funcValue[8] = four_kind;
      int five_kind = five_kind(diceValue);
      funcValue[9] = five_kind;
      int short_straight = short_straight(round);
      funcValue[10] = short_straight;
      int long_straight = long_straight(round);
      funcValue[11] = long_straight;
      int full_house = fullHouse(diceValue);
      funcValue[12] = full_house;
      int simple_sum = sum(diceValue)*diceValue[sum(diceValue)-1];
      funcValue[sum(diceValue)-1] = simple_sum;
      int max = 0;
      int index = 0;
      for (int i=0; i<funcValue.length; i++) {
          if (funcValue[i] > max) {
              max = funcValue[i];
              index = i;
          }
      }

        return new Pair<>(index, max);

    }

    public static int sum(int[] diceValue) {
    int index = 0;
    int sum = 0;
        for (int i = 0; i < diceValue.length; i++) {
            if ((i+1)*diceValue[i] > sum) {
                index = i+1;
            }
        }
        return index;
    }

    public static int chance(int[] diceValue) {
     int sum =0;
     for (int i=0; i<diceValue.length; i++){
         sum += (i+1)*diceValue[i];
     }
     return sum;
    }

    public static int three_kind(int[] diceValue) {
        int max = 0;
        for (int i=0; i<diceValue.length; i++) {
            if (diceValue[i] == 3) {
                max = chance(diceValue);
                break;
            }
        }
        return max;
    }

    public static int four_kind(int[] diceValue) {
        int max = 0;
        for (int i=0; i<diceValue.length; i++) {
            if (diceValue[i] == 4) {
                max = chance(diceValue);
                break;
            }
        }
        return max;
    }

    public static int five_kind(int[] diceValue) {
        int max = 0;
        for (int i=0; i<diceValue.length; i++) {
            if (diceValue[i] == 5) {
                max = 50;
                break;
            }
        }
        return max;
    }

    public static int short_straight(int[] round) {
        //round 는 그냥 dice
        boolean flag1 = true;
        boolean flag2 = true;
        int sum = 0;
        for (int i = 0; i < round.length - 2; i++) {
            if ((round[i + 1] - round[i]) != 1) {
                flag1 = false;
                break;
            }
        }
        for (int i = 1; i < round.length - 2; i++) {
            if ((round[i + 1] - round[i]) != 1) {
                flag2 = false;
                break;
            }
        }

        if (flag1 || flag2) {
            sum = 25;
        }
        return sum;
    }

    public static int long_straight(int[] round) {
        //round 는 그냥 dice
        boolean flag = true;
        int sum = 0;
        for (int i = 0; i < round.length - 1; i++) {
            if ((round[i + 1] - round[i]) != 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            sum = 35;
        }
        return sum;
    }

    public static int fullHouse(int[] diceValue) {
        //2 랑 3만 있어야함.
        int zero = 0;
        int two = 0;
        int three = 0;
        int sum = 0;
        for (int value=0; value<diceValue.length; value++) {
            if (diceValue[value] == 0) {
                zero += 1;
            } else if (diceValue[value] == 2) {
                two += 1;
            } else if (diceValue[value] == 3) {
                three += 1;
            }
        }

        if (zero == 3 && two == 1 && three == 1) {
            sum = 40;
        }

        return sum;
    }

}
