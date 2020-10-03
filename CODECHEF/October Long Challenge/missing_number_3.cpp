#include<bits/stdc++.h>

using namespace std;

long long evaluate(long long base ,string  nums)
{
    // returns the value on string num in base "base"

    

    long long val=0;
    long long place_value=1;
    for(int i = nums.size()-1;i>=0;i--)
    {
        long long temp=nums[i] <='9'?   nums[i]-'0'
                :nums[i]-'A'+10;
        val+=place_value*(temp);
        place_value*=base;

        if(val>1000000000000 || place_value>1000000000000)
        {
          return 1000000000002;
        }
    }
     return val;
    
}

string convert (long long val,long long base)
{
    //converts a number into n-base 

    string ans="";
    while(val>0)
    {
        long long temp=val%base;

        char ch=temp<=9?temp+'0':temp-10+'A';

        ans=ch+ans;

        val=val/base;
    }
    return ans;
}
vector<string> get_values(long long val)
{
    //gives string of values of a particular number in each base from 2-36
    vector <string> list;
    
    for(int i = 0 ; i < 2;i++)
    {
        list.push_back("**");
    }
    if(val>1000000000000)
    {
        return list;
    }
    for(int i = 2;i<=36;i++)
    {
        string  temp=convert(val,i);
        
        list.push_back(temp);
    }
   
     return list;
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
    for(int  i = base;i<=36;i++)
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
vector<long long> get_common_val (string n1,string n2)
{
    //finds the common value of 2 strings if there is none returns -1
    vector<long long> ans;
            int curr_b1=2;
            int curr_b2=2;
            
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
         
            
            while(curr_b1<=36 && curr_b2<=36 && val1<=1000000000000 && val2<=1000000000000 )
            {
                if(val1==val2)
                {
                 ans.push_back(val1);
                 curr_b1++;
                 val1=evaluate(curr_b1,n1);
                 continue;
                }
                
                 if(val1<val2)
                {
                    curr_b1++;
                    val1=evaluate(curr_b1,n1);
                }

                else if(val1>val2)
                {                    
                    curr_b2++;
                    val2=evaluate(curr_b2,n2);
                }      
                
                              
            }

            return ans;
            }

long long solve(vector<int>&base_given,vector<string>  &nums,vector<int> &base,int n)
{
    //base_given stores indexes of all bases which are already given to the user
    //base stores inputed bases
    // nums stores strings input as a number
   if(n==1)
        {    

           long long answ;
            if(base_given.size()==1)
            {
            answ=evaluate(base[0],nums[0]);
           
            answ=answ>1000000000000? -1: answ;
            return answ;
            }
            else
            {
                vector<long long> temp=get_conversions(nums[0]);
                if(temp.size()>0)
                {
                answ=temp[0];
                }
                else
                {
                    answ=-1;
                }
                return answ;
                
            }

            
        }
        else if(base_given.size()>=1)
        {
            int base_n=base[base_given[0]];
           
            long long val=evaluate(base_n,nums[base_given[0]]);
           
            if(val>1000000000000)
            { 
               return -1;        
            } 
            vector<string> list=get_values(val);
            
            for(int i = 0 ; i < n ;i++)
            {
                int base_temp=base[i];
                string num_temp=nums[i];

                if(base_temp==-1)
                {
                            bool check=false;

                            for(int j =2;j<list.size();j++)
                            {
                                if(num_temp==list[j])
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
                else
                {
                    if(num_temp!=list[base_temp])
                    {
                        return -1;
                    }
                }
                
            }
                return val;
        }
        else 
        {
           vector< long long> val=get_common_val(nums[0],nums[1]);
            
            
            if(val.size()==0)
            {
               return -1;
                 
            }
            
                // vector<string> list=get_values(val);        
               
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
                   
        }
        
        
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
   
    while(t-->0)
    {
            
        int n;
        cin>>n;
      
        vector<int> base_given;
        vector<string> nums;
        vector<int> base;

        for(int i = 0 ; i <n;i++)
        {
            int b;
            string temp;
            cin>>b>>temp;
            if(b!=-1)
            {
                base_given.push_back(i);        
            }
           
            base.push_back(b);
            nums.push_back(temp);

        }
        
        cout<<solve(base_given,nums,base,n)<<endl;
    }
    
}