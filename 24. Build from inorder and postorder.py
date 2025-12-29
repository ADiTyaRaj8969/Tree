class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def build_in_post(inorder, postorder):
    idx={v:i for i,v in enumerate(inorder)}
    pIndex=len(postorder)-1
    def helper(l,r):
        nonlocal pIndex
        if l>r: return None
        rootVal=postorder[pIndex]; pIndex-=1
        root=Node(rootVal)
        inIdx=idx[rootVal]
        root.right=helper(inIdx+1,r)
        root.left=helper(l,inIdx-1)
        return root
    return helper(0,len(inorder)-1)

def inorder(root):
    if not root: return
    inorder(root.left); print(root.data, end=' '); inorder(root.right)

if __name__=='__main__':
    inorder_list=[4,2,5,1,3]; post=[4,5,2,3,1]
    root=build_in_post(inorder_list, post)
    inorder(root); print()
