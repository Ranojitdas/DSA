# DSA Pattern Notes — Rules

## 1. Pattern Workflow

- Before creating a new pattern MD, ask Ranojit for the notes from his instructor's video.
- Use those instructor notes to build the pattern's recognition clues and concepts.
- For a new pattern, write the **Introduction** and **Concepts & Patterns** sections before the problem-solving phase.
- Do not wait until 10–12 problems are solved to start recording problems.
- Add each solved problem to the pattern MD incrementally while the learning and mistakes are still fresh.
- After roughly 10–12 problems, review and clean up the pattern notes and summarize the most reusable lessons.

## 2. Pattern MD Structure

Every pattern gets its own `.md` file inside `patterns/`.

Use 3 main sections:

1. Introduction
2. Concepts & Patterns
3. Problems Solved

### 2.1 Introduction Subsections

Keep these subsection names consistent across patterns:

- **Definition** — what the pattern/technique is.
- **When to use?** — the clues in a problem that suggest this pattern may be useful.
  - This section must be **recognition-focused**, not a description of what the pattern does.
  - Build it primarily from the **instructor's notes**, preserving the instructor's recognition framework and terminology where appropriate.
  - **Verify the instructor's recognition clues against standard DSA knowledge** so the final notes teach technically correct and non-misleading concepts.
  - If an instructor note is incomplete or technically incorrect, correct or supplement it rather than preserving an error.
  - The goal is to answer: **"What clues in a new problem should make me consider this pattern?"**
  - Do not turn this section into an explanation of the algorithm's mechanics; those belong in **Definition**, **Basic Idea**, or **Concepts & Patterns**.
- **Basic Idea** — the simple mental model of how the pattern works.

Do not create separate headings such as **Recognition Signals** and **When should I think of it?** for the same purpose. Keep recognition clues under **When to use?**.

### 2.2 Concepts & Patterns Subsections

The subsection names here should be **pattern-specific**, based on the main reusable variations taught by the instructor and supported by standard DSA references.

- Usually use around **2–4 main pattern/variation subsections**.
- Keep subsection names short and natural so they are easy to scan and copy into the handwritten notebook.
- Add a single **Rules** subsection for short reusable rules that do not belong to one specific variation.
- Add a **Generic Brute Force** (or similar) subsection if the pattern has a standard brute-force approach (e.g., "nested loops to check all subarrays"). Documenting it here saves you from repeating it in every individual problem entry.
- Do not create extra subsections under **Rules** by default. Split Rules further only when a pattern genuinely needs separate categories such as Movement, Complexity, or Edge Cases.
- Do not create a subsection just to make the structure look fuller. Every subsection should contain genuinely reusable knowledge.

## 3. Problem Entry Style

For each important problem, keep the entry concise and revision-oriented.

Use:

### LC XX — Problem Name

**Think / Recognition**
- How to recognize the problem/pattern.

**Core Idea**
- Short explanation of the approach.

**Core Logic**
- The main structural loop or code block (usually 4-7 lines) that actually performs the logic, so you can practice translating the Core Idea into code.
- Omit basic boilerplate (like `int ans = 0;` or `return ans;`) to keep it concise.
- When a key code line represents the main trick or reasoning, briefly explain **why it is needed / why it works**.
- If the implementation is trivial, you can omit this section.

**Keep in mind**
> One short, natural memory trigger that makes the idea click later.

**My Mistake**
- Include only mistakes Ranojit actually made while solving or debugging the problem.
- If there are meaningful mistakes, keep them to **at most two concise points**, formatted as **i)** and **ii)**.
- If there is no meaningful mistake, omit the section.

## 4. Sources for Problem Entries

- **ChatGPT conversation:** source of truth for Ranojit's actual attempts, debugging process, mistakes, misconceptions, and lessons.
- **GitHub / LeetSync submission:** source of truth for the final submitted implementation and the approach that was ultimately accepted.
- **Standard DSA reference:** supporting conceptual cross-check only.

Never infer or invent a personal mistake from the final accepted GitHub code or from the standard reference.

## 5. Problem-Solving Workflow

