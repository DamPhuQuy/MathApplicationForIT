import math

# Kiểm tra số nguyên tố
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

# Tìm số hoàn hảo dựa trên phương trình 2^(p-1) * (2^p - 1)
def find_perfect_numbers(limit):
    perfect_count = 1
    p = 2  # Bắt đầu từ p = 2
    while True:
        mersenne_prime = 2**p - 1
        if is_prime(mersenne_prime):
            perfect_number = (2**(p-1)) * mersenne_prime
            if perfect_number > limit:
                break
            print(f"{perfect_count}. {perfect_number} là số hoàn hảo!")
            perfect_count += 1
        p += 1

def main():
    n = int(input("Nhập vào số n: "))
    print(f"Các số hoàn hảo từ 1 đến {n} là:")
    find_perfect_numbers(n)

if __name__ == "__main__":
    main()
