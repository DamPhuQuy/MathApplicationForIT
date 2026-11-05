#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
    BAI TOAN:
    Tim gia tri nho nhat gan dung cua ham f(x)
    bang phuong phap Gradient Descent.

    Cong thuc lap:
        x_new = x - gamma * f'(x)

    Khi de bai doi ham so, chi can sua 2 ham:
        1. f(x)
        2. df(x)

    Cac phan con lai giu nguyen.
*/

// ================== CHI SUA O DAY ==================
// Ham so cua de bai:
// f(x) = (ln(x^2 + 10) + x - 5)^2 + 2x
double f(double x) {
        return pow(log(x * x + 10) + x - 5, 2) + 2*x;
}

// Dao ham cap 1 cua ham so:
// f'(x) = 2(ln(x^2 + 10) + x - 5) * (2x / (x^2 + 10) + 1) + 2
double df(double x) {
    return 2*(log(x * x + 10) + x - 5)*((2 * x) / (x * x + 10) + 1) + 2;
}
// ================== HET PHAN CAN SUA ==================


double gradientDescent(double x0, double gamma, int N, double epsilon) {
    double x = x0;

    for (int i = 1; i <= N; i++) {
        double grad = df(x);

        // Cong thuc Gradient Descent
        double x_new = x - gamma * grad;

        // Dieu kien dung:
        // 1. Hai gia tri x lien tiep gan nhau
        // 2. Dao ham gan bang 0
        if (fabs(x_new - x) < epsilon || fabs(grad) < epsilon) {
            cout << "Dung tai buoc lap: " << i << endl;
            return x_new;
        }

        x = x_new;
    }

    cout << "Dat toi so buoc lap toi da.\n";
    return x;
}

int main() {
    double x0, gamma, epsilon;
    int N;

    cout << "Nhap diem bat dau x0 = ";
    cin >> x0;

    cout << "Nhap learning rate gamma = ";
    cin >> gamma;

    cout << "Nhap so buoc lap toi da N = ";
    cin >> N;

    cout << "Nhap sai so epsilon = ";
    cin >> epsilon;

    double xmin = gradientDescent(x0, gamma, N, epsilon);

    cout << fixed << setprecision(10);
    cout << "\nGia tri x lam f(x) nho nhat gan dung la: " << xmin << endl;
    cout << "Gia tri nho nhat gan dung f(x) = " << f(xmin) << endl;
    cout << "Dao ham tai diem do f'(x) = " << df(xmin) << endl;

    return 0;
}