import matplotlib.pyplot as plt
import numpy as np

# 定义一个函数来绘制圆
def draw_circle(center_x, center_y, radius, color='blue'):
    theta = np.linspace(0, 2 * np.pi, 100)  # 参数方程的角度
    x = center_x + radius * np.cos(theta)  # 圆的x坐标
    y = center_y + radius * np.sin(theta)  # 圆的y坐标
    plt.plot(x, y, color=color, label=f"Center: ({center_x}, {center_y})")

# 设置图形
plt.figure(figsize=(6, 6))
plt.title("Three Circles with a Common Intersection Point")
plt.grid(True)
plt.axis("equal")  # 保持比例

# 绘制三个圆，使它们共享一个公共交点
draw_circle(center_x=0, center_y=2, radius=2, color='blue')  # 圆1
draw_circle(center_x=0, center_y=-2, radius=2, color='red')  # 圆2
draw_circle(center_x=2, center_y=0, radius=2, color='green')  # 圆3

# 标记公共交点
plt.plot(0, 0, 'ko')  # 黑色点表示公共交点
plt.text(0, 0, "Common Point", fontsize=10, ha="right")

# 添加图例
plt.legend()

# 显示图形
plt.show()