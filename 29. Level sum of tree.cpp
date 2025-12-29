#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
vector<int> levelSum(Node* root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        int s = 0;
        while (sz--)
        {
            Node* cur = q.front();
            q.pop();
            s += cur->data;
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        res.push_back(s);
    }
    return res;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    vector<int> s = levelSum(root);
    for (int v : s) cout << v << " ";
    cout << endl;
    return 0;
}
