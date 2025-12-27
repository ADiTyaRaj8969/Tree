"""
Task: Mirror tree
Time Complexity: O(n)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def mirror(root):
    if not root: return
    root.left, root.right = root.right, root.left
    mirror(root.left); mirror(root.right)

def inorder(root):
    if not root: return
    inorder(root.left); print(root.data, end=' '); inorder(root.right)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print('Before inorder:', end=' '); inorder(root); print()
    mirror(root)
    print('After inorder:', end=' '); inorder(root); print()
