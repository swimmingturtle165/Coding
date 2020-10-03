#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int res[t];
    for(int k = 0 ; k < t ;k++)
    {
        int n;
        cin>>n;
        string temp;
        vector<string> ans;
        int left[n];
        int right[n];
        int leftsum=0;
        int rightsum=0;
        for(int i = 0 ; i < n ; i++)
        {
          cin>>temp;
          ans.push_back(temp);
          left[i]=0;
          right[i]=0;
          
        }       
    
        int mat[n][n];       
        
        for(int i = 0 ; i < n ; i++)
        {
                       
            for(int j = 0 ; j <n;j++)
            {
                 mat[i][j]=ans[i][j]-'0';
                 
                 if(mat[i][j]==1)
                 {
                     if(j<n/2)
                     {
                         left[i]++;
                         leftsum++;
                     }
                     else
                     {
                         right[i]++;
                         rightsum++;
                     }
                     
                 }
                 else
                 {
                     mat[i][j]=0;
                 }                 
                
                
            }          
        

        } 
        
        int finalans=rightsum>leftsum?rightsum-leftsum:leftsum-rightsum;
        if(finalans!=0)
        {
            for(int i = 0 ; i < n;i++)
          {
            int templ=leftsum-(left[i]-right[i]);
            int tempr=rightsum-(right[i]-left[i]);
            int tempans=templ>tempr?templ-tempr:tempr-templ;
            finalans=min(finalans,tempans);
          }
        }
        
        res[k]=finalans;     
    }
    for(int i = 0;i<t;i++)
    {
        cout<<res[i]<<endl;
    }
}