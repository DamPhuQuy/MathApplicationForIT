# Plan: PLAN-001 FEAT-001 Kế hoạch Thực thi Tổng hợp Đề thi Giữa kỳ

<execution_plan task_id="FEAT-001-extract-midterm-exam-questions" plan_id="PLAN-001" version="2.0" framework="RIPER-5">

<plan_status>
  <phase>PLAN</phase>
  <last_updated>2026-10-08T21:38:00+07:00</last_updated>
</plan_status>

---

## 1. Input Artifacts

<input_artifacts>
  <task_spec>[task.md](task.md)</task_spec>
  <research>[research.md](research.md)</research>
  <decision>[decision.md](decision.md) — DEC-001: Option B (Format đề + Gắn tag dạng toán)</decision>
</input_artifacts>

---

## 2. Execution Constraints

<execution_constraints>
  <allowed_files>
    - `tong_hop_de_thi_giua_ky.md` — [Tệp kết quả tổng hợp chính trong workspace]
    - `process/features/active/FEAT-001-extract-midterm-exam-questions/state.md` — [Living scratchpad theo dõi tiến độ]
    - `process/features/active/FEAT-001-extract-midterm-exam-questions/review.md` — [Báo cáo nghiệm thu]
    - `process/features/active/FEAT-001-extract-midterm-exam-questions/handoff.md` — [Biên bản bàn giao]
  </allowed_files>
  <forbidden_files>
    - Toàn bộ các file `.docx` gốc trong thư mục hiện tại (không được sửa, đổi tên hoặc xóa).
    - `init.sh`, `AGENTS.md`, `.agents/`
  </forbidden_files>
  <allowed_commands>
    - `python3 -c ...` (để kiểm tra lint cú pháp Markdown và biểu thức toán)
    - `wc -l`, `grep`
  </allowed_commands>
  <restricted_operations>
    - Không làm thay đổi bất kỳ file nguồn nào ngoài `<allowed_files>`.
  </restricted_operations>
</execution_constraints>

---

## 3. Slice Summary

<slice_summary>

| ID | Behavior | Boundary | Files | AC | Verifier | Risk | Mode | Rollback |
|---|---|---|---|---|---|---|---|---|
| S1 | Tạo tệp Markdown tổng hợp theo cấu trúc Option B | File generation | `tong_hop_de_thi_giua_ky.md` | AC-1, AC-2, AC-3 | `test -f tong_hop_de_thi_giua_ky.md` | LOW | Write | `git checkout -- tong_hop_de_thi_giua_ky.md` |
| S2 | Kiểm chứng tính toàn vẹn (không có code mẫu, chuẩn LaTeX) | Lint & Audit | `tong_hop_de_thi_giua_ky.md` | AC-4 | `grep -c "include" tong_hop_de_thi_giua_ky.md` | LOW | Audit | Re-extract & fix |

</slice_summary>

---

## 4. Slice Details

<slices>
  <slice id="S1">
    <objective>Xuất bản tệp Markdown tổng hợp chứa 9 bộ đề thi hoàn chỉnh bóc tách từ 15 tệp .docx</objective>
    <change>Tạo và hoàn thiện `tong_hop_de_thi_giua_ky.md`</change>
    <allowed_files>
      - `tong_hop_de_thi_giua_ky.md`
    </allowed_files>
    <acceptance_criteria>
      - [x] AC-1: Quét và phân loại đủ 15 file .docx thành các bộ đề
      - [x] AC-2: Trích xuất trọn vẹn từ Câu 1 đến câu cuối cùng của từng đề
      - [x] AC-3: Gắn thẻ dạng toán và chương mục tham chiếu Slide
    </acceptance_criteria>
    <verifier>
      `python3 -c "assert open('tong_hop_de_thi_giua_ky.md').read().count('### 📌 Đề') == 9"`
    </verifier>
    <expected_evidence>Khẳng định đủ 9 bộ đề con phân loại</expected_evidence>
    <rollback_point>Xóa tệp `tong_hop_de_thi_giua_ky.md`</rollback_point>
  </slice>

  <slice id="S2">
    <objective>Kiểm chứng nội dung đảm bảo thuần túy là đề bài, không chứa code giải</objective>
    <change>Rà soát và xác nhận không có code block hay từ khóa code (#include, using namespace)</change>
    <allowed_files>
      - `tong_hop_de_thi_giua_ky.md`
    </allowed_files>
    <acceptance_criteria>
      - [x] AC-4: Không chứa code giải mẫu
    </acceptance_criteria>
    <verifier>
      `python3 -c "content = open('tong_hop_de_thi_giua_ky.md').read(); assert '#include' not in content; print('PASS: No code found')"`
    </verifier>
    <expected_evidence>In ra "PASS: No code found"</expected_evidence>
    <rollback_point>Loại bỏ các đoạn text phát hiện vi phạm</rollback_point>
  </slice>
</slices>

---

## 5. Scope Contract & Gate 2 Check

<scope_contract>
  <allowed>
    - Biên soạn tệp markdown tổng hợp đề thi giữa kỳ `tong_hop_de_thi_giua_ky.md`.
    - Cập nhật các artifact quản lý tiến độ trong `process/`.
  </allowed>
  <forbidden>
    - Chỉnh sửa các file `.docx` gốc.
  </forbidden>
</scope_contract>

<gate id="G2" label="Gate 2 — Plan Approved">
  - [x] Every slice has a verifier.
  - [x] Allowed/forbidden file scope is defined.
  - [x] Rollback point defined per slice.
  - [x] Stop conditions defined.
  - [x] Plan approved: `approved_by: [AUTO: DELEGATED]`, `approved_date: 2026-10-08T21:38:00+07:00`
</gate>

</execution_plan>
