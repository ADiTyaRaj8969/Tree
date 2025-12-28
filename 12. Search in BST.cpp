#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
bool searchBST(Node* root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
}
int main()
{
    Node* root = nullptr;
    root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    cout << "Search 3: " << (searchBST(root, 3) ? "Found" : "Not Found") << endl;
    cout << "Search 6: " << (searchBST(root, 6) ? "Found" : "Not Found") << endl;
    return 0;
}
