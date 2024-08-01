// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
    
    Node(int value)
    {
        this->value=value;
        left=NULL;
        right=NULL;
    }
};
Node* createTree()
{
    int data;
    cout<<"enter data : ";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"enter left data : ";
    root->left=createTree();
    cout<<"enter right data";
    root->right=createTree();
    return root;
}
void levelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout<<temp->value<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
void printLevelWise(Node* root)
{
    queue<Node*>qt;
    qt.push(root);
    qt.push(NULL);
    while(!qt.empty())
    {
        Node* temp=qt.front();
        qt.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!qt.empty())
            {
                qt.push(NULL);
            }
        }
        else
        {
            cout<<temp->value<<" ";
            if(temp->left)
            {
                qt.push(temp->left);
            }
            if(temp->right)
            {
                qt.push(temp->right);
            }
        }
        
    }
}
void inOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->value<<" ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->value<<" ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout<<root->value<<" ";
}
int heightOftree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=heightOftree(root->left);
    int right=heightOftree(root->right);
    int maxi=max(left,right)+1;
    return maxi;
}
int main() {
   Node* root=NULL;
   root=createTree();
//   levelOrder(root);
  printLevelWise(root);
// inOrderTraversal(root);
int height=heightOftree(root);
cout<<"height is : "<<height;
    return 0;
}