# CHƯƠNG 2: ĐẠI SỐ TUYẾN TÍNH DÀNH CHO DÂN LẬP TRÌNH (IT)

*(Giải thích bình dân - Trực quan hình ảnh - Từng bước giải tay trên giấy nháp)*

> **Lời tâm sự của Giảng viên:**
> Tôi hiểu cảm giác của bạn khi đọc các giáo trình toán: Đầy rẫy những từ ngữ hàn lâm như *"ánh xạ", "không gian con", "toàn phương", "quang phổ"*, công thức thì toàn ký hiệu $\sum, \in, \forall$ mà không có lấy một ví dụ số cụ thể để bạn tự lấy giấy bút ra tính thử.
>
> Trong tài liệu này, tôi sẽ **"dịch" toàn bộ kiến thức sang ngôn ngữ của dân lập trình**, đi kèm **từng bước tính nháp bằng tay (không nhảy bước)** cho từng con số cụ thể. Bạn sẽ thấy bản chất của chúng thực ra cực kỳ trực quan và thú vị!

---

## BẢN ĐỒ TƯ DUY: HỌC ĐỂ LÀM GÌ TRONG IT?

```
1. VECTOR & MA TRẬN ──► Là cách biểu diễn DỮ LIỆU trong máy tính (ảnh, âm thanh, bảng dữ liệu).
        │
        ▼
2. TRỊ RIÊNG & CHÉO HÓA ──► Tìm các "trục chính" của dữ liệu; giúp tính A^100 trong 1 cái chớp mắt.
        │
        ▼
3. PHÂN RÃ CHOLESKY ──► "Căn bậc hai" của ma trận. Giúp giải phương trình nhanh gấp đôi & sinh dữ liệu ngẫu nhiên (AI/Game).
        │
        ▼
4. PHÂN RÃ SVD ──► Đỉnh cao của xử lý dữ liệu: Nén ảnh, hệ thống gợi ý phim (Netflix), giảm chiều dữ liệu (PCA).
```

---

# PHẦN 1: NỀN TẢNG - HIỂU BẢN CHẤT KHÔNG CẦN TỪ NGỮ ĐAO TO BÚA LỚN

## 1.1. Vector dưới góc nhìn Lập trình viên

- **Ở phổ thông:** Thầy cô dạy vector là mũi tên có hướng và độ dài.
- **Trong máy tính:** Vector đơn giản là **một mảng một chiều (Array/List)** chứa các con số.
  - Ví dụ thông tin của 1 ngôi nhà: `[diện tích, số phòng ngủ, khoảng cách đến trung tâm, giá bán]` $\to$ đây là vector 4 chiều:
    $$
    \mathbf{x} = \begin{bmatrix} 85.5 \\ 3 \\ 4.2 \\ 2500 \end{bmatrix} \in \mathbb{R}^4
    $$
  - Một bức ảnh xám $28 \times 28$ pixel (bộ dữ liệu MNIST nhận dạng chữ số): Bạn duỗi thẳng 28 hàng thành 1 hàng dài $28 \times 28 = 784$ số $\to$ đó là vector $\mathbf{x} \in \mathbb{R}^{784}$.

---

## 1.2. Không gian con (Subspace) - Hiểu như "Sân chơi hợp lệ"

Tại sao slide lại đặt ra 3 điều kiện rắc rối cho "không gian con"? Hãy tưởng tượng nó như một **sân chơi an toàn cho các thuật toán**:

1. **Phải chứa phần tử 0 ($\mathbf{0} \in U$):***Ý nghĩa:* Bạn phải có điểm xuất phát (gốc tọa độ). Nếu hệ thống của bạn không có trạng thái "rỗng/nghỉ" $(\mathbf{0})$, bạn không thể reset hệ thống.
2. **Cộng hai phần tử trong sân chơi thì kết quả vẫn phải nằm trong sân chơi ($x + y \in U$):***Ý nghĩa:* Bạn kết hợp dữ liệu mà kết quả lại văng ra ngoài miền xác định thì chương trình sẽ bị lỗi tràn bộ nhớ hoặc crash!
3. **Nhân với một số bất kỳ vẫn nằm trong sân chơi ($\alpha x \in U$):**
   *Ý nghĩa:* Bạn phóng to/thu nhỏ dữ liệu thì loại dữ liệu đó vẫn phải được hệ thống hỗ trợ.

