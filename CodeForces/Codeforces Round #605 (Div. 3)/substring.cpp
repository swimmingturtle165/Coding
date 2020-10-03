// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count of 
// valid sub-strings 
int printSubstrings(string s) 
{ 

	// To store distinct output substrings 
	unordered_set<string> us; 

	// Traverse through the given string and 
	// one by one generate substrings beginning 
	// from s[i]. 
	for (int i = 0; i < s.size(); ++i) { 

		// One by one generate substrings ending 
		// with s[j] 
		string ss = ""; 
		for (int j = i; j < s.size(); ++j) { 

			ss = ss + s[j]; 
			us.insert(ss); 
		} 
	} 
    int c=0;
	// Print all substrings one by one 
	for (auto s : us)
    {
       
        c++;
    }
    return c;
} 

// Driver code 
int main() 
{ 
    int n,m;
    cin>>n>>m;
	string str ;
    cin>>str;
    map<char,bool> mp;

    for(int i = 0 ; i <m;i++) 
    {
        char ch;
        cin>>ch;
        mp[ch]=true;
    }
    string ans="";
    long long count=0;
    vector <string> partions;
    for(int i = 0 ; i <str.size();i++)
    {
        string temp="";
        char ch=str[i];
        map<char,bool> :: iterator it=mp.find(ch);
        if(it!=mp.end())
        {
            ans+=ch;
            temp=ans;
        }
        else
        {
           partions.push_back(ans);
           ans="";
          
        }
        
    }
    if(ans.size()>=1)
    {
     partions.push_back(ans);
    }
    for(int i = 0 ; i <partions.size();i++)
    {
        long long temp=partions[i].size();
        count+=(temp*(temp+1))/2;
    }
    
	cout<<count<<endl; 
	
    
    return 0; 
} 
