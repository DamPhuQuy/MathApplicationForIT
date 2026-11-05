#include <iostream>
#include <cmath>
using namespace std;

bool NT(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0) return 0;
    return 1;
}

int main() {
    int n; 
    cout << "n = "; 
    cin >> n;
    
    if (n <= 1) {
        cout << "n khong hop le!";
        return 0;
    }
    
    int U[500], cnt = 1;
    U[0] = 1;
    
    long long S = 1, P = 1;  // S: tổng, P: tích
    
    int i = 2, m = n;
    
    while (m > 1) {
        if (NT(i) && m % i == 0) {
            int p = i;
            int oldCnt = cnt;
            
            while (m % i == 0) {
                for (int j = 0; j < oldCnt; j++) {
                    U[cnt] = U[j] * p;
                    S += U[cnt];
                    P *= U[cnt];
                    cnt++;
                }
                m /= i;
                p *= i;
            }
        }
        i++;
    }
    
    // In kết quả
    cout << "\nCac uoc: ";
    for (int k = 0; k < cnt; k++) {
        cout << U[k];
        if (k < cnt - 1) cout << " ";
    }
    
    cout << "\nTong uoc: " << S << endl;
    cout << "Tich uoc: " << P << endl;
    
    return 0;
}