#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    
    int t=0;
    cin>>t;
    
    for(int c=0;c<t;c++)
    {
       int n=0;
       cin>>n;
       int q=0;
       cin>>q;
       string input;
       cin>>input;
       int *val=new int[n];
       
       for(int i = 0 ; i < n;i++)
       {
         val[i]=0;
       }
       
       for(int i = 0 ; i < n-1;i++)
       {   
           if(i<n-1)
           {
             if(input[i]==input[i+1])
             {                
                 val[i+1]=1;         
             }
           }
           if(i<n-2)
           {               
                   if(input[i]==input[i+2])
                   {
                       val[i+1]=1;
                   }               
           }
       }
       for(int i = 1 ; i < n;i++)
       {
           val[i]+=val[i-1];
        
       }  
    //    for(int i = 0 ; i < n;i++)
    //    {
    //        cout<<val[i]<<" ";
    //    }
    //    cout<<endl;
       for(int i = 0 ; i < q;i++)
       {
           int start=0;
           cin>>start;
           int end=0;
           cin>>end;
        //    cout<<start-1<<" "<<end-1<<endl;
        //    cout<<val[end-1]<<" "<<val[start-1]<<endl;
           if(start+1>= end)
           {
               cout<<"NO"<<endl;
           }
            else if(input[end-1]==input[end-2] || val[end-2]>val[start-1])
            {
                 
                   cout<<"YES"<<endl;
            }
            else
            {
               cout<<"NO"<<endl;
            }           
           
       }      
    }
}