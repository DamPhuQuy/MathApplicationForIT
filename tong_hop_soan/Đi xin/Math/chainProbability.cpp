/*
P(x1 = 1) = P(x1 = 2) = 1/4
Ma trận chuyển trạng thái P = [[0.5, 0.25, 0.25], [1/3, 0, 1/3], [1/2, 1/2, 0]]

Chúng ta có thể tính P(x1 = 3, x2 = 2, x3 = 1) như sau:

P(x1 = 3, x2 = 2, x3 = 1) = P(x1 = 3) * P(x2 = 2 | x1 = 3) * P(x3 = 1 | x2 = 2)

Trong đó:

    P(x1 = 3) = 1 - P(x1 = 1) - P(x1 = 2) = 1 - 1/4 - 1/4 = 1/2
    P(x2 = 2 | x1 = 3) = 1/2 (từ ma trận chuyển trạng thái P)
    P(x3 = 1 | x2 = 2) = 1/3 (từ ma trận chuyển trạng thái P)

Thay các giá trị này vào công thức, ta có:
P(x1 = 3, x2 = 2, x3 = 1) = 1/2 * 1/2 * 1/3 = 1/12
*/

#include <iostream>

int main() {
    // Ma trận chuyển trạng thái P
    double P[3][3] = {{0.5, 0.25, 0.25}, {1.0/3, 0, 1.0/3}, {0.5, 0.5, 0}};
    
    // Xác suất ban đầu P(x1 = 1) = P(x1 = 2) = 1/4
    double P_x1_1 = 0.25, P_x1_2 = 0.25, P_x1_3 = 1 - P_x1_1 - P_x1_2;
    
    // Tính P(x1 = 3, x2 = 2, x3 = 1)
    double P_x1_3_x2_2_x3_1 = P_x1_3 * P[2][1] * P[1][0];
    
    std::cout << "P(x1 = 3, x2 = 2, x3 = 1) = " << P_x1_3_x2_2_x3_1 << std::endl;
    
    return 0;
}