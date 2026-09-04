// cho mốt số n in ra tích các ước
#include<bits/stdc++.h>

using namespace std;

int prime[1000001];

void san(int n)
{
    for(int i = 1; i <= n; i++)
        prime[i] = i;
    for(int i = 2; i * i <= n; i++)
        if(prime[i] == i)
            for(int j = i * i; j <= n; j += i)
                if(prime[j] == j)
                    prime[j] = i;
}

void f(int n)
{
    vector<int> ans;
    int cnt = 1;
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0)
        {
            cnt *= i;
            ans.push_back(i);
            if(n / i != i)
                cnt *= n / i, ans.push_back(n / i);
        }
    cout << cnt;
}

int main()
{
    //san(1000000);
    int n;
    cin >> n;
    f(n);
}