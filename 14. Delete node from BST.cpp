#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
Node* findMin(Node* root)
{
    while (root->left) root = root->left;
    return root;
}
Node* deleteNode(Node* root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (!root->left)
        {
            Node* r = root->right;
            delete root;
            return r;
        }
        else if (!root->right)
        {
            Node* l = root->left;
            delete root;
            return l;
        }
        else
        {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
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
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root = deleteNode(root, 3);
    cout << "After delete: ";
    inorder(root);
    cout << endl;
    return 0;
}
