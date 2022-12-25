length = float(input("请输入长度"))
unit = input("请输入单位")
if unit == "in":
    print("%f英寸 = %f厘米"%(length, length / 0.3937))
elif unit == "cm":
    print("%f厘米 = %f英寸"%(length, length * 0.3937))
else:
    print("请输入正确的单位")
