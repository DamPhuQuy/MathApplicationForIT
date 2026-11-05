#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
 
using namespace std;
 
void printMatrix(const vector<vector<double>>& matrix, const vector<string>& order) {
    cout << "\t\t";
    for (const auto& food : order) {
        cout << left << setw(12) << food;
    }
    cout << "\n\n";
 
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << left << setw(12) << order[i];
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << left << setw(12) << fixed << setprecision(5) << matrix[i][j];
        }
        cout << "\n";
    }
}
 
vector<vector<double>> createTransitionMatrix(const vector<string>& data, const vector<string>& order) {
    unordered_map<string, int> food_to_index;
    int num_foods = order.size();
    for (int i = 0; i < num_foods; ++i) {
        food_to_index[order[i]] = i;
    }
 
    vector<vector<double>> transition_matrix(num_foods, vector<double>(num_foods, 0.0));
    vector<int> total_transitions(num_foods, 0);
 
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (food_to_index.count(data[i]) && food_to_index.count(data[i+1])) {
            int yesterday = food_to_index[data[i]];
            int today = food_to_index[data[i + 1]];
            transition_matrix[yesterday][today] += 1.0;
            total_transitions[yesterday]++;
        }
    }
 
    cout << "Ma tran dem:\n";
    printMatrix(transition_matrix, order);
    cout << "\n\n";
 
    for (int i = 0; i < num_foods; ++i) {
        if (total_transitions[i] > 0) {
            for (int j = 0; j < num_foods; ++j) {
                transition_matrix[i][j] /= total_transitions[i];
            }
        } else {
            transition_matrix[i][i] = 1.0;
        }
    }
 
    return transition_matrix;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<string> data = {"Banh my", "Pho", "Bun", "Pizza", "Banh my", "Pho",
        "Bun", "Pizza", "Pizza", "Banh my", "Banh my", "Pho",
        "Banh my", "Pho", "Banh my", "Pho"};
    vector<string> order = {"Banh my", "Pho", "Bun", "Pizza"};
 
    vector<vector<double>> transition_matrix = createTransitionMatrix(data, order);
 
    cout << "Ma tran trang thai:\n";
    printMatrix(transition_matrix, order);
 
    return 0;
}