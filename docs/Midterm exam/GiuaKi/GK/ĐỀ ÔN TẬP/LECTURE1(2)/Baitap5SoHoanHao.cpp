#include <iostream>
using namespace std;
bool checkPerfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return true;
    return false;
}
long long sumOfPerfectNumber(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (checkPerfectNumber(i))
        {
            cout << i << " ";
            sum += i;
        }
    }
    return sum;
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Cac so hoan hao nho hon " << n << " la: ";
    long long sum = sumOfPerfectNumber(n);
    cout << endl;
    cout << "Tong cac so hoan hao nho hon " << n << " la: " << sum;
}