#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

long double f(long double x, int y) {
    if (y == 1) {
        return -log10(1 / (1 + exp(-x)));
    } else if (y == 0) {
        return -log10(1 - 1 / (1 + exp(-x)));
    }
    return 0; 
}

long double grad(long double x, int y) {
    if (y == 1) {
        return (1 / log(10)) * (exp(-x) / (1 + exp(-x)));
    } else if (y == 0) {
        return -(1 / log(10)) * (exp(-x) / (1 + exp(-x)));
    }
    return 0; 
}

pair<vector<long double>, int> gradientDescentWithMomentum(long double alpha, long double beta, long double x0, int y, long double gra = 1e-5, int loop = 10000) {
    vector<long double> x;
    x.push_back(x0);
    long double v = 0;
    
    for (int it = 0; it < loop; ++it) {
        long double g = grad(x.back(), y);
        v = beta * v + alpha * g;
        long double x_new = x.back() - v;
        
        if (abs(g) < gra) {
            break;
        }
        
        x.push_back(x_new);
    }
    
    return make_pair(x, x.size() - 1);
}

int main() {
    int y = 1; 
    pair<vector<long double>, int> my_pair = gradientDescentWithMomentum(0.0001, 0.4, 5.0, y);
    long double funcost = f(my_pair.first.back(), y);
    cout << "x1 = " << my_pair.first.back() << ", y1 = " << funcost << ", sau " << my_pair.second << " step" << endl;

    return 0;
}