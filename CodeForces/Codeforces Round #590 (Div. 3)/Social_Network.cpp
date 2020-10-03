#include <bits/stdc++.h>
using namespace std;

class Node
   {
    public:
    int data=0;
    Node* next=NULL;

         Node()
         {

         }
         Node(int data,Node* next)
        {
            this->data=data;
            this->next=next;
         }    
    };

    void addLast(Node* &head,Node* &tail,int data)
    {
        if(head==NULL)
        {
            Node* curr=new Node(data,NULL);
            head=curr;
            tail=curr;
        }
        else
        {
             Node* curr=new Node(data,NULL);
             tail->next=curr;
             tail=curr;
        }
        
    }
    void display(Node* head)
    {
        for(Node* i =head;i!=NULL;i=i->next )
        {
            cout<<i->data<<" ";
        }
        cout<<endl;
    }
    void addFirst(Node* &head,Node* &tail,int data)
    {
        Node* nn=new Node(data,head);
        if(head==NULL)
        {
            tail=nn;
        }
        head=nn;
    }
    int getFirst(Node* &head)
    {
        if(head==NULL)
        {
            return -1;
        }
        return head->data;
    }
    int getLast(Node* &tail)
    {
        if(tail==NULL)
        {
            return -1;
        }
        return tail->data;

    }
    int getAt(Node* &head,int pos)
    {
        if(head==NULL)
        {
            return -1;
        }
        if(pos==0)
        {
            return head->data;
        }
        return getAt(head->next,pos-1);
    }
    Node* getNodeAt(Node* &head,int pos)
    {
        if(head==NULL)
        {
            return NULL;
        }
        return pos==0?head:getNodeAt(head->next,pos-1);
    }
    int getSize(Node* head)
    {
        int count=0;
        for(Node* i=head;i!=NULL;i=i->next)
        {
            count++;
            
        }
        return count;
    }
    void addAt(Node*&head,Node*&tail,int data,int idx)
    {
        cout<<"************"<<endl;
        int sz=getSize(head);
        cout<<sz<<endl;

        if(sz<0 || sz<idx)
        {
            cout<<"INVALID INDEX"<<endl;
        }
        else  if(idx==0)
        {
            cout<<"U";
            addFirst(head,tail,data);
        }
        else if(idx==sz)
        {
            cout<<"v";
            addLast(head,tail,data);
        }
        else
        {
            cout<<"UV";
            Node* nm=getNodeAt(head,idx-1);
            cout<<"******"<<endl;
            nm->next=new Node(data,nm->next);
        }  
        return;

    }
    //check
    void removeFirst(Node* &head,Node*&tail)
    {
        if(head==NULL)
        {
            return;
        }
        Node* temp=head;
        if(head==tail)
        {
          head=tail=NULL;
        }
        else
        {
            head=head->next;
        }
               
        
        delete temp;
    }
    void removeLast(Node* &head,Node* &tail)
    {
        if(head==NULL)
        {
            return;
        }
        if(head->next==NULL)
        {
            Node*temp= head->next;
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        int sz=getSize(head);
        Node* curr=getNodeAt(head,sz-2);
        Node* ll=curr->next;
        curr->next=NULL;
        delete ll;
        tail=curr;
    }
    void removeAt(Node*&head,Node*&tail,int idx)
    {
        int sz=getSize(head);
        if(idx<0 ||idx>=sz)
        {
            cout<<"INVALID INDEX"<<endl;
        }        
        else if(idx==0)
        {
           removeFirst(head,tail);
        }
        else if(idx==sz-1)
        {
          removeLast(head,tail);
        }
        else
        {
            Node* m1=getNodeAt(head,idx-1);
            Node* n=m1->next;
            Node* p1=n->next;
            m1->next=p1;
            delete n;
        }
        
    }

    int main()
    {
        Node* head=NULL;
        Node* tail=NULL;
        map<int,bool> ind;
        ind.clear();
        long n,k;
        cin>>n>>k;
        long size=0;
        for(int i = 0 ; i < n;i++)
        {
            int temp=0;
            cin>>temp;
            if(ind.find( temp ) == ind.end())
            {
               
                addLast(head,tail,temp);
                size++;
                ind.insert({temp,true});
                if(size>k)
                {
                    ind.erase(getFirst(head));
                    removeFirst(head,tail);
                    size--;
                }
            }
        }
        int arr[size];
        int i = 0;
          
        while(head!=NULL)
        {
            arr[i]=head->data;
          //  cout<<head->data<<" ";
            head=head->next;
            i++;
        }

        cout<<size<<endl;
        for(int i = size-1;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }