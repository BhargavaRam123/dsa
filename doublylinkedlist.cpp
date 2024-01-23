#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int value){
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }
    
};

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int findlength(Node* head)
{
    Node* temp = head;
    int a=0;
    while(temp!=NULL)
    {
        a++;
        temp = temp->next;
    }
    return a;
}

void insertathead(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    }
}
void insertattail(Node* &head,Node* &tail,int data)
{
    if(head==NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    }
}
void insertatmiddle(Node* &head,Node* &tail,int position,int data)
{
  if(head==NULL){
    Node* temp = new Node(data);
    head = temp ;
    tail = temp ;
  }else
  {if(position==1)
  {
    insertathead(head,tail,data);
  }
  else if(position==findlength(head)+1)
  {
    insertattail(head,tail,data);
  }
  else
  {
    Node* temp1 = head;
    Node* temp2 = head->next;
    Node* temp = new Node(data);
    while(position!=2){
      temp1=temp1->next;
      temp2=temp2->next;
      position--;
    }
    temp1->next = temp;
    temp2->prev = temp;
    temp->prev = temp1;
    temp->next = temp2;
  }}
}
void deletenode(Node* &head,Node* &tail,int position)
{
  if(head == NULL){
  cout<<"empty linkedlist delete operation cant be performed"<<endl;
  return;
  }
  if(head == tail)
  {
    Node* temp = head;
    delete temp;
    head=NULL;
    tail=NULL;
    return;
  }
  if(position==1){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
  }
  else if(position==findlength(head)){
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
  }else{
    Node* temp1 = head;
    Node* temp2 = head->next;
    while(position!=2)
    {
      temp1 = temp1->next ; 
      temp2 = temp2->next ; 
      position--;
    }
    temp1->next = temp2->next;
   Node* temp = temp2;
   temp2 = temp2->next;
   temp2->prev = temp1;
   delete temp;
  }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,40);
    insertathead(head,tail,30);
    insertathead(head,tail,20);
    insertathead(head,tail,10);
    insertattail(head,tail,1000);
    insertatmiddle(head,tail,5,11);
    deletenode(head,tail,4);
    print(head);
}