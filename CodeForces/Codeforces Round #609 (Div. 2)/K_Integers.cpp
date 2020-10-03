#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    map<int,int> mp;
    for(int i = 0  ; i <n;i++)
    {
        int temp;
        cin>>temp;
        mp[temp]=i;
    }
    int start=mp[1];
    int end=mp[1];
    ans.push_back(0);
    for(int i = 2;i<=n;i++)
    {
        int idx=mp[2];
        if(idx<start)
        {
            start--;
            
        }
    }
}