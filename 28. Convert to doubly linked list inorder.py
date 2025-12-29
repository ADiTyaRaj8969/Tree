class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

prev_node=None

def b_to_dll(root):
    global prev_node
    if not root: return None
    head=b_to_dll(root.left)
    if prev_node is None:
        head=root
    else:
        prev_node.right=root; root.left=prev_node
    prev_node=root
    b_to_dll(root.right)
    return head

def print_dll(head):
    cur=head
    while cur:
        print(cur.data, end=' '); cur=cur.right
    print()

if __name__=='__main__':
    root=Node(10); root.left=Node(12); root.right=Node(15); root.left.left=Node(25); root.left.right=Node(30)
    head=b_to_dll(root)
    print_dll(head)
