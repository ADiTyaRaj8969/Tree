#/*
 Task: Left view of tree
 Time Complexity: O(n)
 Space Complexity: O(n) — queue for level-order traversal
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
void leftView(Node* root)
{
    if (!root)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node* cur = q.front();
            q.pop();
            if (i == 0)
                cout << cur->data << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
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
    cout << "Left view: ";
    leftView(root);
    return 0;
}
// sc tc
