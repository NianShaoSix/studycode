#长方体的面积和体积计算
length = eval(input("请输入长方体的长："))
width = eval(input("请输入长方体的宽："))
height = eval(input("请输入长方体的高："))

area = 2*(length * width + length * height + width * height)
volume = length * width * height

print(f"长方体的面积为：{area:.2f}")
print(f"长方体的体积为：{volume:.2f}")