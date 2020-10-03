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
        map<long ,long> mp;
        mp.clear();
        int arr[n];
        for(int i = 0 ; i  <n;i++)
        {
            long temp;
            cin>>temp;
            arr[i]=temp;
            mp[temp]=i;
        }
        long left_area=mp[1],right_area=mp[1];
        set<long> left;
        long done=1;
        cout<<1;
        for(int i = 2;i<=n;i++)
        {
            long curr=mp[i];
            if(left_area- curr==1)
            {
                left_area--;
                    done++;

                while(left.size()!=0 && left_area!=0&& left.count(left_area-1)>0)
                {
                    left_area--;
                    done++;
                }
                if(done==i)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
                
            }
            else if(curr-right_area==1)
            {
                    right_area++;

                    done++;

                while(left.size()!=0 && right_area!=n-1 && left.count(right_area+1)>0)
                {
                    right_area++;
                    done++;


                }
                if(done==i)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }

            }
            else
            {
                left.insert(curr);
                cout<<0;
            }
            

        }
        cout<<endl;

        
    }
}