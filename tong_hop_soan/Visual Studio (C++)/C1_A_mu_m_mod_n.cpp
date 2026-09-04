//#include <iostream>
//using namespace std;
//
//int modpow(int a, int m, int n) {
//    if (m == 0) return 1 % n;
//    int u = modpow(a, m / 2, n);
//    u = (u * u) % n;
//    return (m % 2 == 1) ? (u * a) % n : u;
//}
//
//int main() {
//    int a, m, n;
//    cin >> a >> m >> n;
//    cout << modpow(a, m, n);
//    return 0;
//}
