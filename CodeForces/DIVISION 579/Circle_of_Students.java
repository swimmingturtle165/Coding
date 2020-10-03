
/*
Circle of Students
time limit per test 2 seconds
memory limit per test 256 megabytes
inputstandard input
outputstandard output


There are n students standing in a circle in some order. The index of the i-th student is pi. It is guaranteed that all indices of students are distinct integers from 1 to n (i. e. they form a permutation).

Students want to start a round dance. A clockwise round dance can be started if the student 2 comes right after the student 1 in clockwise order (there are no students between them), the student 3 comes right after the student 2 in clockwise order, and so on, and the student n comes right after the student n−1 in clockwise order. A counterclockwise round dance is almost the same thing — the only difference is that the student i should be right after the student i−1 in counterclockwise order (this condition should be met for every i from 2 to n).

For example, if the indices of students listed in clockwise order are [2,3,4,5,1], then they can start a clockwise round dance. If the students have indices [3,2,1,4] in clockwise order, then they can start a counterclockwise round dance.

Your task is to determine whether it is possible to start a round dance. Note that the students cannot change their positions before starting the dance; they cannot swap or leave the circle, and no other student can enter the circle.

You have to answer q independent queries.

Input
The first line of the input contains one integer q (1≤q≤200) — the number of queries. Then q queries follow.

The first line of the query contains one integer n (1≤n≤200) — the number of students.

The second line of the query contains a permutation of indices p1,p2,…,pn (1≤pi≤n), where pi is the index of the i-th student (in clockwise order). It is guaranteed that all pi are distinct integers from 1 to n (i. e. they form a permutation).

Output
For each query, print the answer on it. If a round dance can be started with the given order of students, print "YES". Otherwise print "NO".

Example
input
5
4
1 2 3 4
3
1 3 2
5
1 2 3 5 4
1
1
5
3 2 1 5 4
output
YES
YES
NO
YES
YES
 */
/*
logic

iterate through the array finding the next

just if we are in the end or beginning check the other ends too

*/

import java.util.*;

public class Circle_of_Students
{
    public static void main(String[] args)
    {
        Scanner scn=new Scanner(System.in);
        int t=scn.nextInt();
        for(int k = 0 ; k < t;k++)
        {
            int n=scn.nextInt();
            int [] arr=new int[n];
            int ind=0;
            for(int i= 0 ;i<n;i++)
            {
                arr[i]=scn.nextInt();
                if(arr[i]==1)
                {
                    ind=i;
                }
            }
            int curr=2;
            while(curr<=n)
            {
                if(ind==0)
                {
                  if(ind+1 <n&& arr[ind+1]!=curr &&arr[n-1]!=curr)
                  {
                      break;
                  }
                  else
                  {
                    if(arr[ind+1]!=curr)
                    {
                        ind=n-1;
                    }
                    else
                    {
                        ind++;
                    }
                    
                  }
                }
                else if(ind==n-1)
                {
                    if(arr[ind-1]!=curr && arr[0]!=curr)
                    {
                        break;
                    }
                    else
                    {
                        if(arr[0]!=curr)
                       ind--;

                       else
                       ind=0;
                    }
                }
                else
                {
                    if(arr[ind-1]==curr)
                    {
                     ind--;
                    }
                    else if(arr[ind+1]==curr)
                    {
                      ind++;
                    }
                    else
                    {
                        break;
                    }

                }
                curr++;
            }
            //System.out.println("*"+curr);
            if(curr==n+1)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
        scn.close(); 
        
    }
}