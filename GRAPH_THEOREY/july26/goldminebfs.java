import java.util.*;

public class goldminebfs
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
              return other.cost-this.cost;
          }
    }
    public static void solve(int [][] arr)
    {
        ArrayList<Integer> ans=new ArrayList<>();
        ArrayList<String>  path=new ArrayList<>();
        
        for(int i =0;i<arr.length;i++)
        {
            PriorityQueue<point> q=new PriorityQueue<>();
            point start=new point(i,0,arr[i][0],"");
            q.add(start);
            int maxi=0;
            String pa="";
            while(q.size()!=0)
            {
                point rem=q.remove();
                if(rem.y==arr[0].length-1)
                {
                  if(maxi <= rem.cost)
                  {
                   maxi=rem.cost;
                   pa=rem.psf+"{"+arr[rem.x][rem.y]+"} ";
                  }
                  continue;
                }
                if(rem.x>0)
                { 
                    point temp=new point(rem.x-1,rem.y+1,rem.cost+arr[rem.x-1][rem.y+1],rem.psf+"{"+rem.x+","+rem.y+"} "); 
                    q.add(temp);
                }
                point temp2=new point(rem.x ,rem.y+1,rem.cost+arr[rem.x][rem.y+1],rem.psf+"{"+rem.x+","+rem.y+"} ");
                q.add(temp2);
                if(rem.x<arr.length-1)
                {
                    point temp=new point(rem.x+1,rem.y+1,rem.cost+arr[rem.x+1][rem.y+1],rem.psf+"{"+rem.x+","+rem.y+"} "); 
                    q.add(temp); 
                }

            } 
            ans.add(maxi);
            path.add(pa);      
        }
        for(int i = 0 ;i<ans.size();i++)
        {
            System.out.println(path.get(i) +" @ "+ans.get(i));
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