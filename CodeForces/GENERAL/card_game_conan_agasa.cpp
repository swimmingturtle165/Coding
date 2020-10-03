#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"Conan"<<endl;
       return 0;
    }
    vector<int> cards;
    for(int i = 0 ; i <n;i++)
    {
        int temp;
        cin>>temp;
        cards.push_back(temp);
    }
    sort(cards.begin(),cards.end());   
    // for(int i = 0 ; i < n;i++)
    // {
    //     cout<<cards[i]<<" ";
    // } 
    // cout<<endl;
    long card=1;
    for(int  i = n-1 ; i >=0;i--)
    {
        card=1;
        while(i>0 && cards[i]==cards[i-1])
        {
            i--;
            card++;
        }
        if(card%2==1)
        {
       cout<<"Conan"<<endl;
       return 0;
        }

    }
     cout<<"Agasa"<<endl;
     
}