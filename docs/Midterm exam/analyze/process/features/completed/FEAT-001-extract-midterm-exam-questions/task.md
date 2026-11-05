# Task: FEAT-001 Trích xuất và Tổng hợp Đề thi Giữa kỳ môn Toán Ứng Dụng CNTT

<task_spec version="3.0" framework="RIPER-5">

<!-- ════════════════════════════════════════════
     SECTION 0 — TASK CONTROL (master state record)
     ════════════════════════════════════════════ -->
<task_control>
  <status>COMPLETED</status>  <!-- BACKLOG | ACTIVE | BLOCKED | PAUSED | REVIEW | COMPLETED | CANCELLED -->
  <spec_level>S3</spec_level>  <!-- S0=sketch | S1=defined | S2=verified | S3=locked -->
  <priority>P1</priority>  <!-- P0=urgent | P1=high | P2=normal | P3=low -->
  <risk>LOW</risk>  <!-- LOW | MEDIUM | HIGH -->
  <estimated_story_points>2</estimated_story_points>  <!-- 1 SP ≈ 2-4 focused engineering hours -->
  <working_mode>PAIR</working_mode>  <!-- PAIR (default: halts at each gate for review) | DELEGATED (fast-track: continuous autonomous run) | MANUAL | DIAGNOSE-ONLY -->
  <observability_mode>OFF</observability_mode>  <!-- OFF (default: lean, zero-overhead) | PROFILE (single-shot cost tally at review) | BENCHMARK (with results.tsv) -->
  <current_phase>REVIEW</current_phase>  <!-- RESEARCH | INNOVATE | PLAN | EXECUTE | REVIEW -->
  <owner>@phuqy</owner>
  <decision_owner>@phuqy</decision_owner>
  <created>2026-10-08T21:30:00+07:00</created>
  <last_updated>2026-10-08T21:30:00+07:00</last_updated>
</task_control>

---

## 1. Specification (Pillar 1: Task / Spec)

<specification>
  <goal>
    Trích xuất toàn bộ câu hỏi đề bài thi giữa kỳ từ 15 tệp .docx mẫu trong thư mục hiện tại, tổng hợp vào một tệp Markdown hoàn chỉnh, có phân loại dạng toán chi tiết dựa trên tài liệu tham khảo (Slides Thầy P.C. Thắng & Đề cương môn học), đồng thời KHÔNG kèm code giải mẫu.
  </goal>

  <current_behavior>
    Các đề thi mẫu và bài làm của sinh viên đang phân tán trong 15 file .docx khác nhau, chứa mã nguồn giải bài, bảng biểu, công thức toán dạng MathType/hình ảnh và cấu trúc đề chưa được chuẩn hóa, phân loại.
  </current_behavior>

  <expected_behavior>
    Một tệp markdown tổng hợp duy nhất chứa toàn bộ đề bài (từ Câu 1 đến hết) của tất cả các đề/biến thể, giữ nguyên các thông số đề bài (N, hệ phương trình đồng dư, ma trận A, sai số epsilon), được phân loại rõ ràng theo dạng toán (Lý thuyết số, Đại số tuyến tính, v.v.) dựa trên slide môn học, định dạng chuẩn LaTeX/Markdown, không chứa code giải.
  </expected_behavior>

  <actor_authorization>
    Sinh viên / Người học môn Toán ứng dụng CNTT.
  </actor_authorization>

  <invariants>
    - Giữ nguyên vẹn nội dung câu hỏi đề bài, không tự ý thay đổi số liệu đề gốc.
    - Không chèn code giải mẫu vào tệp markdown tổng hợp (chỉ tổng hợp đề bài).
    - Mọi công thức toán học và ma trận phải được chuyển đổi chuẩn hóa sang định dạng LaTeX Markdown.
    - Ánh xạ chính xác các câu hỏi vào các chương trong tài liệu học tập (`thầy P.C.Thắng/Slides`).
  </invariants>

  <out_of_scope>
    - Viết lời giải chi tiết hoặc viết mã nguồn C/C++/Python cho các bài toán.
    - Chỉnh sửa, ghi đè hoặc xóa bất kỳ file .docx gốc nào.
  </out_of_scope>

  <acceptance_criteria>
    - [ ] AC-1: Quét và phân loại đầy đủ 15 file .docx trong thư mục hiện tại thành các nhóm đề và cấu trúc đề thi.
    - [ ] AC-2: Trích xuất chính xác 100% đề bài từ Câu 1 đến câu cuối cùng của từng đề, phục hồi toàn bộ công thức hệ đồng dư và ma trận từ OLE/ảnh.
    - [ ] AC-3: Gắn thẻ/chú thích dạng toán chi tiết cho từng câu hỏi dựa trên Knowledge Reference (`thầy P.C.Thắng/Slides/` và đề cương môn học).
    - [ ] AC-4: Tạo tệp Markdown hoàn chỉnh, trình bày trực quan, công thức toán LaTeX rõ ràng, không kèm code mẫu.
  </acceptance_criteria>

  <definition_of_ready>
    - [x] Target outcome and acceptance criteria are verifiable without guessing.
    - [x] Invariants and <out_of_scope> boundaries are explicit.
    - [x] Open questions resolved or scheduled in decision.md.
  </definition_of_ready>
