#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
bool identical(Node* a, Node* b)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;
    return a->data == b->data && identical(a->left, b->left) && identical(a->right, b->right);
}
int main()
{
    Node* a = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    Node* b = new Node(1);
    b->left = new Node(2);
    b->right = new Node(3);
    cout << (identical(a, b) ? "Identical" : "Not Identical") << endl;
    return 0;
}
