import math

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return (a * b) // gcd(a, b)

def is_coprime(a, b):
    return gcd(a, b) == 1

def main():
    a = int(input("Nhập a: "))
    b = int(input("Nhập b: "))

    if is_coprime(a, b):
        print("a and b are coprime")
    else:
        print("a and b are not coprime")

    print(f"Gcd({a}, {b}) = {gcd(a, b)}")
    print(f"Lcm({a}, {b}) = {lcm(a, b)}")
main()
