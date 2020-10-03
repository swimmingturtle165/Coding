#include<bits/stdc++.h>
using namespace std;


int count_0(string s)
{
    int ans=0;
    for(int i = 0 ; i < s.size();i++)
    {
        if(s[i]=='0')
        {
            ans++;
        }
    }
    return ans;
}


// class air{
//     public:
//     int zeroes=0;
//     int ones=0;

//     air(int x,int y)
//     {
//         zeroes=x;
//         ones=y;
//     }

// };

// bool cmp(air a,air b)
// {
//     int temp1=abs(a.ones+a.zeroes);
//     int temp2=abs(b.ones+b.zeroes);

//     return abs(temp1-temp2);

// }
int solve(vector<string> &inp2 ,vector<string> &inp1)
{
   
    int unp=0;
    for(int i = 0 ; i <inp1.size();i++)
    {
        if(inp1[i].size()%2==0)
        {
            continue;
        }
        else 
        {
            int tempe=count_0(inp1[i]);
            if(tempe == 0 || inp1[i].size())
            {
                unp++;
            }
        }
        
    }

    int left=inp2.size();
    int temp=0;
    for(int i = 0 ; i < inp2.size();i++)
    {
        if(count_0(inp2[i])%2==0 )
        {
            left--;
            temp++;
   
        }
    }
    if(left%2==0)
    {
        return inp2.size();
    }
    int ans=unp>0 ?inp2.size() :inp2.size()-1;
    
    return ans;

    // vector<air> arr;
    // long long zeroes=0,ones=0;
    // for(int i = 0 ; i < inp2.size();i++)
    // {
    //     int temp=count_0(inp2[i]);
    //     zeroes+=temp;
    //     ones+=(inp2[i].size()-temp);
    //     arr.push_back(air(temp,inp2[i].size()-temp));
    // }

    //  sort(arr.begin(),arr.end(),cmp);

    // int i = 0,ans=0;
    // while(i<arr.size())
    // {
    //     if(arr[i].ones %2==0)
    //     {
    //         ans++;
    //         i++;
    //         continue;
    //     }
    //     else
    //     {
    //         if(zeroes>ones && ones>=0)
    //         {
    //             zeroes--;
    //             ones++;
    //             ans++;
    //         }
    //         else if(zeroes>=0)
    //         {
    //             zeroes++;
    //             ones--;
    //             ans++;
    //         }
            
    //     }

    //     if(zeroes == 0 && ones ==0)
    //     {
    //         break;
    //     }
    //     i++;
    // }
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n ;
        cin>>n;

        int ans=0;
        vector<string> inp,inp2;
        bool pal[n];
        for(int i = 0 ; i < n ; i++)
        {
            pal[i]=false;
            string s;
            cin>>s;
            inp.push_back(s);

            if(s.size()%2==1)
            {
                pal[i]=true;
                ans++;
            }
            else
            {
                inp2.push_back(s);
            }
            
        }
        if(ans==n)
        {
            cout<<ans<<endl;
        }
        else
        {
            int ans_t=solve(inp2,inp);
            cout<<ans+ans_t<<endl;
        }
        

    }
}