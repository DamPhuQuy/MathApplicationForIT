# Technical Decision: DEC-001 FEAT-001 Lựa chọn Cấu trúc Tổ chức Tệp Tổng hợp Đề thi

<technical_decision task_id="FEAT-001-extract-midterm-exam-questions" dec_id="DEC-001" version="2.0" framework="RIPER-5">

<decision_status>
  <phase>INNOVATE</phase>
  <mode>READ-ONLY</mode>
  <halting_status>READY_FOR_SIGN_OFF</halting_status>
  <decision_owner>@engineer</decision_owner>
  <last_updated>2026-10-08T21:37:00+07:00</last_updated>
</decision_status>

---

## 1. Design Space & Degrees of Freedom (I0: Design Space)

<design_space>
  <context_reference>
    <task>[task.md](task.md)</task>
    <research_artifact>[research.md](research.md)</research_artifact>
  </context_reference>

  <mutable_dimensions>
    - Cấu trúc trình bày tài liệu Markdown tổng hợp (theo từng đề, theo định dạng đề, hoặc theo chuyên đề toán học).
    - Mức độ chi tiết của phần ghi chú kiến thức tham khảo (Knowledge Reference citation).
  </mutable_dimensions>

  <immutable_boundaries>
    - Giữ nguyên vẹn 100% nội dung câu hỏi đề bài và các tham số kỹ thuật ($N$, hệ phương trình đồng dư, ma trận $A$, sai số $\varepsilon$).
    - Tuyệt đối không đưa code giải sẵn vào tài liệu tổng hợp (chỉ là đề bài).
    - Chuẩn hóa toàn bộ công thức toán học sang định dạng LaTeX Markdown.
  </immutable_boundaries>

  <hard_constraints>
    - Bao quát đầy đủ toàn bộ 15 file .docx trong thư mục mà không làm rối mắt người đọc do các file bài làm trùng lặp.
  </hard_constraints>
</design_space>

---

## 2. Decision Required

<decision_question>
  Lựa chọn cấu trúc và phương pháp tổ chức tệp Markdown tổng hợp đề thi nhằm tối ưu hóa trải nghiệm ôn tập và tra cứu của sinh viên?
</decision_question>

---

## 3. Candidate Options (I1: Repo-Native Candidates)

<options>
  <option id="A" type="Minimalist">
    <title>Trình bày tuần tự theo từng file .docx (15 mục riêng biệt)</title>
    <approach>Liệt kê lần lượt từng file từ 1 đến 15, trích xuất đề bài của từng file.</approach>
    <complexity>LOW</complexity>
    <blast_radius>MINIMAL</blast_radius>
    <flaw>Gây trùng lặp nghiêm trọng vì nhiều file thực chất là bài làm của các sinh viên khác nhau cùng làm chung 1 đề.</flaw>
  </option>

  <option id="B" type="Repo-Idiomatic">
    <title>Tổ chức theo 2 Format cấu trúc đề thi (Format A: 3 câu, Format B: 4 câu) kết hợp Bảng tổng hợp chuyên đề</title>
    <approach>Gom cụm 15 file về 9 bộ đề duy nhất thuộc 2 format chính (Format A gồm 4 đề, Format B gồm 5 đề), có bảng đối chiếu nguồn file, gắn tag dạng toán ở từng câu và bảng tổng kết kiến thức tham chiếu Slide Thầy P.C. Thắng.</approach>
    <complexity>MEDIUM</complexity>
    <blast_radius>OPTIMAL</blast_radius>
  </option>

  <option id="C" type="Extensible">
    <title>Xé lẻ toàn bộ câu hỏi và gom nhóm thuần túy theo Chuyên đề Toán học</title>
    <approach>Gom toàn bộ câu hỏi thành: Chuyên đề 1 (Lý thuyết số), Chuyên đề 2 (Đại số tuyến tính).</approach>
    <complexity>MEDIUM</complexity>
    <blast_radius>CONTROLLED</blast_radius>
    <flaw>Làm mất cấu trúc của một đề thi hoàn chỉnh (thời gian làm bài 90 phút, thang điểm 10) cần thiết để sinh viên luyện thi thử.</flaw>
  </option>
</options>

---

## 4. Weighted Pugh Decision Matrix (I2: Trade-Off Analysis)

<pugh_matrix>

| Tiêu chí đánh giá | Trọng số ($W_i$) | Baseline (Hiện trạng) | Option A (Tuần tự file) | Option B (Gom cụm Format đề + Gắn tag) | Option C (Gom thuần chuyên đề) |
|---|:---:|:---:|:---:|:---:|:---:|
| 1. Tính trực quan & Dễ ôn thi thử (Mock Test) | 3 | 0 | -1 | +1 | 0 |
| 2. Loại bỏ trùng lặp (Anti-duplication) | 3 | 0 | -1 | +1 | +1 |
| 3. Tính gắn kết với Knowledge Reference (Slide) | 2 | 0 | 0 | +1 | +1 |
| 4. Độ đầy đủ và trung thực dữ liệu gốc | 2 | 0 | +1 | +1 | 0 |
| **Tổng điểm trọng số ($\sum W_i \times S_{ij}$)** | -- | **0** | **-4** | **+10** | **+5** |

</pugh_matrix>

---

## 5. Decision & Negative Architectural Memory (I4: Decision)

<decision_outcome>
  <selected_option>Option B: Tổ chức theo 2 Format cấu trúc đề thi kết hợp Bảng tổng hợp chuyên đề</selected_option>
  <approved_by>[AUTO: DELEGATED]</approved_by>
  <approved_date>2026-10-08T21:37:00+07:00</approved_date>
  <rationale>
    Option B đạt điểm số Pugh cao nhất (+10). Nó giải quyết triệt để vấn đề trùng lặp dữ liệu giữa 15 file của sinh viên, giữ trọn vẹn cấu trúc đề thi 90 phút để luyện giải, đồng thời cung cấp chú thích dạng toán chuẩn hóa theo Slide môn học.
  </rationale>
  <rejected_alternatives>
    - Bác bỏ Option A: Dẫn đến một file dài dòng, lặp đi lặp lại cùng một đề bài nhiều lần.
    - Bác bỏ Option C: Phá vỡ cấu trúc đề thi thực tế, khiến người học khó hình dung ma trận đề thi giữa kỳ 90 phút.
  </rejected_alternatives>
</decision_outcome>

---

## 6. Gate 1 — Deterministic Innovation Halting Predicate

| Tiêu chí | Trạng thái | Minh chứng |
|---|---|---|
| $D_{space}$ (Không gian thiết kế rõ ràng) | **PASS** | Đã định hình 3 phương án tổ chức |
| $S_{alternatives}$ (Đa dạng giải pháp) | **PASS** | Đầy đủ phương án A, B, C |
| $T_{traded}$ (Ma trận Pugh dương) | **PASS** | Option B đạt +10 điểm |
| $A_{challenged}$ (Phản biện & rủi ro) | **PASS** | Đã chỉ rõ nhược điểm của Option A và C |
| $D_{decided}$ (Quyết định được khóa) | **PASS** | Chọn Option B và ghi nhận vào ADR |

**Kết luận Gate G1:** PASS. Chuyển tiếp sang Phase PLAN.
</technical_decision>
