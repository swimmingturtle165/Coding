import java.util.*;

public class staircase2memoization
{
    //public static String[] staircase(int n,int )
    public static int staircase(int n,int [] arr,int [] qb) 
    {
      if(n==arr.length-1)
      {
          return 1;
      } 
      if(n>=arr.length)
      {
          return 0;
      }   
      if(qb[n]!=0)
      {
          return qb[n];
      }
      else
      {
      int temp=0;
      for(int i = 1 ; i <=arr[n] ;i++)
      {
         temp+=staircase(n+i, arr, qb);
      }
     qb[n]=temp;
       return qb[n];
      }
    }
    public static void main(String[] args) 
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int []arr={4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
        int []qb=new int[n+1];         
        int ans=staircase(0, arr,qb);
        System.out.println(ans);
        for(int i = 0 ;i<=25;i++)
        {
            System.out.print(qb[i]+" ");
        }
    }
}