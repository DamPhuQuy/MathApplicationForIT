#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

bool soSanhDiem(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

long long tichCheo(Point O, Point A, Point B) {
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

long long binhPhuongKhoangCach(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

vector<Point> baoLoi1(vector<Point> p) {
    sort(p.begin(), p.end(), soSanhDiem);

    vector<Point> duoi, tren;
    int n = p.size();

    for (int i = 0; i < n; i++) {
        while (duoi.size() >= 2 &&
               tichCheo(duoi[duoi.size()-2], duoi.back(), p[i]) <= 0)
            duoi.pop_back();
        duoi.push_back(p[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        while (tren.size() >= 2 &&
               tichCheo(tren[tren.size()-2], tren.back(), p[i]) <= 0)
            tren.pop_back();
        tren.push_back(p[i]);
    }

    duoi.pop_back();
    tren.pop_back();

    for (int i = 0; i < tren.size(); i++)
        duoi.push_back(tren[i]);

    return duoi;
}

Point goc;

bool soSanhGoc(Point a, Point b) {
    long long c = tichCheo(goc, a, b);
    if (c == 0) return binhPhuongKhoangCach(goc,a) < binhPhuongKhoangCach(goc,b);
    return c > 0;
}

vector<Point> baoLoi2(vector<Point> p) {
    int n = p.size();
    if (n <= 2) return p;

    int id = 0;
    for (int i = 1; i < n; i++) if (p[i].y < p[id].y || (p[i].y == p[id].y && p[i].x < p[id].x)) id = i;

    Point t = p[0];
    p[0] = p[id];
    p[id] = t;
    goc = p[0];

    sort(p.begin()+1, p.end(), soSanhGoc);

    vector<Point> st;
    st.push_back(p[0]);
    st.push_back(p[1]);

    for (int i = 2; i < n; i++) {
        while (st.size() >= 2 &&
               tichCheo(st[st.size()-2], st.back(), p[i]) <= 0)
            st.pop_back();
        st.push_back(p[i]);
    }

    return st;
}

vector<Point> baoLoi3(vector<Point> p) {
    int n = p.size();
    if (n <= 2) return p;

    vector<Point> hull;
    int trai = 0;

    for (int i = 1; i < n; i++)
        if (p[i].x < p[trai].x) trai = i;

    int cur = trai;
    do {
        hull.push_back(p[cur]);
        int nxt = (cur+1)%n;

        for (int i = 0; i < n; i++)
            if (tichCheo(p[cur], p[nxt], p[i]) < 0)
                nxt = i;

        cur = nxt;

    } while (cur != trai);

    return hull;
}

long long khoangCachDuong(Point A, Point B, Point P) {
    return abs(tichCheo(A,B,P));
}

int phia(Point A, Point B, Point P) {
    long long v = tichCheo(A,B,P);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}

void quickHullDeQuy(vector<Point>& p, Point A, Point B, int side, vector<Point>& hull) {
    int id = -1;
    long long mx = 0;

    for (int i = 0; i < p.size(); i++) {
        long long d = khoangCachDuong(A,B,p[i]);
        if (phia(A,B,p[i]) == side && d > mx) {
            id = i;
            mx = d;
        }
    }

    if (id == -1) {
        hull.push_back(A);
        hull.push_back(B);
        return;
    }

    quickHullDeQuy(p, p[id], A, -phia(p[id],A,B), hull);
    quickHullDeQuy(p, p[id], B, -phia(p[id],B,A), hull);
}

vector<Point> baoLoi4(vector<Point> p) {
    int n = p.size();
    if (n <= 2) return p;

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].x < p[min_x].x) min_x = i;
        if (p[i].x > p[max_x].x) max_x = i;
    }

    vector<Point> hull;

    quickHullDeQuy(p, p[min_x], p[max_x], 1, hull);
    quickHullDeQuy(p, p[min_x], p[max_x], -1, hull);

    sort(hull.begin(), hull.end(), soSanhDiem);
    hull.erase(unique(hull.begin(), hull.end(), [](Point a, Point b){
        return a.x == b.x && a.y == b.y;
    }), hull.end());

    return hull;
}

vector<Point> baoLoi(vector<Point>& p) {
    int chon;
    cout << "\nChon thuat toan (1-4): ";
    cin >> chon;

    if (chon == 1) return baoLoi1(p);
    if (chon == 2) return baoLoi2(p);
    if (chon == 3) return baoLoi3(p);
    if (chon == 4) return baoLoi4(p);

    cout << "Sai, dung mac dinh 1\n";
    return baoLoi1(p);
}

double dienTichDaGiac(vector<Point> p) {
    double s = 0;
    int n = p.size();

    for (int i = 0; i < n; i++) {
        int j = (i+1)%n;
        s += p[i].x*p[j].y - p[i].y*p[j].x;
    }

    return fabs(s)/2.0;
}

bool namTrenDoan(Point P, Point A, Point B) {
    if (tichCheo(A,B,P) != 0) return false;

    return P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x) &&
           P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y);
}

bool namTrenBaoLoi(Point p, vector<Point> hull) {
    int n = hull.size();

    for (int i = 0; i < n; i++)
        if (namTrenDoan(p, hull[i], hull[(i+1)%n]))
            return true;

    return false;
}

void phanTichCanh(vector<Point> hull, double& chuVi) {
    long long minD = 9e18, maxD = -1;
    vector<pair<Point,Point>> ngan, dai;

    int n = hull.size();
    chuVi = 0;

    for (int i = 0; i < n; i++) {
        int j = (i+1)%n;

        long long d = binhPhuongKhoangCach(hull[i], hull[j]);
        chuVi += sqrt(d);

        if (d < minD) {
            minD = d;
            ngan.clear();
            ngan.push_back({hull[i], hull[j]});
        } else if (d == minD)
            ngan.push_back({hull[i], hull[j]});

        if (d > maxD) {
            maxD = d;
            dai.clear();
            dai.push_back({hull[i], hull[j]});
        } else if (d == maxD)
            dai.push_back({hull[i], hull[j]});
    }

    cout << "\nCanh ngan nhat:\n";
    for (auto e : ngan)
        cout << "("<<e.first.x<<","<<e.first.y<<") - ("
             <<e.second.x<<","<<e.second.y<<")\n";

    cout << "\nCanh dai nhat:\n";
    for (auto e : dai)
        cout << "("<<e.first.x<<","<<e.first.y<<") - ("
             <<e.second.x<<","<<e.second.y<<")\n";
}

int main() {
    vector<Point> p = {
        {-4,2}, {-3,-2}, {-1,4}, {-1,-4}, {0,0},
        {1,-2}, {1,-4}, {2,-3}, {3,-4}, {5,-2}
    };

    sort(p.begin(), p.end(), soSanhDiem);

    cout << "Danh sach diem:\n";
    for (auto x : p)
        cout << "(" << x.x << "," << x.y << ")\n";

    vector<Point> hull = baoLoi(p);

    cout << "\nBao loi:\n";
    for (auto x : hull)
        cout << "(" << x.x << "," << x.y << ")\n";

    int dem = 0;
    cout << "\nDiem ben trong:\n";

    for (auto x : p)
        if (!namTrenBaoLoi(x, hull)) {
            dem++;
            cout << "(" << x.x << "," << x.y << ")\n";
        }

    cout << "So luong: " << dem << endl;

    double chuVi;
    phanTichCanh(hull, chuVi);

    cout << "\nChu vi: " << chuVi << endl;
    cout << "Dien tich: " << dienTichDaGiac(hull) << endl;

    return 0;
}