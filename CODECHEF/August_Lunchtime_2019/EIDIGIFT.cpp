#include<bits/stdc++.h>
using namespace std;
class pairs
{
    
    public:
    int age=0;
    int money=0;
    
    pairs()
    {

    }
    pairs(int x,int y)
    {
        age=x;
        money=y;
    }
    bool operator < (const pairs & other)
    {
        return money < other.money;
    }     
    bool operator > (const pairs & other)
    {
        return money > other.money;
    }     

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long t;
    cin>>t;
    while(t--)
    {
     int age[3],money[3];
     vector<pairs> val;
     for(int i = 0 ; i < 3;i++)
     {
         cin>>age[i];
     }
      for(int i = 0 ; i < 3;i++)
     {
         cin>>money[i];
         val.push_back(pairs(age[i],money[i]));
     }
     sort(val.begin(),val.end());
     bool flag=true;
     for(int i = 0 ; i <2;i++)
     {
        if(val[i].age>val[i+1].age)
        {
            
                cout<<"NOT FAIR"<<endl;
                flag=false;
                break;
//            }
            
        }
        if(val[i].money==val[i+1].money)
        {
            if(val[i].age!=val[i+1].age)
            {                 
                cout<<"NOT FAIR"<<endl;
                flag=false;
                break;
            }
            
        }
     }
     if(flag)
     {
         cout<<"FAIR"<<endl;
     }


    }
}