class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def print_paths(root):
    def helper(node,path):
        if not node: return
        path.append(node.data)
        if not node.left and not node.right:
            print(' '.join(map(str,path)))
        else:
            helper(node.left,path); helper(node.right,path)
        path.pop()
    helper(root,[])

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print_paths(root)
