import numpy as np
from scipy.linalg import hilbert

n = 6
H = hilbert(n)  # 生成Hilbert矩阵
cond_num = np.linalg.cond(H, 2)  # 计算2-范数条件数
print(f"条件数（2-范数）: {cond_num:.2e}")