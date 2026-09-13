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



void kthLevel(Node* root, int k){   //o(n)

    if(root == NULL) return;

    if(k == 1){
        cout<<root->data<<" ";
        return;
    }

    kthLevel(root->left, k-1);
    kthLevel(root->right, k-1); 
}


int main(){
    vector<int> tree = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node*root = buildTree(tree);

    cout<<root->data<<endl;
    int k = 3;
    kthLevel(root, k);

}