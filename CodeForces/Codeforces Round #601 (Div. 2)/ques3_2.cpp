#include<bits/stdc++.h>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    long n;
    cin>>n;
    // unordered_map<int,vector<int>> mp;
    vector<vector<int>> strg(n+1,vector<int>());
    vector<int> si(n+1,0);
    // vector<bool> start(n+1,false),end(n+1,false);
    for(int i = 0 ; i <n-2;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        strg[a].push_back(b);
        strg[a].push_back(c);

        strg[b].push_back(a);
        strg[b].push_back(c);

        strg[c].push_back(a);
        strg[c].push_back(b);

        si[a]+=2;
        si[b]+=2;
        si[c]+=2;
        
    }
    vector<int> ends;
    for(int i = 1;i<=n;i++)
    {
        if(si[i]==2)
        {
            ends.push_back(i);
            //cout<<i<<" ";
        }
    }
    // cout<<endl;
   

    int end1=ends[0],end2=ends[1];
     unordered_set<int> not_poss;
    not_poss.insert(end1);
    not_poss.insert(end2);

    unordered_set<int> done;
    done.insert(end1);
    done.insert(end2);
    int ans[n];
    ans[0]=end1;
    ans[n-1]=end2;
    int left_idx=1,right_idx=n-2;
    
        vector<int> temp_left=strg[end1];
        int left_min=INT_MAX;
        vector<int>left_next;
        // for(int i = 0 ; i <temp_left.size();i++)
        // cout<<temp_left[i]<<" ** ";

        // cout<<endl;
        for(int i = 0 ; i <temp_left.size();i++)
        {
            vector<int> curr_temp=strg[temp_left[i]];
            int curr_cnt=0;
            set<int> done_temp;
            if(done.count(temp_left[i])==1)
            {
                continue;
            }
            for(int j = 0 ; j <curr_temp.size();j++)
            {
                if(done.count(curr_temp[j])==0)
                {
                    curr_cnt++;
                }
            } 
            if(curr_cnt<left_min)
            {
                left_min=curr_cnt;
                left_next.clear();
                done_temp.clear();
                done_temp.insert(temp_left[i]);

                left_next.push_back(temp_left[i]);
            }
            else if(curr_cnt==left_min)
            {
                if(done_temp.count(temp_left[i])==0)
                {
                left_next.push_back(temp_left[i]);
                done_temp.insert(temp_left[i]);
                }
            }
        }
        
        if(left_next.size()==1)
        {
        ans[left_idx]=left_next[0];
        done.insert(left_next[0]);
        left_idx++;
        end1=left_next[0];
        }
        not_poss.insert(end1);
        

        for(int i = 2;i<n-1;i++)
        {
         vector<int> poss_candidates=strg[ans[i-2]];
        //  vector<int> left_twice=strg[i-2];
         
         for(int j = 0 ; j <poss_candidates.size();j++)
         {
             if( not_poss.count(poss_candidates[j])==0)
             {
                 ans[i]=poss_candidates[j];
                 not_poss.insert(ans[i]);
                 break;
             }
         }

        }

        
    for(int i = 0 ; i <n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
