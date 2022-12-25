a = float(input("输入a"))
b = float(input("输入b"))
c = float(input("输入c"))
if a + b > c and b + c > a and a + c > b:
    p = (a + b + c)/2
    s = (p*(p-a)*(p-b)*(p-c)) ** 0.5
    print("面积是：%f" %s)
else:
    print ("不能构成三角形！")
