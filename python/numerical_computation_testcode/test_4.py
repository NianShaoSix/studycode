import numpy as np
from scipy.linalg import hilbert
import matplotlib.pyplot as plt

# 增强稳定性的雅可比迭代（带正则化和解约束）
def stabilized_jacobi(A, b, max_iter=5000, tol=1e-6, 
                     eps_scale=1e-12, lambda_reg=1e-10):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))
    for k in range(max_iter):
        x_new = np.zeros(n)
        valid = True
        
        for i in range(n):
            # 正则化处理：给对角线添加小扰动
            denominator = A[i, i] + lambda_reg * np.sign(A[i, i]) * eps
            # 安全计算分子
            sigma = np.dot(A[i, :], x) - (A[i, i] * x[i])
            numerator = b[i] - sigma
            
            # 分子分母范围约束
            if abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
            if abs(denominator) < 1e-300:
                denominator = np.sign(denominator) * 1e-300
                
            x_new[i] = numerator / denominator
            
            # 解向量约束：截断到合理范围
            if abs(x_new[i]) > 1e50:
                x_new[i] = np.sign(x_new[i]) * 1e50
                valid = False
        
        # 安全计算残差（避免直接相减）
        residual = np.max(np.abs(A @ x_new - b)) / (np.linalg.norm(A, ord=np.inf) + 1e-300)
        
        if residual < tol or not valid:
            break
        x = x_new.copy()
    return x_new, k+1

# 增强稳定性的SOR迭代（带自适应松弛因子）
def stabilized_sor(A, b, omega_init=1.2, max_iter=5000, tol=1e-6, 
                  eps_scale=1e-12, lambda_reg=1e-10):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))
    omega = omega_init
    for k in range(max_iter):
        x_prev = x.copy()
        valid = True
        max_delta = 0
        
        for i in range(n):
            # 正则化处理
            denominator = A[i, i] + lambda_reg * np.sign(A[i, i]) * eps
            sigma = np.dot(A[i, :i], x[:i]) + np.dot(A[i, i+1:], x[i+1:])
            numerator = b[i] - sigma
            
            # 数值安全处理
            if abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
            if abs(denominator) < 1e-300:
                denominator = np.sign(denominator) * 1e-300
                
            new_val = (1 - omega) * x_prev[i] + omega * numerator / denominator
            
            # 自适应调整松弛因子
            delta = abs(new_val - x_prev[i])
            if delta > max_delta:
                max_delta = delta
                
            # 解约束
            if abs(new_val) > 1e50:
                new_val = np.sign(new_val) * 1e50
                valid = False
            x[i] = new_val
        
        # 根据最大变化调整omega
        if max_delta > 1e-5:  # 变化过大时降低omega
            omega = max(omega * 0.9, 0.1)
        elif max_delta < 1e-10:  # 变化过小时增加omega
            omega = min(omega * 1.1, 2.0)
            
        # 安全残差计算
        residual = np.linalg.norm(A @ x - b, ord=np.inf) / (np.linalg.norm(b, ord=np.inf) + 1e-300)
        if residual < tol or not valid:
            break
    return x, k+1

n_values = list(range(6, 31))
methods = ['Gauss', 'Jacobi', 'SOR']
norms = ['1-norm', '2-norm', '∞-norm']
results = {method: {norm: [] for norm in norms} for method in methods}

for n in n_values:
    H = hilbert(n).astype(np.float64)
    x_true = np.ones(n)
    b = H @ x_true
    
    # 高斯消去法（添加条件数检查）
    try:
        cond_num = np.linalg.cond(H)
        if cond_num > 1e15:  # 条件数过大时跳过
            raise np.linalg.LinAlgError
        x_gauss = np.linalg.solve(H, b)
        error = x_gauss - x_true
        results['Gauss']['1-norm'].append(np.linalg.norm(error, 1))
        results['Gauss']['2-norm'].append(np.linalg.norm(error, 2))
        results['Gauss']['∞-norm'].append(np.linalg.norm(error, np.inf))
    except np.linalg.LinAlgError:
        for norm in norms:
            results['Gauss'][norm].append(np.nan)
    
    # 增强雅可比迭代
    x_jacobi, iter_jacobi = stabilized_jacobi(H, b)
    if iter_jacobi >= 5000 or np.any(np.isnan(x_jacobi)):
        for norm in norms:
            results['Jacobi'][norm].append(np.nan)
    else:
        error_jacobi = x_jacobi - x_true
        results['Jacobi']['1-norm'].append(np.linalg.norm(error_jacobi, 1))
        results['Jacobi']['2-norm'].append(np.linalg.norm(error_jacobi, 2))
        results['Jacobi']['∞-norm'].append(np.linalg.norm(error_jacobi, np.inf))
    
    # 增强SOR迭代
    x_sor, iter_sor = stabilized_sor(H, b)
    if iter_sor >= 5000 or np.any(np.isnan(x_sor)):
        for norm in norms:
            results['SOR'][norm].append(np.nan)
    else:
        error_sor = x_sor - x_true
        results['SOR']['1-norm'].append(np.linalg.norm(error_sor, 1))
        results['SOR']['2-norm'].append(np.linalg.norm(error_sor, 2))
        results['SOR']['∞-norm'].append(np.linalg.norm(error_sor, np.inf))

# 绘图时添加异常值过滤
for method in methods:
    plt.figure(figsize=(10, 6))
    for norm in norms:
        clean_n = []
        clean_errors = []
        for n_val, err in zip(n_values, results[method][norm]):
            if not np.isnan(err) and err < 1e100:  # 过滤异常值
                clean_n.append(n_val)
                clean_errors.append(err)
        plt.semilogy(clean_n, clean_errors, 'o-', label=norm)
    plt.title(f'Stabilized {method} Method Error Norms (n=6-30)')
    plt.xlabel('Matrix Dimension (n)')
    plt.ylabel('Error Norm (log scale)')
    plt.grid(True, which='both', ls='--')
    plt.legend()
    plt.savefig(f'stabilized_{method}_error.png', dpi=300)
    plt.close()