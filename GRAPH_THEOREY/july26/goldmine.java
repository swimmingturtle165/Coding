import java.util.*;

public class goldmine
{
    public static void solve(int[][]maximum_gold,int [][] arr)
    {
        
        for(int j =arr[0].length-1;j>=0;j--)
        {
            for(int i = arr.length-1;i>=0;i--)
            {
               
                // if(i==arr.length-1 && j==arr[0].length-1)
                // {
                //    maximum_gold[i][j]=arr[i][j];
                // }
                if(j==arr[0].length-1)
                {
                  maximum_gold[i][j]=arr[i][j];
                }
                else if(i==arr.length-1)
                {
                   maximum_gold[i][j]=arr[i][j]+Math.max(maximum_gold[i-1][j+1],maximum_gold[i][j+1]);
                }
                else if(i==0)
                {                  
                  maximum_gold[i][j]=arr[i][j]+Math.max(maximum_gold[i+1][j+1],maximum_gold[i][j+1]);
                }
                else
                {
                    maximum_gold[i][j]=arr[i][j]+Math.max(maximum_gold[i+1][j+1], 
                    Math.max( maximum_gold[i][j+1],maximum_gold[i-1][j+1]));
                }               
                
        }
              
    }
  }

    public static  void printpaths(int r,int c, int[][]maximum_gold,int[][]arr ,String asf)
     {
         int i=r;
         int j=c;
       if(c==maximum_gold[0].length-1)
       {
           System.out.println(asf+arr[i][j]);
           return;
       }
       else if(i>0 && i<arr.length-1)
       {
           if(maximum_gold[i][j+1]<maximum_gold[i+1][j+1])
           {
               if(maximum_gold[i-1][j+1]<maximum_gold[i+1][j+1])
               {
                 printpaths(r+1, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
               }
               else
               {
                printpaths(r-1, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
               }
           }
           else
           {
               if(maximum_gold[i][j+1]>maximum_gold[i-1][j+1])
               {
                   printpaths(r, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
               }
               else
               {
                printpaths(r-1, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
               }
           }

       }
       else if(i==arr.length-1)
       {
           if(maximum_gold[i-1][j+1]>maximum_gold[i][j+1])
           {
               printpaths(r-1, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
           }
           else
           {
               printpaths(r, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
           }

       }
       else if(i==0)
       {
        if(maximum_gold[i+1][j+1]>maximum_gold[i][j+1])
        {
            printpaths(r+1, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
        }
        else
        {
            printpaths(r, c+1, maximum_gold, arr, asf+arr[i][j]+" => ");
        }
       }   
     }
    
    public static void main(String[] args)
    {
        int [][] arr={
            {1,5,1,0,3},
            {1,4,0,2,3},
            {4,0,1,3,2},
            {2,4,0,4,1},
            {1,2,3,2,0},
            
        };
        int [][]maximum_gold=new int[arr.length][arr[0].length];
       
        solve(maximum_gold, arr);
        int maxi=0;
        int r=0;
        for(int i = 0 ; i < maximum_gold.length;i++)
        {
           if(maxi<maximum_gold[i][0])
           {
               maxi=maximum_gold[i][0];
               r=i;
           }
        }        
       System.out.println(maxi);
       printpaths(r,0,maximum_gold,arr,"");
    }

 
}