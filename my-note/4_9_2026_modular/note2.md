Cho n nhập từ bàn phím, tìm số fibonacci thứ n. Trong n số fibo vừa tìm được n > 100, số nào chia hết cho 2, cho 5, cho 7, cho m, ....

fermat's theorem

x * x^-1 % m = 1

E.g: 
x = 3 mod 5
x = 4 mod 7 
x = 2 mod 3

a là số dư
m là số chia 

x^-1_m be the inverse of x modulo m, x_k = (m_1 * m_2 * ... * m_k) / m_k

x_k * x^-1_k_mk mod m_k = 1

21 * x^-1_1 mod 5 = 1
21 * x^-1_1 = 5k + 1 (k nhỏ I' = 1 -> x^-1_1 = 1) 

15 * x^-1_2 mod 7 = 1
15 * x^-1_2 = 7k + 1 (k = 2 -> x^-1_2 = 1) 

35 * x^-1_3 mod 3 = 3k + 1 -> k = 23 -> x^-1_3 = 2

x = a_1 * x_1 * x^-1_1 + ... + a_k * x_k * x^-1_k

M = m1 * m2 * m3 = 105
x mod M = 263 mod 105 = 53. 

ngheiejm hệ đã cho: 
x = 53 + M*k

thường ra thi 4 -> 5 phương trình
