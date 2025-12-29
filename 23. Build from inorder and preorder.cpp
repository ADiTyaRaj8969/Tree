#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
Node* buildIP(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& pIndex,
              unordered_map<int, int>& idx)
{
    if (inStart > inEnd)
        return nullptr;
    int rootVal = preorder[pIndex++];
    Node* root = new Node(rootVal);
    int inIndex = idx[rootVal];
    root->left = buildIP(inorder, preorder, inStart, inIndex - 1, pIndex, idx);
    root->right = buildIP(inorder, preorder, inIndex + 1, inEnd, pIndex, idx);
    return root;
}
Node* buildFromInPre(vector<int> inorder, vector<int> preorder)
{
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
    int pIndex = 0;
    return buildIP(inorder, preorder, 0, inorder.size() - 1, pIndex, idx);
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
    vector<int> preorder = {1, 2, 4, 5, 3};
    Node* root = buildFromInPre(inorder, preorder);
    inorder(root);
    cout << endl;
    return 0;
}
