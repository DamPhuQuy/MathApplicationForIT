// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<double>> matrix;
#define nln '\n'

void enterMatrix(matrix &mtx, ll &n) {
    cout << "Enter the size of matrix: ";
    cin >> n;
    mtx.resize(n, vector<double>(n));
    cout << "Enter Matrix: " << nln;
    for (auto &row : mtx)
        for (auto &val : row)
            cin >> val;
}

void viewMatrix(const matrix &arr) {
    for (auto row : arr) {
        for (auto val : row)
            cout << val << ' ';
        cout << endl;
    }
}

void swap2row(vector<double> &a, vector<double> &b) {
	vector<double> tmp = a; a = b; b = tmp;
}

void Gaussian_elimination(matrix &mtx) {
	ll n = mtx.size();
	if (n == 0 || mtx[0].size() != n)
		return;

	for (ll row = 0; row < n-1; ++row) {
		ll foundRowIndex = -1;
        for (ll rowf = row; rowf < n; ++rowf) {
            if (mtx[rowf][row] != 0) {
                foundRowIndex = rowf;
                break;
            }
        }
		if (foundRowIndex != -1) {
			swap2row(mtx[row], mtx[foundRowIndex]);
		} else {
			continue;
		}
		// Now mtx[row][row] is gonna be different with 0
		for (ll erow = row+1; erow < n; ++erow) {
			double k = -mtx[erow][row]/mtx[row][row];
			for (ll col = 0; col < n; ++col) 
				mtx[erow][col] += k*mtx[row][col];
		}
	}
}

int main(int argc, char** argv) {
    // Fast Input
    // cin.tie(0)->sync_with_stdio(0);
    // Input
    ll n;
    matrix mtx = {
		{1, 2, 3, 4}, 
		{5, 6, 7, 8}, 
		{9, 10, 11, 12},
		{13, 14, 15, 16}};;
    // enterMatrix(mtx, n);
    viewMatrix(mtx);
    Gaussian_elimination(mtx);
    cout << nln;
    viewMatrix(mtx);

    return 0;
}