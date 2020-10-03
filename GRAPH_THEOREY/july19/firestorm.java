import java.util.*;

public class firestorm
{
    public static class point
    {
        int x;
        int y;
        int t;
    }
    public static void solve(int[][] board,int time)
    {
        ArrayDeque<point> q=new ArrayDeque<>();
        for(int i= 0 ;i< board.length;i++)
        {
            for(int j = 0 ; j < board[0].length;j++)
            {
                if(board[i][j]==1)
                {
                    //Adding all pts where there is currently fire
                    point t0=new point();
                    t0.x=i;
                    t0.y=j;
                    t0.t=1;
                    q.addLast(t0);
                }
            }
        }
        while(q.size()>0)
        {
          point rem=q.getFirst();
          q.removeFirst();
          if(board[rem.x][rem.y]<0)
          {
              continue;
          }
          if(rem.t==time+2)
          {
              break;
          }
          board[rem.x][rem.y]=-rem.t;
          if(rem.x>0 && board[rem.x-1][rem.y]==0)
          {
            point temp=new point();
            temp.x=rem.x-1;
            temp.y=rem.y;
            temp.t=rem.t+1;
            q.addLast(temp);
          }
          if(rem.y>0 && board[rem.x][rem.y-1]==0)
          {
            point temp=new point();
            temp.x=rem.x;
            temp.y=rem.y-1;
            temp.t=rem.t+1;
            q.addLast(temp);
          }
          if(rem.x+1<board.length&& board[rem.x+1][rem.y]==0)
          {
            point temp=new point();
            temp.x=rem.x+1;
            temp.y=rem.y;
            temp.t=rem.t+1;
            q.addLast(temp);
          }
          if(rem.y+1<board[0].length && board[rem.x][rem.y+1]==0)
          {
            point temp=new point();
            temp.x=rem.x;
            temp.y=rem.y+1;
            temp.t=rem.t+1;
            q.addLast(temp);
          }
        }
    }
    public static void main(String[] args)
    {
     int[][] board={
         {1,2,0,2,0,0,0},
         {0,2,0,2,0,1,0},
         {0,0,0,2,0,0,0},
         {2,2,2,2,2,2,0},
         {0,2,1,0,0,0,0},
         {0,2,0,0,0,0,0},
         {0,2,0,0,0,0,0}
     };   
     solve(board,3); 
     for(int i = 0 ; i < board.length;i++)
     {
         for(int j = 0 ; j < board[0].length;j++)
         {
             System.out.print(board[i][j]+" ");
         }
         System.out.println();
     }
    }
}