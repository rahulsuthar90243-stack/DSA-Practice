#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
   int val;
   Node* left;
   Node* right;

   Node(int value){
   val = value;
   left = right = NULL;
   }
};

// Build in BST
Node* insert(Node* root, int value){
   if(root == NULL) return new Node(value);

   if(value < root->val){
    root->left = insert(root->left, value);
   }else{
    root->right = insert(root->right, value);
   }

   return root;
}

Node* buildTree(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root = insert(root, val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// Search in BST
bool search(Node* root, int key){
    if(root == NULL) return false;
    if(root->val  == key) return true;

    if(root->val > key){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root){
    while (root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

// delete Node
Node* delNode(Node* root, int key){
    if(root == NULL) return NULL;
    if(key < root->val){
        root->left = delNode(root->left, key);
    }else if(key > root->val){
        root->right = delNode(root->right, key);
    }else{
        //key == root
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
            Node* IS =  getInorderSuccessor(root->right);
            root->val = IS->val;
            root->right = delNode(root->right, IS->val);
        }
    }
}

int main(){

    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node* root = buildTree(arr);
    inorder(root);
    cout<<endl;

    cout<<search(root, 20);
    cout<<endl;

    delNode(root, 6);
    inorder(root);
}