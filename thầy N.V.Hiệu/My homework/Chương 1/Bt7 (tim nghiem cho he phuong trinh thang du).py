def TDTrungHoa(m, a, k):
    x = 1
    while True:
        for i in range(k):
            if x % m[i] != a[i]:
                break
        else:  # This executes if the for loop is not broken
            return x
        x += 1

def main():
    k = int(input("Nhập số pt k = "))
    a = []
    m = []
    
    for i in range(k):
        a_i = int(input(f"a{i + 1} = "))
        m_i = int(input(f"m{i + 1} = "))
        
        if m_i <= 0:
            print(f"Lỗi: m{i + 1} phải là số nguyên dương.")
            return
        
        if a_i < 0 or a_i >= m_i:
            print(f"Lỗi: a{i + 1} phải nằm trong khoảng từ 0 đến {m_i - 1}.")
            return
        
        a.append(a_i)
        m.append(m_i)
    
    mod = 1
    for mod_i in m:
        mod *= mod_i
    
    result = TDTrungHoa(m, a, k)
    print(f"x = {result} mod {mod}")

if __name__ == "__main__":
    main()
