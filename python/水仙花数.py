for i in range(1, 1000):
    bai = i // 100 #百位
    ten = (i - bai * 100) // 10#十位
    ge = (i - bai * 100 - ten * 10)
    if i == bai ** 3  + ten ** 3 + ge ** 3:
        print(i)
