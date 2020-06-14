#zadanie 10.8

class RandomQueue:

    def __init__(self):
        self.items = set()
        #self.items = []

    def __str__(self):
        return str(self.items)
    
    def insert(self, item):
        self.items.add(item)

    def remove(self):   # zwraca losowy element
        return self.items.pop()
    
    def is_empty(self):
        if not self.items:
            return True
        else:
            return False

    def is_full(self):
        return False
