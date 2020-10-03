#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n1,n2;
    cin>>n1>>n2;

    if(n1==9 &&n2==1)
    {
        cout<<9<<" "<<10<<endl;
    }
    else if(n2-n1==1)
    {
        cout<<n1<<" "<<n2<<endl;
    }
    else if(n2==n1)
    {
        n2=n2*10+1;
        n1=n1*10;
        cout<<n1<<" "<<n2<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    
}