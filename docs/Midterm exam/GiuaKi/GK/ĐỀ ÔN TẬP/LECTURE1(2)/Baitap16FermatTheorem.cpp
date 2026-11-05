#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
    if (a==0) return b;
    return GCD(b%a,a);
}
int power(int x, int y, int m)
{
    if (y==0) return 1;
    int p = power(x,y/2,m)%m;
    p = (p*p)%m;
    return (y%2 == 0)?p:(x*p)%m;
}
int Fermat(int x, int m)
{
    if(GCD(x,m)!=1) return -1;
    return power(x,m-2,m);
}
int main()
{
    int x, m;
    cout << "Input : ";
    cin >> x >> m;
    cout << "Fermat Modular Inverse: " << Fermat(x,m);
    return 0;
}