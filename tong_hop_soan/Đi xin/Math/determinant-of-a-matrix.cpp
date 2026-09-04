#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

typedef long long ll;
#define nln '\n'

void swap(vector<double> &a, vector<double> &b) {
	vector<double> tmp = a; a = b; b = tmp;
}

void show(const vector<vector<double>>& mtx) {
	cout << nln;
	for (auto row : mtx) {
		for (auto v : row)
			cout << v << ' ';
		cout << nln;
	}
}

double determinantNxN(vector<vector<double>> mtx) {
	ll n = mtx.size();
	if (n == 0 || mtx[0].size() != n)
		return 0;

	double res = 1;
	for (ll row = 0; row < n-1; ++row) {
		ll foundRowIndex = -1;
			for (ll rowf = row; rowf < n; ++rowf) {
				if (mtx[rowf][row]) {
					foundRowIndex = rowf;
					break;
				}
			}
		if (foundRowIndex != -1) {
			if (foundRowIndex != row)
				res *= -1;
			swap(mtx[row], mtx[foundRowIndex]);
		} else {
			return 0;
		}
		// Now mtx[row][row] is gonna be different with 0

		res *= mtx[row][row];

		for (ll erow = row+1; erow < n; ++erow) {
			double k = -mtx[erow][row]/mtx[row][row];
			for (ll col = 0; col < n; ++col) 
				mtx[erow][col] += k*mtx[row][col];
		}
	}

	return res*mtx[n-1][n-1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// vector<vector<double>> mat = {
	// 	{4, 3, 2, 2}, 
	// 	{0, 1, -3, 3}, 
	// 	{0, -1, 3, 3},
	// 	{0, 3, 1, 1}};
	// vector<vector<double>> mat = {
	// 	{1, 0, 2, -1}, 
	// 	{3, 0, 0, 5}, 
	// 	{2, 1, 4, -3},
	// 	{1, 0, 5, 0}};
	vector<vector<double>> mat = {
		{1, 45, 2, 9}, 
		{51, 7, 8, 5}, 
		{2, 1, 3, -3},
		{1, 32, 5, 12}};
    cout << "Determinant of the matrix: " << determinantNxN(mat) << endl;

	return 0;
}