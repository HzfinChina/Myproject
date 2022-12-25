inputnum = int(input("input a num"))
reversed_num = 0
while True:
    reversed_num = reversed_num * 10 + inputnum % 10
    inputnum //= 10
    if inputnum == 0:
        break
print(reversed_num)
