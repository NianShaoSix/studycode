import numpy as np
from scipy.linalg import hilbert

n = 6
H = hilbert(n)  # 生成Hilbert矩阵
cond_num = np.linalg.cond(H, 2)  # 计算2-范数条件数
print(f"条件数（2-范数）: {cond_num:.2e}")

x_true = np.ones(n)
b = H @ x_true

x_gauss = np.linalg.solve(H, b)
error_gauss = x_gauss - x_true