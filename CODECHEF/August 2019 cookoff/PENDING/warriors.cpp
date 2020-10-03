#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base :: sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
     long long q, n;
     cin>>n>>q;
     vector<long long> input;
     long long mini[n];   
     long long ques[q];  
     for(int i = 0 ;i<n;i++)
     {
         long long temp;
         cin>>temp;
         input.push_back(temp);
     }
     sort(input.begin(),input.end()); 
     for(int i = 0 ;i<q;i++)
     {
         cin>>ques[i];
     }
     mini[0]=input[0];     
     for(int i =1;i<n;i++)
     {
      mini[i]=2*mini[i-1]+input[i];      
     }      
     for(int i = 0 ; i < q;i++)
     {
         long long ans=0;        
         if(ques[i]>2*mini[n-1])
         {
         cout<<n<<endl;
         continue;
         }
         long long res=pow(2,ans)*ques[ans]-mini[ans];
         while(res>0 && ans<n)
         {          
           ans++;               
           res=pow(2,ans)*ques[ans]-mini[ans];     
         }
         cout<<ans<<endl;
     }
  }
}