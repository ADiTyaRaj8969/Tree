"""
Task: Inorder traversal (recursive)
Time Complexity: O(n)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def inorder(root):
    if not root: return
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Inorder:', end=' ')
    inorder(root); print()
