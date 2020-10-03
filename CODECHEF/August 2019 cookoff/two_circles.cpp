#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include<iomanip>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    for(int i = 0 ; i<t;i++)
    {
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double ptx=0,pty=0;
        if(r1>r2)
        {
            if(x1>x2)
            {
                ptx=x1+r1;
            }
            else
            {
                ptx=x1-r1;
            }


            if(y1>y2)
            {
              pty=y1+r1;
            }
            else
            {
                pty=y1-r1;
            }   
            double d=pow(ptx-x2,2)+pow(pty-y2,2);
            if(d>pow(r2,2))
            {
                cout<<"YES"<<endl;
                cout.precision(7);
                cout<<fixed<<setprecision(7)<<ptx<<" "<<pty<<endl;
            } 
            else
            {
                cout<<"NO"<<endl;
            }          
       }
       else
       {
            if(x1>x2)
            {
              ptx=x2-r2;
            }
            else
            {
                pty=x2+r2;
            }


            if(y1>y2)
            {
               pty=y2-r2;
            }
            else
            {
              pty=y2+r2;  
            }

             double d=pow(ptx-x1,2)+pow(pty-y1,2);
            if(d>pow(r1,2))
            {
                cout<<"YES"<<endl;
                cout<<ptx<<" "<<pty<<endl;
            } 
            else
            {
                cout<<"NO"<<endl;
            }
       }    
    }
}