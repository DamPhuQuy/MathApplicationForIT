#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

// Hàm in ma trận trạng thái
void printMatrix(const vector<vector<double>>& matrix, const map<string, int>& food_to_index, const vector<string>& order) {
    cout << "\t\t";
    for (const auto& food : order) {
        cout << setw(10) << food;
    }
    cout << endl << endl;

    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << setw(10) << order[i] << '\t'; // In tên món ăn ở cột bên trái
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << setw(10) << fixed << setprecision(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Hàm tạo ma trận trạng thái và ánh xạ món ăn sang chỉ số
pair<vector<vector<double>>, map<string, int>> createTransitionMatrix(const vector<string>& data, const vector<string>& order) {
    // Tạo ánh xạ từ các món ăn sang chỉ số trong ma trận
    map<string, int> food_to_index;
    int index = 0;
    for (auto food : order)
        food_to_index[food] = index++;

    // Khởi tạo ma trận trạng thái
    int num_foods = index;
    vector<vector<double>> transition_matrix(num_foods, vector<double>(num_foods, 0.0));

    // Tạo ma trận trạng thái dựa trên lịch sử ăn uống
    for (int i = 0; i < data.size() - 1; ++i) { // Start from index 0
        int yesterday = food_to_index[data[i]];
        int today = food_to_index[data[i + 1]]; // Use i + 1 to get the next day's food
        transition_matrix[yesterday][today]++;
    }

    // Chuẩn hóa ma trận trạng thái
    map<int, double> total_transitions;
    for (int i = 0; i < num_foods; ++i) {
        for (int j = 0; j < num_foods; ++j) {
            total_transitions[i] += transition_matrix[i][j];
        }
    }


    cout << "Ma tran dem: " << endl;
    printMatrix(transition_matrix, food_to_index, order);
    cout << endl << endl;

    for (int i = 0; i < num_foods; ++i) {
        for (int j = 0; j < num_foods; ++j) {
            if (total_transitions[i] > 0)
                transition_matrix[i][j] /= total_transitions[i];
        }
    }

    return make_pair(transition_matrix, food_to_index);
}

int main() {
    // Dữ liệu lịch sử ăn uống
    vector<string> data = {"Banh my", "Pho", "Bun", "Pizza", "Banh my", "Pho", "Bun", "Pizza", "Pizza", "Banh my", "Banh my", "Pho", "Banh my", "Pho", "Banh my", "Pho"};

    // Tạo ma trận trạng thái và ánh xạ món ăn sang chỉ số
    vector<string> order = {"Banh my", "Pho", "Bun", "Pizza"};
    auto result = createTransitionMatrix(data, order);
    vector<vector<double>> transition_matrix = result.first;
    map<string, int> food_to_index = result.second;

    // In ma trận trạng thái
    cout << "Ma tran trang thai: " << endl;
    printMatrix(transition_matrix, food_to_index, order);

    return 0;
}
