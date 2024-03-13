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
bool searchinbst(Node* root ,int value)
{
    if(root==NULL)
    return false;
    if(root->data==value)
    {
        return true;
    }
    
    // baki sab recursion sambal lega
    
    bool l = searchinbst(root->left,value);
    bool r = searchinbst(root->right,value);
    
    return l||r;
    
}
Node* maxValue(Node* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	Node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

Node* deletenodefrombst(Node* root,int value ){
    // in this we are doing both searching and deletion part
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data == value)
    {
        // write the deletion code here`
        // case 1:leaf node
        if(root->left==NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2:one of the node is null and the other node is not null
        else if(root->left==NULL && root->right!=NULL)
        {
            Node * temp = root->right;
            delete root;
            return temp ;
        }
        // case 3;opposite of case 2
        else if(root->left!=NULL && root->right==NULL)
        {
            Node * temp = root->left;
            delete root;
            return temp ;
        }
        // case 4:delete an internal node
        else
        {
            Node* temp = maxValue(root->left);
            root->data = temp->data; 
            root->left = deletenodefrombst(root->left,temp->data);
            return root;
            
        }
    }
    if(value>root->data)
    {
        root->right = deletenodefrombst(root->right,value);
    }
    else{
        root->left = deletenodefrombst(root->left,value);
    }
    return root;
}
int main() {
    
    Node* root = NULL;
    createbst(root);
    // cout<<(root->left)->data<<endl;
    levelOrderTraversal(root);
    // int value;
    // while(true)
    // {
        
    // cout<<endl<<"The value to search: "<<endl;
    // cin>>value;
    // cout<<"value found:"<<searchinbst(root,value);
    // }
    while(true)
    {
        int value;
        cout<<"Enter the value to delete:"<<endl;
        cin>>value;
        root = deletenodefrombst(root,value);
        levelOrderTraversal(root);
    }
    return 0;
}