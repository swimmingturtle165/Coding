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

// logic
/*
 Sort the array and multiply the first 2 with last 2 ND SON ON TILL  we reach the middle 
 check if 2 being taken together from front and behind are the same or not
 
*/

import java.util.*;

public class  Equal_Rectangles
{
   public static void main(String[] args)
   {
    Scanner scn=new Scanner(System.in);
    int t=scn.nextInt();
    for(int k = 0 ; k < t;k++)
    {
        int n=scn.nextInt();
        int [] arr=new int[4*n];
        
        for(int i= 0 ;i<4*n;i++)
        {
            arr[i]=scn.nextInt();
           
        }
        Arrays.sort(arr);
        boolean ans=true;
        int area=arr[0]*arr[arr.length-1];
        for(int i = 0;i<arr.length/2;i=i+2)
        {
            int temp=arr[i]*arr[arr.length-i-1];
            if(temp!=area || arr[i]!=arr[i+1] ||arr[arr.length-i-1]!=arr[arr.length-i-2])
            {
                ans=false;
                break;
            }
        }
        if(ans==true)
        {
            System.out.println("YES");
        }
        else
        {
            System.out.println("NO");
        }
        
   
     }
    
   }    
}