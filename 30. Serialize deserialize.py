class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

"""
Task: Serialize and deserialize a binary tree
Time Complexity: O(n)
Space Complexity: O(n)
"""

def serialize(root):
    res=[]
    def helper(node):
        if not node:
            res.append('#')
            return
        res.append(str(node.data))
        helper(node.left); helper(node.right)
    helper(root)
    return ' '.join(res)

def deserialize(s):
    vals=iter(s.split())
    def helper():
        val=next(vals)
        if val=='#': return None
        node=Node(int(val))
        node.left=helper()
        node.right=helper()
        return node
    return helper()

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4)
    s=serialize(root)
    print('Serialized:', s)
    r=deserialize(s)
    print('Deserialized root:', r.data if r else None)
