import java.util.*;

import com.sun.javafx.scene.paint.GradientUtils.Point;
public class staircase2memoizationshortest
{
    static class pt
    {
        int point;
        String psf;
        pt(int point,String psf);
        {
            this.point=point;
            this.psf=psf;
        }
    }
    public static pt sp(int n,int[] arr) 
    {
      int steps=0;
      PriorityQueue<pt> p=new PriorityQueue<>(Comparator.reverseOrder());
      pt start=new pt(0,"");
      p.add(0,"");
      while(p.size()>0)
      {          
          pt rem=p.remove();
          if(rem==n)
          {
              return steps;
          }
          if(rem>=n)
          {
              continue;
          }
          steps++;
          for(int i = 1;i<=arr[rem];i++)
          {
              p.add(rem+i);
          }
      }
      return -1;
    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int n=scn.nextInt();
        int [] qb=new int[n+1];
        int [] arr={4,2,0,0,2,4,6,3,1,0,1,2,3,1,1};
        int ans=sp(n, arr);
        System.out.println(ans);
    }
}