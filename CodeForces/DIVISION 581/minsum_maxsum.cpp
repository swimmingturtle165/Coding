/*
Mislove Has Lost an Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mislove had an array a1, a2, ⋯, an of n positive integers, but he has lost it. He only remembers the following facts about it:

The number of different numbers in the array is not less than l and is not greater than r;
For each array's element ai either ai=1 or ai is even and there is a number ai2 in the array.
For example, if n=5, l=2, r=3 then an array could be [1,2,2,4,4] or [1,1,1,1,2]; but it couldn't be [1,2,2,4,8] because this array contains 4 different numbers; it couldn't be [1,2,2,3,3] because 3 is odd and isn't equal to 1; and it couldn't be [1,1,2,2,16] because there is a number 16 in the array but there isn't a number 162=8.

According to these facts, he is asking you to count the minimal and the maximal possible sums of all elements in an array.

Input
The only input line contains three integers n, l and r (1≤n≤1000, 1≤l≤r≤min(n,20)) — an array's size, the minimal number and the maximal number of distinct elements in an array.

Output
Output two numbers — the minimal and the maximal possible sums of all elements in an array.

Examples
inputCopy
4 2 2
outputCopy
5 7
inputCopy
5 1 5
outputCopy
5 31
Note
In the first example, an array could be the one of the following: [1,1,1,2], [1,1,2,2] or [1,2,2,2]. In the first case the minimal sum is reached and in the last case the maximal sum is reached.

In the second example, the minimal sum is reached at the array [1,1,1,1,1], and the maximal one is reached at the array [1,2,4,8,16].*/

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
    int n,l,r;
    cin>>n>>l>>r;
    long ansmax=0,ansmin=0,start1=1,start2=1;
    for(int i = 0 ; i <=n-l;i++)
    {
        
        ansmin+=1;
        //cout<<ansmin<<" ";
    }
    for(int i = 0 ;i<l-1;i++)
    {
        start1*=2;
        ansmin+=start1;
       // cout<<ansmin<<" ";
    }
   // cout<<endl;    
    for(int i = 0 ;i<r;i++)
    {
       
        ansmax+=start2;
         start2*=2;
         //cout<<ansmax<<" ";
    }
    start2=start2/2;
     for(int i = 0 ; i <n-r;i++)
    {
        ansmax+=start2;
         //cout<<ansmax<<" ";
    }
    //cout<<endl;
    cout<<ansmin<<" "<<ansmax<<endl;
 }
 