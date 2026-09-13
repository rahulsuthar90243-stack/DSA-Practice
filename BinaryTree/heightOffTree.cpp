#include<iostream>
#include<vector>
using namespace std;

class Node {
public:    
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int idx = -1;
Node* buildTree(vector<int> tree){

    idx++;

    if(tree[idx] == -1) return NULL;
    Node* root = new Node(tree[idx]);

    root->left = buildTree(tree);
    root->right = buildTree(tree);
    return root;
}

void preOrder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// Height of a  tree
int Height(Node* root){

    if(root == NULL) return 0;
    int left = Height(root->left);
    int right = Height(root->right);

    return max(left, right)+1;
}

// Count a node of tree

int countNode(Node *root){

    if(root == NULL) return 0;
    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return (leftCount + rightCount) + 1;
}

int sumNode(Node *root){

    if(root == NULL) return 0;
    int leftSum = sumNode(root->left);
    int rightSum = sumNode(root->right);
    

    return leftSum + rightSum + root->data;
}

int main(){
    vector<int> tree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node*root = buildTree(tree);

    preOrder(root);

    int treeHeight = Height(root); cout<<endl;
    cout<<"Height of a tree: "<<treeHeight<<endl;

    cout<<"Node count: "<<countNode(root)<<endl;
    cout<<"Sum of Node: "<<sumNode(root)<<endl;


}

