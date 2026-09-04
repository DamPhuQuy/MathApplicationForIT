#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double grad(double x) {
    return 2 * x + 5 * cos(x);
}

double cost(double x) {
    return x * x + 5 * sin(x);
}

pair<vector<double>, int> myGD1(double alpha, double x0, double gra = 1e-3, int loop = 1000) {
    vector<double> x = {x0};
    for (int it = 0; it < loop; ++it) {
        double x_new = x.back() - alpha * grad(x.back());
        if (abs(grad(x_new)) < gra) {
            return make_pair(x, it);
        }
        x.push_back(x_new);
    }
    return make_pair(x, loop);
}

int main() {
    auto [x1, it1] = myGD1(0.1, -10);
    auto [x2, it2] = myGD1(0.1, 10);
    cout << "Solution x1 = " << x1.back() << ", cost = " << cost(x1.back()) << ", obtained after " << it1 << " iterations" << endl;
    cout << "Solution x2 = " << x2.back() << ", cost = " << cost(x2.back()) << ", obtained after " << it2 << " iterations" << endl;

    auto [x3, it3] = myGD1(0.5, 10);
    cout << "Solution x3 = " << x3.back() << ", cost = " << cost(x3.back()) << ", obtained after " << it3 << " iterations" << endl;

    auto [x4, it4] = myGD1(0.01, 10);
    cout << "Solution x4 = " << x4.back() << ", cost = " << cost(x4.back()) << ", obtained after " << it4 << " iterations" << endl;

    return 0;
}
