#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
// Hàm tìm trong khoảng 
int find_closest_index(const vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    
    int closest_index = 0;
    int min_diff = abs(nums[0] - target);

    for (int i = 1; i < nums.size(); i++) {
        int diff = abs(nums[i] - target);
        if (diff < min_diff) {
            closest_index = i;
            min_diff = diff;
        }
    }
    return closest_index;
}
// Hàm tìm nói chung
int nearest_prime(int N) {
    int lower_prime = N;
    
    while (lower_prime > 1 && !is_prime(lower_prime)) {
        --lower_prime;
    }

    int upper_prime = N;
    while (!is_prime(upper_prime)) {
        ++upper_prime;
    }

    if (lower_prime <= 1) {
        return upper_prime;
    }

    if (N - lower_prime <= upper_prime - N) {
        return lower_prime;
    } else {
        return upper_prime;
    }
}

int main() {
    int target;
    cin >> target;
    // Trong khoảng
    vector<int> M; 
    for (int i = 2; i < 500; i++) {
        M.push_back(i);
    }

    vector<int> primes; 
    for (int i = 0; i < M.size(); i++) {
        if (is_prime(M[i])) {
            primes.push_back(M[i]);
        }
    }

    cout << "\nCac so nguyen to trong tap M: ";
    for (int num : primes) {
        cout << num << " ";
    }
    cout << "\n\n";

    if (!primes.empty()) {
        int closest_index = find_closest_index(primes, target);
        cout << "KET QUA TRONG TAP M " << endl;
        cout << "Chi so cua so nguyen to gan nhat voi " << target << " la: " << closest_index << endl;
        cout << "Gia tri cua no la: " << primes[closest_index] << endl;
    } else {
        cout << "Khong co so nguyen to nao trong tap M!" << endl;
    }

    int closest_prime_overall = nearest_prime(target);
    cout << "\nKET QUA TONG QUAT" << endl;
    cout << "So nguyen to gan nhat voi " << target << "la: " << closest_prime_overall << endl;

    return 0;
}