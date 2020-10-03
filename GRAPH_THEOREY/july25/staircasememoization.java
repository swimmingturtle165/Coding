import java.util.*;

public class staircasememoization
{
    // public static void staircaseways(int n,ArrayList<ArrayList<String>> qb,int start,String asf)
    // {
    //     if(n==0)
    //     {
    //      qb.get(start).add(asf);
    //      //System.out.println(asf+" 0");
    //      return;
    //     }
    //     if(n<0)
    //     {
    //        return;
    //     }
    //     if(qb.get(n).size()!=0)
    //     {
    //         for(int i = 0 ; i < qb.get(n).size();i++)
    //         {
    //           String temp=asf+"** n-"+n+"** start-"+start+"**"+qb.get(n).get(i);
    //           System.out.println("**"+temp+"**");
    //           qb.get(start).add(temp);
    //         }
    //     }
    //     else
    //     {
    //         staircaseways(n-1, qb, n,asf+" "+n);
    //         staircaseways(n-2, qb, n,asf+" "+n);
    //         staircaseways(n-3, qb, n,asf+" "+n);
    //     }
        
    // }
    public static int staircase(int n,int [] arr) 
    {
      if(n==0)
      {
         // arr[0]=1;
          return 1;
      } 
      if(n<0)
      {
          return 0;
      }   
      if(arr[n]!=0)
      {
          return arr[n];
      }
      else
      {
      arr[n]= staircase(n-1, arr)+staircase(n-2, arr)+staircase(n-3, arr);
    //   for(int i = 0 ; i <= n ;i++)
    //   {
    //       System.out.print(arr[i] + " ");
    //   }
      System.out.println();
       return arr[n];
      }
    }
    public static void main(String[] args) 
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int [] arr=new int[n+1]; 
       // ArrayList<ArrayList<String>> ans=new ArrayList<>();
        // for(int i = 0 ; i <=n;i++)
        // {
        //     ans.add(new ArrayList<String>());
        // }
        // staircaseways(n,ans,n,"");

        // for(int i = 0 ; i < ans.size();i++)
        // {
        //     System.out.println(i+"=>" );
        //     for(int j = 0 ; j<ans.get(i).size();j++)
        //     {
        //         System.out.println(ans.get(i).get(j));
        //     }
        // }
        // scn.close();
        int ans=staircase(n, arr);
        System.out.println(ans);
    }
}