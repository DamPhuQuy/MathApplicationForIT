import numpy as np

# # ma trận hệ số của hàm mục tiêu
# c = np.array([2, -5, 4, -1, -6, 0])
# # ma trận hệ số tự do
# b = np.array([32, 30, 36])
# # ma trận hệ số của ràng buộc
# a = np.array([
#     [1, 6, 0, -2, -9, 0], 
#     [0, 2, 1, 1, 0, 0], 
#     [0, 3, 0, 0, 0, 1]
# ])

a = np.array([
    [2, 4, 3, 1, 0, 0],
    [4, 2, 3, 0, 1, 0],
    [3, 0, 1, 0, 0 , 1]
], float)
b = np.array([52, 60, 36], float)
c = np.array([5, 4, 5, 2, 1, 3], float)

n = len(c)
m = len(b)

#an co ban
cb = np.zeros(m, dtype=int)
for i in range(n):
    for j in range(m):
        if a[j, i] == 1 and np.all(np.logical_or(a[:, i] == 0, a[:, i] == 1)):
            cb[j] = i
pa = b

def simplex(a, b, c, cb, pa):
    print('cb = ', cb)
    while True:
        hs = np.array([c[i] for i in cb], float)
    
        deltaJ = hs @ a - c
        if np.all(deltaJ <= 0):
            print('ket thuc')
            print('x tối ưu: ', end='')
            for i in range(n):
                if i in cb:
                    print(pa[cb == i], end=' ')
                else:
                    print(0, end=' ')      
            print('\nz = ', hs @ pa)              
            break
        
        for k in range(n):
            if deltaJ[k] > 0:
                if np.all(a[:, k] <= 0):
                    print('vo nghiem')
                    return None
        
        cotquay = np.argmax(deltaJ)
        lambdaJ = pa / a[:, cotquay]
        hangquay = np.where(lambdaJ == np.min(lambdaJ[a[:, cotquay] > 0]))[0][0]
        hscy = a[hangquay, cotquay]
        cb[hangquay] = cotquay
        
        pa[hangquay] = pa[hangquay] / hscy
        pa[0:hangquay] = pa[0:hangquay] - pa[hangquay] * a[0:hangquay, cotquay]
        pa[hangquay+1:] = pa[hangquay+1:] - pa[hangquay] * a[hangquay+1:, cotquay]
        
        a[hangquay, :] = a[hangquay, :] / hscy
        for i in range(m):
            if i != hangquay:
                a[i, :] = a[i, :] - a[i, cotquay] * a[hangquay, :]

simplex(a, b, c, cb, pa)