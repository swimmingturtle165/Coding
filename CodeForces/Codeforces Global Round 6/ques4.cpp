#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    if(a.second!=b.second)
    {
        return a.second<b.second;
    }
    return a.first<b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long n,m;
    cin>>n>>m;
    vector<long long> people(n+1,0);
    for(long long i = 0 ; i <m;i++)
    {
        long long  borrower,lender,sum;
        cin>>borrower>>lender>>sum;
        people[borrower]-=sum;
        people[lender]+=sum;

    }
    vector<pair<long long, long long>> reciever,giver;
    for(long long i = 1 ; i <=n;i++)
    {
        if(people[i]>0)
        {
            pair<long long, long long> temp(i,people[i]);
            reciever.push_back(temp);
        }
        else if(people[i]<0)
        {
            pair<long long, long long> temp(i,0-people[i]);
            giver.push_back(temp);
        }
    }
    sort(reciever.begin(),reciever.end(),cmp);
    sort(giver.begin(),giver.end(),cmp);

    long long i=0,j=0,trans=0;
    vector<long long> a,b,c;
    while (i<reciever.size() && j<giver.size())
    {
        long long p1=reciever[i].first;
        long long amt1=reciever[i].second;
        long long p2=giver[j].first;
        long long amt2=giver[j].second;
        // p1 recieves amt1 
        //p2 gives amt2
        if(amt1==amt2)
        {
           reciever[i].second=0;
           giver[j].second=0;
            i++;
            j++;
            a.push_back(p2);
            b.push_back(p1);
            c.push_back(amt1);
        }
        else if(amt1>amt2)
        {
            reciever[i].second=amt1-amt2;
            giver[j].second=0;

            a.push_back(p2);
            b.push_back(p1);
            c.push_back(amt2);


            j++;
        }
        else
        {
           giver[j].second=amt2-amt1;
           reciever[i].second=0;

            a.push_back(p2);
            b.push_back(p1);
            c.push_back(amt1);
            i++;
        }
    }
    cout<<a.size()<<endl;
    for(long long i = 0 ; i <a.size();i++)
    cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;

}