#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
 public:   
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
    data = val;
    left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx] == -1) return NULL;   // Base Case

    Node* root = new Node(preOrder[idx]);

    root->left = buildTree(preOrder);  // LEFT 
    root->right = buildTree(preOrder);  // RIGHT

    return root;
}

// preOrder Traversal  -> root-left-right
void preOrder(Node* root){   
    if(root == NULL) return;

    cout<<root->data<<" ";

     //recursion call to traversal all node
    preOrder(root->left);  
    preOrder(root->right);
}

// InOrder Travarsal  -> left-root-right
void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

// PostOrder Traveral ->left-right-root
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

// Level traversal -> level
void levelOrder(Node* root){
 queue<Node*> q;
 q.push(root);
 q.push(NULL);
 while (q.size() > 0)
 {
    Node* curr = q.front();
    q.pop();

    if(curr == NULL){
        if(!q.empty()){
            cout<<endl;
            q.push(NULL);
            continue;
        }else{
            break;
        }
    }
    
    cout<<curr->data<<" ";

    if(curr->left != NULL){
        q.push(curr->left);
    }
    if(curr->right != NULL){
        q.push(curr->right);
    }
 }
 
}

int main(){
    vector<int> preOrders = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrders);

    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    levelOrder(root);

    return 0;
}