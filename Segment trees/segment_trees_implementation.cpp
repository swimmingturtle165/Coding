#include<iostream>
using namespace std;

void buildTree(int *tree,int*a,int index,int start,int end)
{
   //start --  starting index of the node
   //end   --  range of the node

   //BASE CASE
   if(start>end)
   {
       return;
   }
   //BASE CASE ->LEAF NODE
   if(start==end)
   {
       tree[index]=a[start];
       return;
   }

   //RECURSIVE CASE
   int mid=(start+end)/2;

   //BUILD LEFT SUBTREE
   buildTree(tree,a,2*index,start,mid);


   //BUILD RIGHT SUBTREE
   buildTree(tree,a,2*index+1,mid+1,end);
   
   //POSTORDER
   int left=tree[2*index];
   int right=tree[2*index+1];

   tree[index]=min(left,right);

}

//RETURN a min elemnt from the tree lying in range qstart & qend
int query(int* tree,int index,int start,int end,int qstart,int qend)
{
    //3 cases 
    
    //1->No Overlap (qend<start ||qstart>end ) return infinity(Worst answer)
    if(qend<start ||qstart>end)
    {
        return INT_MAX;
    }
    
    //2->Complete Overlap (qstart<=start &qend=>end) return tree[index] at the node
    else if(qstart<=start  && qend>=end)
    {
        return tree[index];
    }
    //3->Partial Overlap  Call both Sides   return the best result
    else 
    {   
    int mid=(start+end)/2;
    int leftAns=query(tree,2*index,start,mid,qstart,qend);
    int rightAns=query(tree,2*index+1,mid+1,end,qstart,qend);
    return min(leftAns,rightAns);
    }
} 

//UPDATE

void update(int* tree,int index,int start,int end,int i,int value)
{
 //NO OVERLAP
 if(i<start || i>end)
 {
     return;
 }   

 //LEAF NODE
 if(start==end)
 {
     tree[index]=value;
     return;
 }

 
 //Partial OVERLap i lying between start & end
 int mid=(start+end)/2;
 update(tree,2*index,start,mid,i,value);
 update(tree,2*index+1,mid+1,end,i,value);
 tree[index]=min(tree[2*index],tree[2*index+1]);
  return;
}

//Range Update
 void rangeUpdate(int* tree,int index,int start,int end,
 int range_start,int range_end,int increment)
{
 //NO OVERLAP
 if(range_end<start || range_start>end)
 {
     return;
 }   

 //LEAF NODE
 if(start==end)
 {
     tree[index]+=increment;
     return;
 }

 
 //Partial OVERLap i lying between start & end
 int mid=(start+end)/2;
 rangeUpdate(tree,2*index,start,mid,range_start,range_end,increment);
 rangeUpdate(tree,2*index+1,mid+1,end,range_start,range_end,increment);
 tree[index]=min(tree[2*index],tree[2*index+1]);
  return;
}


int main()
{
    int a[]={1,3,2,-2,4,5};
    int n=sizeof(a)/sizeof(int);

    //BUILD THE TREE ARRAY DYNAMICALLY IN HEAP
    
    int* tree=new int[4*n+1];
    //BUILDING TREE
    int index=1;
    int start=0; 
    int end=n-1;
    buildTree(tree,a,index,start,end);
    for(int i = 0 ; i <=4*n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    //QUERIES
     int no_of_queries=0;
     cin>>no_of_queries;
     for(int i = 0 ; i <no_of_queries;i++)
     {
         int qstart,qend;
         cin>>qstart>>qend;
         cout<<"MIN VAL b/w "<<qstart<<" "<<qend<<" is -> ";
         cout<<query(tree,1,start,end,qstart,qend)<<endl;
     }
    //update

     
}