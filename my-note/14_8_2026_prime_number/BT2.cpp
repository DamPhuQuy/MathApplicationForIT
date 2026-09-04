// cho mốt số n in ra số lượng và tất cả các ước của n
// bai2.cpp
#include <bits/stdc++.h>
using namespace std;

void way1(long long n) 
{
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) 
        if (n % i == 0) 
		{
            ans.push_back(i);
            if (i * i != n) 
                ans.push_back(n / i);
        }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (long long d : ans) 
        cout << d << " ";
    cout << '\n';
}


void way2(long long n) 
{
    long long count = 1;
    for (long long i = 2; i * i <= n; i++) 
	{
        if (n % i == 0) 
		{
            long long a = 0;
            while (n % i == 0) 
			{
                a++;
                n /= i;
            }
            count *= (a + 1);
        }
    }
    if (n > 1) {
        count *= (1 + 1);
    }
    
    cout << count << '\n';
}

void solve() 
{
    long long n;
    cin >> n;
    way1(n);
    way2(n);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
