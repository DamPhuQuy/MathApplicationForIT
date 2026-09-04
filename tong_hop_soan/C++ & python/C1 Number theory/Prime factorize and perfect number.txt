import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def prime_factorization(n):
    p = []
    e = []
    for x in range(2, int(math.sqrt(n)) + 1):
        if is_prime(x):
            if n % x == 0:
                count = 0
                while n % x == 0:
                    n //= x
                    count += 1
                p.append(x)
                e.append(count)
    if n > 1:
        p.append(n)
        e.append(1)
    return p, e

def sum_factors(p, e):
    total_sum = 1
    for i in range(len(p)):
        total_sum *= (p[i] ** (e[i] + 1) - 1) // (p[i] - 1)
    return total_sum

def num_factors(e):
    num_of_factors = 1
    for exp in e:
        num_of_factors *= (exp + 1)
    return num_of_factors

def factor_list(num_of_factors, p, e):
    factors = [1]
    temp_expo = [0] * len(e)
    i = 1
    while i < num_of_factors:
        factor = 1
        j = len(e) - 1
        while j >= 0 and temp_expo[j] == e[j]:
            temp_expo[j] = 0
            j -= 1
        if j >= 0:
            temp_expo[j] += 1
        for k in range(len(p)):
            factor *= (p[k] ** temp_expo[k])
        factors.append(factor)
        i += 1
    return factors

def prod_of_factors(n, num_of_factors):
    return n ** (num_of_factors // 2)

def perfect_numbers(limit):
    perfect_nums = []
    for p in range(2, limit):
        mersenne_prime = 2 ** p - 1
        if is_prime(mersenne_prime):
            perfect_num = (2 ** (p - 1)) * mersenne_prime
            if perfect_num <= limit:
                perfect_nums.append(perfect_num)
            else:
                break
    return perfect_nums

def main():
    n = int(input("Nhập vào số n: "))
    if is_prime(n):
        print("Là số nguyên tố!")
    else:
        print("Không phải số nguyên tố!")
    p, e = prime_factorization(n)
    num = num_factors(e)
    print(f"Tích các thừa số nguyên tố của {n}:")
    print(f"{n} = ", end="")
    for i in range(len(p)):
        print(f"{p[i]}", end="")
        if e[i] > 1:
            print(f"^{e[i]}", end="")
        if i < len(p) - 1:
            print(".", end="")
    print()
    sum_of_factors = sum_factors(p, e)
    print(f"Tổng các ước số của {n} là: {sum_of_factors}")
    print(f"Số ước số của {n} là: {num}")
    factors = factor_list(num, p, e)
    print(f"Các ước số của {n} là: {' '.join(map(str, factors))}")
    prod = prod_of_factors(n, num)
    print(f"Tích các ước số của {n} là: {prod}")
    perfect_nums = perfect_numbers(n)
    if perfect_nums:
        print(f"Các số hoàn hảo nhỏ hơn hoặc bằng {n} là: {', '.join(map(str, perfect_nums))}")
    else:
        print(f"Không có số hoàn hảo nào nhỏ hơn hoặc bằng {n}.")
main()
