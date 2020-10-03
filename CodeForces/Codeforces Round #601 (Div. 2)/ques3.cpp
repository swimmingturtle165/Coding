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
    unordered_set<int> done;
    done.insert(end1);
    done.insert(end2);
    int ans[n];
    ans[0]=end1;
    ans[n-1]=end2;
    int left_idx=1,right_idx=n-2;
    while(left_idx<=right_idx)
    {
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

        vector<int> temp_right=strg[end2];
        int right_min=INT_MAX;
        vector<int>right_next;
        for(int i = 0 ; i <temp_right.size();i++)
        {
            

            vector<int> curr_temp=strg[temp_right[i]];
            int curr_cnt=0;
            set<int> done_temp;

            if(done.count(temp_right[i])==1)
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
            if(curr_cnt<right_min)
            {
                right_min=curr_cnt;
                right_next.clear();
                done_temp.clear();
                    done_temp.insert(temp_right[i]);

                right_next.push_back(temp_right[i]);
            }
            if(curr_cnt==right_min)
            {
                if(done_temp.count(temp_right[i])==0)
                {
                    right_next.push_back(temp_right[i]);
                    done_temp.insert(temp_right[i]);

                }

            }
            
        }
        
        if(right_next.size()==1)
        {
        ans[right_idx]=right_next[0];
        done.insert(right_next[0]);
        right_idx--;
        end2=right_next[0];
        }
        //  cout<<left_next.size()<<" "<<right_next.size()<<endl;
        if(left_next.size()>1)
        {
            
            //even
            for(int i = 0 ; i <left_next.size();i++)
            {

                bool flag=false;
                for(int j = 0 ; j <strg[right_idx+2].size();j++)
                {
                if(strg[right_idx+2][j]==left_next[i]) flag=true;
                }
                if(flag==false)
                {
                    // cout<<left_next[i]<<"**"<<endl;

                ans[left_idx]=left_next[i];
                done.insert(left_next[i]);
                left_idx++;
                end1=left_next[i];
                int sum=left_next[0]+left_next[1]-end1;
                ans[left_idx]=sum;
                right_idx--;
                left_idx++;
                break;
                }
            }
            
            break;
        }
        else if(right_next.size()>1)
        {
            
            //odd
            for(int i = 0 ; i <right_next.size();i++)
            {
                
                bool flag=false;
                for(int j = 0 ; j <strg[right_idx-2].size();j++)
                {
                if(strg[right_idx-2][j]==left_next[i]) flag=true;
                }
                if(flag==false)
                {
                    // cout<<right_next[i]<<"**"<<endl;
                ans[right_idx]=right_next[i];
                done.insert(right_next[i]);
                right_idx--;
                end2=right_next[i];
                int sum=right_next[0]+right_next[1]-end2;
                ans[right_idx]=sum;
                right_idx--;
                left_idx++;
                break;
                }
            }
            
            break;
        }
    }
    for(int i = 0 ; i <n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}
