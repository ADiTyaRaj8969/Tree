class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def diameter_util(root):
    if not root: return (0,0) # height, diameter
    lh, ld = diameter_util(root.left)
    rh, rd = diameter_util(root.right)
    height = 1 + max(lh, rh)
    diam = max(lh+rh+1, max(ld, rd))
    return (height, diam)

def diameter(root):
    return diameter_util(root)[1]

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Diameter:', diameter(root))
