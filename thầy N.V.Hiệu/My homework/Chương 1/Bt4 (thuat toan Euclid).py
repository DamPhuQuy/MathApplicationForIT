def euclid_alg(a, b):
    if b == 0:
        return a
    return euclid_alg(b, a % b)

def main():
    a = int(input("Nhập a: "))
    b = int(input("Nhập b: "))
    
    print(f"Gcd({a}, {b}) = {euclid_alg(a, b)}")

if __name__ == "__main__":
    main()
