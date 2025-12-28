"""
Task: Insert into BST
Time Complexity: O(h)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def insert_bst(root,key):
    if not root: return Node(key)
    if key<root.data:
        root.left=insert_bst(root.left,key)
    else:
        root.right=insert_bst(root.right,key)
    return root

def inorder(root):
    if not root: return
    inorder(root.left); print(root.data, end=' '); inorder(root.right)

if __name__=='__main__':
    root=None
    root=insert_bst(root,5)
    insert_bst(root,3); insert_bst(root,7); insert_bst(root,2); insert_bst(root,4)
    print('BST inorder:', end=' '); inorder(root); print()
