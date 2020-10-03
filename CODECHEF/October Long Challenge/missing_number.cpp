#include<bits/stdc++.h>
using namespace std;

long long evaluate(int base ,string  nums)
{
    long long val=0;
    long long place_value=1;
    for(int i = nums.size()-1;i>=0;i--)
    {
        int temp=nums[i] <='9'?   nums[i]-'0'
                :nums[i]-'A'+10;
        val+=place_value*(temp);
        place_value*=base;

        if(val>pow(10,12))
        {
            return pow(10,12)+1;
        }
    }
    return val;
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
        if(base_given.size()>=1)
        {
            
            int base_n=base[base_given[0]];
           
            long long val=evaluate(base_n,nums[base_given[0]]);
             bool flag=true;
            for(int i = 1 ; i <base_given.size();i++)
            {
                long long val_t=evaluate(base[base_given[i]],nums[base_given[i]]);
                if(val_t!=val)
                {
                    flag==false;
                    break;
                }
            }
            if(val>pow(10,12) || flag==false)
            {
                cout<<-1<<endl;
            }
            else 
            {            
               
             for(int i = 0 ; i < n;i++)
            {
                vector<int>::iterator it;
                it=find(base_given.begin(),base_given.end(),i);
                if(it==base_given.end() && nums[i].size()>=2)
                {
                    double temp=nums[i][0] <='9'?   nums[i][0]-'0'
                    :nums[i][0]-'A'+10;
                       double temper_end=nums[i].size()>=2?pow((double)val/temp,(double)1/(double)(nums[i].size()-1)):2;
                       double temper_start=nums[i].size()>=2?pow((double)val,(double)1/(double)nums[i].size()):36;
                       if(temper_start-int(temper_start)>0)
                       {
                           temper_start++;
                       }
                     
                             for(int j = 0 ; j <nums[i].size() ;j++)
                        {
                        int temp=nums[i][j] <='9'?   nums[i][j]-'0'
                        :nums[i][j]-'A'+10;

                        temper_start=max(temp+1,(int)temper_start);
                        
                        }
                        temper_end=min((int)temper_end,36);
                     
                                    
                        long long  base_temp=temper_start;
                        long long temp_curr=1;
                        
                        long long temp_val=evaluate(base_temp,nums[i]);
                        
                        while(base_temp <=temper_end && val!=temp_val &&temp_val<pow(10,12))
                        {
                            base_temp++;
                            temp_val=evaluate(base_temp,nums[i]);
                        }

                        if(val!=temp_val)
                        {
                            cout<<-1<<endl;
                            flag=false;
                            break;
                        }
                    }
                    if(nums[i].size()==1)
                    {
                        if(val>35)
                        {
                            cout<<-1<<endl;
                            flag=false;
                            break;
                        }
                        else
                        {
                            int temp=nums[i][0] <='9'?   nums[i][0]-'0'
                        :nums[i][0]-'A'+10;

                        if(temp!=val)
                            {
                                cout<<-1<<endl;
                                flag=false;
                                break; 
                            }
                        }
                        
                    }
                    if(flag==false)
                     {
                     break;
                    }
                }
                if(flag)
                        {
                            if(val>pow(10,12))
                            {
                                cout<<-1<<endl;
                            }
                            else
                            {
                            cout<<val<<endl;
                            }
                            
                        }
            
            
            
            }
                
        }
        else
        {
            

            int curr_b1=1;
            int curr_b2=1;
            
            for(int i = 0 ; i <nums[0].size() ;i++)
            {
                int temp=nums[0][i] <='9'?   nums[0][i]-'0'
                :nums[0][i]-'A'+10;

                curr_b1=max(curr_b1,temp+1);
                 
            }
             for(int i = 0 ; i <nums[1].size() ;i++)
            {
                int temp=nums[1][i] <='9'?   nums[1][i]-'0'
                :nums[1][i]-'A'+10;
               

                 curr_b2=max(curr_b2,temp+1);
            }
            // cout<<curr_b1<<" "<<curr_b2<<endl;
            

            long long val1=evaluate(curr_b1,nums[0]);
            long long val2=evaluate(curr_b2,nums[1]);
         
            // cout<<val1<<" "<<val2<<endl;
            while(val1<pow(10,12) && val2<pow(10,12) && val1!=val2)
            {
            //   cout<<val1<<" "<<val2<<endl;

                if(val1<val2)
                {
                    curr_b1++;
                    val1=evaluate(curr_b1,nums[0]);
                }
                else
                {
                    curr_b2++;
                    val2=evaluate(curr_b2,nums[1]);
                }                
            }
            //  cout<<val1<<" "<<val2<<endl;
            if(val1!=val2 || val1>pow(10,12) || val2>pow(10,12))
            {
                cout<<-1<<endl;
            }
            else 
            {
                        bool flag=true;
                        double val=val1;
                       
            for(int i = 2 ; i < n;i++)
            {
                vector<int>::iterator it;
                it=find(base_given.begin(),base_given.end(),i);
                if(it==base_given.end() && nums[i].size()>=2)
                {
                    double temp=nums[i][0] <='9'?   nums[i][0]-'0'
                :nums[i][0]-'A'+10;
                
                       double temper_end=nums[i].size()>=2?pow((double)val/temp,(double)1/(double)(nums[i].size()-1)):2;
                       
                       double temper_start=nums[i].size()>=2?pow((double)val,(double)1/(double)nums[i].size()):36;
                     
                             for(int j = 0 ; j <nums[i].size() ;j++)
                        {
                        int temp=nums[i][j] <='9'?   nums[i][j]-'0'
                        :nums[i][j]-'A'+10;
                        // cout<<temp<<" ";
                        temper_start=max(temp+1,(int)temper_start);                
                        
                        }
                        // cout<<endl;
                        temper_end=min((int)temper_end,36);
                        // cout<<temper_start<<" "<<temper_end<<endl;
                     
                                    
                        long long  base_temp=temper_start;
                        long long temp_curr=1;
                        
                        long long temp_val=evaluate(base_temp,nums[i]);
                        
                        while(base_temp <=temper_end && val!=temp_val &&temp_val<pow(10,12))
                        {
                            base_temp++;
                            temp_val=evaluate(base_temp,nums[i]);
                        }
                        

                        if(val!=temp_val)
                        {
                            cout<<-1<<endl;
                            flag=false;
                            break;
                        }
                    }
                    if(nums[i].size()==1)
                    {
                        if(val>35)
                        {
                            cout<<-1<<endl;
                            flag=false;
                            break;
                        }
                        else
                        {
                            int temp=nums[i][0] <='9'?   nums[i][0]-'0'
                        :nums[i][0]-'A'+10;

                        if(temp!=val)
                            {
                                cout<<-1<<endl;
                                flag=false;
                                break; 
                            }
                        }
                        
                    }
                    if(flag==false)
                     {
                     break;
                    }
                }
                        if(flag)
                        {
                            if(val>pow(10,12))
                            {
                                cout<<-1<<endl;
                            }
                            else
                            {
                            cout<<(int)val<<endl;

                            }
                            
                        }
                }
            
        }
        nums.clear();
        base.clear();
        base_given.clear();
        
    }
}