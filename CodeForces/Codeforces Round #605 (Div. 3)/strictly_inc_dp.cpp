#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> inp;
    for(int i = 0 ; i <n;i++)
    {
        int temp;
        cin>>temp;
        inp.push_back(temp);
    }
    int dp_tab[n][n];
    memset(dp_tab,0,sizeof(dp_tab));

    for(int g = 0 ; g<n;g++)
    {
        for(int i = 0 ; i +g<n;i++)
        {
            int j=g+i;
            if(g==0)
            {
                dp_tab[i][j]=1;
            }
        }
    }
    

}