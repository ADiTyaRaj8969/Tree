#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
int findMin(Node* root)
{
    if (!root)
        throw runtime_error("Empty");
    while (root->left) root = root->left;
    return root->data;
}
int findMax(Node* root)
{
    if (!root)
        throw runtime_error("Empty");
    while (root->right) root = root->right;
    return root->data;
}
int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    cout << "Min: " << findMin(root) << " Max: " << findMax(root) << endl;
    return 0;
}
