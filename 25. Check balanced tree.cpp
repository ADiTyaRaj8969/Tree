#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
int checkHeight(Node* root)
{
    if (!root)
        return 0;
    int lh = checkHeight(root->left);
    if (lh == -1)
        return -1;
    int rh = checkHeight(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    cout << (checkHeight(root) != -1 ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
