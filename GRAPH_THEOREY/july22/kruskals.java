import java.util.*;

public class kruskals 
{
    public static class Edge
    {
      int nbr;
      int wt;
      Edge(int n1,int n2)
      {
          this.nbr=n1;
          this.wt=n2;
      }
    }
    //static ArrayList<ArrayList<Edge
    public static class KEdge implements Comparable<KEdge> {
      int v1;
      int v2;
      int wt;
      KEdge(int n1,int n2,int n3)
      {
          this.v1=n1;
          this.v2=n2;
          this.wt=n3;
      }   
      //implementing comparable
      //this < return -ve
      //this = return 0
      //this > return +ve
      public int compareTo(KEdge other)
      {
          return this.wt-other.wt;
      }
    }
    static ArrayList<ArrayList<Edge>> graph=new ArrayList<>();

    public static void addedge(ArrayList<ArrayList<Edge>> g,int n1,int n2,int wt)
    {
        Edge e1=new Edge(n2, wt);
        g.get(n1).add(e1);
        
        Edge e2=new Edge(n1, wt);
        g.get(n2).add(e2);

    }
    public static void display(ArrayList<ArrayList<Edge>> g)
    {
      for(int i = 0 ; i < g.size();i++)
      {
          System.out.print(i+" => ");
          for(int j = 0 ; j < g.get(i).size();j++)
          {
            System.out.print("["+g.get(i).get(j).nbr+" , "+g.get(i).get(j).wt+"] ");
          }
          System.out.println();
      }    
    }
    
    static void merge(int n1,int n2, int[] ra,int[] par)
    {
        if(ra[n1]==ra[n2])
        {
            par[n1]=n2;
            ra[n1]++;
        }
        else if(ra[n1]>ra[n2])
        {
            par[n2]=n1;
        } 
        else
        {
            par[n1]=n2;
        }
    }
    
    static int find(int[] par,int n)
    {
      if(par[n]==n)
      return n;

      return find(par,par[n]);


    }
    public static void kruskal (ArrayList< ArrayList<Edge> > g) 
    {
        ArrayList<ArrayList<Edge>> mst=new ArrayList<>();
        PriorityQueue<KEdge> pq=new PriorityQueue<>();
        
        int[] par=new int[g.size()];
        int[] ra=new int[g.size()];
        
        for(int i = 0 ; i < g.size();i++)
        {
            par[i]=i;
            ra[i]=1;
            mst.add(new ArrayList<Edge>());
        }
        
        for(int i = 0 ; i < g.size();i++)
        {
            for(int j = 0 ; j < g.get(i).size();j++)
            {
                Edge ne=g.get(i).get(j);
                if(i<ne.nbr)//so that we dont add any edge twice 
                {
                    KEdge ke=new KEdge(i,ne.nbr,ne.wt);
                    pq.add(ke);
                }
            }
        }
        
        while(pq.size()>0)
        {
            KEdge ke=pq.remove();
            int v1=ke.v1;
            int v2=ke.v2;
            //finding king leader of vertex v1
            int v1sl=find(par,v1);
            //finding king leader of vertex v2
            int v2s2=find(par,v2);
             //checking if they belong to the same kingdom if they don't then merge them together
            if(v1sl!=v2s2)
            {
                addedge(mst, v1, v2,ke.wt);
                merge(v1sl,v2s2,ra,par);
            }
        }
        display(mst);
    }
    public static void main(String[] args)
    {
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
       // graph.add(new ArrayList<Edge>());
        addedge(graph,0,1,20);
        addedge(graph,1,2,10);
        addedge(graph,2,3,20);
        addedge(graph,0,3,40);
        addedge(graph,2,5,5);
        addedge(graph,3,4,2);
        addedge(graph,4,5,3);
        addedge(graph,5,6,3);
        addedge(graph,4,6,8);
         display(graph);
        System.out.println();
        kruskal(graph);

        
    }
}