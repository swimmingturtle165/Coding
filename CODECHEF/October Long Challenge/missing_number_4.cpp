#include <bits/stdc++.h>
using namespace std;


long long evaluate(long long base,string num)
{
    long long val=0;
    long long place_value=1;
    for(int i = num.size()-1;i>=0;i--)
    {
        long long temp=num[i]<='9'?num[i]-'0':num[i]-'A'+10;
        val+=place_value*temp;
        place_value*=base;
        if(val>1000000000000)
        {
            return 1000000000000000;
        }
    }
    return val;
}

string convert(long long val, long long base)
{
    string ans="";
    while(val>0)
    {

        long long temp=val%base;
        val=val/base;
        char ch= temp<=9?temp+'0':temp-10+'A';
        ans=ch+ans;

    }
    return ans;
}

vector<string> get_values(long long val)
{
    vector<string> ans;
    for(int i = 0 ;i<2;i++)
    {
        ans.push_back("&&&&&");
    }
    if(val>1000000000000)
    {
        return ans;
    }
    for(int i = 2;i<=36;i++)
    {
        ans.push_back(convert(val,i));
    }
    return ans;    
}

vector<long long> get_conversions(string nums)
{
    vector<long long> ans;
    long long base=2;
    for(int i = nums.size()-1;i>=0;i--)
    {
        long long temp=nums[i] <='9'?   nums[i]-'0'
                :nums[i]-'A'+10;
                base=max(base,temp+1);
    }
    for(int i = base;i<=36;i++)
    {
        long long temp=evaluate(i,nums);
        if(temp<=1000000000000)
        {
            ans.push_back(temp);
        }
        else
        {
            return ans;
        }
        
    }
    return ans;
}

vector<long long > get_common_values(string n1,string n2)
{
    int curr_b1=2;
    int curr_b2=2;

            vector<long long> ans;
    
            for(int i = 0 ; i <n1.size() ;i++)
            {
                int temp=n1[i] <='9'?   n1[i]-'0'
                :n1[i]-'A'+10;

                curr_b1=max(curr_b1,temp+1);
                 
            }
             for(int i = 0 ; i <n2.size() ;i++)
            {
                int temp=n2[i] <='9'?   n2[i]-'0'
                :n2[i]-'A'+10;
               

                 curr_b2=max(curr_b2,temp+1);
            }

            long long val1=evaluate(curr_b1,n1);
            long long val2=evaluate(curr_b2,n2);
            cout<<val1<<"  **  "<<val2<<endl;
         
         while(curr_b1<=36 && curr_b2<=36 && val1<=1000000000000 && val2<=1000000000000)
         {
            //   cout<<val1<<"  ##  "<<val2<<endl;
             if(val1==val2)
             {
                 
            // cout<<val1<<"  ##  "<<val2<<endl;

                 ans.push_back(val1);
                 curr_b1++;
                 val1=evaluate(curr_b1,n1);
                 continue;
             }
             else if(val1<val2)
             {
                 curr_b1++;
                 val1=evaluate(curr_b1,n1);

             }
             else
             {
                 curr_b2++;
                 val2=evaluate(curr_b2,n2);
             }
             
             
         }
         return ans;

}

long long solve(vector<string>&nums,vector<int>&base_given,vector<int>&bases,int n)
{
    if(n==1)
    {
        long long answ;
        if(base_given.size()==1)
        {
            answ=evaluate(bases[base_given[0]],nums[0]);
            if(answ>1000000000000)
            {
                return -1;
            }
            return answ;
        }
        else
        {
            vector<long long > values_pos=get_conversions(nums[0]);
            if(values_pos.size()>0)
            {
                return values_pos[0];
            }
            return -1;
        }
        
    }
    else if(base_given.size()>=1)
    {
        long long val=evaluate(bases[base_given[0]],nums[base_given[0]]);
        if(val>1000000000000)
        {
            return -1;
        }
        for(int i = 0 ; i <base_given.size();i++)
        {
            int base_temp=base_given[i];
            long long temp_eval=evaluate(bases[base_temp],nums[base_temp]);
            if(temp_eval!=val)
            {
                return -1;
            }
        }

        vector<string> list=get_values(val);

        for(int i = 0 ; i <n;i++)
        {
            bool check=false;
            for(int j =2;j<list.size();j++)
            {
                if(nums[i]==list[j])
                {
                    check=true;
                    break;
                }
            }
            if(check==false)
            {
                return -1;
            }
        }
        return val;
    }
    else
    {
        vector< long long> val=get_common_values(nums[0],nums[1]);
         if(val.size()==0)
            {
               return -1;                 
            }
            for(int i = 0 ; i <val.size();i++)
            {
                cout<<val[i]<<" ";
            }
            cout<<endl;
             for(int i  = 2 ; i <nums.size();i++)
                    {
                        vector<long long> temp_conv=get_conversions(nums[i]);
                       
                        
                        for(int j = 0 ; j <val.size();j++)
                        {
                            vector<long long> :: iterator it;
                            it=find(temp_conv.begin(),temp_conv.end(),val[j]);
                            if(it==temp_conv.end())
                            {
                                val.erase(val.begin()+j);
                                j--;
                                if(val.size()==0)
                                {
                                    return -1;
                                }
                            }
                        }
                                                
                    }
                    if(val.size()==0)
                                {
                                    return -1;
                                }
                    return val[0];

        // vector<long long > val=get_conversions(nums[0]);
        // for(int i = 1 ;i<nums.size();i++)
        // {
        //     vector<long long> temp_conv=get_conversions(nums[i]);

        //     for(int j = 0 ; j <val.size();j++)
        //                 {
        //                     vector<long long> :: iterator it;
        //                     it=find(temp_conv.begin(),temp_conv.end(),val[j]);
        //                     if(it==temp_conv.end())
        //                     {
        //                         val.erase(val.begin()+j);
        //                         j--;
        //                         if(val.size()==0)
        //                         {
        //                             return -1;
        //                         }
        //                     }
        //                 }
        // }
        // if(val.size()==0)
        //                         {
        //                             return -1;
        //                         }
        // return val[0];
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> bases;
        vector<string> nums;
        vector<int> bases_given;
        for(int i = 0 ; i <n;i++)
        {
            int b;
            string temp;
            cin>>b>>temp;
            if(b!=-1)
            {
                bases_given.push_back(i);
            }
            nums.push_back(temp);
            bases.push_back(b);
        }
        long long ans=solve(nums,bases_given,bases,n);
        if(ans>1000000000000)
        {
            ans=-1;
        }
        cout<<ans<<endl;

    }
}