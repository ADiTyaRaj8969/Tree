"""
Task: Delete node from BST
Time Complexity: O(h)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def find_min_node(root):
    while root.left: root=root.left
    return root

def delete_node(root,key):
    if not root: return None
    if key<root.data:
        root.left=delete_node(root.left,key)
    elif key>root.data:
        root.right=delete_node(root.right,key)
    else:
        if not root.left:
            return root.right
        if not root.right:
            return root.left
        succ=find_min_node(root.right)
        root.data=succ.data
        root.right=delete_node(root.right,succ.data)
    return root

def inorder(root):
    if not root: return
    inorder(root.left); print(root.data, end=' '); inorder(root.right)

if __name__=='__main__':
    root=None
    root=Node(5); root.left=Node(3); root.right=Node(7)
    root=delete_node(root,3)
    print('After delete:', end=' '); inorder(root); print()
