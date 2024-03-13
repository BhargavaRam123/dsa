// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int element)
    {
        data = element;
        left =  NULL;
        right = NULL;
    }
};

Node* insertintobst(Node* root,int val)
{
    if(root==NULL)
    {
        root = new Node(val);
        return root;
    }
    if(val>root->data)
    {
       root->right = insertintobst(root->right,val);
    }
    else
    {
      root->left =  insertintobst(root->left,val);
    }
    return root;
}

void createbst(Node* &root)
{
    cout<<"Enter the value of the node"<<endl;
    int val;
    cin>>val;
    while(val!=-1)
    {
       root = insertintobst(root,val);
       cout<<"Enter the value of the node"<<endl;
       cin>>val;
    }
    // cout<<(root->left)->data<<endl;
}

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}
int main() {
    
    Node* root = NULL;
    createbst(root);
    // cout<<(root->left)->data<<endl;
    levelOrderTraversal(root);
    return 0;
}