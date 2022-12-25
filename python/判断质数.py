def is_prime(num : int) ->bool :
    for dinum in range(2, int(num ** (1/2) +1)):
        if num % dinum == 0:
            return False
    return True
print(is_prime(87))
