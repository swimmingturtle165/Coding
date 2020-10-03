#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long a,b,c,d;
    cin>>a>>b>>c>>d;
    
    if(a>b || d>c)
    {
        if(a==0 && b==0 && abs(c-d)==1)
        {
            cout<<"YES"<<endl;
            if(c>d)
            {

                for(int i = 0 ; i <d;i++)
                {
                    cout<<2<<" "<<3<<" ";
                }
                cout<<2;
            }
            else
            {
                for(int i = 0 ; i <c;i++)
                {
                    cout<<3<<" "<<2<<" ";
                }
                cout<<3;
            }
            
        }
        else if(c==0 && d==0 && abs(a-b)==1)
        {
            cout<<"YES"<<endl;
            if(a>b)
            {

                for(int i = 0 ; i <b;i++)
                {
                    cout<<0<<" "<<1<<" ";
                }
                cout<<0;
            }
            else
            {
                for(int i = 0 ; i <a;i++)
                {
                    cout<<1<<" "<<0<<" ";
                }
                cout<<1;
            }
        }
        else
        {
        cout<<"NO"<<endl;
            
        }
        
        // continue;
    }
    else
    {
        int b_left=b-a;
        int c_left=c-d;
        
        if(abs(b_left-c_left)>1)
        {
        cout<<"NO"<<endl;
        }
        else
        {
             cout<<"YES"<<endl;
             if(b_left==c_left)
             {
                 for(int i = 0 ; i <a;i++)
                 {
                     cout<<0<<" "<<1<<" ";
                 }
                 for(int i = 0 ; i <b_left;i++)
                 {
                     cout<<2<<" "<<1<<" ";
                 }
                 for(int i = 0 ; i <d;i++)
                 {
                     cout<<2<<" "<<3<<" ";
                 }
                 
             }
             else if(b_left>c_left)
             {

                 for(int i = 0 ; i <a;i++)
                 {
                     cout<<1<<" "<<0<<" ";
                 }
                 for(int i = 0 ; i <c_left;i++)
                 {
                     cout<<1<<" "<<2<<" ";
                 }
                 cout<<1<<" ";
                 for(int i = 0 ; i <d;i++)
                 {
                     cout<<2<<" "<<3<<" ";
                 }

             }
             else
             {
                 for(int i = 0 ; i <a;i++)
                 {
                     cout<<0<<" "<<1<<" ";
                 }
                 for(int i = 0 ; i <b_left;i++)
                 {
                     cout<<2<<" "<<1<<" ";
                 }
                 cout<<2<<" ";
                 for(int i = 0 ; i <d;i++)
                 {
                     cout<<3<<" "<<2<<" ";
                 }
             }
             
        }
        

    }
    
    

}