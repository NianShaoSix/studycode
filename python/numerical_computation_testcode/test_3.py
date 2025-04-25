import numpy as np
import matplotlib.pyplot as plt

# ================== 被积函数定义 ==================
def f1(x):
    """积分1的被积函数：4/(1+x²)"""
    return 4 / (1 + x**2)

def f2(x):
    """积分2的被积函数：x*e^x"""
    return x * np.exp(x)

# ================== 复化梯形公式 ==================
def composite_trapezoid(f, a, b, n):
    h = (b - a) / n
    total = 0.5*(f(a) + f(b))
    for i in range(1, n):
        total += f(a + i*h)
    return total * h

# ================== 复化Gauss-Legendre I型 ==================
def gauss_legendre_2(f, a, b):
    """两点Gauss-Legendre积分"""
    t = [-1/np.sqrt(3), 1/np.sqrt(3)]
    points = 0.5*((b - a)*np.array(t) + (a + b))
    return 0.5*(b - a)*(f(points[0]) + f(points[1]))

def composite_gauss_legendre(f, a, b, n):
    h = (b - a)/n
    total = 0.0
    for i in range(n):
        total += gauss_legendre_2(f, a + i*h, a + (i+1)*h)
    return total

# ================== Romberg方法 ==================
def romberg(f, a, b, tol=0.5e-7, max_iter=20):
    R = np.zeros((max_iter, max_iter))
    h = b - a
    R[0,0] = 0.5*h*(f(a) + f(b))
    
    for m in range(1, max_iter):
        h /= 2
        sum_new = sum(f(a + (2*k-1)*h) for k in range(1, 2**(m-1)+1))
        R[m,0] = 0.5*R[m-1,0] + h*sum_new
        
        for l in range(1, m+1):
            R[m,l] = (4**l * R[m,l-1] - R[m-1,l-1]) / (4**l - 1)
            
        if abs(R[m,m] - R[m-1,m-1]) < tol:
            return R[m,m], 2**m
    return R[-1,-1], 2**max_iter

# ================== 绘图函数 ==================
def plot_errors(errors_dict):
    methods = list(errors_dict.keys())
    integrals = ['Integral 1 (π)', 'Integral 2 (e²)']
    
    plt.figure(figsize=(10,6))
    width = 0.25
    x = np.arange(len(methods))
    
    for i, integral in enumerate(integrals):
        values = [errors_dict[method][f'积分{i+1}'] for method in methods]
        plt.bar(x + i*width, values, width, label=integral)
        
    plt.yscale('log')
    plt.ylabel('Absolute Error (log scale)')
    plt.title('Error Comparison of Numerical Integration Methods')
    plt.xticks(x + width/2, methods)
    plt.legend()
    plt.grid(True, which='both', linestyle='--', alpha=0.5)
    plt.show()

# ================== 主程序 ==================
def main():
    epsilon = 0.5e-7
    results = {
        '积分1': {'精确值': np.pi},
        '积分2': {'精确值': np.exp(2)}  # 修正后的精确值
    }
    
    # ------------------ 积分1计算 ------------------
    a, b = 0, 1
    exact1 = results['积分1']['精确值']
    
    # 梯形公式 (n=4096)
    result_trap1 = composite_trapezoid(f1, a, b, 4096)
    
    # Gauss-Legendre (n=16)
    result_gl1 = composite_gauss_legendre(f1, a, b, 16)
    
    # Romberg (10次迭代)
    result_romb1, _ = romberg(f1, a, b)
    
    # ------------------ 积分2计算 ------------------
    a, b = 1, 2
    exact2 = results['积分2']['精确值']
    
    # 梯形公式 (n=512)
    result_trap2 = composite_trapezoid(f2, a, b, 512)
    
    # Gauss-Legendre (n=8)
    result_gl2 = composite_gauss_legendre(f2, a, b, 8)
    
    # Romberg (9次迭代)
    result_romb2, _ = romberg(f2, a, b)
    
    # ================== 结果输出 ==================
    error_data = {
        'Trapezoidal': {
            '积分1': abs(result_trap1 - exact1),
            '积分2': abs(result_trap2 - exact2)
        },
        'Gauss-Legendre': {
            '积分1': abs(result_gl1 - exact1),
            '积分2': abs(result_gl2 - exact2)
        },
        'Romberg': {
            '积分1': abs(result_romb1 - exact1),
            '积分2': abs(result_romb2 - exact2)
        }
    }
    
    print("积分1结果：")
    print(f"精确值: {exact1:.16f}")
    print(f"复化梯形公式 (n=4096): {result_trap1:.10f} 误差: {error_data['Trapezoidal']['积分1']:.2e}")
    print(f"Gauss-Legendre (n=16): {result_gl1:.10f} 误差: {error_data['Gauss-Legendre']['积分1']:.2e}")
    print(f"Romberg: {result_romb1:.10f} 误差: {error_data['Romberg']['积分1']:.2e}\n")
    
    print("积分2结果：")
    print(f"精确值: {exact2:.16f}")
    print(f"复化梯形公式 (n=512): {result_trap2:.10f} 误差: {error_data['Trapezoidal']['积分2']:.2e}")
    print(f"Gauss-Legendre (n=8): {result_gl2:.10f} 误差: {error_data['Gauss-Legendre']['积分2']:.2e}")
    print(f"Romberg: {result_romb2:.10f} 误差: {error_data['Romberg']['积分2']:.2e}")
    
    plot_errors(error_data)

if __name__ == "__main__":
    main()