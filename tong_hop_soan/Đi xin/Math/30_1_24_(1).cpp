// Le Duc Phuc Long, 01/22/24, Da Nang
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

typedef long long ll;

#define nln '\n'

const ll MAX_VALUE = 1e7;

ll *min_dvs, *qtt_dvs;
vector<ll> primes;


ll fast_pow(ll n, ll m) {
	ll res = 1;
	while (m > 0) {
		if (m % 2)
			res *= n;
		n *= n, m /= 2;
	}
	return res;
}

bool is_sqr_number(ll x) {
	return sqrt(x) == static_cast<long long>(sqrt(x));
}

ll gcd(ll a, ll b) {
	if (a % b == 0)
		return b;
	return gcd(b%a, a);
}

class Number {
private:
	ll value;

public:
	Number(ll initialValue = 0): value(initialValue) {};
	~Number() {}

	void find_phi_function();
	void find_nearest_prime();

	friend istream& operator>>(istream&, Number&);
	friend ostream& operator<<(ostream&, const Number&);
};

void Number::find_phi_function() {
	ll tmp = value;
	ll res = value;
	for (int i = 2; i*i <= value; ++i) {
		if (tmp % i == 0) {
			while (tmp % i == 0)
				tmp /= i;
			res -= res / i;
		}
	}
	if (tmp > 1)
		res -= res / tmp;

	cout << "Number of coprime < n: " << res << nln;
	cout << "They are: ";
	ll t = 0;
	for (ll i = 1; i < value; ++i)
		if (gcd(i, value) == 1) {
			cout << i << ' ';
			t += i;
		}
	cout << nln;
	cout << "Their sum: " << t << nln;
}

void Number::find_nearest_prime() {

}

istream& operator>>(istream& input, Number& num) {
	input >> num.value;
	return input;
}

ostream& operator<<(ostream& output, const Number& num) {
	output << num.value;
	return output;
}

void build_choices_dictionary(map<char, string>& choices) {
	choices['0'] = "Enter another Number";
	choices['1'] = "Find the coprime of number (from 1 to n), listing it, calculate sum.";
	choices['2'] = "Find nearest Prime number of given number";
}

void Enter(Number& n) {
	cout << "Please Enter a number: ";
	cin >> n;
}

int main() {	
	Number n(ll(2024));

	map<char, string> choices;
	build_choices_dictionary(choices);

	char choice;
	do {
		system("cls");
		cout << "Current Number is: " << n << nln;
		cout << "Give me your choice by pressing one of the number keys below:" << nln;
		cout << "0: " << choices['0'] << nln;
		cout << "1: " << choices['1'] << nln;
		cout << "2: " << choices['2'] << nln;
		cout << "Press ESC to quit this." << nln;

		choice = getch();
		if (choice == 27)
			continue;

		system("cls");
		cout << "You chose " << choice << ": " << choices[choice] << nln;

		switch (choice) {
			case '0':
				Enter(n);
				break;
			case '1':
				n.find_phi_function();
				system("pause");
				break;
			case '2':
				system("pause");
				break;
		}
	} while (choice != 27);

	return 0;
}