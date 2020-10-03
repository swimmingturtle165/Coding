#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        long r,p,s;
        cin>>r>>p>>s;
        long kr=0,kp=0,ks=0,wins=0;
        vector<char> inp,oupt(n,'#');
        for(int i = 0 ; i <n;i++)
        {
            char ch;
            cin>>ch;
            inp.push_back(ch);
            if(ch=='R')
            {
                kr++;

                if(p>0)
                {
                    oupt[i]='P';
                    wins++;
                    p--;
                }
            }
            else if(ch=='S')
            {
                ks++;
                if(r>0)
                {
                    oupt[i]='R';
                    r--;
                    wins++;
                }
            }
            else
            {
                kp++;
                if(s>0)
                {
                    oupt[i]='S';
                    s--;
                    wins++;
                }
            }
            
            
                        
        }
        float cn=n;
           
            int temp=(cn+1)/2;
            if(wins>=temp)
            {
                cout<<"YES"<<endl;
                for(int i = 0 ; i <n;i++)
                {
                    if(oupt[i]=='#')
                    {
                        if(s>0)
                        {
                            s--;
                            oupt[i]='S';
                        }
                        else if(p>0)
                        {
                            p--;
                            oupt[i]='P';
                        }
                        else
                        {
                            r--;
                            oupt[i]='R';
                        }
                        
                    }
                    cout<<oupt[i];
                }
                cout<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
    //     int sum=min(r,ks)+min(s,kp)+min(p,kr);
    //     if(sum>=((n+1)/2))
    //     {
    //         cout<<"YES"<<endl;
    //         vector<char>oupt(n,'*');
    //         for(int i = 0 ; i <n;i++)
    //         {
    //             char ch=inp[i];
    //             if(ch=='R')
    //         {
    //             if(kp>0)
    //             {
    //                 oupt[i]='P';
    //                 kp--;
    //             }
                
    //         }
    //         else if(ch=='S')
    //         {
    //             if(kr>0)
    //             {
    //                 kr--;

    //                 oupt[i]='R';
    //             }
    //         }
    //         else
    //         {
    //             if(ks>0)
    //             {
    //                 ks--;
    //                 oupt[i]='S';
    //             }
    //         }
    //         }
    //         for(int i = 0 ; i < n;i++)
    //         {
    //             if(oupt[i]!='*')
    //             {
    //                 cout<<oupt[i];
    //             }
    //             else
    //             {
    //                 if(kp>0)
    //                 {
    //                     kp--;
    //                     cout<<"P";
    //                 }
    //                 else if(ks>0)
    //                 {
    //                     ks--;
    //                     cout<<"S";
    //                 }
    //                 else
    //                 {
    //                     cout<<"R";
    //                 }                    
                    
    //             }
                
    //         }
    //         cout<<endl;
    //     }
    //     else
    //     {
    //         cout<<"NO"<<endl;
    //     }
        
     }
}