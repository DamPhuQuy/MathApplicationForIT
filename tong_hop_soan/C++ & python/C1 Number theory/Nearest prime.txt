import math

def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def nearest_prime(N):
    lower_prime = N
    while lower_prime > 1 and not is_prime(lower_prime):
        lower_prime -= 1

    upper_prime = N
    while not is_prime(upper_prime):
        upper_prime += 1

    if N - lower_prime <= upper_prime - N:
        return lower_prime
    else:
        return upper_prime
    
def main():
    N = int(input("Nhập số N: "))
    closest_prime = nearest_prime(N)
    print(f"Số nguyên tố gần nhất với {N} là: {closest_prime}")
main()