1. Ranojit attempts the problem himself.
2. He runs/tests his code.
3. If stuck, gets TLE, runtime error, or cannot trace the issue, he brings the current attempt to ChatGPT.
4. ChatGPT should guide progressively rather than immediately giving the full solution, unless Ranojit explicitly asks for it.
5. After the problem is solved, record the meaningful learning in the pattern MD while it is fresh.

The goal is to teach reusable problem-solving and debugging habits, not just produce accepted code.

## 6. Interview Preparation Workflow

After solving and testing a problem, include a short interview-preparation step before recording the problem in the pattern MD.

The discussion should cover:

1. Brute-force approach
2. Why brute force is not preferred, including TC and SC
3. Optimal approach
4. Optimal TC and SC
5. Verification of correctness, complexity, and optimization

The purpose is to practice explaining solutions clearly in an interview, not only producing accepted code.

The interview discussion does not need to be copied into the pattern MD. **Do not include `Brute Force` or `Complexity` sections in the problem entry unless there is a very specific, non-obvious trick or it is absolutely necessary for revision.** The GitHub notes must remain concise and revision-oriented.

The problem-solving attempt comes first. Hints and explanations should remain progressive so that the solution is still derived by Ranojit whenever possible.

## 7. Revision Philosophy

The notes are for quick interview revision, not for reproducing a full LeetCode editorial.

The desired mental flow is:

**Problem → Recognition → Core Idea → Key Trick → Click**

Keep entries compact enough that Ranojit can scan them quickly and reconstruct the solution from memory.

## 8. Keep in Mind

The **Keep in mind** line should sound natural and useful in a handwritten notebook.

Avoid artificial or repetitive flashcard-style wording. Prefer a short sentence that captures the underlying idea.

## 9. Problem-Specific Mistakes

- A mistake that is specific to one problem belongs beside that problem under **My Mistake**.
- Include only mistakes Ranojit actually made while solving or debugging.
- Keep problem-specific mistakes to **0–2 meaningful points**.
- Do not create a separate general **My Mistakes & Lessons** section for the pattern.

## 10. Handwritten Notes vs GitHub MD

Ranojit's handwritten notebook may contain fuller explanations, traces, rough work, and personal reminders.

The GitHub pattern MD should be the cleaned, concise revision version.

They do not need to be identical.

## 11. GitHub Organization

Keep LeetSync-generated problem folders unchanged.

Pattern revision notes belong inside:

    patterns/

`patterns/` is the dedicated area for our revision notes.

## 12. New Pattern Rule

For every new pattern:

**Instructor notes first → Introduction + Concepts → Solve problems → Add each problem incrementally → Final cleanup after ~10–12 problems.**

The instructor's way of recognizing the pattern should be preserved in a cleaned-up form.

## 13. Concepts & Patterns Conciseness

The **Concepts & Patterns** section should contain only the **core, reusable concepts/patterns** needed to recognize and apply the pattern.

- Keep this section concise and revision-oriented; do not turn it into a textbook chapter.
- Use a small number of clear core patterns rather than many separate subsections.
- Problem-specific tricks, counting techniques, implementation details, debugging details, and one-off observations should normally stay inside the relevant **Problems Solved** entry or as short supporting rules.
- Do not create a separate major concept unless it is genuinely reusable across multiple problems in the pattern.

## 14. Interview-Important ⭐

Use a **⭐** beside a problem when it is worth prioritizing for interview and handwritten revision.

A problem may receive ⭐ for:

- **High interview value**
- **Important pattern/variation**
- **Reusable technique/trick**
- **Personal difficulty**

Keep stars selective. The ⭐ is a **revision-priority marker**, not a statement that unstarred problems are unimportant.

## 15. LeetSync Commit Messages

When Ranojit provides the **exact LeetSync commit message**, use that exact text as the commit message for the related GitHub problem changes.

Example:

    Time: 50 ms (30.58%) | Memory: 85 MB (34.64%) - LeetSync

**Do not replace it with a custom commit message.** For example, do not use `Add LC 904`, `Fix folder name`, or `Update problem` when Ranojit has supplied the LeetSync message.

This is part of Ranojit's established GitHub workflow. Preserve the exact LeetSync commit message whenever he provides it.
