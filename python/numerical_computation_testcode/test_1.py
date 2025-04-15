import math
import matplotlib.pyplot as plt

def f(x):
    return 1 / (1 + 25 * x**2)

def polynomial_interpolation(x_data, y_data, x):
    n = len(x_data)
    result = 0.0
    for i in range(n):
        term = y_data[i]
        for j in range(n):
            if j != i:
                term *= (x - x_data[j]) / (x_data[i] - x_data[j])
        result += term
    return result

def newton_interpolation(x_data, y_data, x):
    n = len(x_data)
    coef = [[0.0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        coef[i][0] = y_data[i]
    for j in range(1, n):
        for i in range(n - j):
            coef[i][j] = (coef[i + 1][j - 1] - coef[i][j - 1]) / (x_data[i + j] - x_data[i])
    result = coef[0][0]
    for j in range(1, n):
        term = coef[0][j]
        for i in range(j):
            term *= (x - x_data[i])
        result += term
    return result

def cubic_spline_interpolation(x_data, y_data, x):
    n = len(x_data)
    h = [x_data[i+1] - x_data[i] for i in range(n-1)]
    alpha = [3*(y_data[i+1] - y_data[i])/h[i] for i in range(n-1)]
    c = [0.0] * n
    l = [1.0] * n
    mu = [0.0] * n
    z = [0.0] * n

    for i in range(1, n-1):
        l[i] = 2*(x_data[i+1] - x_data[i-1]) - h[i-1]*mu[i-1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i] - h[i-1]*z[i-1]) / l[i]

    c[-1] = 0.0
    for i in range(n-2, -1, -1):
        c[i] = z[i] - mu[i]*c[i+1]

    b = [0.0] * (n-1)
    d = [0.0] * (n-1)
    for i in range(n-1):
        b[i] = (y_data[i+1] - y_data[i])/h[i] - h[i]*(c[i+1] + 2*c[i])/3
        d[i] = (c[i+1] - c[i])/(3*h[i])

    for i in range(n-1):
        if x >= x_data[i] and x <= x_data[i+1]:
            return y_data[i] + b[i]*(x - x_data[i]) + c[i]*(x - x_data[i])**2 + d[i]*(x - x_data[i])**3
    return y_data[-1]

def main():
    x_values = []
    y_values = []
    for n in range(1, 11):
        x_data = [-1 + i*(2/(n)) for i in range(n+1)]
        y_data = [f(x) for x in x_data]
        x_test = [-1 + i*0.01 for i in range(201)]
        y_true = [f(x) for x in x_test]
        y_poly = [polynomial_interpolation(x_data, y_data, x) for x in x_test]
        y_newton = [newton_interpolation(x_data, y_data, x) for x in x_test]
        y_spline = [cubic_spline_interpolation(x_data, y_data, x) for x in x_test]

        x_values.append(x_test)
        y_values.append((y_true, y_poly, y_newton, y_spline))

    plt.figure(figsize=(10, 8))
    for i in range(10):
        plt.subplot(5, 2, i+1)
        plt.plot(x_values[i], y_values[i][0], label='True Function')
        plt.plot(x_values[i], y_values[i][1], label='Polynomial Interpolation')
        plt.plot(x_values[i], y_values[i][2], label='Newton Interpolation')
        plt.plot(x_values[i], y_values[i][3], label='Cubic Spline Interpolation')
        plt.title(f'n = {i+1}')
        plt.legend()
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()