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
    private String[] matrix;
    private char[][] charMatrix;
    private String[] words;
    private int row;
    private int column;


    Case(String[] matrix, String[] words, int row, int column){
        this.matrix = matrix;
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
        //find String in the matrix (can be any way digonal // upper //lower ...

        Pair startPoint = new Pair(50, 50);


        return startPoint.getXPos() + " " + startPoint.getYPos();

        //if the first letter is (a,b)
        //then the ith letter should be
        // if left (a, b-i), left up diagonal (a-i, b-i)
        //if right (a, b+i), right up diagonal (a-i, b+i)
        //if upward (a-i, b), left down diagonal (a+i, b-i)
        //if downward (a+i, b), right down diognal (a+i, b+i)

    }

    public Pair searchLeft(String word){
        boolean exists = true;
        // to search left, start at least at the length column
        // to search left diagonal
        int startX = 0;
        int startY = 0;

        for (int i=0; i<row; i++){
            for (int j=column-1; j>column-word.length(); j--){
                for (int k=j; )
                if (charMatrix[i][j] != word.charAt(word.length()-j-1)){
                    exists = false;
                    break;
                }
            }
        }

        if (exists){
            return new Pair(startX, startY);
        }else{
            return null;
        }

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
}
