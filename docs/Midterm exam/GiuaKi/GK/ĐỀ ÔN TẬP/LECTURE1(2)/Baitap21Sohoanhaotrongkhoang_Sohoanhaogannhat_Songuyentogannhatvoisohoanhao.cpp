#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số hoàn hảo
bool is_perfect(int num) {
    if (num <= 1) return false; // Loại trừ số 1 và các số âm
    int sum = 1; // Tổng các ước của num, bắt đầu từ 1
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

// Hàm kiểm tra số nguyên tố
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm số gần nhất với target trong một vector
int find_closest(const vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    
    int closest = nums[0];
    int min_diff = abs(nums[0] - target);

    for (int num : nums) {
        int diff = abs(num - target);
        if (diff < min_diff) {
            closest = num;
            min_diff = diff;
        }
    }
    return closest;
}

// Hàm tìm số nguyên tố gần nhất với một số
int find_closest_prime(int value) {
    int lower = value;
    // Lùi dần để tìm số nguyên tố nhỏ hơn hoặc bằng value
    while (lower > 1 && !is_prime(lower)) {
        lower--;
    }

    int upper = value;
    // Tăng dần để tìm số nguyên tố lớn hơn hoặc bằng value
    while (!is_prime(upper)) {
        upper++;
    }

    // Nếu lower lùi về số không hợp lệ
    if (lower <= 1) return upper;

    return (value - lower <= upper - value) ? lower : upper;
}

int main() {
    int M, N, C;

    cout << "Nhap gia tri M (bat dau khoang): ";
    cin >> M;
    cout << "Nhap gia tri N (ket thuc khoang): ";
    cin >> N;
    cout << "Nhap gia tri C (so can tim so hoan hao gan nhat): ";
    cin >> C;

    vector<int> perfect_numbers; // Danh sách các số hoàn hảo trong khoảng [M, N]

    // Tìm các số hoàn hảo trong khoảng [M, N]
    for (int i = M; i <= N; i++) {
        if (is_perfect(i)) {
            perfect_numbers.push_back(i);
        }
    }

    // In các số hoàn hảo tìm được
    cout << "\nCac so hoan hao trong khoang [" << M << ", " << N << "]: ";
    if (perfect_numbers.empty()) {
        cout << "Khong co!" << endl;
    } else {
        for (int num : perfect_numbers) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Tìm số hoàn hảo gần nhất với C
    if (!perfect_numbers.empty()) {
        int closest = find_closest(perfect_numbers, C);
        cout << "So hoan hao gan nhat voi " << C << " la: " << closest << endl;

        // Tìm số nguyên tố gần nhất với số hoàn hảo lớn nhất
        int max_perfect = perfect_numbers.back(); // Số cuối cùng trong vector luôn là số lớn nhất
        int closest_prime = find_closest_prime(max_perfect);
        cout << "So nguyen to gan nhat voi so hoan hao lon nhat (" << max_perfect << ") la: " << closest_prime << endl;
    }
    else {
        cout << "Khong co so hoan hao nao trong khoang de thuc hien tiep!" << endl;
    }

    return 0;
}