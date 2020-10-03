#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,sx,sy;
    cin>>n>>sx>>sy;
    vector<int> x_coor,y_coor;
    int v_up=0,v_dn=0,h_l=0,h_r=0;
    int final_x=0,final_y=0,count=0;
    for(int i = 0 ; i <n;i++)
    {
        int temp_x,temp_y;
        cin>>temp_x>>temp_y;
        x_coor.push_back(temp_x);
        y_coor.push_back(temp_y);

        if(temp_x>sx)
        {
            h_r++;
        }
        if(temp_x<sx)
        {
            h_l++;
        }
        if(temp_y>sy)
        {
            v_up++;
        }
        if(temp_y<sy)
        {
            v_dn++;
        }
        
        

    }
    int maxi=max(h_r,max(h_l,max(v_dn,v_up)));
        if(maxi==h_l || maxi==h_r)
        {
            
            final_y=sy;
            final_x=h_l>h_r?sx-1:sx+1;
            count=maxi;
            
        }
        else
        {
            

            final_x=sx;
            final_y=(v_up>v_dn?sy+1:sy-1);
            count=maxi;
        }

        // count=0;
        cout<<count<<endl;
        cout<<final_x<<" "<<final_y<<endl;


}