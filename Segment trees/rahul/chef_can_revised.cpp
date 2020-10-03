#include<bits/stdc++.h>
using namespace std;

class Pair{

    public :
     long long temp;
     long long price;
     long long min;
     long long max;
    bool flag=true;
    Pair()
    {

    }
    Pair( long long x, long long y, long long z , long long z1)
    {
        temp=x;
        price=y;
        min=z;
        max=z1;
    }
};

void buildTree(Pair* tree, long long n, long long q, long long k, long long l, long long r, long long index,long long left,long long right)
{
    if(left>right)
    {
        return;
    }
    if(left==right)
    {
        //setting nodes in the lowest level

        long long c,p,min=INT_MIN,max=q;
        cin>>c>>p;

        if(k<l)
        {
            if(c<l)
            {
               min=q+1;
               max=q+1; 
            }
            else if(c>r)
            {
              min=c-r;
              max=c-l;
            }
            else
            {   
                min=0;
                max=c-l;                
            }
            
        }
        else if(k>r)
        {
             if(c<l)
            {
                min=l-c;
                max=r-c;
            }
            else if(c>r)
            {
               min=q+1;
               max=q+1;  
            }
            else
            {
                min=0;
                max=r-c;
            }
        }
        else
        {
            // l<=k<=r
             if(c<l)
            {
                min=l-c;
                max=q;
            }
            else if(c>r)
            {
                min=c-r;
                max=q;
            }
            else
            {
                min=0;
                max=q;
            }
        }
        
        
       
       //cout<<c<<" *** "<<p<<"--"<<min<<" * "<<max<<" * "<<index<<endl;
        Pair temp(c,p,min,max);
        tree[index]=temp;
        return;

    }
    long long mid=(left+right)/2;
    buildTree(tree,n,q,k,l,r,2*index,left,mid);
    buildTree(tree,n,q,k,l,r,2*index+1,mid+1,right);
    
    Pair temp;
   
    temp.price=min(tree[2*index].price,tree[2*index+1].price);
    temp.temp=0;
    temp.min=min(tree[2*index].min,tree[2*index+1].min);
    temp.max=max(tree[2*index].max,tree[2*index+1].max);
    temp.flag=(tree[2*index].min==tree[2*index+1].min)&&(tree[2*index].max==tree[2*index+1].max);
    tree[index]=temp;
   //cout<<temp.temp<<" *** "<<temp.price<<"--"<<temp.min<<" * "<<temp.max<<" * "<<index<<endl;
}
 long long solution(Pair* tree, long long query, long long index)
{
    //3 cases 
    
    //1->No Overlap (qend<start ||qstart>end ) return infinity(Worst answer)
    if(query<tree[index].min || query >tree[index].max)
    {
        return INT_MAX;
    }
    
    //2->Complete Overlap (qstart<=start &qend=>end) return tree[index] at the node
    else if(query>=tree[index].min && query<=tree[index].max &&tree[index].flag==true)
    {
        return tree[index].price;
    }
    //3->Partial Overlap  Call both Sides   return the best result
    else 
    {   
    
      long long leftAns=solution(tree,query,2*index);
    
      long long rightAns=solution(tree,query,2*index+1);
      //cout<<leftAns<<"<->"<<rightAns<<endl;
     return min(leftAns,rightAns);
    }
}
int main()
{
     long long t;
    cin>>t;
    while(t--)
    {
      long long n,q,k,l,r;
     cin>>n>>q>>k>>l>>r;
     Pair *tree=new Pair[4*n+1];
     buildTree(tree,n,q,k,l,r,1,0,n-1);
    //  for(long long i = 1 ; i <4*n+1;i++)
    //  {
    //      cout<<tree[i].price<<" ";
    //  }
    //cout<<endl;
     for(long long i =1;i<=q;i++)
     {
          long long ans=solution(tree,i,1);
        //  if(ans!=INT_MAX)
        //  {
        //      cout<<ans<<" ";//<<endl;
        //  }
        //  else
        //  {
        //      cout<<-1<<" ";//<<endl;;
        //  }
        cout<<ans<<endl;
         
     }
     cout<<endl;
    
    }
}