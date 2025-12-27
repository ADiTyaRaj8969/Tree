"""
Task: Count nodes in binary tree
Time Complexity: O(n)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def count_nodes(root):
    if not root: return 0
    return 1+count_nodes(root.left)+count_nodes(root.right)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print('Count:', count_nodes(root))
