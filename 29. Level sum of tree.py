from collections import deque
class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def level_sum(root):
    if not root: return []
    q=deque([root])
    res=[]
    while q:
        sz=len(q); s=0
        for _ in range(sz):
            cur=q.popleft(); s+=cur.data
            if cur.left: q.append(cur.left)
            if cur.right: q.append(cur.right)
        res.append(s)
    return res

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print(level_sum(root))
