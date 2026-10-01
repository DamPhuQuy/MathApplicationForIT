Eigen được ví như "NumPy của thế giới C++". Nếu bạn làm về Trí tuệ nhân tạo (AI), Xử lý ảnh (OpenCV), Game/Đồ họa 3D, Robot (ROS) hay Mô phỏng vật lý, 99%
bạn sẽ gặp thư viện này.

Dưới đây là bức tranh toàn cảnh, cô đọng nhất về những gì Eigen cung cấp và các hàm bạn sẽ dùng nhiều nhất trong thực tế:
──────

## 1. Eigen là gì và tại sao dân IT lại chuộng nó?

• Là thư viện chỉ gồm các file header (Header-only): Bạn không cần cài đặt phức tạp, không cần build .dll hay .so. Chỉ cần #include <Eigen/Dense> là dùng
được ngay.
• Tốc độ cực nhanh: Eigen tận dụng tối đa tập lệnh phần cứng SIMD (SSE, AVX) của CPU và cơ chế Expression Templates (tránh tạo ra các biến tạm trong bộ
nhớ khi cộng/nhân ma trận).
• Thư viện nền tảng: Cả PyTorch, TensorFlow, Google Ceres Solver đều nhúng Eigen ở tầng C++ backend.
──────

## 2. Các kiểu dữ liệu cốt lõi (Core Data Structures)

Eigen phân loại ma trận dựa theo kích thước và kiểu dữ liệu:

               Cú pháp: Matrix<Kiểu dữ liệu, Số hàng, Số cột>

Kiểu dữ liệu │ Ý nghĩa │ Khi nào dùng?
────────────────────┼──────────────────────────────────────────────────────────┼──────────────────────────────────────────────────────────────────────────
MatrixXd │ Ma trận cỡ động (Dynamic), phần tử số thực double. │ Dùng phổ biến nhất khi không biết trước kích thước dữ liệu (Data
│ │ Science, Machine Learning).
VectorXd │ Vector cột cỡ động (thực chất là Matrix<double, Dynamic, │ Đại diện cho các vector đặc trưng, mảng trọng số.
│ 1>). │
Matrix3d, Matrix4f │ Ma trận kích thước cố định (3 × 3, 4 × 4). │ Dùng trong Game 3D, Đồ họa, Tọa độ Robot (chạy trên bộ nhớ Stack nên
│ │ nhanh hơn MatrixXd).
ArrayXXd │ Mảng dữ liệu số học. │ Dùng khi muốn tính toán trên từng phần tử (Element-wise) giống mảng
│ │ NumPy.
──────

## 3. Các Method (Hàm) phổ biến nhất - Chia theo nhóm tác vụ

### Nhóm 1: Khởi tạo và Gán dữ liệu

    MatrixXd A(3, 3);
    A << 1, 2, 3,        // Gán nhanh bằng toán tử '<<'
         4, 5, 6,
         7, 8, 9;

    MatrixXd Z = MatrixXd::Zero(3, 3);      // Ma trận toàn số 0
    MatrixXd I = MatrixXd::Identity(3, 3);  // Ma trận đơn vị
    MatrixXd O = MatrixXd::Ones(3, 3);      // Ma trận toàn số 1
    MatrixXd R = MatrixXd::Random(3, 3);    // Ma trận số ngẫu nhiên (-1 đến 1)

### Nhóm 2: Các phép toán Đại số Tuyến tính cơ bản

    A.rows();        // Số hàng
    A.cols();        // Số cột
    A.transpose();   // Ma trận chuyển vị (A^T)
    A.inverse();     // Ma trận nghịch đảo (A^-1)
    A.determinant(); // Định thức det(A)
    A.trace();       // Vết ma trận (tổng đường chéo)

    // Phép toán vector:
    u.dot(v);        // Tích vô hướng (u . v)
    u.cross(v);      // Tích có hướng (trong không gian 3D)
    u.norm();        // Chuẩn Euclidean L2 (độ dài vector)
    u.squaredNorm(); // Bình phương chuẩn (không cần căn bậc hai, chạy nhanh hơn)

