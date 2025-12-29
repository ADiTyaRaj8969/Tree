from collections import deque
class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def zigzag(root):
    if not root: return
    curr=[root]
    left_to_right=True
    while curr:
        next_level=[]
        for node in curr[::-1]:
            print(node.data, end=' ')
            if left_to_right:
                if node.left: next_level.append(node.left)
                if node.right: next_level.append(node.right)
            else:
                if node.right: next_level.append(node.right)
                if node.left: next_level.append(node.left)
        left_to_right=not left_to_right
        curr=next_level
    print()

if __name__=='__main__':
    root=Node(1); root.left=Node(2); root.right=Node(3); root.left.left=Node(4); root.left.right=Node(5)
    print('Zigzag:', end=' '); zigzag(root)
