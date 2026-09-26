#include<iostream>
#include<vector>
#include<climits>
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

class Info{
public:
    int min;
    int max;
    int size;

    Info(int min, int max, int size){
        this->min = min;
        this->max = max;
        this->size = size;
    }

};

Info helper(Node* root){
  if(root == NULL){
    return Info(INT_MAX, INT_MIN, 0);
  }

  Info left = helper(root->left);
  Info right = helper(root->right);

  if(root->data > left.max && root->data < right.min){
    int currMin = min(root->data, left.min);
    int currMax =  max(root->data, right.max);
    int currSize =  left.size + right.size + 1;

    return Info(currMin, currMax, currSize);
  }
  else{
    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
  }
}


int largetBSTinBT(Node* root){
    Info info = helper(root);
    return info.size;
}

int main(){
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);

     cout<<endl;
    int largetSize = largetBSTinBT(root);
    cout<<"Largest Size of BST in BT: " <<largetSize <<endl;
}