//#include <bits/stdc++.h>

#include<iostream>
#include<cmath>

using namespace std;

#define gamma 0.001  // hệ số học
#define N 1000        // số vòng lặp tối đa
#define alpha 0.1   // hệ số động lượng
#define e 0.00001   // sai số
using namespace std;

double function(double x) {
	return ((exp(2 * x) + 8 * x * x + 4 * x) / (5 - x)) - 10 * x;
}

double grad(double x)
{
	return ((2 * exp(2 * x) + 16 * x + 4) * (5 - x) + exp(2 * x) + 8 * x * x + 4 * x) / (pow(5 - x, 2)) - 10;
}
double GradientDescentWithMomentum(double x)
{
	double v = 0;
	double x_new = 0;
	for (int i = 1; i < N; i++)
	{
		// gamma: step_size: learning rate
		// alpha: momentum
		v = alpha * v + gamma * grad(x);
		x_new = x - v;
		cout << "v = " << v << "; x = " << x_new << endl;
		if (abs(x_new - x) < e)
			return x_new;
		x = x_new;
	}
	return x;
}

//int main()
//{
//	double x = 0;
//	double minimum = GradientDescentWithMomentum(x);
//	cout << "X_min = " << minimum << " ";// <<iterations;
//	cout << "Y_min = " << function(minimum);
//	return 0;
//}
