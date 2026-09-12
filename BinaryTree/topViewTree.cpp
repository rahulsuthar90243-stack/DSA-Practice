#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node {
public:
  int val;
  Node* left;
  Node* right;
  
  Node(int value){
    val = value;
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

void topViewNode(Node* root){
 queue<pair<Node*, int>> q;
 map<int, int> m;
 q.push({root, 0});

 while (q.size() > 0)
 {
    Node* curr = q.front().first;
    int currHD = q.front().second;
    q.pop();

    if(m.find(currHD) == m.end()){
        m[currHD] = curr->val;
    }

    if(curr->left != NULL) q.push({curr->left, currHD-1});
    if(curr->right != NULL) q.push({curr->right, currHD+1});
 }
 for(auto val : m){
   cout<<val.second<<" ";
 }
}

int main(){
    vector<int> preOrders = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrders);
    topViewNode(root);
}