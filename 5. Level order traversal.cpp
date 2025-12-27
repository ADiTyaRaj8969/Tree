#/*
/*
 Task: Level-order traversal (BFS)
 Time Complexity: O(n)
 Space Complexity: O(n) — queue may hold up to width of tree
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

void levelOrder(Node* root)
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
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level order: ";
    levelOrder(root);
    return 0;
}

// sc tc
