import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def euler_phi(n):
    result = n
    for p in range(2, int(math.sqrt(n)) + 1):
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
    if n > 1:
        result -= result // n
    return result

def power_mod(a, b, m):
    result = 1
    a = a % m
    while b > 0:
        if b % 2 == 1:
            result = (result * a) % m
        b //= 2
        a = (a * a) % m
    return result

def mod_inverse(a, m):
    phi_m = euler_phi(m)
    return power_mod(a, phi_m - 1, m)

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def main():
    a = int(input("Nhập số a: "))
    m = int(input("Nhập mod m: "))

    if gcd(a, m) != 1:
        print(f"Không tồn tại nghịch đảo modular của {a} theo mod {m}")
    else:
        inverse = mod_inverse(a, m)
        print(f"Nghịch đảo modular của {a} theo mod {m} là: {inverse}")
main()