</specification>

---

## 2. Context Boundaries (Pillar 2: Context)

<context_boundaries>
  <target_files>
    - `tong_hop_de_thi_giua_ky.md` — [Tệp markdown tổng hợp đề thi]
    - `process/features/active/FEAT-001-extract-midterm-exam-questions/research.md` — [Tài liệu nghiên cứu và trích xuất sơ bộ]
  </target_files>

  <context_groups>
    - [`planning/all-planning.md`](process/context/planning/all-planning.md)
    - [`../../thầy P.C.Thắng/Slides`](/home/phuqy/Develop/MathApplicationForIT/thầy P.C.Thắng/Slides)
  </context_groups>

  <source_of_truth>
    <requirement>User request: Trích xuất đề bài từ câu 1 đến hết từ các file .docx, tổng hợp vào file markdown, ghi chú dạng toán, không lấy code.</requirement>
    <architecture>RIPER-5 Framework (Full Track, PAIR mode)</architecture>
    <knowledge_reference>/home/phuqy/Develop/MathApplicationForIT/thầy P.C.Thắng/Slides</knowledge_reference>
  </source_of_truth>
</context_boundaries>

---

## 3. Verification Strategy

<verification_strategy>
| AC / Risk | Evidence required | Verifier |
|---|---|---|
| AC-1 | Danh mục đối chiếu 15 file .docx | Kiểm tra bảng phân loại file trong research.md |
| AC-2 | Đầy đủ thông số (N, hệ đồng dư, ma trận) | So sánh chéo nội dung trích xuất với ảnh/bản in đề |
| AC-3 | Ghi chú dạng toán và chương mục | Trích dẫn tương ứng với Slide Thầy Thắng |
| AC-4 | Tệp Markdown sạch, công thức LaTeX chuẩn, không code | Lint cú pháp Markdown và kiểm tra không có code block |
</verification_strategy>

---

## 4. Decisions

<decisions>
  <approved_decisions>
    | ID | Decision | Rationale | Owner |
    |---|---|---|---|
    | DEC-01 | Phân loại các file .docx thành 2 format chính (Format A: 3 câu 10 điểm; Format B: 4 câu 10 điểm) | 15 file thực chất là các biến thể của 2 cấu trúc đề thi giữa kỳ chính qua các năm | @phuqy |
    | DEC-02 | Chuyển đổi toàn bộ ma trận và hệ phương trình MathType OLE/WMF sang LaTeX | Đảm bảo hiển thị chuẩn toán học trên mọi trình đọc Markdown | @phuqy |
  </approved_decisions>

  <open_decisions>
  </open_decisions>
</decisions>

---

## 5. RIPER-5 Execution Plan

<execution_plan>
  <phase name="Research" order="1">
    - [x] Khảo sát toàn bộ 15 file .docx trong thư mục hiện tại.
    - [x] Khảo sát knowledge reference từ Slide Thầy P.C. Thắng và Đề cương môn học.
    - [x] Trích xuất toàn bộ câu hỏi đề thi và giải mã công thức toán từ hình ảnh/MathType.
    - [x] Xây dựng artifact `research.md`.
    <gate id="G0" label="Research Complete">
      - [x] Toàn bộ 15 file đã được phân tích.
      - [x] Các dạng toán đã được map vào chương mục Slide.
      - [x] Không còn thông số/công thức bị thiếu.
    </gate>
  </phase>

  <phase name="Innovate" order="2">
    - [ ] Lựa chọn cấu trúc trình bày tệp Markdown tổng hợp (theo Format đề hay theo Chuyên đề dạng toán, hay kết hợp cả hai).
    - [ ] Lập `decision.md`.
    <gate id="G1" label="Gate 1 — Decision Approved">
      - [ ] Phương án tổ chức Markdown được duyệt.
    </gate>
  </phase>

  <phase name="Plan" order="3">
    - [ ] Lập kế hoạch các lát cắt (Slices) để sinh tệp markdown tổng hợp.
    - [ ] Lập `plan.md`.
    <gate id="G2" label="Gate 2 — Plan Approved">
      - [ ] Kế hoạch được phê duyệt.
    </gate>
  </phase>

  <phase name="Execute" order="4">
    - [ ] Tạo tệp Markdown tổng hợp đề thi theo cấu trúc đã thống nhất.
    - [ ] Cập nhật `state.md`.
  </phase>

  <phase name="Review" order="5">
    - [ ] Kiểm tra tính đầy đủ, chính xác của công thức và dạng toán.
    - [ ] Lập `review.md` và `handoff.md`.
    <gate id="G3" label="Gate 3 — Review Passed">
      - [ ] Nghiệm thu sản phẩm cuối cùng.
    </gate>
  </phase>
</execution_plan>

---

## 6. Guardrails & Escalation

<guardrails>
  <stop_conditions>
    - Phát hiện đề bài thiếu dữ liệu quan trọng không thể khôi phục.
    - Yêu cầu vi phạm nguyên tắc chỉ lấy đề bài (bị lẫn code).
  </stop_conditions>

  <retry_budget max_attempts="3">
    Tối đa 3 lần điều chỉnh trích xuất công thức nếu có sai lệch.
  </retry_budget>
</guardrails>

</task_spec>
