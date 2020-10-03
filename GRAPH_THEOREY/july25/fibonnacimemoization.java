import java.util.*;

public class fibonnacimemoization
{
    //memoization is done
    public static int fibonnaci(int n,int[] qb)
    {
        if(n==0 || n==1)
        {
            return n;
        }        
        else if(qb[n]!=0)
        {
            return qb[n];
        }
        else
        {
         int fnm1=fibonnaci(n-1, qb);
         int fnm2=fibonnaci(n-2, qb);
         qb[n]=fnm1+fnm2;
         return qb[n];

        }
        
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int [] qb=new int[n+1];
        long start=System.currentTimeMillis();
        System.out.println(fibonnaci(n, qb));
        long end=System.currentTimeMillis();
        System.out.println(end-start +" ms");
        scn.close();
    }
}