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

bool check_prime(ll x) {
	if (x < 2)
		return false;
  	for (int i = 2; i*i <= x; ++i)
    	if (x % i == 0)
      		return false;
    return true;
}

class Number {
private:
	ll value;

public:
	Number(ll initialValue = 0): value(initialValue) {};
	~Number() {}

	void find_phi_function();
	void find_nearest_prime();
	void find_divisor();
	void find_perfect_numbers();

	friend istream& operator>>(istream&, Number&);
	friend ostream& operator<<(ostream&, const Number&);
};

vector<ll> divisors(ll n) {
	vector<ll> res;
	for (int i = 1; i*i <= n; ++i)
		if (n % i == 0) {
			res.push_back(i);
			if (i != n/i)
				res.push_back(n/i);
		}
	return res;
}

vector<ll> prime_divisors(ll n) {
	vector<ll> prime, dvs = divisors(n);
	for (auto v : dvs)
		if (min_dvs[v] == v)
			prime.push_back(v);
	return prime;
}

void Number::find_divisor() {
	vector<ll> dvs = divisors(value);
	cout << "Quantity of divisors: " << dvs.size() << nln;
	vector<ll> prime;
	for (auto v : dvs)
		if (min_dvs[v] == v)
			prime.push_back(v);
	cout << "Quantity of prime divisors: " << prime.size() << nln;
	sort(prime.begin(), prime.end());
	cout << "They are: ";
	for (auto v : prime)
		cout << v << ' '; cout << nln;
	cout << "Sum of them: " << accumulate(prime.begin(), prime.end(), 0) << nln;

}

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
	ll res = value, d = 0;
	while (min_dvs[res+d] != res+d)
		d++;
	cout << "The nearest prime number of the given number is: " << res+d << nln;
}

void Number::find_perfect_numbers() {
	vector<ll> perfect;
	for (ll i = 1; i <= value; ++i) {
		vector<ll> dvs = divisors(i);
		if (accumulate(dvs.begin(), dvs.end(), 0) - i == i)
			perfect.push_back(i);
	}
	cout << "size: " << perfect.size() << nln;
	cout << "The perfect numbers from 1 -> n are: ";
	for (auto v : perfect)
		cout << v << ' ';
	cout << nln;	
	cout << "Sum of them: " << accumulate(perfect.begin(), perfect.end(), 0) << nln;
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
	choices['1'] = "1.a) Find the coprime of given number (from 1 to n), listing it, calculate sum.";
	choices['2'] = "1.b) Find nearest Prime number of given number";
	choices['3'] = "2.a) Find quantity of divisors of given number, listing and sumary the prime numbers in those";
	choices['4'] = "2.b) Find all perfect numbers from 1 to n, listing and sumary.";
}

void Enter(Number& n) {
	cout << "Please Enter a number: ";
	cin >> n;
}

int main() {	
	build_min_dvs_array();

	Number n(ll(82300));

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
				n.find_nearest_prime();
				system("pause");
				break;
			case '3':
				n.find_divisor();
				system("pause");
				break;
			case '4':
				n.find_perfect_numbers();
				system("pause");
				break;
		}
	} while (choice != 27);

	return 0;
}