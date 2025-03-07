import numpy as np
import matplotlib.pyplot as plt

#定义原函数
def f(x):
    return 1/(1 + 25 * x**2)

# 生成密集点采样点用于绘图
x_fine = np.linspace(-1 , 1 , 1000)
y_true = f(x_fine)

# 实验分段数
n_value = range(1,11) #实验要求的n从1->10

plt.figure(figsize=(15,15)) #初始化绘制窗口

for idx,n in enumerate(n_value):
    #生成插值节点
    n_node = n + 1
    x_nodes = np.linspace(-1 , 1 , n_node)
    y_nodes = f(x_nodes)

    #多项式插值 n次多项式
    poly_coeffs = np.polyfit(x_nodes, y_nodes, n) #存放多项式的系数，从高次到低次
    y_poly = np.polyval(poly_coeffs, x_fine)

    #绘制子图
    plt.subplot(5, 2, idx + 1)
    plt.plot(x_fine, y_true, '--',label='Ture Function', linewidth=2,color='black')
    plt.plot(x_fine, y_poly, label=f'Polynomial (n={n})', color='blue', alpha=0.7)
    plt.scatter(x_nodes, y_nodes, color='green', s=30, zorder=3, label='Nodes')
    plt.ylim(-1.5, 1.5)  # 固定y轴范围以观察震荡
    plt.legend(loc='upper right')
    plt.title(f'Segments = {n}')

    plt.tight_layout()
    plt.show()