### ✍️ Ví dụ giải tay kiểm tra Không gian con:

* **Ví dụ 1:** Xét tập hợp $U = \{(x, y) \in \mathbb{R}^2 \mid y = 2x\}$ (đường thẳng $y = 2x$ đi qua gốc tọa độ).
  - Kiểm tra điều kiện 1: Cho $x = 0 \implies y = 2(0) = 0 \implies (0, 0) \in U$. *(Thỏa mãn)*.
  - Kiểm tra điều kiện 2: Lấy $\mathbf{u}_1 = (x_1, 2x_1)$ và $\mathbf{u}_2 = (x_2, 2x_2)$.Cộng lại: $\mathbf{u}_1 + \mathbf{u}_2 = (x_1 + x_2, 2(x_1 + x_2))$. Tọa độ sau vẫn gấp đôi tọa độ trước $\implies$ thuộc $U$. *(Thỏa mãn)*.
  - $\implies$ **$U$ là một không gian con hợp lệ!**
* **Ví dụ 2:** Xét tập hợp $W = \{(x, y) \in \mathbb{R}^2 \mid y = 2x + 1\}$.
  - Kiểm tra điểm $(0, 0)$: Thay $x = 0 \implies y = 1 \neq 0 \implies (0, 0) \notin W$.
  - $\implies$ **Loại ngay lập tức! $W$ KHÔNG PHẢI là không gian con.** *(Đường thẳng không đi qua gốc tọa độ thì không bao giờ là không gian con)*.

---

## 1.3. Tích vô hướng (Dot Product) - "Máy đo độ hợp gu"

Cho hai vector $\mathbf{a} = \begin{bmatrix} a_1 \\ a_2 \end{bmatrix}$ và $\mathbf{b} = \begin{bmatrix} b_1 \\ b_2 \end{bmatrix}$.
Tích vô hướng là nhân từng cặp số tương ứng rồi cộng dồn lại:

$$
\mathbf{a} \cdot \mathbf{b} = a_1 b_1 + a_2 b_2 = \|\mathbf{a}\| \|\mathbf{b}\| \cos\alpha
$$

### Ý nghĩa trong IT:

- **Nếu $\mathbf{a} \cdot \mathbf{b} = 0 \iff \cos\alpha = 0 \implies \alpha = 90^\circ$ (Trực giao / Vuông góc):**Hai đối tượng **hoàn toàn độc lập**, không có tí điểm chung nào.
- **Độ tương đồng Cosine (Cosine Similarity):**
  Ví dụ đo sở thích xem phim giữa bạn và một người bạn:
  `[thích hành động, thích kinh dị, thích hài hước]`
  Bạn: $\mathbf{u}_1 = [5, 1, 4]$, Người ấy: $\mathbf{u}_2 = [4, 1, 5]$.
  Tích vô hướng lớn nghĩa là 2 người cực kỳ hợp gu $\to$ YouTube / TikTok dùng chính công thức này để gợi ý video cho bạn!

---

## 1.4. Chuẩn (Norm) - "Cái thước dây" đo độ dài vector

Làm sao biết một vector "dài" bao nhiêu? Ta dùng Chuẩn (ký hiệu là hai dấu gạch sọc $\|\mathbf{x}\|$):

| Tên chuẩn                               |         Ký hiệu         | Cách tính dễ hiểu                                                                | Ví dụ giải tay với$\mathbf{x} = \begin{bmatrix} 3 \\ -4 \end{bmatrix}$ | Ứng dụng thực tế                                                   |
| :---------------------------------------- | :-----------------------: | :----------------------------------------------------------------------------------- | :--------------------------------------------------------------------------- | :--------------------------------------------------------------------- |
| **Chuẩn $L_1$ (Manhattan)**      |   $\|\mathbf{x}\|_1$   | Cộng trị tuyệt đối từng phần tử (như đi bộ qua từng dãy phố bàn cờ). | $\|3\| + \|-4\| = 3 + 4 = \mathbf{7}$                                      | Dùng trong**Lasso**: triệt tiêu các đặc trưng rác về 0. |
| **Chuẩn $L_2$ (Euclidean)**      |   $\|\mathbf{x}\|_2$   | Định lý Pytago quen thuộc: Căn bậc hai của tổng các bình phương.         | $\sqrt{3^2 + (-4)^2} = \sqrt{9 + 16} = \sqrt{25} = \mathbf{5}$             | Đo khoảng cách thẳng, dùng trong**Ridge Regression / SGD**. |
| **Chuẩn $L_\infty$ (Vô cùng)** | $\|\mathbf{x}\|_\infty$ | Tìm phần tử có trị tuyệt đối lớn nhất.                                     | $\max(\|3\|, \|-4\|) = \mathbf{4}$                                         | Giới hạn mức độ nhiễu lớn nhất mà hacker có thể can thiệp. |

