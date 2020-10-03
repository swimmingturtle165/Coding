/*
Boxers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n boxers, the weight of the i-th boxer is ai. Each of them can change the weight by no more than 1 before the competition (the weight cannot become equal to zero, that is, it must remain positive). Weight is always an integer number.

It is necessary to choose the largest boxing team in terms of the number of people, that all the boxers' weights in the team are different (i.e. unique).

Write a program that for given current values ​ai will find the maximum possible number of boxers in a team.

It is possible that after some change the weight of some boxer is 150001 (but no more).

Input
The first line contains an integer n (1≤n≤150000) — the number of boxers. The next line contains n integers a1,a2,…,an, where ai (1≤ai≤150000) is the weight of the i-th boxer.

Output
Print a single integer — the maximum possible number of people in a team.

Examples
input
4
3 2 4 1
output
4
input
6
1 1 1 4 4 4
output
5
Note
In the first example, boxers should not change their weights — you can just make a team out of all of them.

In the second example, one boxer with a weight of 1 can be increased by one (get the weight of 2), one boxer with a weight of 4 can be reduced by one, and the other can be increased by one (resulting the boxers with a weight of 3 and 5, respectively). Thus, you can get a team consisting of boxers with weights of 5,4,3,2,1.


*/
import java.util.*;

public class boxers
{
  public static void main(String[] args) 
  {
      Scanner scn=new Scanner(System.in);
      int n=scn.nextInt();
      int maxi=0;
      int [] weights=new int[n]; 
      for(int i = 0 ;i<n;i++)
      {
        int temp=scn.nextInt();
        if(temp > 150000)
        {
          weights[i]=-1;
        }
        else
        weights[i]=temp;
       
        maxi=Math.max(maxi,weights[i]);
      }
      maxi=Math.min(150000,maxi);
      Arrays.sort(weights);
      boolean [] team=new boolean[maxi+2];
      int count=0;
      for(int i = 0 ; i < n ; i++)
      {     
                  
        if(weights[i]<=15000 && weights[i]>0)
        {
          if(weights[i]>1  &&  team[weights[i]-1]==false)
            {
              team[weights[i]-1]=true;
              count++;
            }  
       
          else if(team[weights[i]]==false)
          {
            team[weights[i]]=true;
            count++;
          }
           else if(team[weights[i]+1]==false)
            {
              team[weights[i]+1]=true;
              count++;
            }
        }  
            
      }
        
      System.out.println(count);
  }
}