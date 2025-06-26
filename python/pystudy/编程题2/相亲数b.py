def get_factors(n):
    factors = []
    for i in range(1, n):
        if n % i == 0:
            factors.append(i)
    return sorted(factors, reverse=True)

def main():
    import sys
    input = sys.stdin.readline().strip().split()
    a, b = map(int, input)
    
    # 计算a的因数之和
    factors_a = get_factors(a)
    sum_a = sum(factors_a)
    formula_a = ',' + '+'.join(map(str, factors_a)) + '=' + str(sum_a)
    
    # 计算b的因数之和
    factors_b = get_factors(b)
    sum_b = sum(factors_b)
    formula_b = ',' + '+'.join(map(str, factors_b)) + '=' + str(sum_b)
    
    # 输出结果
    print(f"{a}{formula_a}")
    print(f"{b}{formula_b}")
    
    # 判断是否为相亲数
    if sum_a == b and sum_b == a:
        print(1)
    else:
        print(0)

if __name__ == "__main__":
    main()