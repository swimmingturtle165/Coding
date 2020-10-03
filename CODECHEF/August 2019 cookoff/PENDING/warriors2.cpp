#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
   long t;
   //scanf("%ld",t);
   cin>>t;
   while(t--)
   {
     long long q, n;
     map<long long int, long long int> m;
     m.clear();

    
    //scanf("%lld%lld", &n, &q);
    cin>>n>>q; // input for no. of enemies and queries
     vector<long long int> input;// vector where we store the inputs
     vector<long long int> ques_s;// vector where sorted queries are stored
     
     long long ans[q]; // Stores answer for each query
     long long ques[q]; // Stores queries in original order
    //  long  long difference[q]; // stores the difference between original and sorted queries : 1 2 1  -- 1 1 2  --    0 1 -1 
     
     for(long long i = 0 ; i < n;i++)
     {
         long long int temp;
       // scanf("%lld", &temp);
         cin>>temp;
         input.push_back(temp); // taking input for enemy powers
     }
     
     sort(input.begin(),input.end()); // sorting the enemy powers
     
     for(long long i = 0 ; i < q;i++) // taking input for each query
     {      
         //scanf("%lld",&ques[i]);
         
         cin>>ques[i];
         ans[i]= 0;
         
         ques_s.push_back(ques[i]);
     }
     
     sort(ques_s.begin(),ques_s.end());  // sorting the queries and storing in new vector
     
     
     
     long long start=0; // current query's power
     
     long long prevind=0; // index before which the previous query could kill(not inclusive)
     
     long long prevstart=0;   // power of previous query
     
     long long res =0-input[0];  // Value of complete expression 
   
     for(long long j = 0 ; j < q;j++) // solving each query 
     {             
       start=ques_s[j];
        // storing current power in start
       if(m.count(start)==1)
       {
         continue;
       }
       long long dif=start-prevstart; // difference of power between current and previous query
        res=pow(2,prevind)*dif+res; // updating for current expression
       
        while(res>0 && prevind<n)
        {          
          res=2*res-input[prevind+1];
          prevind++;
          if(res<=0 )
          {           
            break;
          }
         }
                  //  difference[i]=ques[i]-ques_s[i];
           m[ques_s[j]]=prevind;
           prevstart=start; 
           //cout<<prevind<<" ";
          //  cout<<index<<" ";        
               
     }     
    // cout<<endl;
     for(int g=0 ; g<q;g++)
     {       
         cout<<m[ques[g]]<<endl;
     }
  }
}
