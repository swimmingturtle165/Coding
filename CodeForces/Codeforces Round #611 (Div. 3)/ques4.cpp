#include<bits/stdc++.h>
using namespace std;

long long evaluator(long long a,long long b)
{
    if(abs(a-b)%2==0)
    {
        long long n=abs(a-b)/2;
        return n*n;
    }
    else
    {
        long long n=abs(a-b)/2;
        return n*n+n;
    }
    
}


int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,m,mini=INT_MAX,maxi=0,sum=0;
    cin>>n>>m;
    map<long long,long long> mp;
    vector<long long> pos_trees,pos_person;
    for(int i = 0 ; i <n;i++)
    {
        long long temp;
        cin>>temp;
        mp[temp]=i;
        pos_trees.push_back(temp);
        
    }
    sort(pos_trees.begin(),pos_trees.end());
    for(int i = 1 ; i <n;i++)
    {
        
            mini=min(pos_trees[i]-pos_trees[i-1]-1,mini);
            maxi=min(pos_trees[i]-pos_trees[i-1]-1,maxi);
            sum+=pos_trees[i]-pos_trees[i-1]-1;
        
    }


        if(sum+2*maxi>=m)
        {
            map<long long ,bool> visited;
            queue<pair<long long ,int>> q;
            long long left=m;
            for(long long i = 0 ; i <n;i++) 
            {
                pair<long long,int> temp={pos_trees,0};
                 q.push(temp);
            }
            while(left!=0)
            {
                pair<long long,bool> temp=q.front();
                

            }

        }
        else
        {
            long long diff=m-sum;
            long long left_end=diff/2 +diff%2;
            long long right_end=diff/2;
            long long left_end_start=pos_trees[0]-left_end;
            long long right_end_end=pos_trees[n-1]+right_end;
            long long calculation=0;
            calculation+=(((left_end)*(left_end+1)/2))+((right_end)*(right_end+1))/2;
            for(int i = 0 ; i <n-1;i++)
            {
                calculation+=evaluator(pos_trees[i],pos_trees[i+1]);
            }
            cout<<calculation<<endl;
            int j = 0 ;
            for(long long i =left_end_start;i<=right_end_end;i++)
            {
                if((j!=n && i!=pos_trees[j])||j==n)
                {
                    cout<<i<<" ";
                }
                else
                {
                    
                    j++;
                }
                
            }
            
        }
        

    
}
