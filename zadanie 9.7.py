
#zadanie 9.7

class Node:

    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.data)

    def count_leafs(top):
        if top is None:
            return 0
        if (top.left == None) and (top.right == None):
            return 1
        else:
            return  Node.count_leafs(top.left) + Node.count_leafs(top.right)
        
    def count_total(top):
        if top is None:
            return 0
        return top.data + Node.count_total(top.left) + Node.count_total(top.right)


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
root.left.left.left = Node(8)
root.left.left.right = Node(9)
root.left.right.left = Node(10)
root.left.right.right = Node(11)
root.right.left.left = Node(12)
root.right.left.right = Node(13)
root.right.right.left = Node(14)
root.right.right.right = Node(15)


print(Node.count_leafs(root))
