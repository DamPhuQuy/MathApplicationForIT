def eratosthenes(n):
    sieve = [0] * (n + 1)
    sieve[0] = sieve[1] = 1
    for x in range(2, int(n**0.5) + 1):
        if sieve[x] == 0:
            for u in range(2 * x, n + 1, x):
                sieve[u] = x
    return sieve

def eratosthenes_range(K, N):
    sieve = [0] * (N - K + 1)
    sum_primes = 0
    product_primes = 1
    is_first = True
    for x in range(2, int(N**0.5) + 1):
        if sieve[x] == 0:
            start = max(x * x, (K + x - 1) // x * x)
            for u in range(start, N + 1, x):
                sieve[u - K] = x
    if K == 1:
        sieve[0] = 1
    for i in range(len(sieve)):
        if sieve[i] == 0:
            prime_number = i + K
            sum_primes += prime_number
            product_primes *= prime_number
    return sieve, sum_primes, product_primes

def main():
    n = int(input("Nhập n: "))
    sieve = eratosthenes(n)
    for i in range(2, n + 1):
        print(f"{i} {sieve[i]}")
main()
