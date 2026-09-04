def is_perfect_number(num):
    sum_of_divisors = 0
    for i in range(1, num):
        if num % i == 0:
            sum_of_divisors += i
    return sum_of_divisors == num

def find_perfect_numbers(n):
    perfect_numbers = []
    for i in range(1, n+1):
        if is_perfect_number(i):
            perfect_numbers.append(i)
    return perfect_numbers

n = 100
perfect_numbers = find_perfect_numbers(n)
print("Các số hoàn hảo từ 1 đến", n, "là:", perfect_numbers)
