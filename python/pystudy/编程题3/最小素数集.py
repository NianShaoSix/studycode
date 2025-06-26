def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True

def prime_factors(x):
    factors = set()
    i = 2
    while i * i <= x:
        if x % i == 0:
            factors.add(i)
            while x % i == 0:
                x //= i
        i += 1
    if x > 1:
        factors.add(x)
    return factors

n = int(input())
nums = list(map(int, input().split()))

min_set = set()

for num in nums:
    if is_prime(num):
        min_set.add(num)
    else:
        factors = prime_factors(num)
        min_set.update(factors)

sorted_primes = sorted(min_set)
print(' '.join(map(str, sorted_primes)) + ' ')