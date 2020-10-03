import java.util.*;

public class snakesandladders 
{
   public  static class Edge
   {
       
       int nbr;
       int wt;
   }
   public static class SPair 
   {
       int curr;
       int stepsofar;
       String psf;
       
   }
   public static void ShortestRoute(int start,int dest) 
   {
        SPair first=new SPair();
        first.curr=start;
        first.stepsofar=0;
        first.psf="";
        PriorityQueue<SPair,ArrayList<SPair>,greater<SPair>> 

   }

   public static void mian(String[] args)
   {
       
   }    
}