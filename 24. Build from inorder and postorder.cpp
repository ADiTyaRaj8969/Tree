#/*
 Task: Build from inorder and postorder
 Time Complexity: O(n)
 Space Complexity: O(n) — recursion + index map
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
Node* buildIPost(vector<int>& inorder, vector<int>& post, int inStart, int inEnd, int& pIndex,
                 unordered_map<int, int>& idx)
{
    if (inStart > inEnd)
        return nullptr;
    int rootVal = post[pIndex--];
    Node* root = new Node(rootVal);
    int inIndex = idx[rootVal];
    root->right = buildIPost(inorder, post, inIndex + 1, inEnd, pIndex, idx);
    root->left = buildIPost(inorder, post, inStart, inIndex - 1, pIndex, idx);
    return root;
}
Node* buildFromInPost(vector<int> inorder, vector<int> postorder)
{
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
    int pIndex = postorder.size() - 1;
    return buildIPost(inorder, postorder, 0, inorder.size() - 1, pIndex, idx);
}
void inorder(Node* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> post = {4, 5, 2, 3, 1};
    Node* root = buildFromInPost(inorder, post);
    inorder(root);
    cout << endl;
    return 0;
}
// sc tc
