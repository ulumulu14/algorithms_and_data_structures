#Zadanie 4.2

def miarka(n):
    s = ""
    
    for i in range(n):
        s += "|...."
        
    s += "|\n"

    for i in range(n + 1):
        st = str(i)
        s += st
        
        for j in range(5 - len(st)):
            s +=  " "

    return s

def prostokat(k, w):
    s = ""
    
    for i in range(k):
        for j in range(w):
            s += "+---"
            
        s += "+\n"
        
        for j in range(w):
            s += "|   "
            
        s += "|\n"
        
    for i in range(w):
        s += "+---"
        
    s += "+\n"

    return s
