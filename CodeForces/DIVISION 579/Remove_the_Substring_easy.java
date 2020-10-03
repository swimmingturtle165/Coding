import java.util.*;
public class Remove_the_Substring_easy
{
      public static void main(String[] args)
      {
       Scanner scn=new Scanner(System.in);
       String p=scn.next();
       String c=scn.next();
       int omax=0;
       int j=0;
       for(int i =0;i<p.length();i++)
       {
           int temp=0;
          while(i<p.length() && p.charAt(i)!= p.charAt(j))
          {
              temp++;
              i++;
          }
          i++;
          j++;
          if(j<c.length())
          {
              omax=Math.max(omax,temp);
          }
          else
          {
              omax=Math.max(omax,p.length()-i);
              break;
          }
       }
       System.out.println(omax);   
      }
}