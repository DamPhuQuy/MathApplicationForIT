#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to build the transition matrix
vector<vector<double>> buildTransitionMatrix(const vector<string>& data) {
    // Count the occurrences of each state transition
    unordered_map<string, unordered_map<string, int>> transitionCounts;
    for (int i = 0; i < data.size() - 1; ++i) {
        transitionCounts[data[i]][data[i + 1]]++;
    }

    // Get unique states
    vector<string> uniqueStates;
    for (const auto& kvp : transitionCounts) {
        uniqueStates.push_back(kvp.first);
    }
    sort(uniqueStates.begin(), uniqueStates.end());

    // Build the transition matrix
    int n = uniqueStates.size();
    vector<vector<double>> transitionMatrix(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        const string& currentState = uniqueStates[i];
        int totalCount = 0;
        for (int j = 0; j < n; ++j) {
            const string& nextState = uniqueStates[j];
            totalCount += transitionCounts[currentState][nextState];
        }
        for (int j = 0; j < n; ++j) {
            const string& nextState = uniqueStates[j];
            transitionMatrix[i][j] = static_cast<double>(transitionCounts[currentState][nextState]) / totalCount;
        }
    }

    return transitionMatrix;
}

int main() {
    vector<string> data = {"Banh my", "Pho", "Bun", "Pizza", "Banh my", "Pho", "Bun", "Pizza", "Pizza", "Banh my", "Banh my", "Pho", "Banh my", "Pho", "Banh my", "Pho"};

    // Build transition matrix
    vector<vector<double>> transitionMatrix = buildTransitionMatrix(data);

    // Print transition matrix
    cout << "Transition Matrix:" << endl;
    for (const auto& row : transitionMatrix) {
        for (double prob : row) {
            cout << prob << " ";
        }
        cout << endl;
    }

    return 0;
}
