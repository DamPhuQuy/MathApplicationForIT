// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define nln '\n'

struct Point {
	ll x, y;
};

ll orientation(Point A, Point B, Point C) {
	// We define the orientation of three given points by 
	// calculating the slope
	// slope of segment AB : (yB - yA) / (xB - xA)
	// slope of segment BC : (yC - yB) / (xC - xB)
	// We compare (yB - yA) / (xB - xA) and (yC - yB) / (xC - xB)
	// We compare (yB - yA) * (xC - xB) and (yC - yB) * (xB - xA)
	ll res = (B.y - A.y) * (C.x - B.x) - (C.y - B.y) * (B.x - A.x);
	return (res == 0) ? 0 : (res > 0 ? 1 : -1);
	// if the function return 0 --> collinear
	// if the function return 1 --> clockwise
	// if the function return 2 --> anti-clockwise
}

int main(int argc, char const *argv[])
{
	Point p1 = { 0, 0 }, p2 = { 4, 4 }, p3 = { 1, 2 };
    int o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << endl;
 
    p1 = { 0, 0 }, p2 = { 4, 4 }, p3 = { 1, 1 };
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";
    cout << endl;
 
    p1 = { 1, 2 }, p2 = { 4, 4 }, p3 = { 0, 0 };
    o = orientation(p1, p2, p3);
    if (o == 0)
        cout << "Linear";
    else if (o == 1)
        cout << "Clockwise";
    else
        cout << "CounterClockwise";

	return 0;
}