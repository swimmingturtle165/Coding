import java.util.*;

public class knighttour
{
    static int counter=0;
    public static void knighttraversal(int[][] board,int r,int c,int moves)
    {
        
     if(r<0 || c<0 ||r>=board.length ||c>=board.length||board[r][c]!=0)
     {       return ;
     }
     
     board[r][c]=moves;
     if(moves==board.length*board.length )
     {
         System.out.println("**************");
         System.out.println(++counter);
         System.out.println("**************");
       for(int i = 0 ;i < board.length;i++)
        {
            for(int j = 0; j < board.length;j++)
            {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
        System.out.println("**************");
       // System.out.println(counter);
        System.out.println("**************");
        board[r][c]=0;
        return;
     }
     knighttraversal(board, r+2, c-1, moves+1);
     knighttraversal(board, r+2, c+1, moves+1);
     knighttraversal(board, r-2, c-1, moves+1);
     knighttraversal(board, r-2, c+1, moves+1);
     knighttraversal(board, r+1, c-2, moves+1);
     knighttraversal(board, r+1, c+2, moves+1);
     knighttraversal(board, r-1, c-2, moves+1);
     knighttraversal(board, r-1, c+2, moves+1);
     board[r][c]=0; 
        
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int[][] board=new int[n][n];
        int r=scn.nextInt();
        int c=scn.nextInt();    
            knighttraversal(board, r, c, 1);
    }
   
}