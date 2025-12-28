"""
Task: Check valid BST
Time Complexity: O(n)
Space Complexity: O(h)
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def is_bst_util(root,minv,maxv):
    if not root: return True
    if root.data<=minv or root.data>=maxv: return False
    return is_bst_util(root.left,minv,root.data) and is_bst_util(root.right,root.data,maxv)

if __name__=='__main__':
    root=Node(2); root.left=Node(1); root.right=Node(3)
    print('BST' if is_bst_util(root,float('-inf'), float('inf')) else 'Not BST')
