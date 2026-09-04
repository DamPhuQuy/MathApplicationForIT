#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iomanip>

using namespace std;

unordered_map<int, bool> alr;

bool is_alr(int key) {
    return alr[key];
}

int findPivotColumn(const vector<double>& cost) {
    int pivotCol = -1;
    for (int i = 0; i < cost.size(); i++) {
        if (cost[i] > 0) {
            if (pivotCol == -1 || cost[i] > cost[pivotCol]) {
                pivotCol = i;
            }
        }
    }
    return pivotCol;
}

int findPivotRow(const vector<vector<double>>& a, const vector<pair<int, double>>& side, int pivotCol) {
    int pivotRow = -1;
    double minRatio = 1e9;

    for (int i = 0; i < a.size() - 1; i++) {
        if (true) {//is_alr(side[i].first) == false) {
            if (a[i][pivotCol] > 0) {
                double ratio = side[i].second / a[i][pivotCol];
                if (ratio < minRatio) {
                    minRatio = ratio;
                    pivotRow = i;
                } else if (ratio == minRatio) {
                    pivotRow = (side[pivotRow].first < side[i].first) ? pivotRow : i;
                }
            }
        }
    }
    return pivotRow;
}

// Hàm in bảng
void printTable(const vector<vector<double>>& a, const vector<pair<int, double>>& side) {
    cout << "Bảng hiện tại:\n";
    cout << left << setw(10) << "x*" << setw(10) << "PA";
    for (int j = 0; j < a[0].size(); j++) {
        cout << left << setw(10) << "x" + to_string(j + 1);
    }
    cout << endl;

    for (int i = 0; i < a.size(); i++) {
        if (i < side.size()) {
            cout << left << setw(10) << "x" + to_string(side[i].first + 1)
                 << setw(10) << side[i].second;
        } else {
            cout << left << setw(10) << " " << setw(10) << " ";
        }

        for (int j = 0; j < a[i].size(); j++) {
            cout << left << setw(10) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


// Hàm triển khai phương pháp đơn hình
vector<double> Simplex(const vector<double>& c, vector<double>& x, vector<vector<double>>& a, vector<pair<int, double>>& side) {
    int pivotCol, pivotRow;

    while (true) {
        for (int col = 0; col < a[0].size(); col++) {
            a.back()[col] = -c[col];
            for (int row = 0; row < a.size() - 1; row++) {
                a.back()[col] += c[side[row].first] * a[row][col];
            }
        }

        pivotCol = findPivotColumn(a.back());
        alr[pivotCol] = true;

        if (pivotCol == -1 || a.back()[pivotCol] <= 0) {
            printTable(a, side);
            return x;
        }

        pivotRow = findPivotRow(a, side, pivotCol);

        if (pivotRow == -1) {
            cout << "Không có giải pháp tối ưu (không giới hạn)." << endl;
            exit(1);
        }

        double pivotValue = a[pivotRow][pivotCol];

        vector<pair<int, double>> temp = side;
        vector<vector<double>> tmp = a;

        x[side[pivotRow].first] = 0;
        side[pivotRow].first = pivotCol;
        side[pivotRow].second /= pivotValue;
        x[pivotCol] = side[pivotRow].second;

        for (int i = 0; i < side.size(); i++) {
            if (i != pivotRow) {
                side[i].second -= side[pivotRow].second * a[i][pivotCol] / a[i][side[i].first];
                x[side[i].first] = side[i].second;
            }
        }

        for (int j = 0; j < a[0].size(); j++) {
            a[pivotRow][j] /= pivotValue;
        }

        for (int i = 0; i < a.size() - 1; i++) {
            if (i != pivotRow) {
                double factor = a[i][pivotCol];
                for (int j = 0; j < a[0].size(); j++) {
                    a[i][j] -= factor * a[pivotRow][j];
                }
            }
        }
        printTable(tmp, temp);
    }
}

bool is_in(const vector<pair<int, double>>& arr, int key) {
    for (const auto& a : arr) {
        if (a.first == key) return true;
    }
    return false;
}

bool is_ct(const vector<vector<double>>& a, const vector<double>& b, vector<pair<int, double>>& side) {
    int e_num = a.size() - 1;
    for (int i = 0; i < a.size() - 1; i++) {
        side.push_back(make_pair(0, 0));
    }
    for (int col = 0; col < a[0].size(); col++) {
        int something = 0;
        int take = -1;
        for (int row = 0; row < e_num; row++) {
            if (a[row][col] == 0) something += 2;
            else if(a[row][col] == 1) {
                something += 1;
                take = row;
            }
        if (something == e_num * 2 - 1 && !is_in(side, col))
            side[take].first = col;
            side[take].second = b[take];
        }
    }
    if (side.size() == e_num) return true;
    return false;
}

void solve(const vector<double> c, vector<double>& x, vector<vector<double>> a, const vector<double>& b, vector<pair<int, double>>& side) {
    x.resize(a[0].size(), 0);
    if (!a.empty()) {
        if (is_ct(a, b, side)) {
            for (const auto& s : side) {
                x[s.first] = s.second;
            }
            x = Simplex(c, x, a, side);
        }
    }
}

int main() {
    vector<vector<double>> a = {
        {0.5, -5.5, -2.5, 9, 1, 0, 0},
        {0.5, -1.5, -0.5, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0}
    };

    vector<double> b = {0, 0, 1};

    vector<pair<int, double>> side;

    vector<double> x;

    vector<double> c = {-10, 57, 9, 24, 0, 0, 0};

    solve(c, x, a, b, side);

    cout << "Giải pháp tối ưu x = {";
    for (int i = 0; i < x.size(); i++) {
        cout << x[i];
        if (i != x.size() - 1) cout << ", ";
        else cout << "}" << endl;
    }

    double answer = 0;
    for (int i = 0; i < x.size(); i++) {
        answer += c[i] * x[i];
    }
    cout << "f(min) = " << answer << endl;
    return 0;
}