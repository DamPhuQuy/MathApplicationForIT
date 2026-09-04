////#include <bits/stdc++.h>
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//double func(double x) {
//    return x * x + 5 * sin(x);
//}
//
//double grad(double x) {
//    return 2 * x + 5 * cos(x);
//}
//
//double gradientDescent(double x, double alpha, double gra, int loop) {
//    for (int i = 1; i <= loop; i++) {
//        x = x - alpha * grad(x);
//        // Uncomment the following line for debugging
//         cout << "Buoc lap " << i << ": x = " << x << ", y = " << func(x) << endl;
//        if (abs(grad(x)) < gra)
//            break;
//    }
//    return x;
//}
//
//int main() {
//    double x0, alpha, gra;
//    int loop;
//
//    x0 = 0;
//    alpha = 0.1; // hệ số học 
//    gra = 0.00001; // sai số exciplon
//    loop = 1000;
//
//    double x_min = gradientDescent(x0, alpha, gra, loop);
//    double y_min = func(x_min);
//
//    printf("Diem khoi tao: x0 = %lf, y0 = %lf\n", x0, func(x0));
//    printf("Ham so dat nho nhat tai x = %lf, y = %lf\n", x_min, y_min);
//
//    return 0;
//}
