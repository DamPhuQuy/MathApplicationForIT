# State: FEAT-001 Trích xuất và Tổng hợp Đề thi Giữa kỳ

<loop_state task_id="FEAT-001-extract-midterm-exam-questions" version="2.0" framework="RIPER-5">

<state_header>
  <current_phase>EXECUTE</current_phase>
  <current_gate>G2</current_gate>
  <last_updated>2026-10-08T21:38:30+07:00</last_updated>
</state_header>

---

## 1. Task

<task_ref>
  <task_spec>[task.md](task.md)</task_spec>
  <plan>[plan.md](plan.md)</plan>
</task_ref>

---

## 2. Goal & Invariants

<goal_and_invariants>
  <goal>Trích xuất đầy đủ đề bài từ Câu 1 đến hết từ 15 file .docx thành tệp Markdown có phân loại dạng toán theo Slide Thầy Thắng và không chứa code mẫu.</goal>
  <invariants>
    - Đề bài gốc được giữ nguyên 100% dữ liệu.
    - Công thức toán và ma trận chuyển đổi sang định dạng LaTeX chuẩn.
    - Không chứa mã nguồn giải bài.
  </invariants>
</goal_and_invariants>

---

## 3. Approved Decisions

<approved_decisions>
  - DEC-001: Lựa chọn cấu trúc Option B (Tổ chức theo 2 Format cấu trúc đề thi kết hợp Bảng tổng hợp chuyên đề)
</approved_decisions>

---

## 4. Completed Slices

<completed_slices>
  | Slice | Status | Atomic Change | Verifier Result | Evidence |
  |---|---|---|---|---|
  | S1 | DONE | Xuất bản `tong_hop_de_thi_giua_ky.md` | PASS | 9 bộ đề thi hoàn chỉnh với 452 dòng Markdown |
  | S2 | DONE | Kiểm chứng không có code mẫu & chuẩn LaTeX | PASS | `python3 -c "assert '#include' not in open('tong_hop_de_thi_giua_ky.md').read()"` PASSED |
</completed_slices>

---

## 5. Current Slice

<current_slice>
  <id>S2</id>
  <objective>Kiểm chứng nội dung đảm bảo thuần túy là đề bài, không chứa code giải</objective>
  <status>DONE</status>
</current_slice>

---

## 6. Verification Evidence

<verification_evidence>
```text
$ python3 -c "
c = open('tong_hop_de_thi_giua_ky.md').read()
assert c.count('### 📌 Đề') == 9, 'Count not 9'
assert '#include' not in c, 'Has #include'
assert 'using namespace' not in c, 'Has using namespace'
print('ALL VERIFIERS PASSED!')
"
Output:
ALL VERIFIERS PASSED!
```
</verification_evidence>

---

## 7. Next Action

<next_action>
  Chuyển sang Phase REVIEW để lập `review.md`, thẩm định Gate 3 và xuất bản `handoff.md`.
</next_action>

</loop_state>
