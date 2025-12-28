#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
bool isBSTUtil(Node* root, long minv, long maxv)
{
    if (!root)
        return true;
    if (root->data <= minv || root->data >= maxv)
        return false;
    return isBSTUtil(root->left, minv, root->data) && isBSTUtil(root->right, root->data, maxv);
}
int main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    cout << (isBSTUtil(root, LONG_MIN, LONG_MAX) ? "BST" : "Not BST") << endl;
    return 0;
}
