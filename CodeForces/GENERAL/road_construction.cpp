#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long n,m;
    cin>>n>>m;
    vector<long> a;
    vector<long> b;
    map<long,int> stored;
    int turn=0;
    
   
    for(long i = 0 ; i < m ;i++)
    {
      long temp1,temp2;
      cin>>temp1>>temp2;
        if(stored.count(temp1)>0 &&stored.count(temp2)==0)
        {
           if(stored[temp1]==1)
           {
               a.push_back(temp2);
               stored[temp2]=1;
           }
           else if(stored[temp1]==2)
           {
               b.push_back(temp2);
               stored[temp2]=2;
           }
           
        }
        else if(stored.count(temp2)>0 && stored.count(temp1)==0)
        {
            if(stored[temp2]==1)
           {
               a.push_back(temp1);
               stored[temp1]=1;
           }
           else if(stored[temp2]==2)
           {
               b.push_back(temp1);
               stored[temp1]=2;
           }
        }
        else
        {
           if(turn%2==0)
                {
                  a.push_back(temp1);
                  a.push_back(temp2);
                  stored[temp1]=1;
                  stored[temp2]=1;
                }
                else
                {
                  b.push_back(temp1);
                  b.push_back(temp2);
                  stored[temp1]=2;
                  stored[temp2]=2;
                }
                
        }
        turn=a.size()>b.size()?1:0;    
    }
   
    
        if(a.size()+b.size()==n)
        {
           vector<long> s1;
           vector<long> s2;
           for(int i = 2 ; i < a.size();i++)
           {
               s1.push_back(a[i]);
           }
            for(int i = 0 ; i < b.size();i++)
           {
               s1.push_back(b[i]);
           }
           s2.push_back(a[0]);
           s2.push_back(a[1]);
            sort(s1.begin(),s1.end());
           sort(s2.begin(),s2.end());
           cout<<s1.size()*s2.size()<<endl;
            for(long i = 0 ; i <s1.size();i++)
            {
                for(long j = 0 ; j <s2.size();j++)
                {
                    cout<<s1[i]<<" "<<s2[j]<<endl;
                }
            }

        }
        else
        {
       
           bool flag=true;
           long val=0;
           for(long i = 1 ; i <= n ;i++)
           {
               if(stored.count(i)==1)
               {
                   continue;
               }
               else if(flag==true)
               {
                   flag=false;
                   val=i;
                   break;
               }
                       
           }
              cout<<n-1<<endl;
             for(long i = 1 ; i <=n;i++)
             {
                 if(i!=val)
                 {
                     cout<< val<<" "<<i<<endl;
                 }
             }
         
        
        }
        
}
        
    
  