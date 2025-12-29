#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
void zigzag(Node* root)
{
    if (!root)
        return;
    stack<Node*> curr, next;
    bool leftToRight = true;
    curr.push(root);
    while (!curr.empty())
    {
        Node* cur = curr.top();
        curr.pop();
        cout << cur->data << " ";
        if (leftToRight)
        {
            if (cur->left)
                next.push(cur->left);
            if (cur->right)
                next.push(cur->right);
        }
        else
        {
            if (cur->right)
                next.push(cur->right);
            if (cur->left)
                next.push(cur->left);
        }
        if (curr.empty())
        {
            leftToRight = !leftToRight;
            swap(curr, next);
        }
    }
    cout << endl;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Zigzag: ";
    zigzag(root);
    return 0;
}
