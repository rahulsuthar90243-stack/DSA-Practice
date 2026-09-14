#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = right = NULL;
    }
};

int search(vector<int> inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
    if (left > right) return NULL;

    
    Node* root = new Node(preorder[preIdx]);

    int inIdx = search(inorder, left, right, preorder[preIdx]);
    preIdx++;

    root->left = buildTree(preorder, inorder, preIdx, left, inIdx - 1);
    root->right = buildTree(preorder, inorder, preIdx, inIdx + 1, right);
    return root;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    int preIdx = 0;
    Node* root = buildTree(preorder, inorder, preIdx, 0, inorder.size() - 1);

    cout << root->val << " " << root->left->val << " " << root->right->val << endl;
    return 0;
}