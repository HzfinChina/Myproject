import random
setnum = random.randint(0,100)
while True:
    inputnum = int(input("Input the num"))
    if inputnum > setnum:
        print("猜大了！")
        continue
    elif inputnum < setnum:
        print("猜小了！")
        continue
    elif inputnum == setnum:
        print("猜对了！")
        break
    else:
        print("错误输入！")
        continue
