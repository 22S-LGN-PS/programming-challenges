import java.util.*;

public class test{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        boolean stop = false;
        StringBuilder sb = new StringBuilder();

        while(!stop){
            int cases = sc.nextInt();
            for (int i=1; i<=cases; i++){
                int rows = sc.nextInt();
                int columns = sc.nextInt();
                String[] matrix = new String[rows];

                for (int j=0; j<rows; j++){
                    matrix[j] = sc.nextLine();
                }

                matrix[rows-1] = sc.nextLine();

                int numWords = sc.nextInt();
                String[] words = new String[numWords];

                for (int k=0; k<numWords; k++){
                    words[k] = sc.nextLine();
                }
                Case oneCase = new Case(matrix, words,rows, columns);
                sb.append(oneCase.command()).append("\n");
            }
            stop = true;
        }
        System.out.println(sb.toString().trim());
        System.exit(0);
    }
}

class Case{
    private char[][] charMatrix;
    private String[] words;
    private int row;
    private int column;


    Case(String[] matrix, String[] words, int row, int column){
        this.words = words;
        char[][] charMatrix = new char[row][column];
        this.row = row;
        this.column = column;

        for (int i=0; i<matrix.length; i++){
            charMatrix[i] = matrix[i].toCharArray();
        }
        this.charMatrix = charMatrix;
    }

    public String command(){
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<words.length; i++){
            sb.append(find(words[i])).append("\n");
        }

        return sb.toString().trim();
    }

    public String find(String word){
        //if the first letter is (a,b)
        //then the ith letter should be
        //if left (a, b-i), left up diagonal (a-i, b-i)
        //if right (a, b+i), right up diagonal (a-i, b+i)
        //if upward (a-i, b), left down diagonal (a+i, b-i)
        //if downward (a+i, b), right down diognal (a+i, b+i)


        Pair startPoint = new Pair(50, 50);
        ArrayList<Pair> instructions = new ArrayList<>();
        instructions.add(new Pair(-1, -1));
        instructions.add(new Pair(-1, 0));
        instructions.add(new Pair(-1, 1));
        instructions.add(new Pair(0, -1));
        instructions.add(new Pair(0, 1));
        instructions.add(new Pair(1, -1));
        instructions.add(new Pair(1, 0));
        instructions.add(new Pair(1, 1));

        for (Pair instruction: instructions){
            for (int i=0; i<row; i++){
                for( int j=0; j<column; j++){
                    Pair resultPoint = searchAccording(word, instruction, 0, i, j, new Pair(50, 50));

                    if (resultPoint != null && startPoint.compareTo(resultPoint) == -1){
                        startPoint.swap(resultPoint);
                    }
                }
            }
        }

        return startPoint.getXPos()+1 + " " + startPoint.getYPos()+1;
    }

    public Pair searchAccording(String word, Pair instruction, int times, int xPoint, int yPoint, Pair result){

        if (times == word.length()){
            return result;
        }else{
            //left (a, b-i) left diagonal up (a-i, b-i), left diagonal down (a+i, b-i)
            //left 는 항상 (*, b-i), right 는 항상 (*, b+i)

            //up 는 항상 (a-i, *) down 는 항상 (a+i, *)
            //diagonal 은 그냥 (x,y) 모두 합쳤을 떄의 결과물 (고려 X)
            if (Character.toLowerCase(word.charAt(times)) == Character.toLowerCase(charMatrix[xPoint][yPoint]) && xPoint < row && yPoint < column){
                result = searchAccording(word, instruction, times+1,
                        xPoint+instruction.getXPos(), yPoint+instruction.getYPos(), result);
            }else{
               return null;
            }
        }
        return result;
    }


class Pair{
    int xPos;
    int yPos;
    Pair(int x, int y){
        xPos = x;
        yPos = y;
    }
    public int getXPos(){return xPos;}
    public int getYPos(){return yPos;}

    public int compareTo (Pair comparePos){
        if (comparePos.getXPos() < xPos){
            //then comparePos needs to return
            return -1;
        }else if (comparePos.getXPos() > xPos){
            return 1;
            //then no change
        }else{
            if (comparePos.getYPos() < yPos){
                return -1;
            }else if (comparePos.getYPos() > yPos){
                return 1;
            }else{
                return 0;
                //no change
            }
        }
    }

    public void swap(Pair newPair){
        xPos = newPair.getXPos();
        yPos = newPair.getYPos();
    }
    }
}


