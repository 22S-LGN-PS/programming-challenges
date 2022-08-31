import java.util.*;
import java.math.BigInteger;

public class test {
    private final static BigInteger[][] F = new BigInteger[151][151];

    public static void main( String[] args ) {
        Scanner sc = new Scanner(System.in);
        int length, depth;

        while( sc.hasNext() ) {
            length = sc.nextInt();
            depth = sc.nextInt();
            System.out.println( (command(length/2,depth).subtract(command(length/2,depth-1))) );
        }

        sc.close();
    }

    private static BigInteger command(int length, int depth ) {
        //if pair is already recorded
        if( F[length][depth] != null ) return F[length][depth];

        //if length = 0
        if( length == 0 ) return F[length][depth] = BigInteger.valueOf(1);

        //if depth = 0
        if( depth==0 ) return F[length][depth] = BigInteger.valueOf(0);

        //!null
        F[length][depth] = BigInteger.valueOf(0);

        //책에 나온 식
        for( int i=0; i <= length-1; ++i ){
            BigInteger tmp = command(i,depth-1).multiply(command(length-i-1,depth));
            F[length][depth] = F[length][depth].add(tmp);
        }

        return F[length][depth];
    }
}
