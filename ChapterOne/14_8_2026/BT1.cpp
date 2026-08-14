// cho mốt số n > 1 phân tích thừa số nguyên tố của số nguyên dương n
#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    long long n;
    cin >> n;
    
    for (long long i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            int cnt = 0;
            while (n % i == 0) 
            {
                cnt++;
                n /= i;
            }
            cout << i << " " << cnt << '\n';
        }
    }
    if (n > 1) 
        cout << n << " " << 1 << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}