class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def build_in_pre(inorder, preorder):
    idx={v:i for i,v in enumerate(inorder)}
    pIndex=0
    def helper(l,r):
        nonlocal pIndex
        if l>r: return None
        rootVal=preorder[pIndex]; pIndex+=1
        root=Node(rootVal)
        inIdx=idx[rootVal]
        root.left=helper(l,inIdx-1)
        root.right=helper(inIdx+1,r)
        return root
    return helper(0,len(inorder)-1)

def inorder(root):
    if not root: return
    inorder(root.left); print(root.data, end=' '); inorder(root.right)

if __name__=='__main__':
    inorder_list=[4,2,5,1,3]
    preorder=[1,2,4,5,3]
    root=build_in_pre(inorder_list, preorder)
    inorder(root); print()
