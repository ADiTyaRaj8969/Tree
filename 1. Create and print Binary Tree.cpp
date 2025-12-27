/*
 Task: Create and print Binary Tree
 Time Complexity: O(n) — build and print visit each node once
 Space Complexity: O(n) — queue for level-order construction/printing
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

Node* buildLevelOrder(const vector<int>& vals)
{
    if (vals.empty())
    {
        return nullptr;
    }

    int i = 0;
    Node* root = new Node(vals[i++]);
    queue<Node*> q;
    q.push(root);

    while (i < static_cast<int>(vals.size()))
    {
        Node* cur = q.front();
        q.pop();

        if (vals[i] != INT_MIN)
        {
            cur->left = new Node(vals[i]);
            q.push(cur->left);
        }

        ++i;
        if (i >= static_cast<int>(vals.size()))
        {
            break;
        }

        if (vals[i] != INT_MIN)
        {
            cur->right = new Node(vals[i]);
            q.push(cur->right);
        }

        ++i;
    }

    return root;
}

void printLevelOrder(Node* root)
{
    if (!root)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";
        if (cur->left)
        {
            q.push(cur->left);
        }
        if (cur->right)
        {
            q.push(cur->right);
        }
    }

    cout << endl;
}

int main()
{
    // use INT_MIN to represent nulls in level-order array
    vector<int> vals = {1, 2, 3, 4, 5, INT_MIN, 7};
    Node* root = buildLevelOrder(vals);
    cout << "Level order print: ";
    printLevelOrder(root);
    return 0;
}

/*
 Task: Create and print Binary Tree
 Time Complexity: O(n)
 Space Complexity: O(n)
*/
// sc tc
