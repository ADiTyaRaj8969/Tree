"""
Task: Sum of all nodes in binary tree
Time Complexity: O(n)
Space Complexity: O(h)
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def sum_nodes(root):
    if not root: return 0
    return root.data+sum_nodes(root.left)+sum_nodes(root.right)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print('Sum:', sum_nodes(root))
