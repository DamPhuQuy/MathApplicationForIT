#include <iostream>

using namespace std;
//Phân tích thừa số nguyên tố

const int MAX_N = 1000005; 
int spf[MAX_N]; 

// Độ phức tạp: O(N log(log N))
void sieve() {
    for (int i = 1; i < MAX_N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i < MAX_N; i++) {
       
        if (spf[i] == i) {
  
            for (int j = i * i; j < MAX_N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

// Độ phức tạp: O(log n)
void fastFactorization(int n) {
    if (n >= MAX_N) {
        cout << "Loi: So nhap vao qua lon so voi kich thuoc mang!" << endl;
        return;
    }

    cout << "Phan tich " << n << ": ";
    
    if (n <= 1) {
        cout << n << endl; 
        return;
    }

    while (n > 1) {
        int p = spf[n]; // lấy ước số nguyên tố nhỏ nhất
        cout << p;
        
        n = n / p; 
        
        if (n > 1) cout << " * ";
    }
    cout << endl;
}

int main() {

    sieve(); 

    int num1;
    cout << "Nhap so can phan tich (n < " << MAX_N << "): ";
    if (cin >> num1) {
        fastFactorization(num1);
    }
    
    return 0;
}