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

// transform to sum tree
int sumTree(Node* root){
    if(root == NULL) return 0;

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data += (leftSum + rightSum);
    return root->data;
}
void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    vector<int> preOrders = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrders);
    cout<<"before conversion: ";
    preOrder(root);
    cout<<endl;

    sumTree(root);

    cout<<"after conversion: ";
    preOrder(root);

    return 0;
}