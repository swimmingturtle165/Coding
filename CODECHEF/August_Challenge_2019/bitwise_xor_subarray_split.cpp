#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
      long n;
      cin>>n;
      long input[n];//input array
      long val[n]; //storing the bit value answer from starting to i-th index
      long ans=0;
      map<long int,vector<long>>m; //to store the occurence of a particular 
      vector<long> ind;//starting indexes of a distict xor values
      for(long i = 0;i<n;i++)
      {          
          cin>>input[i];
          if(i==0)
          {
              ans=input[i];
              val[i]=ans;
          }
          else
          {
              ans=ans^input[i];
              val[i]=ans;
          }
          if(m.count(val[i]==1)) //if this bit value has occured before
          {
              m[val[i]].push_back(i);
              // add this to the vector whhich stores the indexes of occurence 
              //of the particular bit
          }          
          else
          {
              //first occurence of a particular bit
              vector<long> temp;
              temp.push_back(i);
              m[val[i]]=temp;
              //add to hashmap
              ind.push_back(val[i]);
              //add  to the list storing the distinct bitvalues
          }
        //  cout<<val[i]<<" ";
    
      }
      //cout<<endl;
       long long count=0;
      for(long i = 0 ; i < ind.size();i++)
      {
          vector<long>temp=m[ind[i]];       
          if(temp.size()==1)
          {
              // the occurence of particular bit has been once only no possible subsets starting 
              //or ending here
              continue;
          }   
        
       
          
          {
              //modify karna hai
              // this basically adds the  number of subsets in between that 
              //have product of bits equal to zero 
              //for example if 3 comes at 1 5 7 9 11 13 indexes it stores
              // 1,5,7,9,11,13
              //xor product of subset b/w(1,5)  including only one either the starting or ending pt is 0;
              //possible combinations can be 
            //   5-1    ,7-1    ,9-1    ,11-1   .13-1
            //   7-5    ,9-5    ,11-5   ,13-5;
            //   9-7    ,11-7   ,13-7; 
            //   11-9   ,13-9;
            //   13-11;
            // we need to take sum of all these subsets
            //also note that only and only if their value is
             
                for(long j=1;j<temp.size();j++)
                {                
                        count+=(temp[j]-temp[j-1])>1?temp[j]-temp[j-1]:0;
                 }  
          }
          
         
      }
      cout<<count<<endl;
    }    
}