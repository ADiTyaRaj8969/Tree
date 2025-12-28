"""
Task: Search in BST
Time Complexity: O(h)
Space Complexity: O(h) — recursion stack
"""

class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def search_bst(root,key):
    if not root: return False
    if root.data==key: return True
    if key<root.data: return search_bst(root.left,key)
    return search_bst(root.right,key)

if __name__=='__main__':
    root=Node(5); root.left=Node(3); root.right=Node(7)
    print('Search 3:', 'Found' if search_bst(root,3) else 'Not Found')
    print('Search 6:', 'Found' if search_bst(root,6) else 'Not Found')
