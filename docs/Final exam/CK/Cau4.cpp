#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF_LIMIT = 1e100;

double f(double x, double y) {
    double u = x * x + y - 12;
    double v = x + y * y - 9;

    return u * u + v * v;
}

double dfdx(double x, double y) {
    double u = x * x + y - 12;
    double v = x + y * y - 9;

    return 4 * x * u + 2 * v;
}

double dfdy(double x, double y) {
    double u = x * x + y - 12;
    double v = x + y * y - 9;

    return 2 * u + 4 * y * v;
}

bool isValid(double value) {
    return isfinite(value) && fabs(value) < INF_LIMIT;
}

void gradientDescentMomentum(
    double x,
    double y,
    double gamma,
    double alpha,
    int N,
    double epsilon
) {
    double vx = 0.0;
    double vy = 0.0;

    int iter = 0;
    bool converged = false;

    for (int i = 1; i <= N; i++) {
        iter = i;

        double gx = dfdx(x, y);
        double gy = dfdy(x, y);

        if (!isValid(gx) || !isValid(gy)) {
            cout << "Thuat toan bi tran so tai buoc lap: " << i << endl;
            break;
        }

        double vx_new = alpha * vx - gamma * gx;
        double vy_new = alpha * vy - gamma * gy;

        double x_new = x + vx_new;
        double y_new = y + vy_new;

        if (!isValid(x_new) || !isValid(y_new) || !isValid(f(x_new, y_new))) {
            cout << "Thuat toan bi phan ky tai buoc lap: " << i << endl;
            break;
        }

        double step = sqrt((x_new - x) * (x_new - x) + (y_new - y) * (y_new - y));
        double gradNorm = sqrt(dfdx(x_new, y_new) * dfdx(x_new, y_new)
                             + dfdy(x_new, y_new) * dfdy(x_new, y_new));

        if (step < epsilon && gradNorm < epsilon) {
            x = x_new;
            y = y_new;
            converged = true;
            break;
        }

        x = x_new;
        y = y_new;

        vx = vx_new;
        vy = vy_new;
    }

    cout << fixed << setprecision(10);

    if (converged) {
        cout << "Thuat toan hoi tu tai buoc lap: " << iter << endl;
    } else {
        cout << "Dat toi so buoc lap toi da hoac chua hoi tu.\n";
    }

    cout << "Gia tri x gan dung = " << x << endl;
    cout << "Gia tri y gan dung = " << y << endl;
    cout << "Gia tri nho nhat gan dung f(x, y) = " << f(x, y) << endl;
    cout << "Dao ham rieng theo x = " << dfdx(x, y) << endl;
    cout << "Dao ham rieng theo y = " << dfdy(x, y) << endl;
}

int main() {
    double x0, y0;
    double gamma, alpha, epsilon;
    int N;

    cout << "Nhap x0 = ";
    cin >> x0;

    cout << "Nhap y0 = ";
    cin >> y0;

    cout << "Nhap learning rate gamma = ";
    cin >> gamma;

    cout << "Nhap he so momentum alpha = ";
    cin >> alpha;

    cout << "Nhap so buoc lap N = ";
    cin >> N;

    cout << "Nhap sai so epsilon = ";
    cin >> epsilon;

    gradientDescentMomentum(x0, y0, gamma, alpha, N, epsilon);

    return 0;
}