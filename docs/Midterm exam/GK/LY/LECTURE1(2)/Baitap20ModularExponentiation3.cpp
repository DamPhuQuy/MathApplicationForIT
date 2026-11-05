#include <bits/stdc++.h>
//(x*y)%m
using namespace std;
int ModularExponentiation(int x, int y, int m)
{
    return (x%m * y%m)%m;
}
int main()
{
    int y, m, x;
    cout << "Nhap x, y, m: ";
    cin >> x >> y >> m;
    cout << "(x*y)%m = " << ModularExponentiation(x,y,m);
    return 0;
}