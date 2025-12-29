#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
bool rootToNode(Node* root, int key, vector<int>& path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (rootToNode(root->left, key, path) || rootToNode(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> path;
    if (rootToNode(root, 4, path))
    {
        for (int v : path) cout << v << " ";
        cout << endl;
    }
    return 0;
}
