"""
Task: Count leaf nodes in binary tree
Time Complexity: O(n)
Space Complexity: O(h)
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def count_leaf(root):
    if not root: return 0
    if not root.left and not root.right: return 1
    return count_leaf(root.left)+count_leaf(root.right)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print('Leaf count:', count_leaf(root))
