def modpow(a, m, n):
    if m == 0:
        return 1 % n
    u = modpow(a, m // 2, n)
    u = (u * u) % n
    if m % 2 == 1:
        u = (u * a) % n
    return u

def main():
    a = int(input("Nhập a: "))
    m = int(input("Nhập m: "))
    n = int(input("Nhập n: "))
    result = modpow(a, m, n)
    print(f"Gía trị của {a}^{m} mod {n} = {result}")
main()
