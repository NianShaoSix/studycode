import numpy as np
from scipy.linalg import hilbert
import matplotlib.pyplot as plt

# --------------------- 改进的Jacobi迭代法 ---------------------
def stabilized_jacobi(A, b, max_iter=5000, tol=1e-6, eps_scale=1e-12):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))  # 动态设置极小值阈值
    for k in range(max_iter):
        x_new = np.zeros(n)
        valid = True
        for i in range(n):
            # 计算分子和分母（含正则化）
            sigma = np.dot(A[i, :], x) - A[i, i] * x[i]
            numerator = b[i] - sigma
            denominator = A[i, i]
            
            # 分母截断保护
            if np.abs(denominator) < eps:
                denominator = eps * (1 if denominator >= 0 else -1)
            
            # 分子截断保护
            if np.abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
                valid = False
            
            x_new[i] = numerator / denominator
            
            # 解向量范围约束
            if np.abs(x_new[i]) > 1e50 or not np.isfinite(x_new[i]):
                valid = False
                break
        
        # 检查迭代有效性
        if not valid:
            return np.full(n, np.nan), k+1
        
        # 计算残差（相对误差）
        residual = np.linalg.norm(A @ x_new - b, np.inf) / (np.linalg.norm(b, np.inf) + 1e-300)
        if residual < tol:
            break
        x = x_new.copy()
    return x_new, k+1

# --------------------- 改进的SOR迭代法 ---------------------
def stabilized_sor(A, b, omega_init=1.2, max_iter=5000, tol=1e-6, eps_scale=1e-12):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))
    omega = omega_init
    for k in range(max_iter):
        x_prev = x.copy()
        valid = True
        max_delta = 0.0
        
        for i in range(n):
            # 计算分子和分母（含正则化）
            sigma = np.dot(A[i, :i], x[:i]) + np.dot(A[i, i+1:], x[i+1:])
            numerator = b[i] - sigma
            denominator = A[i, i]
            
            # 分母截断保护
            if np.abs(denominator) < eps:
                denominator = eps * (1 if denominator >= 0 else -1)
            
            # 分子截断保护
            if np.abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
                valid = False
            
            # 更新解分量
            new_val = (1 - omega) * x_prev[i] + omega * numerator / denominator
            
            # 解向量范围约束
            if np.abs(new_val) > 1e50 or not np.isfinite(new_val):
                valid = False
                break
            x[i] = new_val
            
            # 记录最大变化量（用于调整omega）
            delta = np.abs(new_val - x_prev[i])
            if delta > max_delta:
                max_delta = delta
        
        # 自适应调整松弛因子
        if max_delta > 1e-5:  # 变化过大时降低omega
            omega = max(omega * 0.9, 0.1)
        elif max_delta < 1e-10:  # 变化过小时增加omega
            omega = min(omega * 1.1, 2.0)
        
        # 检查迭代有效性
        if not valid:
            break
        
        # 计算残差（相对误差）
        residual = np.linalg.norm(A @ x - b, np.inf) / (np.linalg.norm(b, np.inf) + 1e-300)
        if residual < tol:
            break
    return x, k+1

# --------------------- 主程序 ---------------------
n_values = range(6, 31)
methods = ['Gauss', 'Jacobi', 'SOR']
norms = ['1-norm', '2-norm', '∞-norm']
results = {method: {norm: [] for norm in norms} for method in methods}

for n in n_values:
    H = hilbert(n).astype(np.float64)  # 强制双精度
    x_true = np.ones(n)
    b = H @ x_true
    
    # --------------------- 高斯消去法 ---------------------
    try:
        # 条件数过大时跳过（避免无效解）
        if np.linalg.cond(H) > 1e16:
            raise np.linalg.LinAlgError
        x_gauss = np.linalg.solve(H, b)
        error = x_gauss - x_true
        results['Gauss']['1-norm'].append(np.linalg.norm(error, 1))
        results['Gauss']['2-norm'].append(np.linalg.norm(error, 2))
        results['Gauss']['∞-norm'].append(np.linalg.norm(error, np.inf))
    except np.linalg.LinAlgError:
        for norm in norms:
            results['Gauss'][norm].append(np.nan)
    
    # --------------------- Jacobi迭代法 ---------------------
    x_jacobi, iter_jacobi = stabilized_jacobi(H, b)
    if iter_jacobi >= 5000 or np.any(np.isnan(x_jacobi)):
        for norm in norms:
            results['Jacobi'][norm].append(np.nan)
    else:
        error_jacobi = x_jacobi - x_true
        results['Jacobi']['1-norm'].append(np.linalg.norm(error_jacobi, 1))
        results['Jacobi']['2-norm'].append(np.linalg.norm(error_jacobi, 2))
        results['Jacobi']['∞-norm'].append(np.linalg.norm(error_jacobi, np.inf))
    
    # --------------------- SOR迭代法 ---------------------
    x_sor, iter_sor = stabilized_sor(H, b)
    if iter_sor >= 5000 or np.any(np.isnan(x_sor)):
        for norm in norms:
            results['SOR'][norm].append(np.nan)
    else:
        error_sor = x_sor - x_true
        results['SOR']['1-norm'].append(np.linalg.norm(error_sor, 1))
        results['SOR']['2-norm'].append(np.linalg.norm(error_sor, 2))
        results['SOR']['∞-norm'].append(np.linalg.norm(error_sor, np.inf))

# --------------------- 绘图 ---------------------
for method in methods:
    plt.figure(figsize=(10, 6))
    for norm in norms:
        # 过滤NaN和异常值（误差超过1e50视为无效）
        clean_n = []
        clean_errors = []
        for n_val, err in zip(n_values, results[method][norm]):
            if not np.isnan(err) and err < 1e50:
                clean_n.append(n_val)
                clean_errors.append(err)
        plt.semilogy(clean_n, clean_errors, 'o-', label=norm)
    
    plt.title(f'Stabilized {method} Method Error Norms (n=6-30)')
    plt.xlabel('Matrix Dimension (n)')
    plt.ylabel('Error Norm (log scale)')
    plt.grid(True, which='both', linestyle='--')
    plt.legend()
    plt.savefig(f'stabilized_{method}_error.png', dpi=300)
    plt.close()

print("图像已保存为 stabilized_Gauss_error.png, stabilized_Jacobi_error.png, stabilized_SOR_error.png")