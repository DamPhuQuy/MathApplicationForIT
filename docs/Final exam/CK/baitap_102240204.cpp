#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// --- CÁC SIÊU THAM SỐ TỪ ĐỀ BÀI ---
const double X0 = 0.0;           // Điểm xuất phát h(x) = 0
const double GAMMA = 0.01;       // Hệ số học (Learning Rate)
const double ALPHA = 0.1;        // Hệ số quán tính (Momentum)
const double EPSILON = 1e-5;     // Sai số cho phép
const int MAX_ITER = 1000;       // Số bước lặp tối đa

// --- HÀM MỤC TIÊU (ĐỀ CHẴN) ---
double f(double x) {
    if (abs(x - 5.0) < 1e-9) return INFINITY; // Xử lý mẫu số = 0
    return (exp(2 * x) + 8 * x * x + 4 * x) / (5.0 - x);
}

// --- ĐẠO HÀM SỐ HỌC (Tự động tính f' và f'') ---
double grad(double x) {
    double h = 1e-5;
    return (f(x + h) - f(x - h)) / (2 * h);
}

double hessian(double x) {
    double h = 1e-4;
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

// --- 1. VANILLA GRADIENT DESCENT ---
void gradientDescent() {
    double x = X0;
    for (int i = 1; i <= MAX_ITER; i++) {
        double g = grad(x);
        if (abs(g) < EPSILON) {
            cout << "[1. Gradient Descent] Hoi tu sau " << i << " buoc. x = " << x << ", Min f(x) = " << f(x) << "\n";
            return;
        }
        x = x - GAMMA * g;
    }
    cout << "[1. Gradient Descent] Cham gioi han vong lap. x = " << x << "\n";
}

// --- 2. GRADIENT DESCENT WITH MOMENTUM ---
void momentum() {
    double x = X0;
    double v = 0.0;
    for (int i = 1; i <= MAX_ITER; i++) {
        double g = grad(x);
        if (abs(g) < EPSILON) {
            cout << "[2. Momentum]         Hoi tu sau " << i << " buoc. x = " << x << ", Min f(x) = " << f(x) << "\n";
            return;
        }
        v = ALPHA * v + GAMMA * g;
        x = x - v;
    }
    cout << "[2. Momentum]         Cham gioi han vong lap. x = " << x << "\n";
}

// --- 3. NEWTON-RAPHSON ---
void newtonRaphson() {
    double x = X0;
    for (int i = 1; i <= MAX_ITER; i++) {
        double g = grad(x);
        double h = hessian(x);
        
        if (abs(g) < EPSILON) {
            cout << "[3. Newton-Raphson]   Hoi tu sau " << i << " buoc. x = " << x << ", Min f(x) = " << f(x) << "\n";
            return;
        }
        if (abs(h) < 1e-12) {
            cout << "[3. Newton-Raphson]   Gay thuat toan do dao ham bac 2 bang 0.\n";
            return;
        }
        x = x - g / h; 
    }
    cout << "[3. Newton-Raphson]   Cham gioi han vong lap. x = " << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "===== KET QUA TOI UU DE CHAN =====\n";
    cout << "Diem xuat phat x0 = " << X0 << "\n\n";
    
    gradientDescent();
    momentum();
    newtonRaphson();

    return 0;
}