---

# PHẦN 2: TRỊ RIÊNG (EIGENVALUE) & CHÉO HÓA (DIAGONALIZATION)

*(Trọng tâm của Exercise 01, 02, 03)*

## 2.1. Bản chất trực giác: Trục nào "không bị xoay"?

Bình thường, khi bạn nhân một ma trận $A$ với một vector $\mathbf{x}$, vector kết quả $A\mathbf{x}$ sẽ **bị xoay sang hướng khác** và **bị dãn/co độ dài**.

> **Ý tưởng thiên tài của Trị riêng & Vector riêng:**
> Có những vector đặc biệt mà khi bị ma trận $A$ tác động, nó **GIỮ NGUYÊN HƯỚNG CŨ**, chỉ bị kéo dãn ra hoặc co ngắn lại theo một tỷ lệ $\lambda$:
>
> $$
> A\mathbf{x} = \lambda \mathbf{x} \quad (\mathbf{x} \neq \mathbf{0})
> $$
>
> - Hướng không bị xoay đó gọi là **Vector riêng (Eigenvector)** $\mathbf{x}$.
> - Mức độ dãn (gấp mấy lần) gọi là **Trị riêng (Eigenvalue)** $\lambda$.

---

## 2.2. Hướng dẫn giải tay từng bước (Pen-and-Paper Step-by-Step)

*(Chúng ta cùng lấy đúng Ma trận $A_1$ trong đề bài Exercise 01 để giải tay từng con số)*:

$$
A_1 = \begin{bmatrix} 3 & 2 \\ 1 & 4 \end{bmatrix}
$$

### ✍️ BƯỚC 1: Lập phương trình tìm trị riêng $\lambda$

Ta biến đổi: $A\mathbf{x} = \lambda \mathbf{x} \iff (A - \lambda I)\mathbf{x} = \mathbf{0}$.
Để có nghiệm $\mathbf{x} \neq \mathbf{0}$, định thức của ma trận $(A - \lambda I)$ bắt buộc phải bằng $0$:

$$
\det(A - \lambda I) = 0
$$

Ta viết ma trận $A$, lấy các số trên đường chéo chính trừ đi $\lambda$:

$$
A - \lambda I = \begin{bmatrix} 3-\lambda & 2 \\ 1 & 4-\lambda \end{bmatrix}
$$

Tính định thức cấp 2 (chéo chính trừ chéo phụ):

$$
\det = (3 - \lambda)(4 - \lambda) - (2 \times 1) = 0
$$

$$
\iff 12 - 3\lambda - 4\lambda + \lambda^2 - 2 = 0
$$

$$
\iff \lambda^2 - 7\lambda + 10 = 0
$$

Bấm máy tính hoặc nhẩm nghiệm phương trình bậc 2:

$$
(\lambda - 5)(\lambda - 2) = 0 \implies \lambda_1 = 5, \quad \lambda_2 = 2
$$

> **Thuật ngữ cần nhớ:**
>
> - Mỗi nghiệm xuất hiện 1 lần nên ta nói: $\lambda_1 = 5$ có **Bội đại số = 1**, $\lambda_2 = 2$ có **Bội đại số = 1**.

---

### ✍️ BƯỚC 2: Giải tay tìm Vector riêng ứng với từng $\lambda$

#### 🔹 Trường hợp 1: Với $\lambda_1 = 5$

Thay $\lambda = 5$ vào hệ phương trình $(A - 5I)\mathbf{x} = \mathbf{0}$:

$$
\begin{bmatrix} 3-5 & 2 \\ 1 & 4-5 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} \iff \begin{bmatrix} -2 & 2 \\ 1 & -1 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix}
$$

Viết thành hệ 2 phương trình đại số:

