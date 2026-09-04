// xác định số lượng các số nguyên tố bằng công thức: pi(n) = n / ln(n)
#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    double n;
    cin >> n;
    
    if (n > 1) 
    {
        double pi_n = n / log(n); 
        cout << (long long)pi_n << '\n';
    } 
    else 
        cout << 0 << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}