// cho mốt số n in ra tổng các ước của n
#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    long long n;
    cin >> n;
    
    long long sum = 0;
    for (long long i = 1; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            sum += i;
            if (i * i != n) 
                sum += (n / i);
        }
    }
    
    cout << sum << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}