import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.rcParams['axes.unicode_minus'] = False  # 显示负号

# 原始数据
x = np.array([-1.0, -0.5, 0.0, 0.5, 1.0, 1.5, 2.0])
y = np.array([-4.447, -0.452, 0.551, 0.048, -0.447, 0.549, 4.552])

# ========== 普通多项式拟合 ==========
coeff_standard = np.polyfit(x, y, 3)
p_standard = np.poly1d(coeff_standard)
error_standard = np.sum((y - p_standard(x))**2)

# ========== 正交多项式拟合 ==========
# 勒让德多项式基函数
def legendre_basis(n, x):
    if n == 0: return np.ones_like(x)
    if n == 1: return x
    return ((2*n-1)*x*legendre_basis(n-1,x) - (n-1)*legendre_basis(n-2,x))/n

# 构建设计矩阵
A = np.column_stack([legendre_basis(i,x) for i in range(4)])
coeff_orth, *_ = np.linalg.lstsq(A, y, rcond=None)
error_orth = np.sum((y - A@coeff_orth)**2)

# ========== 结果可视化 ==========
x_fit = np.linspace(-1, 2, 500)
plt.figure(figsize=(10, 6))

# 绘制原始数据
plt.scatter(x, y, s=80, facecolors='none', edgecolors='b', label='Data Points')

# 普通多项式拟合曲线
plt.plot(x_fit, p_standard(x_fit), 'r--',
         label=f'Standard Poly (Error: {error_standard:.4f})')

# 正交多项式拟合曲线
A_fit = np.column_stack([legendre_basis(i,x_fit) for i in range(4)])
plt.plot(x_fit, A_fit@coeff_orth, 'g-',
         label=f'Orthogonal Poly (Error: {error_orth:.4f})')

# 图表设置
plt.xlim(-1.2, 2.2)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Polynomial Fitting Comparison')
plt.show()

# 输出结果
print("Standard Coefficients:", coeff_standard.round(4))
print("Orthogonal Coefficients:", coeff_orth.round(4))
print(f"Standard Error: {error_standard:.6f}")
print(f"Orthogonal Error: {error_orth:.6f}")