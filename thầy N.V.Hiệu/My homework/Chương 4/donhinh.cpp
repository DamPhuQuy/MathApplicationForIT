#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <string>

using std::vector;
using std::unordered_map;
using std::pair;
using std::cout;
using std::endl;
using std::setw;
using std::left;

unordered_map<int, bool> used_vars;

bool is_used(int index) {
    return used_vars[index];
}

int findPivotColumn(const vector<double>& coefficients) {
    int colIndex = -1;
    for (int i = 0; i < coefficients.size(); ++i) {
        if (coefficients[i] > 0 && (colIndex == -1 || coefficients[i] > coefficients[colIndex])) {
            colIndex = i;
        }
    }
    return colIndex;
}

int findPivotRow(const vector<vector<double>>& tableau, const vector<pair<int, double>>& limits, int pivotCol) {
    int rowIndex = -1;
    double smallest_ratio = 1e9;

    for (int i = 0; i < tableau.size() - 1; ++i) {
        if (!is_used(limits[i].first) && tableau[i][pivotCol] > 0) {
            double ratio = limits[i].second / tableau[i][pivotCol];
            if (ratio < smallest_ratio) {
                smallest_ratio = ratio;
                rowIndex = i;
            }
        }
    }
    return rowIndex;
}

void printTable(const vector<vector<double>>& tableau, const vector<pair<int, double>>& limits) {
    cout << "Current Tableau:\n";
    cout << left << setw(10) << "Var" << setw(10) << "Const";
    for (int j = 0; j < tableau[0].size(); ++j) {
        cout << left << setw(10) << "x" + std::to_string(j + 1);
    }
    cout << endl;

    for (int i = 0; i < tableau.size(); ++i) {
        if (i < limits.size()) {
            cout << left << setw(10) << "x" + std::to_string(limits[i].first + 1)
                 << setw(10) << limits[i].second;
        } else {
            cout << left << setw(10) << " " << setw(10) << " ";
        }

        for (int j = 0; j < tableau[i].size(); ++j) {
            cout << left << setw(10) << tableau[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

vector<double> simplex(const vector<double>& cost_fn, vector<double>& solution, vector<vector<double>>& tableau, vector<pair<int, double>>& limits) {
    int pivotCol, pivotRow;

    while (true) {
        for (int col = 0; col < tableau[0].size(); ++col) {
            tableau.back()[col] = -cost_fn[col];
            for (int row = 0; row < tableau.size() - 1; ++row) {
                tableau.back()[col] += cost_fn[limits[row].first] * tableau[row][col];
            }
        }

        pivotCol = findPivotColumn(tableau.back());
        used_vars[pivotCol] = true;

        if (pivotCol == -1 || tableau.back()[pivotCol] <= 0) {
            printTable(tableau, limits);
            return solution;
        }

        pivotRow = findPivotRow(tableau, limits, pivotCol);

        if (pivotRow == -1) {
            cout << "No optimal solution (unbounded)." << endl;
            exit(1);
        }

        double pivotVal = tableau[pivotRow][pivotCol];

        vector<pair<int, double>> limits_copy = limits;
        vector<vector<double>> tableau_copy = tableau;

        solution[limits[pivotRow].first] = 0;
        limits[pivotRow].first = pivotCol;
        limits[pivotRow].second /= pivotVal;
        solution[pivotCol] = limits[pivotRow].second;

        for (int i = 0; i < limits.size(); ++i) {
            if (i != pivotRow) {
                limits[i].second -= limits[pivotRow].second * tableau[i][pivotCol] / tableau[i][limits[i].first];
                solution[limits[i].first] = limits[i].second;
            }
        }

        for (int j = 0; j < tableau[0].size(); ++j) {
            tableau[pivotRow][j] /= pivotVal;
        }

        for (int i = 0; i < tableau.size() - 1; ++i) {
            if (i != pivotRow) {
                double factor = tableau[i][pivotCol];
                for (int j = 0; j < tableau[0].size(); ++j) {
                    tableau[i][j] -= factor * tableau[pivotRow][j];
                }
            }
        }
        printTable(tableau_copy, limits_copy);
    }
}

bool contains(const vector<pair<int, double>>& arr, int key) {
    for (const auto& item : arr) {
        if (item.first == key) return true;
    }
    return false;
}

bool verifyConstraints(const vector<vector<double>>& tableau, const vector<double>& limits_vals, vector<pair<int, double>>& limits) {
    int rows = tableau.size() - 1;
    for (int i = 0; i < rows; ++i) {
        limits.push_back({0, 0});
    }
    for (int col = 0; col < tableau[0].size(); ++col) {
        int count = 0, targetRow = -1;
        for (int row = 0; row < rows; ++row) {
            if (tableau[row][col] == 0) count += 2;
            else if (tableau[row][col] == 1) {
                count += 1;
                targetRow = row;
            }
            if (count == rows * 2 - 1 && !contains(limits, col)) {
                limits[targetRow].first = col;
                limits[targetRow].second = limits_vals[targetRow];
            }
        }
    }
    return limits.size() == rows;
}

void executeSimplex(const vector<double>& cost_fn, vector<double>& solution, vector<vector<double>> tableau, const vector<double>& limits_vals, vector<pair<int, double>>& limits) {
    solution.resize(tableau[0].size(), 0);
    if (!tableau.empty() && verifyConstraints(tableau, limits_vals, limits)) {
        for (const auto& limit : limits) {
            solution[limit.first] = limit.second;
        }
        solution = simplex(cost_fn, solution, tableau, limits);
    }
}

int main() {
    vector<vector<double>> tableau = {
        {-1, 3, 1, 1, 0, 0},
        {3, -4, 8, 0, 1, 0},
        {4, -2, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    vector<double> limits_vals = {7, 10, 12};

    vector<pair<int, double>> limits;

    vector<double> solution;

    vector<double> cost_fn = {-3, 1, 2, 0, 0, 0};

    executeSimplex(cost_fn, solution, tableau, limits_vals, limits);

    cout << "Optimal solution x = {";
    for (int i = 0; i < solution.size(); ++i) {
        cout << solution[i];
        if (i != solution.size() - 1) cout << ", ";
        else cout << "}" << endl;
    }

    double result = 0;
    for (int i = 0; i < solution.size(); ++i) {
        result += cost_fn[i] * solution[i];
    }
    cout << "f(max/min) = " << result << endl;
    return 0;
}

