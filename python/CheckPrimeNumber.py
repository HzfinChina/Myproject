checknum = int(input("Please input a num"))
end = int(checknum ** 0.5)
flag = True
for i in range(2, end):
    if checknum % i == 0:
        flag = False
    if checknum %i != 0:
        continue
if flag :
    print("It's a prime number")
else :
    print("It's not a prime number")
    