### Nhóm 3: Cắt xén và Truy xuất Ma trận con (Slicing / Block)

    A(i, j);                  // Truy xuất phần tử ở hàng i, cột j
    A.row(i);                 // Lấy toàn bộ hàng thứ i
    A.col(j);                 // Lấy toàn bộ cột thứ j
    A.block(i, j, rows, cols);// Cắt một ma trận con từ vị trí (i, j) kích thước (rows x cols)
    A.diagonal();             // Rút trích đường chéo chính thành 1 vector
    v.asDiagonal();           // Biến 1 vector thành ma trận đường chéo

### Nhóm 4: Tính toán từng phần tử (Element-wise)

Trong toán ma trận: A × B là nhân ma trận. Nhưng nếu muốn nhân/chia từng vị trí tương ứng, ta dùng .array():

    MatrixXd C = A.cwiseProduct(B);  // Nhân Hadamard (từng phần tử nhân với nhau)
    MatrixXd D = A.array() + 2.0;    // Cộng 2 vào mọi phần tử của ma trận
    MatrixXd E = A.array().sqrt();   // Lấy căn bậc hai từng phần tử
    double max_val = A.maxCoeff();   // Giá trị lớn nhất trong ma trận
    double total   = A.sum();        // Tổng tất cả các phần tử

──────

## 4. Các bộ giải phân rã ma trận (Decompositions) - Gắn liền với Chương 2

Đây là sức mạnh lớn nhất của Eigen khi áp dụng vào giải bài toán thực tế:

Tác vụ toán học │ Class trong Eigen │ Ví dụ sử dụng code
────────────────────────────┼────────────────────────────────────────────────┼────────────────────────────────────────────────────────────────────────────
Giải hệ A𝐱 = 𝐛 │ FullPivLU hoặc ColPivHouseholderQR │ VectorXd x = A.colPivHouseholderQr().solve(b); (Không nên nghịch đảo A⁻¹b
│ │ vì chậm và sai số)
Trị riêng & Vector riêng │ EigenSolver (vuông bất │ EigenSolver<MatrixXd></matrixxd> es(A);MatrixXd D =
│ kỳ)SelfAdjointEigenSolver (đối xứng) │ es.eigenvalues().real().asDiagonal();MatrixXd P =
│ │ es.eigenvectors().real();
Phân rã Cholesky (A = LLᵀ) │ LLT (ma trận SPD) │ LLT<MatrixXd></matrixxd> llt(A);MatrixXd L = llt.matrixL();
Phân rã SVD (A = UΣVᵀ) │ JacobiSVD (mọi ma trận) │ JacobiSVD<MatrixXd></matrixxd> svd(A, ComputeFullU | ComputeFullV);MatrixXd U =
│ │ svd.matrixU();VectorXd S = svd.singularValues();MatrixXd V =
│ │ svd.matrixV();
──────

## 5. 3 Lưu ý "xương máu" của dân lập trình khi dùng Eigen

1. Cạm bẫy từ khóa auto:// NGUY HIỂM: Eigen dùng Expression Templates, 'auto' có thể giữ tham chiếu tạm thờiauto C = A _ B + D;// AN TOÀN: Luôn khai báo rõ kiểu dữ liệuMatrixXd C = A _ B + D;
2. Lỗi Aliasing khi gán đè lên chính nó:
   A = A.transpose(); // SAI: Dữ liệu đang đọc bị ghi đè cùng lúc -> ra kết quả rác!
   A.transposeInPlace(); // ĐÚNG: Đảo trực tiếp tại chỗ
   A = A.transpose().eval(); // ĐÚNG: Ép tính toán xong rồi mới gán
3. Khi giải hệ phương trình A𝐱 = 𝐛:
   • Đừng bao giờ viết: x = A.inverse() \* b; (Vừa chậm O(n³), vừa dễ tràn số khi định thức gần 0).
   • Luôn luôn viết: x = A.colPivHouseholderQr().solve(b); hoặc A.llt().solve(b); (nếu đối xứng dương).
