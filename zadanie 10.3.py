#zadanie 10.3


class Stack:

    def __init__(self, size):
        self.items = []
        self.values = []
        for i in range(0, size):
            self.values.append(0)

    def __str__(self):                  # podglądamy stos
        return str(self.items)

    def is_empty(self):
        return not self.items

    def is_full(self):                  # nigdy nie jest pełny
        return False

    def push(self, item):
        if self.values[item] == 1:
            print("wartosc znajduje sie na stosie")
        else:
            self.items.append(item)         # dodajemy na koniec
            self.values[item] = 1

    def pop(self):                      # zwraca element
        rtrn = self.items.pop()
        self.values[rtrn] = 0
        return rtrn                     # zabieram od końca
