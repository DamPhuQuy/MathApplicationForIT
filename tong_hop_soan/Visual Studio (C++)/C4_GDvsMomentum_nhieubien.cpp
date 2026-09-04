////#include <bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//#define gamma 0.01    // hệ số học 
//#define N 1000       // số vòng lặp tối đa
//#define alpha 0.9    // hệ số động lượng
//#define e 0.00001    // exceplon
//
//// Cho ham so f(x) = x^1 + x^2
//double function(double x1, double x2) {
//	return x1 * x1 + x2 * x2;
//}
//double grad1(double x1) {
//	return 2 * x1;
//}
//double grad2(double x2)
//{
//	return 2 * x2;
//}
//void GradientDescentWithMomentum(double x1, double x2)
//{
//	double v1 = 0, v2 = 0;
//	double x1_new, x2_new;
//	for (int i = 1; i < N; i++)
//	{
//		v1 = alpha * v1 + gamma * grad1(x1);
//		v2 = alpha * v2 + gamma * grad2(x2);
//		x1_new = x1 - v1;
//		x2_new = x2 - v2;
//
//		cout << x1_new << " " << x2_new << endl;
//		if (abs(x1_new - x1) < e && abs(x2_new - x2) < e)
//			break;
//		x1 = x1_new;
//		x2 = x2_new;
//	}
//	cout << "Ham so dat nho nhat tai x1 = " << x1 << ", x2 = " << x2;
//	cout << "\nMin = " << function(x1, x2);
//}
//
//int main()
//{
//	double x1 = 1, x2 = -1;    // các giá trị khởi tạo ban đầu 
//	GradientDescentWithMomentum(x1, x2);
//	return 0;
//}
