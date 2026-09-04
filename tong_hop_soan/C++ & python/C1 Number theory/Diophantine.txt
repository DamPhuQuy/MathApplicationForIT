def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def extended_gcd(a, b):
    if b == 0:
        return 1, 0
    elif a == 0:
        return 0, 1
    else:
        x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return x, y

def diophantine(a, b, c):
    d = gcd(a, b)
    if c % d != 0:
        print("Phương trình không tồn tại nghiệm nguyên!")
        return
    x, y = extended_gcd(a, b)
    x *= c // d
    y *= c // d
    a //= d
    b //= d
    print(f"Nghiệm nguyên tổng quát x = {x} + {b}r")
    print(f"Nghiệm nguyên tổng quát y = {y} - {a}r")

def main():
    a = int(input("a = "))
    b = int(input("b = "))
    c = int(input("c = "))
    diophantine(a, b, c)
main()
