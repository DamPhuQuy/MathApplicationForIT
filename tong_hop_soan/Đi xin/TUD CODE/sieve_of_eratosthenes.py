#Trong đoạn mã trên, chúng ta sử dụng thuật toán ràng Eratosthenes để tạo một danh sách các số nguyên tố từ 2 đến giới hạn n. 
# Hàm sieve_of_eratosthenes tạo một mảng primes với giá trị ban đầu là True cho tất cả các phần tử từ 0 đến n. 
# Sau đó, chúng ta duyệt qua các số từ 2 đến căn bậc hai của n và đánh dấu các bội của các số nguyên tố đã tìm thấy. 
# Cuối cùng, chúng ta tạo danh sách prime_numbers từ các phần tử có giá trị True trong mảng primes.

def sieve_of_eratosthenes(n):
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False

    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1

    prime_numbers = [i for i, is_prime in enumerate(primes) if is_prime]
    return prime_numbers

# Giới hạn để tìm số nguyên tố
n = 1000000

# Tìm số nguyên tố sử dụng ràng Eratosthenes
prime_numbers = sieve_of_eratosthenes(n)

# In kết quả
print("Các số nguyên tố từ 2 đến", n, "là:")
print(prime_numbers)