#include <bits/stdc++.h>
using namespace std;
bool check_distinct(int num)
{
    int temp=num;
    bool num1[10];
    for(int i = 0 ; i <10;i++)
    {
        num1[i]=false;
    }
    while(temp>0)
    {
        int d=temp%10;
        if(num1[d])
        {
            return false;
        }
        else
        {
            num1[d]=true;
            temp=temp/10;
        }
        
    }
    return true;

}
int main()
{
    bool flag=true;
    int l,r;
    cin>>l>>r;
    if(l>r)
    {
        cout<< "-1"<<endl;
    }
    else
    {

        for(int i = l;i<=r;i++)
        {
            if(check_distinct(i))
            {
                flag=false;
                cout<<i<<endl;
               break;
            }
            else
            {
                continue;
            }
            
        }
    }
    if(flag==true)
    {
    cout<<"-1"<<endl;
    }
}