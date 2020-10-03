#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n,ans=1;
        cin>>n;
        map<int,bool> skill;
        // vector<int> skills;
        for(int i = 0  ; i <n;i++)
        {
            int temp;
            cin>>temp;
            skill.insert({temp,true});

            if(skill.find(temp-1) !=skill.end() || skill.find(temp+ 1) !=skill.end() ) 
            {
                if(ans<2 && skill.find(temp-1) !=skill.end() && skill.find(temp+ 1) !=skill.end())
                {
                ans++;
                }
                else
                {
                    if(ans>1)
                    {
                        continue;
                    }
                    else
                    {
                        ans++;
                    }
                    
                }
                
            }

        }
        cout<<ans<<endl;
    }
}