"""
Task: Level order traversal (BFS)
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import deque
class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def level_order(root):
    if not root: return
    q=deque([root])
    while q:
        cur=q.popleft(); print(cur.data, end=' ')
        if cur.left: q.append(cur.left)
        if cur.right: q.append(cur.right)
    print()

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Level order:', end=' ')
    level_order(root)
