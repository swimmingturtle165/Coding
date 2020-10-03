#include <bits/stdc++.h>
using namespace std;

long ans(vector<int>& procedure,int higher,int lower,long higher_count,long lower_count )
{
    
    vector<long> right_movement,left_movement;
    long higher_eaten=0,lower_eaten=0,left_sz=0,right_sz=0;
    long mini=procedure.size(),dif=higher_count-lower_count;

    for(int i = (procedure.size()/2);i<procedure.size();i++)
    {
        if(procedure[i]==lower)
        {
            lower_eaten++;
        }
        else
        {
            higher_eaten++;
        }
        right_movement.push_back(0-lower_eaten+higher_eaten);
        if(dif==right_movement[right_sz])
        {
            mini=min(mini,right_sz+1);
        }
        right_sz++;
        
    }
    higher_eaten=0,lower_eaten=0;
    for(int i = (procedure.size()/2)-1;i>=0;i--)
    {
        if(procedure[i]==lower)
        {
            lower_eaten++;
        }
        else
        {
            higher_eaten++;
        }
        left_movement.push_back(0-lower_eaten+higher_eaten);
        if(dif==left_movement[left_sz])
        {
            mini=min(mini,left_sz+1);
        }
        left_sz++;
        
    }
    
    
    map<long ,long>mp;
    for(long i = right_movement.size()-1 ; i>=0;i--)
    {
        mp[right_movement[i]]=i+1;
    }
    for(long i = left_movement.size()-1 ; i>=0;i--)
    {
       if(mp[dif-left_movement[i]]!=0)
       {
           mini=min(i+mp[dif-left_movement[i]]+1,mini);
       }
    }
    return mini;
    


}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arrang(2*n,0);
        long count1=0,count2=0;
        for(int i = 0 ; i <2*n;i++)
        {
            cin>>arrang[i];
            if(arrang[i]==1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
            

        }
        if(count1==count2)
        {
            cout<<0<<endl;
            
        }
        else if(count1<count2)
        {
            cout<<ans(arrang,2,1,count2,count1)<<endl;
        }
        else
        {
            cout<<ans(arrang,1,2,count1,count2)<<endl;
            
        }
        
        

    }
}