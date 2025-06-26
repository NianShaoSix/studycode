import numpy as np
import time
import matplotlib.pyplot as plt

# ====================== 定义非线性方程组及其雅可比矩阵 ======================

# 方程组1: 3个方程
def F1(x):
    return np.array([
        12 * x[0] - x[1]**2 - 4 * x[2] - 7,       # 方程1
        x[0]**2 + 10 * x[1] - x[2] - 11,          # 方程2
        x[1]**3 + 10 * x[2] - 8                   # 方程3
    ])

def J1(x):
    return np.array([
        [12,           -2 * x[1],          -4       ],  # 方程1的雅可比行
        [2 * x[0],      10,                -1       ],  # 方程2的雅可比行
        [0,             3 * x[1]**2,        10      ]   # 方程3的雅可比行
    ])

# 方程组2: 修正第三个方程变量为x[2]
def F2(x):
    return np.array([
        3 * x[0] - np.cos(x[1] * x[2]) - 0.5,                  # 方程1
        x[0]**2 - 81 * (x[1] + 0.1)**2 + np.sin(x[2]) + 1.06,  # 方程2
        np.e **(- (x[0] * x[1])) + 20 * x[2] + (10 * np.pi - 3)/3    # 方程3
    ])

def J2(x):
    return np.array([
        [3, x[2] * np.sin(x[1] * x[2]), x[1] * np.sin(x[1] * x[2]) ],  # 方程1的雅可比行
        [2 * x[0], -162 * (x[1] + 0.1), np.cos(x[2])             ],  # 方程2的雅可比行
        [-x[1],    -x[0],               20                      ]   # 方程3的雅可比行
    ])

# ====================== 算法实现 ======================

def newton_method(F, J, x0, tol=1e-9, max_iter=100):
    """ Newton法求解非线性方程组 """
    x = x0.copy().astype(float)
    residuals = []  # 记录残差范数
    start_time = time.time()
    for _ in range(max_iter):
        Fx = F(x)
        residual = np.linalg.norm(Fx)
        residuals.append(residual)
        if residual < tol:
            break
        Jx = J(x)
        try:
            delta_x = np.linalg.solve(Jx, -Fx)
        except np.linalg.LinAlgError:
            print("警告：雅可比矩阵奇异，迭代终止。")
            break
        x += delta_x
    return x, len(residuals), time.time() - start_time, residuals

def broyden_method(F, J, x0, tol=1e-9, max_iter=100):
    """ Broyden秩1修正法 """
    x = x0.copy().astype(float)
    B = J(x)  # 初始近似雅可比矩阵
    Fx = F(x)
    residuals = [np.linalg.norm(Fx)]
    start_time = time.time()
    for _ in range(max_iter):
        if residuals[-1] < tol:
            break
        try:
            delta_x = np.linalg.solve(B, -Fx)
        except np.linalg.LinAlgError:
            print("警告：近似矩阵B奇异，迭代终止。")
            break
        x_new = x + delta_x
        Fx_new = F(x_new)
        y = Fx_new - Fx
        s = x_new - x
        # Broyden秩1修正公式
        B += np.outer((y - B @ s), s) / (s.dot(s) + 1e-16)  # 添加小量避免除零
        x = x_new
        Fx = Fx_new
        residuals.append(np.linalg.norm(Fx))
    return x, len(residuals), time.time() - start_time, residuals

def steepest_descent(F, J, x0, tol=1e-9, max_iter=1000, c=1e-4, tau=0.5):
    """ 最速下降法（带Armijo线搜索） """
    x = x0.copy().astype(float)
    residuals = []
    start_time = time.time()
    for _ in range(max_iter):
        Fx = F(x)
        residual = np.linalg.norm(Fx)
        residuals.append(residual)
        if residual < tol:
            break
        Jx = J(x)
        grad = Jx.T @ Fx  # 目标函数梯度
        direction = -grad
        alpha = 1.0  # 初始步长
        # Armijo线搜索
        while True:
            x_new = x + alpha * direction
            Fx_new = F(x_new)
            f_new = 0.5 * np.dot(Fx_new, Fx_new)
            f_current = 0.5 * np.dot(Fx, Fx)
            if f_new <= f_current + c * alpha * grad.dot(direction):
                break
            alpha *= tau
            if alpha < 1e-12:  # 步长过小则终止
                break
        x = x_new
    return x, len(residuals), time.time() - start_time, residuals

# ====================== 测试与结果分析 ======================

def run_experiment(system_name, F, J, x0_list):
    """ 运行实验并打印结果 """
    print(f"\n=== {system_name} ===")
    for idx, x0 in enumerate(x0_list):
        print(f"\nInitial Value {x0}:")
        # 运行各算法并获取残差数据
        x_newton, iter_newton, time_newton, res_newton = newton_method(F, J, x0)
        x_broyden, iter_broyden, time_broyden, res_broyden = broyden_method(F, J, x0)
        x_steep, iter_steep, time_steep, res_steep = steepest_descent(F, J, x0)
        
        # 打印结果
        print(f"Newton Method: Solution = {x_newton.round(9)}, Iterations = {iter_newton}, Time = {time_newton:.6f}s")
        print(f"Broyden Method: Solution = {x_broyden.round(9)}, Iterations = {iter_broyden}, Time = {time_broyden:.6f}s")
        print(f"Steepest Descent: Solution = {x_steep.round(9)}, Iterations = {iter_steep}, Time = {time_steep:.6f}s")
        
        # 绘制残差曲线（英文标签）
        plt.figure(figsize=(10, 6))
        plt.semilogy(res_newton, label='Newton Method', marker='o', linestyle='-')
        plt.semilogy(res_broyden, label='Broyden Method', marker='s', linestyle='--')
        plt.semilogy(res_steep, label='Steepest Descent', marker='^', linestyle='-.')
        plt.xlabel('Iteration')
        plt.ylabel('Residual Norm (Log Scale)')
        plt.title(f'{system_name} - Initial Value {x0} Convergence Curve')
        plt.legend()
        plt.grid(True, which='both', linestyle=':')
        plt.show()

# ====================== 主程序 ======================
if __name__ == "__main__":
    # 定义初始值列表（保持不变）
    x0_list_system1 = [
        np.array([1.0, 1.0, 1.0]),   # Initial Value 1
        np.array([0.0, 0.0, 0.0])     # Initial Value 2
    ]
    x0_list_system2 = [
        np.array([0.0, 0.0, 0.0]),    # Initial Value 1
        np.array([0.5, 0.0, -0.5])    # Initial Value 2 (near solution)
    ]
    
    # 运行实验（标题自动使用英文）
    run_experiment("Nonlinear System 1", F1, J1, x0_list_system1)
    run_experiment("Nonlinear System 2", F2, J2, x0_list_system2)