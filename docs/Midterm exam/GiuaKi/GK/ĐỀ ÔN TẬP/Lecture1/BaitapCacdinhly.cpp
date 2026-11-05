#include <iostream>
#include <cmath>

using namespace std;

// Tìm ước chung lớn nhất (để kiểm tra nguyên tố cùng nhau cho bài Pytago)
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// --- 1. ĐỊNH LÝ LAGRANGE (TỔNG 4 BÌNH PHƯƠNG) ---
void solveLagrange(int n) {
    cout << "Phan tich Lagrange cho so " << n << ": ";
    int limit = sqrt(n);
    
    // Sử dụng 3 vòng lặp, số thứ 4 sẽ được tính toán
    for (int a = 0; a <= limit; a++) {
        for (int b = 0; b <= limit; b++) {
            for (int c = 0; c <= limit; c++) {
                int d_squared = n - (a*a + b*b + c*c);
                if (d_squared < 0) break; // Vượt quá n thì dừng vòng lặp c
                
                int d = sqrt(d_squared);
                if (d * d == d_squared) {
                    cout << n << " = " << a << "^2 + " << b << "^2 + " 
                         << c << "^2 + " << d << "^2" << endl;
                    return; // Tìm thấy 1 nghiệm là đủ, thoát hàm ngay
                }
            }
        }
    }
}

// --- 2. ĐỊNH LÝ ZECKENDORF (TỔNG FIBONACCI) ---
// Bài toán: Phân tích n thành tổng các số Fibonacci không liên tiếp
void solveZeckendorf(int n) {
    cout << "Bieu dien Zeckendorf cho so " << n << ": " << n << " = ";
    
    long long fib[50];
    fib[0] = 1;
    fib[1] = 2; 
    
    int count = 2;
    while (true) {
        long long next_fib = fib[count - 1] + fib[count - 2];
        if (next_fib > n) break;
        fib[count] = next_fib;
        count++;
    }

    bool isFirst = true;
    for (int i = count - 1; i >= 0; i--) {
        if (n >= fib[i]) {
            if (!isFirst) cout << " + ";
            cout << fib[i];
            n -= fib[i];
            isFirst = false;
            
        }
        if (n == 0) break;
    }
    cout << endl;
}

// --- 3. BỘ BA PYTHAGORAS (CÔNG THỨC EUCLID) ---
void generatePythagoreanTriples(int limit_n) {
    cout << "Cac bo ba Pythagoras nguyen thuy (voi n < " << limit_n << "):" << endl;
    
    for (int n = 2; n < limit_n; n++) {
        for (int m = 1; m < n; m++) {
            // Kiểm tra tính chẵn lẻ khác nhau: (n - m) phải là số lẻ
            if ((n - m) % 2 == 1 && gcd(n, m) == 1) {
                int a = n*n - m*m;
                int b = 2*n*m;
                int c = n*n + m*m;
                
                // Sắp xếp a và b để in cho đẹp (tùy chọn)
                if (a > b) swap(a, b);
                
                cout << "(" << a << ", " << b << ", " << c << ")" << endl;
            }
        }
    }
}

// --- 4. ĐỊNH LÝ WILSON (KIỂM TRA SỐ NGUYÊN TỐ) ---
void checkWilson(int n) {
    if (n <= 1) {
        cout << n << " khong phai la so nguyen to." << endl;
        return;
    }
    
    long long factorial = 1;
    for (int i = 1; i < n; i++) {
        factorial = (factorial * i) % n; // Tính (n-1)! mod n
    }
    
    // Theo định lý: (n-1)! đồng dư -1 mod n, hay đồng dư (n-1) mod n
    if (factorial == n - 1) {
        cout << "Theo dinh ly Wilson: " << n << " LA so nguyen to." << endl;
    } else {
        cout << "Theo dinh ly Wilson: " << n << " KHONG phai la so nguyen to." << endl;
    }
}

int main() {
    cout << "--- TEST LAGRANGE ---" << endl;
    solveLagrange(123);
    cout << endl;
    cout << "--- TEST ZECKENDORF ---" << endl;
    solveZeckendorf(74);
    cout << endl;
    cout << "--- TEST PYTHAGOREAN ---" << endl;
    generatePythagoreanTriples(6); // Thử với n nhỏ để tạo vài bộ số
    cout << endl;

    cout << "--- TEST WILSON ---" << endl;
    checkWilson(11); 
    checkWilson(12); 
    
    return 0;
}