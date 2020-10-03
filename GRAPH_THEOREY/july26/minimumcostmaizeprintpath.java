import java.util.*;

public class minimumcostmaizeprintpath
{
    public static void solve(int[][] minimum_moves,int [][] arr)
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
              
    }
    public static  void printpaths(int r,int c,int[][] minimum_moves, String asf)
    {
        if(r==minimum_moves.length-1  && c==minimum_moves[0].length-1)
        {
            System.out.println(asf);
            return;
        }
        if(r <minimum_moves.length-1 && c<minimum_moves[0].length-1)
        {
            if(minimum_moves[r+1][c]==minimum_moves[r][c+1])
            {
                printpaths(r+1, c, minimum_moves, asf+" D ");
                printpaths(r, c+1, minimum_moves, asf+" R ");
            }
             if(minimum_moves[r+1][c]>minimum_moves[r][c+1])
            {               
                printpaths(r, c+1, minimum_moves, asf+" R ");
            }
             if(minimum_moves[r+1][c]<minimum_moves[r][c+1])
            {
                printpaths(r+1, c, minimum_moves, asf+" D ");
            }
        }
       else if(r==minimum_moves.length-1)
        {
            printpaths(r, c+1, minimum_moves, asf+" R ");
        }
        else 
        {
            printpaths(r+1, c, minimum_moves, asf+" D ");
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
        int [][] minimum_moves=new int[arr.length][arr[0].length];
        solve( minimum_moves, arr);
        for(int i = 0 ;i <minimum_moves.length;i++)
        {
            for(int j = 0 ;j<minimum_moves[0].length;j++)
            {
                System.out.print(minimum_moves[i][j]+ " ");
            }
            System.out.println();
        }
       
        
        
        // for(int i = 0 ; i < arr.length;i++)
        // {
        //     minimum_moves[i][arr[0].length-1]=arr[i][arr[0].length-1];
        // }
        
        printpaths(0,0, minimum_moves,"");
        
    }
}