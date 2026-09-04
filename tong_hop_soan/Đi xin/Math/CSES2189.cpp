#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> Point;
typedef complex<ll> Vector;

#define nln '\n'
#define x real()
#define y imag()

ll crossProduct(Vector A, Vector B) {
    return (A.x * B.y) - (A.y * B.x);
}

// function to check the side of a point to a straight line
// defined by other two points.
ll checkTheSide(Point C, Point A, Point B) {
    Vector CA = A - C;
    Vector CB = B - C;
    ll crossProductResult = crossProduct(CA, CB);
    if (crossProductResult > 0) {
        return 1;
    } else if (crossProductResult < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    // Give a straight line defined by 2 points A and B
    // And a point C
    Point A = {3, 1}, B = {5, 2}, C = {4, 0};

    ll n;  cin >> n;
    while (n--) {
    	ll x1, y1, x2, y2, x3, y3;
    	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    	A = Point(x1, y1), B = Point(x2, y2), C = Point(x3, y3);
        ll pst = checkTheSide(C, A, B);
        if (pst == 0) {
            cout << "TOUCH" << nln;
        } else if (pst < 0) {
            cout << "RIGHT" << nln;
        } else {
            cout << "LEFT" << nln;
        }
    }

    return 0;
}
