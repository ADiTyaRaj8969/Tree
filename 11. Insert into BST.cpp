#/*
 Task: Insert into BST
 Time Complexity: O(h) — height of tree (O(log n) for balanced BST)
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
Node* insertBST(Node* root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
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
    Node* root = nullptr;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 2);
    insertBST(root, 4);
    cout << "BST inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}
// sc tc
