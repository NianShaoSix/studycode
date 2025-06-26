import math

def calculate_sin(x, e):
    result = 0.0
    previous_result = 0.0
    n = 1
    while True:
        term = ((-1) ** (n - 1)) * (x ** (2 * n - 1)) / math.factorial(2 * n - 1)
        result += term
        if n >= 2 and abs(result - previous_result) < e:
            break
        previous_result = result
        n += 1
    return n, result

def main():
    x, e = map(float, input().split())
    n, sin_x = calculate_sin(x, e)
    print(f"{n} {sin_x:.9f}")

if __name__ == "__main__":
    main()