$$
\begin{cases} -2x_1 + 2x_2 = 0 \\ 1x_1 - 1x_2 = 0 \end{cases}
$$

Hai phương trình này thực chất là một! Rút gọn ta được:

$$
x_1 = x_2
$$

Ta chọn một giá trị đẹp cho $x_2$ (ví dụ chọn $x_2 = 1 \implies x_1 = 1$).
Vậy vector riêng đầu tiên là:

$$
\mathbf{p}_1 = \begin{bmatrix} 1 \\ 1 \end{bmatrix}
$$

- **Không gian riêng $E_5$:** $E_5 = \text{span}\left\{\begin{bmatrix} 1 \\ 1 \end{bmatrix}\right\}$.
- Vì chỉ có 1 vector cơ sở nên **Bội hình học (số chiều của $E_5$) = 1**.

---

#### 🔹 Trường hợp 2: Với $\lambda_2 = 2$

Thay $\lambda = 2$ vào hệ phương trình $(A - 2I)\mathbf{x} = \mathbf{0}$:

$$
\begin{bmatrix} 3-2 & 2 \\ 1 & 4-2 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} \iff \begin{bmatrix} 1 & 2 \\ 1 & 2 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix}
$$

Viết thành phương trình:

$$
x_1 + 2x_2 = 0 \implies x_1 = -2x_2
$$

Chọn $x_2 = 1 \implies x_1 = -2$.
Vậy vector riêng thứ hai là:

$$
\mathbf{p}_2 = \begin{bmatrix} -2 \\ 1 \end{bmatrix}
$$

- **Không gian riêng $E_2$:** $E_2 = \text{span}\left\{\begin{bmatrix} -2 \\ 1 \end{bmatrix}\right\}$.
- **Bội hình học (số chiều của $E_2$) = 1**.

---

### ✍️ BƯỚC 3: Kết luận & Chéo hóa ma trận ($A = P D P^{-1}$)

- Ma trận kích thước $2 \times 2$. Ta tìm được $1 + 1 = 2$ vector riêng độc lập tuyến tính $\mathbf{p}_1, \mathbf{p}_2$.
- Theo **Theorem 1 & 2**: Ma trận $A_1$ **CHÉO HÓA ĐƯỢC (Diagonalizable)**!

**Ghép ma trận $P$ và $D$ cực kỳ dễ dàng:**

1. **Ma trận $P$:** Đặt các vector riêng vừa tìm được làm các cột:

   $$
   P = [\mathbf{p}_1 \quad \mathbf{p}_2] = \begin{bmatrix} 1 & -2 \\ 1 & 1 \end{bmatrix}
   $$
2. **Ma trận đường chéo $D$:** Đặt các trị riêng tương ứng lên đường chéo chính (cột 1 ứng với $\lambda_1 = 5$, cột 2 ứng với $\lambda_2 = 2$):

   $$
   D = \begin{bmatrix} 5 & 0 \\ 0 & 2 \end{bmatrix}
   $$
3. **Tìm $P^{-1}$ bằng tay:**Công thức nghịch đảo ma trận $2 \times 2$: Cho $M = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \implies M^{-1} = \frac{1}{ad - bc} \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}$.Áp dụng cho $P$:

   - $\det(P) = (1)(1) - (-2)(1) = 1 + 2 = 3$.
   - $P^{-1} = \frac{1}{3} \begin{bmatrix} 1 & 2 \\ -1 & 1 \end{bmatrix} = \begin{bmatrix} 1/3 & 2/3 \\ -1/3 & 1/3 \end{bmatrix}$.
4. **Thử nhân lại bằng tay để tự tin 100%:**

   $$
   P \times D = \begin{bmatrix} 1 & -2 \\ 1 & 1 \end{bmatrix} \begin{bmatrix} 5 & 0 \\ 0 & 2 \end{bmatrix} = \begin{bmatrix} 5 & -4 \\ 5 & 2 \end{bmatrix}
   $$

   $$
   (P D) \times P^{-1} = \begin{bmatrix} 5 & -4 \\ 5 & 2 \end{bmatrix} \begin{bmatrix} 1/3 & 2/3 \\ -1/3 & 1/3 \end{bmatrix} = \begin{bmatrix} \frac{5+4}{3} & \frac{10-4}{3} \\ \frac{5-2}{3} & \frac{10+2}{3} \end{bmatrix} = \begin{bmatrix} 3 & 2 \\ 1 & 4 \end{bmatrix} = A_1 \quad \text{(Chính xác tuyệt đối!)}
   $$

