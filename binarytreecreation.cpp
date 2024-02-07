#include <iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int value)
  {
    this->data = value;
    this->left = NULL;
    this->right =NULL;
  }
};
  Node* createtree()
  {
    int val;
    cout<<"Enter the value for the node"<<endl;
    cin>>val;
    if(val==-1){
    return NULL;}

    Node * root = new Node(val);

    cout<<"left of node:"<<root->data<<endl;

    root->left = createtree();

    cout<<"right of node:"<<root->data<<endl;

    root->right = createtree();

    return root;

  }
int main() {
  Node* root = createtree();
  cout<<"Root node is:"<<root->data<<endl;
  return 0;
}