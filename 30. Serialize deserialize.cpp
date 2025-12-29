#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
void serialize(Node* root, ostream& out)
{
    if (!root)
    {
        out << "# ";
        return;
    }
    out << root->data << " ";
    serialize(root->left, out);
    serialize(root->right, out);
}
Node* deserialize(istringstream& in)
{
    string val;
    if (!(in >> val))
        return nullptr;
    if (val == "#")
        return nullptr;
    Node* root = new Node(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    ostringstream out;
    serialize(root, out);
    string s = out.str();
    cout << s << endl;
    istringstream in(s);
    Node* r = deserialize(in);
    return 0;
}
