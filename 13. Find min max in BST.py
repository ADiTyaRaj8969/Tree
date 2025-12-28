"""
Task: Find min and max in BST
Time Complexity: O(h)
Space Complexity: O(1)
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def find_min(root):
    if not root: raise ValueError('Empty')
    while root.left: root=root.left
    return root.data

def find_max(root):
    if not root: raise ValueError('Empty')
    while root.right: root=root.right
    return root.data

if __name__=='__main__':
    root=Node(5); root.left=Node(3); root.right=Node(7)
    print('Min:', find_min(root), 'Max:', find_max(root))
