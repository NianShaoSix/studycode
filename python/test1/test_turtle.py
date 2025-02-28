print("计算长方形的面积和体积")
print("输入长方形的长： ")
length = float(input())
print("输入长方形的宽：")
width = float(input())
print("输入长方形的高：")
hight = float(input())

area = 2 *(length * width + length * hight + width * hight)
volume = length * width * hight
print("长方体的面积为：%f"%area)
print("长方形的体积为：%f"%volume)