
//#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//// Cho ham f(x) = x1^2 + x2^2
//double func(double x1, double x2) {
//	return x1 * x1 + x2 * x2;
//}
//
//double grad1(double x1) {
//	return 2 * x1;
//}
//double grad2(double x2) {
//	return 2 * x2;
//}
//
//void gradientDescent(double x1, double x2, double alpha, double gra, int loop) {
//	double x1_new, x2_new;
//	for (int i = 1; i <= loop; i++) {
//		x1_new = x1 - alpha * grad1(x1);
//		x2_new = x2 - alpha * grad2(x2);
//		if (abs(x1_new - x1) < gra && abs(x2_new - x2) < gra)
//			break;
//		x1 = x1_new;
//		x2 = x2_new;
//	}
//	cout << "Ham so dat gia tri nho nhat tai x1 = " << x1 << ", x2 = " << x2 << endl;
//	cout << "Gia tri nho nhat = " << func(x1, x2);
//}

//int main() {
//	double x1, x2, alpha, gra;
//	int loop;
//	x1 = -1;   // giá trị khởi tạo ban đầu
//	x2 = 1;    // giá trị khởi tạo ban đầu
//	alpha = 0.1;      // hệ số học 
//	gra = 0.00001;     // exceplon
//	loop = 1000;        // số vòng lặp tối đa
//	gradientDescent(x1, x2, alpha, gra, loop);
//	return 0;
//}

