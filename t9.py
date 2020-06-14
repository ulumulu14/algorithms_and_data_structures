import itertools

class TrieNode():
    """Węzeł drzewa Trie"""
    def __init__(self):
        self.children = {}
        self.isWordEnd = False

class Trie():

    def __init__(self):
        """Konstruktor"""
        self.root = TrieNode()

    def add(self, word):
        """Funkcja dodaje nowy węzeł"""
        node = self.root

        for letter in word:
            if letter not in node.children:
                node.children[letter] = TrieNode()
                
            node = node.children[letter]
            
        node.isWordEnd = True

    def search(self, word):
        """Funkcja wyszukuje podane słowo"""
        node = self.root

        for letter in word:
            if letter in node.children:
                node = node.children[letter]
            else:
                return False
            
        if node.isWordEnd:
            return True
        else:
            return False

    def learn(self, dictionary):
        """Funkcja tworzy drzewo na podstawie wprowadzonego słownika"""
        print("Wczytuje słownik: " + dictionary)
        
        dict = open(dictionary, "r").read().split('\n')

        for line in dict:
            self.add(line)

        print("Gotowe")

def combos(input):
    """Funkcja generuje wszystkie kombinacje liter na podstawie wprowadzonych cyfr"""
    digits = str(input)
    inputChars = []
    strings = []
    
    mapping = {'2': ['a', 'b', 'c'],
               '3': ['d', 'e', 'f'],
               '4': ['g', 'h', 'i'],
               '5': ['j', 'k', 'l'],
               '6': ['m', 'n', 'o'],
               '7': ['p', 'r', 's'],
               '8': ['t', 'u', 'v'],
               '9': ['w', 'x', 'y', 'z']}

    for digit in digits:
        inputChars.append(mapping[digit])

    combos = list(itertools.product(*inputChars))

    for combo in combos:
        strings.append(''.join(combo))

    return strings

def predict(dictionary, words):
    """Funkcja wyszukuje możliwe kombinacje w słowniku i zwraca te, które sie tam znajdują"""
    predictedWords = []
    
    for word in words:
        if dictionary.search(word):
            predictedWords.append(word)
                
    return predictedWords




trie = Trie()

trie.learn("english_dictionary.txt")

#Odkomentować tą część kodu aby ręcznie wprowadzić kombinacje cyfr
#while True:
#    x = input("Wpisz cyfry:")
#    print(predict(trie, combos(x)))

import unittest

class TestT9(unittest.TestCase):


    def test_search(self):
        self.assertEqual(trie.search("python"), True)
        
    def test_add(self):
        trie.add("słowo")
        self.assertEqual(trie.search("słowo"), True)

    def test_combos(self):
        self.assertEqual(combos(22), ['aa', 'ab', 'ac', 'ba', 'bb', 'bc', 'ca', 'cb', 'cc'])

    def test_predict(self):
        self.assertEqual(predict(trie, combos(9455)), ['wilk', 'will', 'yill', 'zill'])



if __name__ == '__main__':
    unittest.main()
