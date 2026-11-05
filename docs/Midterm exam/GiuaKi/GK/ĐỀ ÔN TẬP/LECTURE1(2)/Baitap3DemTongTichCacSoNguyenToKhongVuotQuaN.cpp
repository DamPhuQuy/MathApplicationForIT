#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
unsigned long long int productOfPrime(int n)
{
    if (n <= 1)
        return 0;
    unsigned long long int product = 1;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            product = product * i;
    }
    return product;
}
long long int sumOfPrime(int n)
{
    if (n <= 1)
        return 0;
    long long int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            sum = sum + i;
    }
    return sum;
}
void listPrimeLessThanN(int n)
{
    if (n <= 1)
    {
        cout << "Khong co so nguyen to truoc n";
        return;
    }
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Nhap n = ";
    cin >> n;
    cout << "Cac so nguyen to nho hon n = " << n << " la : ";
    listPrimeLessThanN(n);
    cout << endl;
    cout << "Tich cac so nguyen to khong vuot qua n la: " << productOfPrime(n) << endl;
    cout << "Tong cac so nguyen to khong vuot qua n la: " << sumOfPrime(n);
    return 0;
}