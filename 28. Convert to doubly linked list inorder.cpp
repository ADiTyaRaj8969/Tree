#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
Node* prevNode = nullptr;
Node* bToDLL(Node* root)
{
    if (!root)
        return root;
    Node* head = bToDLL(root->left);
    if (prevNode == nullptr)
        head = root;
    else
    {
        prevNode->right = root;
        root->left = prevNode;
    }
    prevNode = root;
    bToDLL(root->right);
    return head;
}
void printDLL(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    Node* head = bToDLL(root);
    printDLL(head);
    return 0;
}
