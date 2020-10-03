import java.util.*;

public class binarystringofsizenwithoutconsecutive0
{
    public static int solve(int n,int opt)
    {
        if(n==1)
        {
            return 1;
        }
        if(opt==-1)
        {
            return 2*solve(n-1,1)+solve(n-1,0);

        }   
        else if(opt==0)
        {
            return solve(n-1,1);
        }   
        else
        {
           return solve(n-1,1)+solve(n-1,0);
        }  
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int ans=solve(n,-1);
        System.out.println(ans);
        scn.close();        
    }
}