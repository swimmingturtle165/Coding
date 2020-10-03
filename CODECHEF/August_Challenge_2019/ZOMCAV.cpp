#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    long t;
    cin>>t;
    while (t--)
    {
        long n;
        cin>>n;
        vector<long> arr1;
        long arr[n];
        for(int i = 0 ; i<n;i++)
        {
            arr1.push_back(0);         
        }
        //cout<<"## ";
        for(int i = 0 ; i <n;i++)
        {
            
            cin>>arr[i];
            
            long start=i-arr[i]>=0?i-arr[i]:0;
            long end=i+arr[i]<n?i+arr[i]:n-1;
            //cout<<arr[i]<<" ";
               if(start>=0)
              arr1[start]++;
              if(end+1<n)
              {
              arr1[end+1]--;
              }
        }
        // cout<<endl;
        // cout<<"@@ ";
        // cout<<arr1[0]<<" ";
        //cout<<arr1[0]<<" ";
        for(int i = 1 ; i<n;i++)
        {
            //cout<<arr1[i]<<" ";
            arr1[i]=arr1[i]+arr1[i-1];
            //cout<<arr1[i]<<" ";         
        }
       
        sort(arr1.begin(),arr1.end());
        
        vector<long> zomb;
        for(long i = 0 ; i < n;i++)
        {
            long temp;
            cin>>temp;
            zomb.push_back(temp);
        }
        sort(zomb.begin(),zomb.end());
        
        
        bool flag=true;
        for(long j=0;j<n;j++)
        {
            if(zomb[j]!=arr1[j])
            {
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag==true)
        {
            cout<<"YES"<<endl;
        }
    }
    
}

/*

 5,5,4,4,3)

 3 4 4 5 5 
 1 2 3 4 5
 3 4 4 5 5

 2
5
1 2 3 4 5
1 2 3 4 5
5
1 2 3 4 5
5 4 3 4 5
*/