---

## 2.3. Khi nào một ma trận BỊ LỖI không thể chéo hóa? (Ma trận $A_3$ trong đề bài)

Hãy giải tay ma trận $A_3 = \begin{bmatrix} 2 & 1 \\ 0 & 2 \end{bmatrix}$ để thấy rõ nguyên nhân:

1. **Đa thức đặc trưng:**

   $$
   \det(A_3 - \lambda I) = \begin{vmatrix} 2-\lambda & 1 \\ 0 & 2-\lambda \end{vmatrix} = (2 - \lambda)^2 = 0 \implies \lambda = 2 \text{ (nghiệm kép, Bội đại số = 2)}
   $$
2. **Tìm vector riêng ứng với $\lambda = 2$:**

   $$
   (A_3 - 2I)\mathbf{x} = \mathbf{0} \iff \begin{bmatrix} 0 & 1 \\ 0 & 0 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} \implies 0x_1 + 1x_2 = 0 \implies x_2 = 0
   $$

   Còn $x_1$ thì tùy ý! Chọn $x_1 = 1 \implies \mathbf{p} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$.- Ta **chỉ tìm được DUY NHẤT 1 vector riêng** $\mathbf{p} = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$.

   - **Bội hình học (số vector riêng tìm được) = 1 < Bội đại số (2)**.
3. **Kết luận:**
   Ma trận kích thước $2 \times 2$ cần 2 hướng độc lập để tạo thành hệ tọa độ 2D. Ở đây ta chỉ tìm được 1 hướng duy nhất $\to$ thiếu mất 1 chiều!
   $\implies$ **$A_3$ là ma trận suy biến (Defective matrix) và KHÔNG THỂ CHÉO HÓA ĐƯỢC.**

---

## 2.4. Tại sao dân IT lại mê mẩn Chéo hóa ma trận? (Exercise 03)

Giả sử đề bài yêu cầu bạn tính $A^{100}$.

- **Cách ngây thơ:** Bạn cho vòng lặp `for` chạy 100 lần lấy $A \times A \times A \dots$Mỗi lần nhân ma trận mất rất nhiều phép tính, số bị to lên và sai số tích lũy làm tràn số.
- **Cách của chuyên gia dùng Chéo hóa:**
  Vì $A = P D P^{-1}$, nên:

  $$
  A^2 = (P D P^{-1})(P D P^{-1}) = P D (P^{-1} P) D P^{-1} = P D^2 P^{-1}
  $$

  $$
  A^3 = P D^3 P^{-1}
  $$

  $$
  \dots
  $$

  $$
  \mathbf{A}^{100} = \mathbf{P} \mathbf{D}^{100} \mathbf{P}^{-1}
  $$

  Vì $D$ là ma trận đường chéo $\begin{bmatrix} 5 & 0 \\ 0 & 2 \end{bmatrix}$, nâng lên lũy thừa 100 chỉ đơn giản là nâng từng số trên đường chéo:

  $$
  D^{100} = \begin{bmatrix} 5^{100} & 0 \\ 0 & 2^{100} \end{bmatrix}
  $$

  Máy tính tính $5^{100}$ và $2^{100}$ trong vòng $1$ phép tính, sau đó nhân với $P$ và $P^{-1}$ là xong ngay lập tức!

---

# PHẦN 3: PHÂN RÃ CHOLESKY ($A = L L^T$)

*(Phép lấy "căn bậc hai" cho ma trận)*

## 3.1. Ngữ cảnh đời thường & Điều kiện áp dụng

Trong số học: Số $9$ có căn bậc hai là $3$ vì $9 = 3 \times 3$.Trong đại số ma trận: Một ma trận đặc biệt có thể phân rã thành $A = L \times L^T$ (trong đó $L$ là ma trận tam giác dưới). Đó chính là **Phân rã Cholesky**.

> **Điều kiện bắt buộc để dùng Cholesky:**
> Ma trận phải là **SPD (Symmetric Positive Definite - Đối xứng, xác định dương)**:
>
> 1. Đối xứng: $A = A^T$ qua đường chéo chính.
> 2. Các phần tử trên đường chéo chính phải dương ($a_{ii} > 0$).
> 3. Mọi trị riêng $\lambda_i > 0$.

