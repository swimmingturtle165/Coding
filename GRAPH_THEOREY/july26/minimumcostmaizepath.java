import java.util.*;

public class minimumcostmaizepath
{
    public static int solve(int[][] minimum_moves,int [][] arr)
    {
        for(int i = arr.length-1;i>=0;i--)
        {
            for(int j =arr[0].length-1;j>=0;j--)
            {
                if(i==arr.length-1 && j==arr[0].length-1)
                {
                    minimum_moves[i][j]=arr[i][j];
                }
                else if(i==arr.length-1)
                {
                    minimum_moves[i][j]=arr[i][j]+minimum_moves[i][j+1];
                }
                else if(j==arr[0].length-1)
                {
                   minimum_moves[i][j]=minimum_moves[i+1][j]+arr[i][j];
                }
                else
                {
                    minimum_moves[i][j]=arr[i][j]+Math.min(minimum_moves[i][j+1],minimum_moves[i+1][j]);
                    
                }
            }
        }
        return minimum_moves[0][0];
          
    }
    public static void main(String[] args)
    {
        int [][] arr={
            {2,7,3,8,0,3,7},
            {4,0,1,2,4,3,4},
            {3,8,5,9,0,8,1},
            {1,6,0,4,5,5,2},
            {6,2,9,5,7,0,6},
            {0,8,7,9,6,3,0},
            {1,3,5,0,5,1,0},
        };
        int [][] minimum_moves=new int[arr.length][arr[0].length];
        
        // for(int i = 0 ; i < arr.length;i++)
        // {
        //     minimum_moves[i][arr[0].length-1]=arr[i][arr[0].length-1];
        // }
        int ans=solve( minimum_moves, arr);
        System.out.println(ans);
    }
}