#include <iostream>
#include <unordered_map>

int main() {
    // Define the data
    std::string data[] = {"Banh my", "Pho", "Bun", "Pizza", "Banh my", "Pho", "Bun", "Pizza", "Pizza", "Banh my", "Banh my", "Pho", "Banh my", "Pho", "Banh my", "Pho"};

    // Create a hash table to store the food items
    std::unordered_map<std::string, int> food_to_index = {
        {"Banh my", 0},
        {"Pho", 1},
        {"Bun", 2},
        {"Pizza", 3}
    };

    // Calculate the transition probability matrix
    double transition_prob[4][4] = {0};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]) - 1; i++) {
        int from_state = food_to_index[data[i]];
        int to_state = food_to_index[data[i+1]];
        transition_prob[from_state][to_state]++;
    }

    for (int i = 0; i < 4; i++) {
        double row_sum = 0;
        for (int j = 0; j < 4; j++) {
            row_sum += transition_prob[i][j];
        }
        for (int j = 0; j < 4; j++) {
            transition_prob[i][j] /= row_sum;
        }
    }

    // Print the transition probability matrix
    std::cout << "Transition probability matrix:" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << transition_prob[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Calculate the probability of eating "Pho" given that the previous meal was "Banh my"
    int banh_my_index = food_to_index["Banh my"];
    int pho_index = food_to_index["Pho"];
    double probability_of_pho_given_banh_my = transition_prob[banh_my_index][pho_index];

    std::cout << "Probability of eating \"Pho\" given that the previous meal was \"Banh my\": " << probability_of_pho_given_banh_my << std::endl;

    return 0;
}