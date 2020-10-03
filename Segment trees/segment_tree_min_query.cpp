#include<bits/stdc++.h>
using namespace std;


void buildTree(int* tree,int*arr,int index,int start,int end)
{
    //start -->start of the input arr
    //end  -->end of the input arr
    if(start>end)
    {
        return;
    } 
    if(start==end)
    {
        tree[index]=arr[start];
        return;
    }
   
        //calculate mid pt
        int mid=(start+end)/2;

        

        //build left subtree
        buildTree(tree,arr,2*index,start,mid);
        //build right subtree
        buildTree(tree,arr,2*index+1,mid+1,end);
        //POST ORDER
        int left=tree[2*index];
        int right=tree[2*index+1];

        //setting value of current index
        tree[index]=min(left,right);
        return;   
    
}
//return minimum element from the given range of query
int query(int*tree,int index,int start,int end,int q_start,int q_end)
{
    /*
    3 cases possible
    1)complete overlap (qstart<=start && end<=qend) return value without making any further calls
    2)partial overlap (qstart<end || qend>start) call both sides and return the best answer
    3)no overlap (qstart>end || qend<start) return the worst possible answer
    */
  

    
    //1->No Overlap (qend<start ||qstart>end ) return infinity(Worst answer)
    if(q_end<start ||q_start>end)
    {
        return INT_MAX;
    }
    
    //2->Complete Overlap (qstart<=start &qend=>end) return tree[index] at the node
    else if(q_start<=start  && q_end>=end)
    {
        return tree[index];
    }
    else
    {
        //partial overlap
         int mid=(start+end)/2;
       int left=query(tree,2*index,start,mid,q_start,q_end);
       int right=query(tree,2*index+1,mid+1,end,q_start,q_end);
       
       int best_ans=min(left,right);
       
        //cout<<"#"<<best_ans<<endl;
       return best_ans;
    }
    
   
}

int main()
{
    int arr[]= {-1,7,-3,1,2,-4,-2,-1,3,1,-2};
    for(int i = 0 ; i <11;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int n=sizeof(arr)/sizeof(int);
    int *tree=new int[4*n+1];
    buildTree(tree,arr,1,0,n-1);
    for(int i = 0 ; i <=4*n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        int qstart,qend;
        cin>>qstart>>qend;
        int ans=query(tree,1,0,n-1,qstart,qend);
        cout<<qstart<<" - "<<qend<<" -> "<<ans<<endl;
    }
}