#/*
 Task: Mirror tree (swap left/right subtrees)
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
void mirror(Node* root)
{
    if (!root)
        return;
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "Before inorder: ";
    inorder(root);
    cout << "\n";
    mirror(root);
    cout << "After inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}
// sc tc
