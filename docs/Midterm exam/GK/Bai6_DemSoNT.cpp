#include <iostream>
using namespace std;

void s(int A[], int n) {
    for (int i = 2; i <= n; i++) A[i] = 0;
    for (int x = 2; x <= n; x ++) {
        if (A[x] != 0)  continue;
        for (int i = 2 * x; i <= n; i += x) A[i] = x;
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    if (n <= 1) cout << "n khong hop le!\n";
    else {
        int A[n + 1];
        s(A, n);
        for (int i = 2; i <= n; i++) {
            if (A[i] == 0) cout << i << " ";
        }
        cout << endl;
    }

}