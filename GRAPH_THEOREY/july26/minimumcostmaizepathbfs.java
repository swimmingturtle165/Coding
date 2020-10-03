import java.util.*;

public class minimumcostmaizepathbfs
{
    public static class point implements Comparable<point>
    {
          int x;
          int y;
          int cost;
          String psf;
          point(int n1,int n2,int n3,String psf)
          {
              x=n1;
              y=n2;
              cost=n3;
              this.psf=psf;
          }
           public int compareTo (point other)
          {
              return this.cost-other.cost;
          }
    }
    public static void solve(int [][] arr)
    {
      point curr=new point(0,0,arr[0][0],"");
      PriorityQueue<point> q=new PriorityQueue<>();
      q.add(curr);
      int val=0;
      while(q.size()>0)
      {
          point rem=q.remove();
          if(rem.x==arr.length-1 && rem.y==arr[0].length-1)
          {
              if(val==0 || rem.cost==val)
              {             
              System.out.println(rem.psf +"{"+rem.x+","+rem.y+"} "+" @"+rem.cost);
              val=rem.cost;
              }
              if(rem.cost>val)
              {
                  return;
              }
              continue;
          }
          if(rem.x<arr.length-1)
          {
            point temp=new point(rem.x+1,rem.y,rem.cost+arr[rem.x+1][rem.y],rem.psf+"{"+rem.x+","+rem.y+"} ");
            q.add(temp);
          }
          if(rem.y<arr[0].length-1)
          {
            point temp=new point(rem.x,rem.y+1,rem.cost+arr[rem.x][rem.y+1],rem.psf+"{"+rem.x+","+rem.y+"} ");
            q.add(temp);
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
        
        solve(arr);
        
    }
}