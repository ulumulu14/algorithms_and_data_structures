#zadanie 9.2


class Node:
    """Klasa reprezentująca węzeł listy jednokierunkowej."""

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next

    def __str__(self):
        return str(self.data)   # bardzo ogólnie
    
    def print_list(node):

        while node:
            print (node)
            node = node.next
            
    def reverse_list(node):   # zwraca nowy head
        before = None
        after = node
        while after:
            node = after.next
            after.next = before
            before = after
            after = node
        return before

    def merge(node1, node2):
        head = node1
        node = node1
        
        while node.next:
            node = node.next

        node.next = node2

        return head


head1 = None                   
head1 = Node(3, head1)         
head1 = Node(2, head1)         
head1 = Node(4, head1)

head2 = None                  
head2 = Node(5, head2)          
head2 = Node(6, head2)          
head2 = Node(7, head2)

head3 = Node.merge(head1, head2)
Node.print_list(head3)
