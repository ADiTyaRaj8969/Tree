"""
Task: Create and print Binary Tree
Time Complexity: O(n)
Space Complexity: O(n)
"""

from collections import deque

class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None


def build_level_order(vals):
    if not vals: return None
    it=iter(vals)
    root=Node(next(it))
    q=deque([root])
    for v in it:
        cur=q[0]
        if v is not None:
            node=Node(v); cur.left=node; q.append(node)
        else:
            cur.left=None
        try:
            v2=next(it)
        except StopIteration:
            break
        if v2 is not None:
            node=Node(v2); cur.right=node; q.append(node)
        else:
            cur.right=None
        q.popleft()
    return root


def print_level_order(root):
    if not root: return
    q=deque([root])
    while q:
        cur=q.popleft()
        print(cur.data, end=' ')
        if cur.left: q.append(cur.left)
        if cur.right: q.append(cur.right)
    print()

if __name__=='__main__':
    vals=[1,2,3,4,5,None,7]
    root=build_level_order(vals)
    print('Level order print:', end=' ')
    print_level_order(root)

# Task: Create and print Binary Tree
# Time Complexity: O(n)
# Space Complexity: O(n)
