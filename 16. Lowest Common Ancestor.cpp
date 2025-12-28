#/*
 Task: Lowest Common Ancestor (binary tree)
 Time Complexity: O(n)
 Space Complexity: O(h) — recursion stack
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
Node* lca(Node* root, int a, int b)
{
    if (!root)
        return nullptr;
    if (root->data == a || root->data == b)
        return root;
    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);
    if (l && r)
        return root;
    return l ? l : r;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Node* res = lca(root, 4, 5);
    if (res)
        cout << "LCA: " << res->data << endl;
    return 0;
}
// sc tc
