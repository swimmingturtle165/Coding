#include<bits/stdc++.h>
using namespace std;

class Pair{

    public :
    int temp;
    int price;
    int min;
    int max;
    Pair()
    {

    }
    Pair(int x,int y,int z ,int z1)
    {
        temp=x;
        price=y;
        min=z;
        max=z1;
    }
};

void buildTree(Pair* tree,int n,int q,int k,int l,int r,long index,int left,int right)
{
    if(left>right)
    {
        return;
    }
    if(left==right)
    {
        //setting nodes in the lowest level

        int c,p,min=q,max=q+1;
        cin>>c>>p;
        
        if(c>=l && c<=r)
        {
            min=1;
             if(k<l)
                {
                max=c-l;
                }
             else if(k>r)
                {
                max=min+r-c-1;
                }
            
            
        }
        else if(c>r )
        {
            //k must be less than r to make this possible else temp wont ever fit in the required range
            if(k<=r)
            {
              min=c-r;
                if(k<l)
                {
                max=min+c-l-1;
                }
            }
            else
            {
                min=q+1;
                max=q+1;
                //so that these are nodes are never considered
            }
            
        }
        else if(c<l )
        {
            //k must be greater than l to make this possible else temp wont ever fit in the required range
            if(k>=l)
            {
            min=l-c;
              if(k>r)
                {
                max=min+r-l-1;
                }
        
            }
            else
            {
                min=q+1;
                max=q+1;
                  //so that these are nodes are never considered
                
            }
            
            
        }
        cout<<c<<" *** "<<p<<"--"<<min<<" * "<<max<<" * "<<index<<endl;
        Pair temp(c,p,min,max);
        tree[index]=temp;
        return;

    }
    int mid=(left+right)/2;
    buildTree(tree,n,q,k,l,r,2*index,left,mid);
    buildTree(tree,n,q,k,l,r,2*index+1,mid+1,right);
    
    Pair temp;
   
    temp.price=min(tree[2*index].price,tree[2*index+1].price);
    temp.temp=0;
    temp.min=min(tree[2*index].min,tree[2*index+1].min);
    temp.max=max(tree[2*index].max,tree[2*index+1].max);
    tree[index]=temp;
    cout<<temp.temp<<" *** "<<temp.price<<"--"<<temp.min<<" * "<<temp.max<<" * "<<index<<endl;
}
int solution(Pair* tree,int query,int index)
{
    //3 cases 
    
    //1->No Overlap (qend<start ||qstart>end ) return infinity(Worst answer)
    if(query<tree[index].min ||query >tree[index].max)
    {
        return INT_MAX;
    }
    
    //2->Complete Overlap (qstart<=start &qend=>end) return tree[index] at the node
    else if(query>=tree[index].min ||query<=tree[index].max)
    {
        return tree[index].price;
    }
    //3->Partial Overlap  Call both Sides   return the best result
    else 
    {   
    
     long leftAns=solution(tree,query,2*index);
    
     long rightAns=solution(tree,query,2*index+1);
    
     return min(leftAns,rightAns);
    }
}

int main()
{
    long t;
    cin>>t;
    while(t--)
    {
     long n,q,k,l,r;
     cin>>n>>q>>k>>l>>r;
     Pair *tree=new Pair[4*n+1];
     buildTree(tree,n,q,k,l,r,1,0,n-1);
    //  for(int i = 1 ; i <4*n+1;i++)
    //  {
    //      cout<<tree[i].price<<" ";
    //  }
     for(int i =1;i<=q;i++)
     {
         long ans=solution(tree,i,1);
         if(ans!=INT_MAX)
         {
             cout<<ans<<" ********* ";
         }
         else
         {
             cout<<"-1"<<" ********* ";
         }
         
     }
     cout<<endl;
    
    }
}