---

## 3.2. Giải tay từng con số một cho Phân rã Cholesky

Cho ma trận đối xứng dương $A$:

$$
A = \begin{bmatrix} 4 & 2 & -2 \\ 2 & 10 & 2 \\ -2 & 2 & 6 \end{bmatrix}
$$

Ta cần tìm ma trận tam giác dưới $L = \begin{bmatrix} l_{11} & 0 & 0 \\ l_{21} & l_{22} & 0 \\ l_{31} & l_{32} & l_{33} \end{bmatrix}$ sao cho $A = L L^T$:

$$
\begin{bmatrix} 4 & 2 & -2 \\ 2 & 10 & 2 \\ -2 & 2 & 6 \end{bmatrix} = \begin{bmatrix} l_{11} & 0 & 0 \\ l_{21} & l_{22} & 0 \\ l_{31} & l_{32} & l_{33} \end{bmatrix} \begin{bmatrix} l_{11} & l_{21} & l_{31} \\ 0 & l_{22} & l_{32} \\ 0 & 0 & l_{33} \end{bmatrix}
$$

Không cần nhớ công thức phức tạp, bạn chỉ cần **nhân hàng của $L$ với cột của $L^T$ rồi cho bằng số tương ứng ở $A$**:

#### 🔹 Cột 1:

1. Hàng 1 nhân Cột 1: $l_{11} \times l_{11} = 4 \implies l_{11}^2 = 4 \implies \mathbf{l_{11} = 2}$.
2. Hàng 2 nhân Cột 1: $l_{21} \times l_{11} = 2 \implies l_{21} \times 2 = 2 \implies \mathbf{l_{21} = 1}$.
3. Hàng 3 nhân Cột 1: $l_{31} \times l_{11} = -2 \implies l_{31} \times 2 = -2 \implies \mathbf{l_{31} = -1}$.

#### 🔹 Cột 2:

4. Hàng 2 nhân Cột 2: $l_{21}^2 + l_{22}^2 = 10 \implies 1^2 + l_{22}^2 = 10 \implies l_{22}^2 = 9 \implies \mathbf{l_{22} = 3}$.
5. Hàng 3 nhân Cột 2: $l_{31} l_{21} + l_{32} l_{22} = 2 \implies (-1)(1) + l_{32}(3) = 2 \implies -1 + 3l_{32} = 2 \implies 3l_{32} = 3 \implies \mathbf{l_{32} = 1}$.

#### 🔹 Cột 3:

6. Hàng 3 nhân Cột 3: $l_{31}^2 + l_{32}^2 + l_{33}^2 = 6 \implies (-1)^2 + 1^2 + l_{33}^2 = 6 \implies 1 + 1 + l_{33}^2 = 6 \implies l_{33}^2 = 4 \implies \mathbf{l_{33} = 2}$.

**Kết quả cuối cùng:**

$$
L = \begin{bmatrix} 2 & 0 & 0 \\ 1 & 3 & 0 \\ -1 & 1 & 2 \end{bmatrix}
$$

---

## 3.3. Ứng dụng thực tế của Cholesky trong IT

1. **Giải hệ phương trình $A\mathbf{x} = \mathbf{b}$ nhanh gấp 2 lần:**Thay vì khử Gauss $O(n^3)$ rất chậm, ta phân rã $A = L L^T$. Giải $L\mathbf{y} = \mathbf{b}$ bằng cách thế xuôi từ trên xuống, rồi giải $L^T\mathbf{x} = \mathbf{y}$ bằng thế ngược từ dưới lên. Cực nhanh!
2. **Tính định thức $\det(A)$ trong chớp mắt:**
   $$
   \det(A) = \det(L L^T) = \det(L)^2 = (l_{11} \times l_{22} \times l_{33})^2 = (2 \times 3 \times 2)^2 = 12^2 = \mathbf{144}
   $$
3. **Sinh dữ liệu mô phỏng trong AI (Reparameterization Trick trong VAE):**
   Máy tính chỉ biết sinh số ngẫu nhiên độc lập $z \sim \mathcal{N}(0, 1)$. Muốn sinh dữ liệu có mối tương quan theo ma trận hiệp phương sai $\Sigma$, ta chỉ việc lấy: $\mathbf{x} = L \mathbf{z}$ với $\Sigma = L L^T$.

