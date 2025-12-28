from collections import deque
class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def right_view(root):
    if not root: return
    q=deque([root])
    while q:
        sz=len(q)
        for i in range(sz):
            cur=q.popleft()
            if i==sz-1: print(cur.data, end=' ')
            if cur.left: q.append(cur.left)
            if cur.right: q.append(cur.right)
    print()

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Right view:', end=' '); right_view(root)
