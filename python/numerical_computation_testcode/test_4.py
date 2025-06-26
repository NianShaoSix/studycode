import numpy as np
from scipy.linalg import hilbert
import matplotlib.pyplot as plt

# --- 增强 Jacobi 迭代 ---
def stabilized_jacobi(A, b, max_iter=5000, tol=1e-8, eps_scale=1e-12, lambda_reg=1e-10):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))
    for k in range(max_iter):
        x_new = np.zeros(n)
        valid = True
        for i in range(n):
            denominator = A[i, i] + lambda_reg * np.sign(A[i, i]) * eps
            sigma = np.dot(A[i, :], x) - A[i, i] * x[i]
            numerator = b[i] - sigma
            if abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
            if abs(denominator) < 1e-300:
                denominator = np.sign(denominator) * 1e-300
            x_new[i] = numerator / denominator
            if not np.isfinite(x_new[i]) or abs(x_new[i]) > 1e50:
                valid = False
                break
        residual = np.max(np.abs(A @ x_new - b)) / (np.linalg.norm(b, ord=np.inf) + 1e-300)
        if residual < tol or not valid:
            break
        x = x_new.copy()
    return x_new, k + 1

# --- 增强 SOR 迭代 ---
def stabilized_sor(A, b, omega_init=1.2, max_iter=5000, tol=1e-8, eps_scale=1e-12, lambda_reg=1e-10):
    n = len(b)
    x = np.zeros(n)
    eps = eps_scale * np.max(np.abs(A))
    omega = omega_init
    for k in range(max_iter):
        x_prev = x.copy()
        valid = True
        max_delta = 0
        for i in range(n):
            denominator = A[i, i] + lambda_reg * np.sign(A[i, i]) * eps
            sigma = np.dot(A[i, :i], x[:i]) + np.dot(A[i, i+1:], x[i+1:])
            numerator = b[i] - sigma
            if abs(numerator) > 1e100:
                numerator = np.sign(numerator) * 1e100
            if abs(denominator) < 1e-300:
                denominator = np.sign(denominator) * 1e-300
            new_val = (1 - omega) * x_prev[i] + omega * numerator / denominator
            delta = abs(new_val - x_prev[i])
            if delta > max_delta:
                max_delta = delta
            if not np.isfinite(new_val) or abs(new_val) > 1e50:
                valid = False
                break
            x[i] = new_val
        if max_delta > 1e-5:
            omega = max(omega * 0.9, 0.1)
        elif max_delta < 1e-10:
            omega = min(omega * 1.1, 2.0)
        residual = np.linalg.norm(A @ x - b, ord=np.inf) / (np.linalg.norm(b, ord=np.inf) + 1e-300)
        if residual < tol or not valid:
            break
    return x, k + 1

# --- 主程序 ---
n_values = list(range(6, 31))
methods = ['Gauss', 'Jacobi', 'SOR']
norms = ['1-norm', '2-norm', '∞-norm']
results = {method: {norm: [] for norm in norms} for method in methods}
iterations = {'Jacobi': [], 'SOR': []}

for n in n_values:
    H = hilbert(n).astype(np.float64)
    x_true = np.ones(n)
    b = H @ x_true

    # Gauss
    try:
        cond_num = np.linalg.cond(H)
        if cond_num > 1e20:
            raise np.linalg.LinAlgError
        x_gauss = np.linalg.solve(H, b)
        error = x_gauss - x_true
        results['Gauss']['1-norm'].append(np.linalg.norm(error, 1))
        results['Gauss']['2-norm'].append(np.linalg.norm(error, 2))
        results['Gauss']['∞-norm'].append(np.linalg.norm(error, np.inf))
    except np.linalg.LinAlgError:
        for norm in norms:
            results['Gauss'][norm].append(np.nan)

    # Jacobi
    x_jacobi, iter_jacobi = stabilized_jacobi(H, b)
    iterations['Jacobi'].append(iter_jacobi)
    if iter_jacobi >= 5000 or np.any(np.isnan(x_jacobi)):
        for norm in norms:
            results['Jacobi'][norm].append(np.nan)
    else:
        error_jacobi = x_jacobi - x_true
        results['Jacobi']['1-norm'].append(np.linalg.norm(error_jacobi, 1))
        results['Jacobi']['2-norm'].append(np.linalg.norm(error_jacobi, 2))
        results['Jacobi']['∞-norm'].append(np.linalg.norm(error_jacobi, np.inf))

    # SOR
    x_sor, iter_sor = stabilized_sor(H, b)
    iterations['SOR'].append(iter_sor)
    if iter_sor >= 5000 or np.any(np.isnan(x_sor)):
        for norm in norms:
            results['SOR'][norm].append(np.nan)
    else:
        error_sor = x_sor - x_true
        results['SOR']['1-norm'].append(np.linalg.norm(error_sor, 1))
        results['SOR']['2-norm'].append(np.linalg.norm(error_sor, 2))
        results['SOR']['∞-norm'].append(np.linalg.norm(error_sor, np.inf))

# --- 绘图 ---
for method in methods:
    plt.figure(figsize=(10, 6))
    for norm in norms:
        clean_n = []
        clean_errors = []
        for n_val, err in zip(n_values, results[method][norm]):
            if not np.isnan(err) and err < 1e50:
                clean_n.append(n_val)
                clean_errors.append(err)
        plt.semilogy(clean_n, clean_errors, 'o-', label=norm)
    plt.title(f'{method} Method Error Norms (n=6–30)')
    plt.xlabel('Matrix Dimension (n)')
    plt.ylabel('Error Norm (log scale)')
    plt.grid(True, which='both', ls='--')
    plt.legend()
    plt.savefig(f'stabilized_{method}_error.png', dpi=300)
    plt.close()

# --- 迭代次数绘图 ---
plt.figure(figsize=(10, 6))
for method in ['Jacobi', 'SOR']:
    plt.plot(n_values, iterations[method], 'o-', label=f'{method} Iterations')
plt.title('Iterations vs Matrix Size (n=6–30)')
plt.xlabel('Matrix Dimension (n)')
plt.ylabel('Iterations')
plt.grid(True, ls='--')
plt.legend()
plt.savefig('iterations_plot.png', dpi=300)
plt.close()

print("所有图像保存完毕：")
print("- stabilized_Gauss_error.png")
print("- stabilized_Jacobi_error.png")
print("- stabilized_SOR_error.png")
print("- iterations_plot.png")