---

# PHẦN 4: PHÂN RÃ GIÁ TRỊ SUY BIẾN (SVD - SINGULAR VALUE DECOMPOSITION)

*(Đỉnh cao của Đại số tuyến tính trong Khoa học Dữ liệu)*

## 4.1. Tại sao Chéo hóa chưa đủ mà phải cần SVD?

Hãy so sánh thực tế:

- **Chéo hóa ($A = P D P^{-1}$):** Bắt buộc ma trận phải **vuông**, và nếu thiếu vector riêng thì **chịu chết** (như $A_3$).
- **Thế giới thực:** Bảng dữ liệu người dùng xem phim của Netflix: $1.000$ người dùng $\times$ $50$ bộ phim $\to$ Đây là **ma trận hình chữ nhật** $1000 \times 50$, làm sao mà chéo hóa được?
- **SVD giải quyết tất cả:** Áp dụng cho **BẤT KỲ MA TRẬN NÀO** (vuông, chữ nhật, suy biến) và **LUÔN LUÔN TỒN TẠI**!

$$
A = U \Sigma V^T
$$

```
   A (m x n)     =     U (m x m)     *    Σ (m x n)    *    V^T (n x n)
  [         ]         [ |   |     | ]     [ σ₁ 0  0 ... 0 ]   [ — v₁^T — ]
  [ Dữ liệu ]    =    [ u₁  u₂ ...uₘ]  *  [ 0  σ₂ 0 ... 0 ] * [ — v₂^T — ]
  [  gốc    ]         [ |   |     | ]     [ 0  0  σᵣ... 0 ]   [    :     ]
                                          [ 0  0  0 ... 0 ]   [ — vₙ^T — ]
```

### Ý nghĩa hình học dễ hiểu nhất:

Mọi biến đổi phức tạp trong vũ trụ từ không gian này sang không gian khác đều chỉ gồm 3 bước:

1. **$V^T$:** Xoay hệ tọa độ ban đầu.
2. **$\Sigma$:** Kéo dãn/co ngắn các trục theo các hệ số $\sigma_1 \ge \sigma_2 \ge \dots > 0$ (gọi là giá trị suy biến).
3. **$U$:** Xoay tiếp sang hệ tọa độ đích.

---

## 4.2. Giải tay từng bước một bài toán SVD

Xét ma trận hình chữ nhật $A = \begin{bmatrix} 1 & 0 & 1 \\ -2 & 1 & 0 \end{bmatrix}$ (cỡ $2 \times 3$).

### ✍️ Bước 1: Nhân ma trận $A^T A$ để tạo ma trận vuông đối xứng

$$
A^T = \begin{bmatrix} 1 & -2 \\ 0 & 1 \\ 1 & 0 \end{bmatrix}
$$

$$
A^T A = \begin{bmatrix} 1 & -2 \\ 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 1 & 0 & 1 \\ -2 & 1 & 0 \end{bmatrix} = \begin{bmatrix} 1(1)+(-2)(-2) & 1(0)+(-2)(1) & 1(1)+(-2)(0) \\ 0(1)+1(-2) & 0(0)+1(1) & 0(1)+1(0) \\ 1(1)+0(-2) & 1(0)+0(1) & 1(1)+0(0) \end{bmatrix} = \begin{bmatrix} 5 & -2 & 1 \\ -2 & 1 & 0 \\ 1 & 0 & 1 \end{bmatrix}
$$

### ✍️ Bước 2: Tìm trị riêng của $A^T A$ để suy ra $\Sigma$

Giải phương trình $\det(A^T A - \lambda I) = 0$, ta được các nghiệm:

$$
\lambda_1 = 6, \quad \lambda_2 = 1, \quad \lambda_3 = 0
$$

Giá trị suy biến $\sigma_i$ chính là căn bậc hai của các trị riêng:

$$
\sigma_1 = \sqrt{\lambda_1} = \sqrt{6} \approx 2.449
$$

$$
\sigma_2 = \sqrt{\lambda_2} = \sqrt{1} = 1
$$

Ma trận $\Sigma$ có cùng kích thước với $A$ ($2 \times 3$):

$$
\Sigma = \begin{bmatrix} \sqrt{6} & 0 & 0 \\ 0 & 1 & 0 \end{bmatrix}
$$

