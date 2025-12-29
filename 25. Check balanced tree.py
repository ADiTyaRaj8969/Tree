class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def is_balanced(root):
    def helper(node):
        if not node: return 0
        lh=helper(node.left)
        if lh==-1: return -1
        rh=helper(node.right)
        if rh==-1: return -1
        if abs(lh-rh)>1: return -1
        return 1+max(lh,rh)
    return helper(root)!=-1

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.left.left=Node(3)
    print('Balanced' if is_balanced(root) else 'Not Balanced')
