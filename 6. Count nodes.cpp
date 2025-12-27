/*
 Task: Count nodes
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

int countNodes(Node* root)
{
    if (!root)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Count: " << countNodes(root) << endl;
    return 0;
}

// sc tc
