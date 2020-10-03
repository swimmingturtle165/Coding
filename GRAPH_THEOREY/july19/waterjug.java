import java.util.*;

public class waterjug
{
    static int count=0;
    public static class jug
    {
        int j1;
        int j2;
        int level;
        String asf;
    }
    public static void solve(int n1,int n2,int target)
    {
        
      jug start=new jug();
      start.j1=0;
      start.j2=0;
      start.level=0;
      start.asf="";

      ArrayDeque<jug> q=new ArrayDeque<>();
      q.addLast(start);
      boolean [][] check=new boolean [n1+1][n2+1];
      //check[0][0]=true;
      while(q.size()>0)
      {
          //System.out.print(q.size() +" -> ");
        jug curr=q.getFirst();
        q.removeFirst();
        //  System.out.print(++count +" "+curr.asf);

       // System.out.println(curr.level);
        //System.out.print(curr.j1+" "+curr.j2);//+" " +curr.level+" "+curr.asf+" "+q.size());
        if(curr.j1==target)
        {
           System.out.println(curr.asf);
           System.out.println(target + "litres in " +"jar j1");
           
            return;
           
        }
        if( curr.j2==target)
        {
           System.out.println(curr.asf);
           System.out.println(target + "  litres in " +"jar 2");
           
            return;
           
        }
        check[curr.j1][curr.j2]=true;
        //empty-3
        if(curr.j1>0)
        {
           jug upd1=new jug();
           upd1.j1=0;
           upd1.j2=curr.j2;
           upd1.level=curr.level+1;
           upd1.asf=curr.asf+"empty"+n1+" ";
           if(check[upd1.j1][upd1.j2]==false)
           {
            q.addLast(upd1);              
           }
        }
        //empty-5
        if(curr.j2>0)
        {
            jug upd2=new jug();
            upd2.j1=curr.j1;
            upd2.j2=0;
            upd2.level=curr.level+1;
            upd2.asf=curr.asf+"empty"+n2+" ";
            if(check[upd2.j1][upd2.j2]==false)
            {
             q.addLast(upd2);              
            }
        }
        //fill 3
        if(curr.j1<n1)
        {           
            jug upd3=new jug();
            upd3.j1=n1;
            upd3.j2=curr.j2;
            upd3.level=curr.level+1;
            upd3.asf=curr.asf+"fill "+n1+" ";
            if(check[upd3.j1][upd3.j2]==false)
            {
             q.addLast(upd3);              
                      
            }
        }
        //fill 5
        if(curr.j2<n2)
        {
            jug upd4=new jug();
            upd4.j1=curr.j1;
            upd4.j2=n2;
            upd4.level=curr.level+1;
            upd4.asf=curr.asf+"fill "+n2+" ";
            if(check[upd4.j1][upd4.j2]==false)
            {
             q.addLast(upd4);              
            }
        }
        //move 3 to 5
        if(curr.j2<n2 && curr.j1>0)
        {
            jug upd5=new jug(); 
            int space=n2-curr.j2;
            if(curr.j1 >space)
            {
              upd5.j1=curr.j1-space;
              upd5.j2=n2;
            }
            else
            {
                upd5.j1=0;
                upd5.j2=curr.j1+curr.j2;
            }
            upd5.level=curr.level+1;
            upd5.asf=curr.asf+"move "+n1+" to "+n2+" ";
            if(check[upd5.j1][upd5.j2]==false)
           {
            q.addLast(upd5);              
           }

        }
        //move 5 to 3
        if(curr.j1<n1 && curr.j2>0)
        {
            jug  upd6=new jug(); 
            int space=n1-curr.j1;
            if(curr.j2 > space)
            {
               upd6.j1=n1;
               upd6.j2=curr.j2-space;
            }
            else
            {
                 upd6.j1=curr.j1+curr.j2;
                 upd6.j2=0;
            }
             upd6.level=curr.level+1;
             upd6.asf=curr.asf+"move "+n2+" to "+n1+" ";
            if(check[upd6.j1][upd6.j2]==false)
            {
             q.addLast( upd6);              
            }

        }
        //System.out.println("!!! "+curr.j1+" "+curr.j2+" " +curr.level+" "+curr.asf+" "+q.size());
        //System.out.println(q.size() +" ## ");

      }
      if(q.size()==0)
      {
          System.out.println("Not possible");
      }

    }
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        // int n1=scn.nextInt();
        // int n2=scn.nextInt();
        // int target=scn.nextInt();
        solve(3,5,4);
        scn.close();
    }

}