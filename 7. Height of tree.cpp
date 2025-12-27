#/*
 Task: Height of tree
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
int height(Node* root)
{
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << "Height: " << height(root) << endl;
    return 0;
}
// sc tc
