def product_of_divisors(n):
    if n <= 0:
        return 0  # Không có ước số cho số âm hoặc 0

    product = 1
    divisor_count = 0

    # Lặp qua các số từ 1 đến sqrt(n)
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:  # Nếu i là ước số của n
            product *= i
            divisor_count += 1
            
            # Nếu n/i khác với i, tính cả ước số n/i
            if i != n // i:
                product *= n // i
                divisor_count += 1

    return product

def format_with_exponent(result):
    # Kiểm tra xem số có dạng bội của 10 không
    exponent = 0
    while result % 10 == 0:
        result //= 10
        exponent += 1

    if exponent > 0:
        return f"{result}x10^{exponent}"
    else:
        return str(result)

# Nhập số nguyên từ người dùng
n = int(input("Nhập vào một số nguyên n: "))
result = product_of_divisors(n)
formatted_result = format_with_exponent(result)
print(f"Tích các ước của số {n} là: {formatted_result}")
