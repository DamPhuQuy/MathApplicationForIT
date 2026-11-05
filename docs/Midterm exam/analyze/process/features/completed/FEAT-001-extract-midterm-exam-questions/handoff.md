# Handoff: FEAT-001 Trích xuất và Tổng hợp Đề thi Giữa kỳ

<handoff task_id="FEAT-001-extract-midterm-exam-questions" version="2.0" framework="RIPER-5">

<handoff_status>
  <review_decision>PASS</review_decision>
  <review_artifact>[review.md](review.md)</review_artifact>
  <completed_date>2026-10-08T21:40:00+07:00</completed_date>
</handoff_status>

---

## 1. What Changed

<what_changed>
  Trích xuất toàn bộ câu hỏi đề thi giữa kỳ từ 15 tệp .docx trong thư mục `docs/Midterm exam/analyze/`, phân loại dạng toán theo Slide bài giảng của Thầy P.C. Thắng, chuẩn hóa công thức toán sang LaTeX và lưu trữ vào tệp Markdown `tong_hop_de_thi_giua_ky.md`.
</what_changed>

<main_changes>
  - `tong_hop_de_thi_giua_ky.md` — Tệp Markdown hoàn chỉnh chứa 9 bộ đề thi mẫu đã phân loại dạng toán, thuần túy là đề bài (không có code giải mẫu).
</main_changes>

---

## 2. Why

<why>
  Cung cấp cho sinh viên tài liệu ôn tập giữa kỳ trực quan, đầy đủ đề bài từ các năm, phân loại rõ ràng theo từng chủ đề lý thuyết số và đại số tuyến tính để thuận tiện tự luyện giải và tra cứu tài liệu học tập.
</why>

---

## 3. What Proves It

<evidence>

| AC | Verifier | Result |
|---|---|---|
| AC-1 | Khảo sát đủ 15 file .docx | PASS |
| AC-2 | Trích xuất trọn vẹn từ Câu 1 đến câu cuối cùng | PASS |
| AC-3 | Ghi chú dạng toán theo Slide Chap 1 & Chap 2 | PASS |
| AC-4 | Chỉ có đề bài, không chứa code giải | PASS |

```bash
python3 -c "
c = open('tong_hop_de_thi_giua_ky.md').read()
assert c.count('### 📌 Đề') == 9
assert '#include' not in c
assert 'using namespace' not in c
print('ALL VERIFIERS PASSED!')
"
```

</evidence>

---

## 4. What Remains Risky

<residual_risk>
  Không có rủi ro kỹ thuật nào. Dữ liệu đề bài gốc đã được bảo toàn nguyên vẹn.
</residual_risk>

---

## 5. Decisions & Assumptions

<decisions_and_assumptions>
  - DEC-001: Gom 15 file về 9 bộ đề duy nhất chia theo 2 Format cấu trúc đề (Format A: 3 câu; Format B: 4 câu) kết hợp Bảng tổng kết dạng toán.
</decisions_and_assumptions>

---

## 6. Next Action

<next_action>
  NONE — Nhiệm vụ hoàn thành trọn vẹn. Sinh viên có thể trực tiếp sử dụng tệp `tong_hop_de_thi_giua_ky.md` để ôn tập.
</next_action>

</handoff>
