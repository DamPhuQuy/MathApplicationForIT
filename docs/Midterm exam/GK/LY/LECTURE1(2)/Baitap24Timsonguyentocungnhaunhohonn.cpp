#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void coprime(int n){
    int count = 0;
    int res[10000];
    for (int i=2;i<n;i++){
        if (gcd(i, n) == 1){
            res[count++] = i;
        }
    }
    cout << "Co " << count << " so nguyen to cung nhau voi "<< n  << endl;
    for (int i=0;i<count;i++){
        cout << res[i] << " ";
    }
}   
int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    coprime(n);
    return 0;
}