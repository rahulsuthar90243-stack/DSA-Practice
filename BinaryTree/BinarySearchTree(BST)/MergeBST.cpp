#include<iostream>
#include<vector>
using namespace std;

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int val){
     this->data = val;
     left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* build(vector<int> arr){
  Node* root = NULL;

  for(int val: arr){
    root = insert(root, val);
  }
  return root;
}

void inOrder(Node* root, vector<int> &arr){
 if(root == NULL) return;

 inOrder(root->left, arr);
 arr.push_back(root->data);
 inOrder(root->right, arr);
}

Node* buildSortedBST(vector<int> temp, int st, int end){
    if(st > end) return NULL;
    int mid = st+(end-st)/2;

    Node* root = new Node(temp[mid]);

    root->left = buildSortedBST(temp, st, mid-1);
    root->right = buildSortedBST(temp, mid+1, end);

    return root;
}

Node* merge2BST(Node* root1, Node* root2){
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> temp;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }else{
            temp.push_back(arr2[j++]);
        }
    }

    while(i < arr1.size()) temp.push_back(arr1[i++]);
    while(j < arr2.size()) temp.push_back(arr2[j++]);

    return buildSortedBST(temp, 0, temp.size()-1);
}

int main(){

    vector<int> arr1 = {1, 2, 8, 10};
    vector<int> arr2 = {0, 3, 5};

    Node* root1 = build(arr1);
    Node* root2 = build(arr2);

    Node* root = merge2BST(root1, root2);

    vector<int> seq;
    inOrder(root, seq);
    for(int val: seq){
        cout<<val<<" ";
    }

    return 0;
}