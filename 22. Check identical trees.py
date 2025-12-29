class Node:
    def __init__(self,data): self.data=data; self.left=None; self.right=None

def identical(a,b):
    if not a and not b: return True
    if not a or not b: return False
    return a.data==b.data and identical(a.left,b.left) and identical(a.right,b.right)

if __name__=='__main__':
    a=Node(1); a.left=Node(2); a.right=Node(3)
    b=Node(1); b.left=Node(2); b.right=Node(3)
    print('Identical' if identical(a,b) else 'Not Identical')
