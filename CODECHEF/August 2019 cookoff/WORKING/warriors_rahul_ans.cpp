#include <iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    scanf("%lld", &t);
    while(t--)
    {
        long long int n;
        long long int q;
        scanf("%lld%lld", &n, &q);
        vector<long long int> arr(n);
        
        for(int i=0;i<n;i++)
        {
            long long int temp;
            scanf("%lld", &arr[i]);
        }
        
        sort(arr.begin(),arr.end());

        map<long long int,long long int> m;
        m.clear();
       
        while(q--)
        {
            long long int mypower;
            scanf("%lld", &mypower); 
            long long int temp = mypower;

            
            if(m.count(mypower))
            {
                printf("%lld\n", m[mypower]);
                continue;
            }
            
            long long int count = 0;
            
            for(int i=0;i<arr.size();i++)
            {
                 
                if(mypower > 2*arr[n-1])
                {
                    count = n;
                    break;
                }

                if(mypower>arr[i])
                {   
                    
                    count++;
                    mypower = 2*(mypower-arr[i]);
                }
                else
                {  
                    break;
                }

                
            }
            
            m[temp] = count;
            printf("%lld\n", count); 
        }
        
    }
	return 0;
}