import java.util.*;

public class staircase2tabulationsir
{
    public static int countPaths(int[] arr)
    {
        //strg=storage
      int [] strg=new int[arr.length];
      strg[arr.length-1]=1;
      for(int i =arr.length-2;i>=0;i--)
      {
          for(int j =i+1;j<=arr[i]+i && j<arr.length;j++)
          {
              strg[i]+=strg[j];
          }         
      }
      for(int i = 0 ; i < strg.length;i++)
      {
        System.out.print(strg[i]+" ");
      }
      return strg[0];    
    }
    public static int minSteps(int [] arr)
    {
       int [] strg=new int[arr.length];
       strg[arr.length-1]=0;
       for(int i = arr.length-2;i>=0; i--)
       {
         if(arr[i]==0)
         {
           strg[i]=arr.length;
           continue;
         }
            int min=arr.length;         
         for(int j=i+1;j<=i+arr[i] && j<arr.length;j++)
          {
              if(min > strg[j] )
              {
                min=strg[j];
              }
          }
          strg[i]=min+1;                   
         
       }
      //  for(int i = 0 ; i < strg.length;i++)
      //  {
      //    System.out.print(strg[i]+" ");
      //  }
      //  System.out.println();
       return strg[0];
    }
    public static void main(String[] args)
    {

        //Scanner scn=new Scanner(System.in);
        //int n=scn.nextInt();
        int []arr={4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
        //int []qb=new int[n+1];         
        int ans=minSteps(arr);
        System.out.println(ans);
    }
}