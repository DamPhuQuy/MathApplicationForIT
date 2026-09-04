#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> factorization(int n) {
    vector<pair<int, int>> factor;
    if (n % 2 == 0) {
        factor.push_back({2, 0});
        int &ex = factor.back().second;
        while (n % 2 == 0) {
            n >>= 1;
            ex++;
        }
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factor.push_back({i, 0});
            int &ex = factor.back().second;
            while (n % i == 0) {
                n /= i;
                ex++;
            }
        }
    }
    if (n > 1)
        factor.push_back({n, 1});
    return factor;
}

long long gcd_formula(int a, int b) {
    vector<pair<int, int>> p1 = factorization(a);
    vector<pair<int, int>> p2 = factorization(b);
    long long ans = 1;
    for (auto temp : p1) {
        auto it = lower_bound(p2.begin(), p2.end(), temp);
        if (it != p2.end() && it->first == temp.first) {
            int minex = min(temp.second, it->second);
            ans *= pow(temp.first, minex);
        }
    }
    return ans;
}

long long gcd_euclid(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd_euclid(b, a % b);
}

int coprime(int n) {
    vector<pair<int, int>> factor = factorization(n);
    int ans = 1;
    for (auto p : factor) {
        ans *= pow(p.first, p.second - 1) * (p.first - 1);
    }
    return ans;
}

int coprime_m_to_n(int n, int m) {
    int cnt = 0;
    for (int i = m; i <= n; i++) {
        if (gcd_euclid(i, n) == 1)
            cnt++;
    }
    return cnt;
}

int binpowmod(int a, int n, int m) {
    a %= m;
    int ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return ans;
}

void check_formula(int x, int y, int m, int n) {
    int expow = 1;`
    for (int i = 1; i <= n; i++)
        expow *= x;

    cout << "(x + y) %m =" << (x + y) % m << "\n";
    cout << "(x%m + y%m) %m =" << (x % m + y % m) % m << "\n\n";
    cout << "(x - y) %m=" << ((x - y) % m + m) % m << "\n";
    cout << "(x%m - y%m) %m =" << ((x % m - y % m) + m) % m << "\n\n";
    cout << "x.y %m =" << x * y % m << "\n";
    cout << "((x%m) * (y%m)) %m =" << ((x % m) * (y % m)) % m << "\n\n";
    cout << "(x^n) %m =" << expow % m << "\n";
    cout << "((x%m) ^n) %m =" << binpowmod(x, n, m) << "\n\n";
}

bool Fermat_primality_test(int n) {
    if (n < 4)
        return n == 2 || n == 3;
    for (int i = 0; i < 5; i++) {
        int a = 2 + rand() % (n - 3);
        if (binpowmod(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int extended_eulid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, g;
    g = extended_eulid(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

int modular_inverse(int a, int m) {
    int x, y, g;
    g = extended_eulid(a, m, x, y);
    if (g != 1) {
        return 0;
    }
    return (x % m + m) % m;
}

int chinese_remainder_theorem(vector<int> a, vector<int> m) {
    int M = 1, x;
    for (auto it : m)
        M *= it;
    vector<int> x_inverse;
    for (int i = 0; i < a.size(); i++) {
        x = M / m[i];
        x_inverse.push_back(modular_inverse(x, m[i]));
    }
    x = 0;
    for (int i = 0; i < a.size(); i++) {
        x += a[i] * M / m[i] * x_inverse[i];
        x = x % M;
    }
    return x;
}

int main() {
    int m, n, x, y;
    cout << "Question 1: \n";
    cout << "Input n,m =";
    cin >> n >> m;

    cout << "Find GCD(m,n) using formula :" << gcd_formula(m, n) << "\n";
    cout << "Find GCD(m,n) using Euclid's algorithm :" << gcd_euclid(m, n) << "\n\n";

    cout << "Question 2:\n";
    cout << "Input n,m =";
    cin >> n >> m;
    cout << "Count coprime to n between 1 and n :" << coprime(n) << "\n";
    cout << "Count coprime to n between m and n :" << coprime_m_to_n(n, m) << "\n\n";

    cout << "Question 3:\n";
    cout << "Input x,y,m,n =";
    cin >> x >> y >> m >> n;
    cout << "Check formula:\n";
    check_formula(x, y, m, n);
    cout << "\n";

    cout << "Question 4:\n";
    cout << "Input m =";
    cin >> m;
    cout << "Fermat primality test :";
    if (Fermat_primality_test(m))
        cout << m << " is a prime number";
    else
        cout << m << " is not a prime number";
    cout << "\n\n";

    cout << "Question 5: \n";
    cout << "Input x,m =";
    cin >> x >> m;
    cout << "Modular inverse x^-1 : " << modular_inverse(x, m) << "\n\n";

    cout << "Question 6:\n";
    cout << "Input n= ";
    cin >> n;
    cout << "Input array a[]= ";
    vector<int> a(n), m_arr(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Input array m[]= ";
    for (int i = 0; i < n; i++)
        cin >> m_arr[i];
    cout << "Chinese remainder theorem x :" << chinese_remainder_theorem(a, m_arr);
    return 0;
}
