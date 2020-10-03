/*
 BowWow and the Timetable
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
In the city of Saint Petersburg, a day lasts for 2100 minutes. From the main station of Saint Petersburg, a train departs after 1 minute, 4 minutes, 16 minutes, and so on; in other words, the train departs at time 4k for each integer k≥0. Team BowWow has arrived at the station at the time s and it is trying to count how many trains have they missed; in other words, the number of trains that have departed strictly before time s. For example if s=20, then they missed trains which have departed at 1, 4 and 16. As you are the only one who knows the time, help them!

Note that the number s will be given you in a binary representation without leading zeroes.

Input
The first line contains a single binary number s (0≤s<2100) without leading zeroes.

Output
Output a single number — the number of trains which have departed strictly before the time s.

Examples
inputCopy
100000000
outputCopy
4
inputCopy
101
outputCopy
2
inputCopy
10100
outputCopy
3
Note
In the first example 1000000002=25610, missed trains have departed at 1, 4, 16 and 64.

In the second example 1012=510, trains have departed at 1 and 4.

The third example is explained in the statements.

*/

#include<bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n;i++)
#define frm(i,m,n) for(int i = m ; i < n;i++)
#define ll long long int
#define ld long double
#define gcd(a,b) __gcd(a,b)

#define testcase int t;cin>>t;while(t--)
#define maxV INT_MAX
#define minv INT_MIN

/**Define function and object**/
#define pb push_back
#define Sort(v) sort(v.begin(),v.end())
#define RSort(v) sort(v.rbegin(),v.rend())
#define CSort(v,C) sort(v.begin(),v.end(),C)
#define all(v) (v).begin(),(v).end()
#define sqr(x) ((x)*(x))
#define find_dist(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))

/**Debug tools**/
#define DEBUG(x) cout<<#x<<" : "<<x<<endl;

/**Sync off with stdio**/
#define __ cin.sync_with_stdio(false);\
           cin.tie();

/**Typedef**/
typedef vector<int> vint;
typedef vector< vint > vint2D;
typedef vector<string> vstr;
typedef vector<char>vchar;
typedef vector< vchar >vchar2D;
typedef queue<int> Qi;
typedef queue< Qi > Qii;
typedef map<int,int> Mii;
typedef map<string,int> Msi;
typedef map<int,string> Mis;
typedef stack<int> stk;
typedef pair<int,int> pp;
typedef pair<int, pp > ppp;
typedef long long int LLD;
const int inf=0x7FFFFFFF;

/**Template & structure**/
struct point_int{int x,y;point_int(){}point_int(int a,int b){x=a,y=b;}
    bool operator==(const point_int &a)const{return x==a.x and y==a.y;}
}; ///Point for x,y (int) coordinate in 2D space
struct point_double{double x,y;point_double(){}point_double(double a,double b){x=a,y=b;}}; ///Point for x,y (double) coordinate in 2D space
struct Node{int v,w;Node() {}bool operator<(const Node &a)const{return w>a.w;}Node(int _v,int _w){v=_v,w=_w;}};///Node for Dijkstra
namespace my{
template<class T>T gcd(T a,T b){return b == 0 ? a : gcd(b, a % b);}

template<typename T>T lcm(T a, T b) {return a / gcd(a,b) * b;}

template<class T>T big_mod(T n,T p,T m){if(p==0)return (T)1;T x=big_mod(n,p/2,m);x=(x*x)%m;if(p&1)x=(x*n)%m;return x;}

template<class T>T multiplication(T n,T p,T m){if(p==0)return (T)0;T x=multiplication(n,p/2,m);x=(x+x)%m;if(p&1)x=(x+n)%m;return x;}

template<class T>T my_pow(T n,T p){if(p==0)return 1;T x=my_pow(n,p/2);x=(x*x);if(p&1)x=(x*n);return x;} ///n to the power p

template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}/// distance between a & b

template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}/// extract words or numbers from a line

template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}/// convert a number to string

template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} ///For Positive Negative No.

template<class T> T MIN3(T a,T b,T c) {return min(a,min(b,c));} /// minimum of 3 number

template<class T> T MAX3(T a,T b,T c) {return max(a,max(b,c));} ///maximum of 3 number

template <class T> void print_vector(T &v){int sz=v.size();if(sz)cout<<v[0];for(int i = 1; i < sz; i++)cout << ' '<<v[i];cout<<"\n";}/// prints all elements in a vector

bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}

bool isConsonant(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}}

int main()
 {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    string temp;
    cin>>temp;
    int ans=temp.length()/2;
    if(temp.length()%2==1)
    {
        //string subs=temp.substr(1,temp.length()-1);
            for(int i =1;i<temp.length();i++)
            {
                if(temp[i]=='1')
                {
                    ans++;
                    break;
                }
            }        
    }
    cout<<ans<<endl;
 }
 // 11 01 00 11 01 1
 //11 10 00 10 01

//  1 0000 0000
//  1 1110 1001 0000 1011 0010 0001 1100 1110 1111
//  1 1110 0101 1000 0101 0010 0110 1010 1111 1010 1101 1110 0100 0100 1001 0111 1011
//  1000 0100 1110 0010 1110 0000 1101 0000 1100 1010 0111 0101 1001 1011 0000 0001 0110 1100 0000 1011 0110 1011 1011 1101 1011