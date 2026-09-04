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

class Number {
private:
	ll value;
	vector<ll> exponents, factors;
	void factorize();
	ll count_divisors();
	ll sum_divisors();
	ll product_divisors();
	bool is_perfect();
	ll nearest_prime(ll, ll, ll);
	ll gcd(ll, ll); // Euclid's Algorithm

public:
	Number(ll initialValue = 0): value(initialValue) {};
	~Number() {}

	void show_factorized();
	void show_count_divisors();
	void show_sum_divisors();
	void show_product_divisors();
	void show_if_perfect();
	void show_density();
	void find_primes(ll s);
	void find_nearest_prime();
	void find_gcd(); 

	friend istream& operator>>(istream&, Number&);
	friend ostream& operator<<(ostream&, const Number&);
};

istream& operator>>(istream& input, Number& num) {
	input >> num.value;
	return input;
}

ostream& operator<<(ostream& output, const Number& num) {
	output << num.value;
	return output;
}

void build_min_dvs_array() {
	min_dvs = new ll[MAX_VALUE+1];
	qtt_dvs = new ll[MAX_VALUE+1];

	for (ll v = 0; v <= MAX_VALUE; ++v)
		min_dvs[v] = v;

	for (ll d = 2; d*d <= MAX_VALUE; ++d) {
		for (ll m = 2*d; m <= MAX_VALUE; m += d) {
			if (min_dvs[m] == m)
				min_dvs[m] = d;
		}
	}

	for (ll i = 2; i <= MAX_VALUE; ++i) {
		qtt_dvs[i] = qtt_dvs[i-1];
		if (min_dvs[i] == i) {
			primes.push_back(i);
			qtt_dvs[i]++;
		}
	}
}

void Number::factorize() {
	factors.clear(), exponents.clear();
	ll tmp = value;
	while (tmp > 1) {
		if (factors.empty() || min_dvs[tmp] != factors.back()) {
			factors.push_back(min_dvs[tmp]);
			exponents.push_back(1);
		} else {
			exponents.back()++;
		}
		tmp /= min_dvs[tmp];
	}
}

void Number::show_factorized() {
	factorize();
	cout << nln;
	ll n = factors.size();
	cout << value << " is factorized: ";
	for (ll i = 0; i < n-1; ++i)
		cout << factors[i] << "^" << exponents[i] << " * ";
	cout << factors.back() << "^" << exponents.back() << nln;
	cout << nln;
}

ll Number::count_divisors() {
	factorize();
	ll cnt = 1;
	for (auto v : exponents)
		cnt *= (v+1);
	return cnt;
}

void Number::show_count_divisors() {
	cout << nln << "Number of the factors of " << value << " : " << count_divisors() << nln << nln;
}

ll Number::sum_divisors() {
	factorize();
	ll s = 1, n = factors.size();
	for (ll i = 0; i < n; ++i) 
		s *= (fast_pow(factors[i], exponents[i]+1) - 1)/(factors[i] - 1);
	return s;
}

void Number::show_sum_divisors() {
	cout << nln << "Summary of all factors of " << value << " : " << sum_divisors() << nln << nln;
}

ll Number::product_divisors() {
	ll pro = fast_pow(value, count_divisors()/2) * (is_sqr_number(value) ? round(sqrt(value)) : 1);
	return pro;
}

void Number::show_product_divisors() {
	cout << nln << "Product of all factors of " << value << " : " << product_divisors() << nln << nln;
}

bool Number::is_perfect() {
	return 2*value == sum_divisors();
}

void Number::show_if_perfect() {
	cout << nln << "The given number " << value << " is" << (is_perfect() ? "" : " NOT") 
	<< " perfect number!";
	cout << nln << nln;
}

void Number::show_density() {
	cout << nln << "The Density of primes of " << value << " is " << qtt_dvs[value] << "/"
	<< round(1.0*value/log(value)) << nln << nln;
}

void Number::find_primes(ll s) {
	factorize();
	vector<ll> res;
	for (auto v : factors)
		if (s <= v && v <= value)
			res.push_back(v);

	if (res.empty()) {
		cout << nln << "There is no factors such that." << nln << nln;
	} else {
		cout << nln << "All those prime factors are: ";
		for (auto v : res)
			cout << v << ' ';
		cout << nln << nln;
	}
}

ll Number::nearest_prime(ll l, ll r, ll n) {
	if (l > r)
		return 2;

	if (r == 0 || l == primes.size()-1)
		return primes[r];

	ll mid = (l+r)/2;
	if (primes[mid] < n && n < primes[mid+1])
		return primes[mid];

	if (primes[mid+1] < n)
		return nearest_prime(mid+1, r, n);
	else // n < primes[mid]
		return nearest_prime(l, mid-1, n);
}

void Number::find_nearest_prime() {
	cout << nln << "The nearest Prime number of " << value << " is: "
	<< nearest_prime(2, primes.size()-1, value) << nln << nln;
}

ll Number::gcd(ll a, ll b) {
	if (a % b == 0)
		return b;
	return gcd(b, a%b);
}

void Number::find_gcd() {
	ll a = value, b;
	cout << "Please enter the remaining number to find gcd: ";
	cin >> b;
	cout << nln << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << nln << nln;
}

void build_choices_dictionary(map<char, string>& choices) {
	choices['0'] = "Enter another Number";
	choices['1'] = "Factorize";
	choices['2'] = "Calculate Number of factors";
	choices['3'] = "Calculate Summary of all factors of given number";
	choices['4'] = "Calculate Product of all factors of given number";
	choices['5'] = "Check if this number is perfect";
	choices['6'] = "Show Density of primes";
	choices['7'] = "Find all prime factor between selected number and given number";
	choices['8'] = "Find nearest Prime number of given number";
	choices['9'] = "Find GCD of given number with another number";
}

void Enter(Number& n) {
	cout << "Please Enter a number: ";
	cin >> n;
}

int main() {	
	build_min_dvs_array();

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
		cout << "3: " << choices['3'] << nln;
		cout << "4: " << choices['4'] << nln;
		cout << "5: " << choices['5'] << nln;
		cout << "6: " << choices['6'] << nln;
		cout << "7: " << choices['7'] << nln;
		cout << "8: " << choices['8'] << nln;
		cout << "9: " << choices['9'] << nln;
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
				n.show_factorized();
				system("pause");
				break;
			case '2':
				n.show_count_divisors();
				system("pause");
				break;
			case '3':
				n.show_sum_divisors();
				system("pause");
				break;
			case '4':
				n.show_product_divisors();
				system("pause");
				break;
			case '5':
				n.show_if_perfect();
				system("pause");
				break;
			case '6':
				n.show_density();
				system("pause");
				break;
			case '7':
				n.find_primes(7); // Cuz 7 is the selected number
				system("pause");
				break;
			case '8':
				n.find_nearest_prime();
				system("pause");
				break;
			case '9':
				n.find_gcd();
				system("pause");
				break;
		}
	} while (choice != 27);

	return 0;
}