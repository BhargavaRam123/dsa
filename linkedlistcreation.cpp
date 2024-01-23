#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(){
    cout<<"default constructor is called"<<endl;
    this->next=NULL;
  }
  Node(int val){
    cout<<"param constructor is called"<<endl;
    this->data = val;
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
int main() {
  // Node o(10);
  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  first->next=second;
  second->next=third;
  third->next=fourth;
  Node* head = first;
  printll(head);
  return 0;
}