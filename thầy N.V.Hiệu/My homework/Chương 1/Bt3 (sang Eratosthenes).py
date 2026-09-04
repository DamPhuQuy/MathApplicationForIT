def eratosthenes(n):
    sieve = [0] * (n + 1)
    sieve[0], sieve[1] = 1, 1  # Đánh dấu 0 và 1 là không phải số nguyên tố

    for x in range(2, int(n**0.5) + 1):
        if sieve[x] != 0:
            continue
        for u in range(2 * x, n + 1, x):
            sieve[u] = x  # Đánh dấu các bội số của x

    return sieve

def main():
    n = int(input("Nhập n: "))
    sieve = eratosthenes(n)
    
    print(f"Sàng Eratosthenes từ 2 đến {n}:")
    print("{:<10} {:<15}".format("Số", "Ước số nhỏ nhất"))
    print("-" * 25)
    
    for i in range(2, n + 1):
        if sieve[i] == 0:
            print("{:<10} {:<15}".format(i, "Nguyên tố"))
        else:
            print("{:<10} {:<15}".format(i, sieve[i]))

if __name__ == "__main__":
    main()
