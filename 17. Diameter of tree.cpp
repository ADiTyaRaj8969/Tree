#/*
 Task: Diameter of tree
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
int diameterUtil(Node* root, int& res)
{
    if (!root)
        return 0;
    int l = diameterUtil(root->left, res);
    int r = diameterUtil(root->right, res);
    res = max(res, l + r + 1);
    return 1 + max(l, r);
}
int diameter(Node* root)
{
    int res = 0;
    diameterUtil(root, res);
    return res;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Diameter: " << diameter(root) << endl;
    return 0;
}
// sc tc
