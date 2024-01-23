#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(){
    // cout<<"default constructor is called"<<endl;
    this->next=NULL;
  }
  Node(int val){
    // cout<<"param constructor is called"<<endl;
    this->data = val;
  }
  ~Node(){
    cout<<"Destructor called!"<<endl;
  }
};
void printll(Node* head){
  Node* temp = head;
  cout<<"traversing ll"<<endl;
  while(temp!=NULL)
  {
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}
void insertathead(Node* &head,Node* &tail,int data){
  if(head==NULL)
  {
  Node* temp = new Node(data);
  head = temp;
  tail=temp;
  }
  else
  {
  Node* temp = new Node(data);
  temp->next = head;
  head = temp;

  }
}
void insertattail(Node* &tail,int data){
  if(tail==NULL)
  {
    Node* temp = new Node(data);
    tail=temp;
  }
  else{Node* temp = new Node(data);
  tail->next = temp;
  tail = temp;}
}
int getlength(Node* head)
{
  int l=0;
  Node* temp = head;
  while(temp!=NULL)
  {
    l++;
    temp=temp->next;
  }
  return l;
}
void deletenode(Node* &head,Node* &tail,int position){
  if(head==NULL)
  cout<<"nothing to delete"<<endl;
    if(head == tail)
    {
      Node* temp = head;
      delete temp;
      head == NULL;
      tail == NULL;
    }
  if(position==1)
  {
    Node* temp = head;
    head=head->next;
    delete temp;
  }
  else if(position==getlength(head))
  {
    Node* temp = head;
    while(temp->next!=tail)
    {
      temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
    temp=temp->next;
    delete temp;
  }
  else{
    Node* temp1 = head;
    Node* temp2 = head->next;
    while(position!=2)
    {
      temp1 = temp1->next;
      temp2  = temp2->next;
      position--;
    }
    temp1->next = temp2->next;
    delete temp2;
  }
}
int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // insertathead(head,tail,5);
  // insertathead(head,tail,4);
  // insertathead(head,tail,3);
  // insertathead(head,tail,2);
  insertathead(head,tail,1);
  deletenode(head,tail,1);
  printll(head);
  cout<<"tail is:"<<tail->data<<endl;
  cout<<"length of the ll is:"<<getlength(head)<<endl;
  return 0;
}