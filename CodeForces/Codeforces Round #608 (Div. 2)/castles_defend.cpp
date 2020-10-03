#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,army;
    vector<int> minsol,recruit,imp,passagefrom,passageto;
    for(int i = 0 ; i <n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        minsol.push_back(a);
        recruit.push_back(b);
        imp.push_back(c);
    }
    for(int i = 0 ; i <m;i++)
    {
        int a, b;
        cin>>a>>b;
        passagefrom.push_back(a);
        passageto.push_back(b);
    }
    int curr_castle=0;
    while(curr_castle<n)
    {
        if(army<minsol[curr_castle])
        {
            cout<<-1<<endl;
        }
    }
}