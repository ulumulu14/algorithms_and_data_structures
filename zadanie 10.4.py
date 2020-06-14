#zadanie 10.4
import unittest

class emptyError(Exception):
    pass

class sizeError(Exception):
    pass

class Queue:

    def __init__(self, size):
        self.items = []
        self.s = size

    def __str__(self):             # podglądanie kolejki
        return str(self.items)

    def is_empty(self):
        return not self.items

    def is_full(self):
        if len(self.items) == self.s:
            return True
        else:
            return False

    def put(self, data):
        if Queue.is_full(self):
            raise sizeError("Kolejka przepelniona")
        else:
            self.items.append(data)

    def get(self):
        if Queue.is_empty(self):
            raise emptyError("Kolejka jest pusta")
        else:
            return self.items.pop(0)   # mało wydajne!


class TestQueue(unittest.TestCase):
    
    def setUp(self):
        self.q = Queue(2)
        Queue.put(self.q, 0)
        
    def test_print(self):
        self.assertEqual(str(self.q), "[0]")
        
    def test_is_full(self):
        self.assertFalse(Queue.is_full(self.q))
        
    def test_is_empty(self):
        self.assertFalse(Queue.is_empty(self.q))
        
    def test_put(self):
        Queue.put(self.q, 1)
        self.assertEqual(str(self.q), "[0, 1]")
        with self.assertRaises(sizeError):
            Queue.put(self.q, 2)
            
    def test_get(self):
        self.assertEqual(Queue.get(self.q), 0)
        with self.assertRaises(emptyError):
            Queue.get(self.q)

if __name__ == '__main__':
    unittest.main()     # włącza wszystkie testy
