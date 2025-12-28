class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def lca(root,a,b):
    if not root: return None
    if root.data==a or root.data==b: return root
    l=lca(root.left,a,b)
    r=lca(root.right,a,b)
    if l and r: return root
    return l if l else r

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    res=lca(root,4,5)
    print('LCA:', res.data if res else None)
