#zadanie 4.7

def flatten(sequence):
    retrn = []
    
    for item in sequence:
        if isinstance(item, (list, tuple)):
            retrn.extend(flatten(item))
        else:
            retrn.append(item)

    return retrn
