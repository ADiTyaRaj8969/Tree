/*
 Task: Inorder traversal (recursive)
 Time Complexity: O(n)
 Space Complexity: O(h) — recursion stack, where h is tree height
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

void inorder(Node* root)
{
    if (!root)
    {
        return;
    }

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
    root->left->right = new Node(5);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}

// sc tc
