/*
=====================================
                RPKV
=====================================
*/ 
// HEADER FILES :
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

// #DEFINE DEFINITIONS:
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,b,a) for(int i=b;i>a;i--)
#define DEBUG(x) cout<< '>'<<#x<<" : "<<x<<endl
#define nn cout<<endl
#define ll long long int
#define pb push_back
#define testcase int t;cin>>t;while(t--)
#define ld long double
#define gcd(a,b) __gcd(a,b)
#define space " "
#define maxv INT_MAX
#define minv INT_MIN
#define square(x) x*x
// DEBUGGING TEMPLATES :

void debug()
{
    cout<<endl;
}

template<class T1, class... Types> void debug(T1 e1, Types ... e2)
{
    cout<<e1<<" ";
    print(e2...);
}

template<class T> void displayvector(vector<T> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<space;
    }
    nn;
}

template<class T> void displayarray(T *v, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<space;
    }
    
    nn;
}

template<class T> int sizeofarr(T *v)
{
    return sizeof(v)/sizeof(T);
}

// ACTUAL CODE:



class Node{
    public:
    ll minimum ;

    Node()
    {
        this->minimum = -1;
    }
    Node(ll minimum)
    {
        this->minimum = minimum;
    }

};

class Can{

    public:

    ll temp;
    ll price;

    Can()
    {
        this->temp = 0;
        this->price = 0;
    }
    Can(ll temp, ll price)
    {
        this->temp = temp;
        this->price = price;
    }
};

// Building tree and storing INT_MAX at every node for each query from 1 to q
void buildTree(vector<Node>& tree,ll index,ll left, ll right)
{
    if(left>right)
    {
        return;
    }

    if(left == right)
    {   
        //DEBUG(index);
        //DEBUG(left);
        //DEBUG(right);
        Node mynode;
        mynode.minimum = 12345678;
        tree[index] = mynode;
        return;
    }
    //DEBUG(index);
    //DEBUG(left);
    //DEBUG(right);
    ll mid = (left+right)/2;
    Node mynode;
    mynode.minimum = 12345678;
    tree[index] = mynode;
    
    buildTree(tree,2*index, left, mid);
    buildTree(tree,2*index + 1, mid+1, right);

    
}

// Updating the tree for each can to find minimum over range 1 to q
void updatetree(vector<Node>& tree, ll index, ll tl, ll tr, ll qs, ll qe, Can c)
{
    if(tl > tr)
    {
        return;
    }

    if(tl>qe || tr<qs)
    {
        return;
    }
    // Updating for leaf node
    if(tl ==  tr && tl>=qs && tr<=qe) 
    {
        tree[index].minimum = min(tree[index].minimum,c.price);
        return;

    }
    // For Complete Overlap but not leaf node(Lazy Propagation):

    if(tl>= qs && tr<=qe )
    {
        if(tree[index].minimum> c.price)
        {    
            tree[index].minimum = c.price;
            ll mid = (tl + tr)/2;
            updatetree(tree, 2* index,tl, mid, qs,qe,c);
            updatetree(tree,2* index +1 ,mid+1, tr, qs, qe, c);
            
        }
        return;
    }

    ll mid = (tl + tr)/2;

    updatetree(tree, 2* index,tl, mid, qs,qe,c);
    updatetree(tree,2* index +1 ,mid+1, tr, qs, qe, c);


}

void printtree(vector<Node>& tree)
{
    FOR(i,0,tree.size())
        {
            cout<<tree[i].minimum<< " ";
        }
        cout<<endl;
}

void printquery(vector<Node>& tree,ll index,ll tl, ll tr, ll qs,ll qe)
{
    if(tl>tr)
    {
        return;
    }

    

    if(tl>qe || tr<qs)
    {
        return;
    }


    if(tl>= qs && tr<= qe)
    {   
        // DEBUG(tl);
        // DEBUG(tr);
        // DEBUG(index);
        // DEBUG(tree[index].minimum);    

            if(tree[index].minimum != 12345678)
            {   
                //cout<<"**"<<endl;
                FORE(i,tl,tr)
                {
                    cout<<tree[index].minimum<<" ";
                }
                return;
            }
            else
            {   
                ll mid = (tl+tr)/2;
                printquery(tree,2*index,tl,mid,qs,qe);
                printquery(tree,2*index+1,mid+1,tr,qs,qe);
                return;
            }
    }

    // DEBUG(tl);
    // DEBUG(tr);
    // DEBUG(index);
    // DEBUG(tree[index].minimum);

    ll mid = (tl+tr)/2;
    printquery(tree, 2*index, tl,mid,qs, qe);
    printquery(tree,2*index + 1, mid+1, tr, qs, qe);

}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    testcase
    {

        ll n,q,k,l,r;
        cin>>n>>q>>k>>l>>r;
        vector<Can> cans(n);

        vector<Node> tree(8*q + 5);
        ll tl = 0;
        ll tr = q;
        ll index = 1;
        buildTree(tree, index , tl, tr);
        //printtree(tree);
        
        FOR(i,0,n)
        {
            cin>>cans[i].temp>>cans[i].price;
            ll c = cans[i].temp;
            ll qs, qe;
            if(k<l)
            {
                if(c>=l && c<=r)
                {
                    qs = 0;
                    qe = c-l;
                    //cout<<"hello"<<endl;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                    //cout<<tree[8].updatevalue<<" "<<tree[9].updatevalue<<endl;
                }
                else if(c>r)
                {
                    qs = c-r;
                    qe = c-l;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
            }
            else if(k>= l && k<= r)
            {
                if(c<l)
                {   
                    //cout<<"hello"<<endl;
                    qs = l-c;
                    qe = q;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
                else if(c>= l && c<= r)
                {
                    //cout<<"hello"<<endl;
                    qs = 0;
                    qe = q;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
                else if(c>r)
                {
                    qs = c-r;
                    qe = q;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
            }
            else if(k>r)
            {
                if(c<l)
                {
                    qs = l-c;
                    qe = r-c;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
                else if(c>= l && c<= r)
                {
                    qs = 0;
                    qe = r-c;
                    if(qs<= qe)
                    updatetree(tree,index,tl,tr,qs,qe,cans[i]);
                    //printtree(tree);
                }
            }
        }


        printquery(tree, index, tl,tr,1,q);
        cout<<endl;

        

    }
    

    return 0;
}
