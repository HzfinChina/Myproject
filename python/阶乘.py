def factorial(x):
    sum = 1
    for _ in range(x):
        sum *= x
        x -= 1
    return sum 
