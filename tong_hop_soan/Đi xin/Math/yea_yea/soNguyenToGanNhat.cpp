#include <iostream>

using namespace std;

bool isPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i*i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int n = 173, left = n, right = n, pad = 1;	



	while (!isPrime(left+pad) && !isPrime(right+pad))
		++pad;

	cout << "So nguyen to gan voi 173 nhat khac 173 la: " << n+pad << endl;	


	return 0;
}