### ✍️ Bước 3: Tìm $V$ và $U$

- **Tìm $V$:** Giải $(A^TA - \lambda_i I)\mathbf{v}_i = \mathbf{0}$ rồi chuẩn hóa độ dài về $1$ để được các cột của $V$.
- **Tìm $U$ bằng công thức cực nhanh (không cần tìm trị riêng của $A A^T$):**

  $$
  u_i = \frac{1}{\sigma_i} A \mathbf{v}_i
  $$

  Ta tính được:

  $$
  U = \frac{1}{\sqrt{5}} \begin{bmatrix} 1 & 2 \\ -2 & 1 \end{bmatrix}, \quad V = \begin{bmatrix} 5/\sqrt{30} & 0 & -1/\sqrt{6} \\ -2/\sqrt{30} & 1/\sqrt{5} & -2/\sqrt{6} \\ 1/\sqrt{30} & 2/\sqrt{5} & 1/\sqrt{6} \end{bmatrix}
  $$

---

## 4.3. Ứng dụng đỉnh cao: Nén ảnh với SVD

Giả sử bạn có bức ảnh đen trắng kích thước $1000 \times 1000$ pixel (ma trận $A$).

- Để lưu bức ảnh này, máy tính cần lưu: $1000 \times 1000 = \mathbf{1.000.000}$ con số.
- Khi phân rã SVD:
  $$
  A = \sigma_1 \mathbf{u}_1 \mathbf{v}_1^T + \sigma_2 \mathbf{u}_2 \mathbf{v}_2^T + \dots + \sigma_{1000} \mathbf{u}_{1000} \mathbf{v}_{1000}^T
  $$
- Các giá trị $\sigma$ giảm rất nhanh: $\sigma_1, \dots, \sigma_{50}$ rất lớn (chứa $90\%$ chi tiết bức ảnh), còn từ $\sigma_{51}$ trở đi rất nhỏ (chỉ là nhiễu hạt li ti).
- **Thuật toán nén:** Bạn chỉ giữ lại $k = 50$ thành phần đầu tiên!
  - Số lượng số cần lưu: $50$ vector $u$ ($50 \times 1000$) + $50$ giá trị $\sigma$ ($50$) + $50$ vector $v$ ($50 \times 1000$) $\approx \mathbf{100.050}$ con số.
  - **Giảm dung lượng tới $90\%$** mà mắt người nhìn vào hầu như không nhận ra sự khác biệt!

---

# TỔNG KẾT: BẢNG TRA CỨU KHI LÀM BÀI THI & CODE

| Vấn đề                                                                                     | Gặp trường hợp nào?                                                                                                                                                                                                                                                                                                                      | Cách giải quyết / Công thức |
| :-------------------------------------------------------------------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------- |
| **Kiểm tra chéo hóa**                                                                | Đề cho ma trận$A$ vuông cấp $n$      | 1. Tính$\det(A - \lambda I) = 0$.2. Nếu có $n$ nghiệm phân biệt $\to$ **Chéo hóa được** ngay.3. Nếu có nghiệm bội $\to$ giải hệ tìm số vector riêng. Nếu số vector riêng $=$ số mũ $\to$ **Được**, ngược lại $\to$ **Không**. |                                  |
| **Tính $A^k$ ($A^{10}, A^{100}$)** | Ma trận chéo hóa được$A = P D P^{-1}$ |                                                                                                                                                                                                                                                                                                                                               |                                  |

$$
A^k = P \begin{bmatrix} \lambda_1^k & 0 \\ 0 & \lambda_2^k \end{bmatrix} P^{-1}
$$

                                                                                                                                                                                                            |
| **Phân rã Cholesky**                  | Ma trận$A = A^T$ và đối xứng dương   |

$$
A = L L^T \quad (L \text{ là ma trận tam giác dưới})
$$

 Nhân từng hàng với cột để tìm từng số của $L$.                                                                                                                                                                      |
| **Phân rã SVD**                       | Ma trận bất kỳ$m \times n$               |

$$
A = U \Sigma V^T
$$

 $\sigma_i = \sqrt{\lambda_i(A^T A)}$, $v_i$ là vector riêng của $A^T A$, $u_i = \frac{1}{\sigma_i} A v_i$.                                                                                                                                                     |
