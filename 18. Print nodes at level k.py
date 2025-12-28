class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def print_level_k(root,k):
    if not root: return
    if k==0:
        print(root.data, end=' ')
        return
    print_level_k(root.left,k-1); print_level_k(root.right,k-1)

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Nodes at level 2:', end=' ')
    print_level_k(root,2); print()
