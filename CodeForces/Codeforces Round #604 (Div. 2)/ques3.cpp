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
            int n;
            cin>>n;
            int arr[n];
            multiset<int> mp;
            set<int> dist;
            for(int i = 0 ; i <n;i++)
            {
                cin>>arr[i];
                mp.insert(arr[i]);
                dist.insert(arr[i]);
            }
            if(n<6)
            {
                cout<<"0 0 0"<<endl;
                continue;
            }
            vector<pair<int,int>> maped;
            // bool flag=false;
            int lowerlimit=-1;
            if( arr[(n/2)]==arr[(n/2)-1])
            {
                // flag=true;
                lowerlimit=arr[(n/2) -1 +n%2];
            }
            // cout<<lowerlimit<<"**"<<endl;
            maped.push_back({arr[0],mp.count(arr[0])});
            for(int i = 1 ;i<n/2 && arr[i]>lowerlimit;i++)
            {
                if(arr[i]!=arr[i-1])
                {
                    maped.push_back({arr[i],mp.count(arr[i])});
                    // cout<<arr[i]<<"  "<<mp.count(arr[i])<<endl;
                }
            }
            if(dist.size()<=3 || n<6 ||maped.size()<3)
            {
                cout<<"0 0 0"<<endl;
                continue;
            }
            int sum=0;
            for(int i = 1 ; i <maped.size();i++)
            {
                sum+=maped[i].second;
            }
            // cout<<sum<<endl;
            if(sum<2*(maped[0].second+1))
            {
            // cout<<sum<<endl;

                cout<<"0 0 0"<<endl;
                continue;

            }
            else
            {
                    int sum1=0,sum2=0;
                    int left=1,right=maped.size()-1;
                    while (sum1<=maped[0].second)
                    {
                        sum1+=maped[left].second;
                        left++;
                    }
                    while (sum2<=maped[0].second)
                    {
                        sum2+=maped[right].second;
                        right--;
                    }
                    //  cout<<maped[0].second<<"  "<<sum1<<"   "<<sum2<<endl;
                    //  cout<<left<<" --  "<<right<<endl;
                    if(left-right>1)
                    {
                       cout<<"0 0 0"<<endl;
                        continue; 
                    }
                    else
                    {
                        cout<<maped[0].second<<" "<<sum1<<" "<<sum-sum1<<endl;
                        continue;
                    }
                    

                    
            }
            
            
            
            

    }
}