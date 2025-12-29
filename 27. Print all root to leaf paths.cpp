#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
void paths(Node* root, vector<int>& cur)
{
    if (!root)
        return;
    cur.push_back(root->data);
    if (!root->left && !root->right)
    {
        for (int v : cur) cout << v << " ";
        cout << "\n";
    }
    else
    {
        paths(root->left, cur);
        paths(root->right, cur);
    }
    cur.pop_back();
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> cur;
    paths(root, cur);
    return 0;
}
