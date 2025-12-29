class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def root_to_node(root,key):
    path=[]
    def helper(node):
        if not node: return False
        path.append(node.data)
        if node.data==key: return True
        if helper(node.left) or helper(node.right): return True
        path.pop()
        return False
    if helper(root): return path
    return None

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    print(root_to_node(root,4))
