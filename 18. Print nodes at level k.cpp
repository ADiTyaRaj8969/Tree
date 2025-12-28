#/*
 Task: Print nodes at level k
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
void printLevelK(Node* root, int k)
{
    if (!root)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printLevelK(root->left, k - 1);
    printLevelK(root->right, k - 1);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Nodes at level 2: ";
    printLevelK(root, 2);
    cout << endl;
    return 0;
}
// sc tc
