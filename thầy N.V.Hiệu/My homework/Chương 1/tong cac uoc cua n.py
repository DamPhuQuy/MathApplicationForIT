def sum_of_divisors(n):
    total_sum = 0
    # Lặp qua các số từ 1 đến sqrt(n)
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            total_sum += i
            if i != n // i:  # Tránh tính gấp đôi cho số chính nó
                total_sum += n // i
    return total_sum

def main():
    n = int(input("Nhập vào số n: "))
    total_sum = sum_of_divisors(n)
    print(f"Tổng các ước của {n} là: {total_sum}")

if __name__ == "__main__":
    main()
