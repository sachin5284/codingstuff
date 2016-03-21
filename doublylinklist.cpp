#include <iostream>
using namespace std;
struct linklist
{
    int data;
    struct linklist *next;
    struct linklist *prev;
};
void insertelement(linklist **head,int key)
{
    linklist *newnode= new linklist;
    newnode->data=key;
    newnode->next=*head;
    newnode->prev=NULL;
    if(*head) (*head)->prev=newnode;
    *head=newnode;
}
void insertlist(linklist **head,int key,int position)
{
    linklist *newnode= new linklist;
    newnode->data=key;
    linklist *p=*head;
    int k=2;
    if(position==1)insertelement(&(*head),key);
    else
    {
        while(p!=NULL && k<position)
        {
            p=p->next;
            k++;
        }
        newnode->next=p->next;
        p->next->prev=newnode;
        newnode->prev=p;
        p->next=newnode;
    }
}
void printlist(linklist *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"--->";
        head=head->next;
    }cout<<"NULL"<<endl;
}
void deletelink(linklist **head,int position)
{
    linklist *temp=*head;
    int k=1;
    if(position==1)
    {
        *head=temp->next;
        (*head)->prev=NULL;
        delete(temp);
    }
    else
    {
    while(temp!=NULL && k<position)
    {
        temp=temp->next;
        k++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(temp);
    }
}
linklist *reverselist(linklist *head)
{
    linklist *node=head;
    linklist *revnode=NULL;
    while(node!=NULL)
    {
        insertelement(&revnode,node->data);
        node=node->next;
    }
    return revnode;
}
int main()
{
    linklist *node=NULL;
    cout<<"Welcome !! choose option for Doubly link list"<<endl;
    cout<<"*  TO add a new node press 1 "<<endl<<"*  to add a node at a position press 2 "<<endl<<"*  to delete a node at a postion press 3"<<endl<<"*  to reverse the link list press 4"<<endl<<"TO QUIT PRESS 0"<<endl;
    int n;
    cin>>n;
    while(n)
    {
    if(n==1)
    {
        cout<<"enter number you want to add : ";
        int m;
        cin>>m;
        insertelement(&node,m);
        printlist(node);
    }
    else if(n==2)
    {
        cout<<"enter node data: ";
        int a,b;
        cin>>a;
        cout<<"enter position: ";
        cin>>b;
        insertlist(&node,a,b);
        printlist(node);
    }
    else if(n==3)
    {
        cout<<"enter position to delete: ";
        int c;
        cin>>c;
        deletelink(&node,c);
        printlist(node);
    }
    else if(n==4)
    {
        node=reverselist(node);
        printlist(node);
    }
    else cout<<"ERROR enter again"<<endl;
    int k;
    cout<<endl<<"enter option: "<<endl;
    cin>>k;
    n=k;
    }
    return 0;
}
