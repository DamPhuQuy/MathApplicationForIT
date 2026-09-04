def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def prime_factors(n):
    factors = []
    for i in range(2, n + 1):
        if is_prime(i):
            while n % i == 0:
                factors.append(i)
                n //= i
    return factors

# https://docs.google.com/presentation/d/1cwFKnHd4nPth0bh0gQvR3SRSXs401cNJPFdoXrC4pMI/edit#slide=id.gdb7384ee9e_5_33
# slide 7
def count_factors(n):
    factors = prime_factors(n)
    count = 1
    for i in set(factors):
        count *= factors.count(i) + 1
    return count

n = 84
factors = prime_factors(n)


