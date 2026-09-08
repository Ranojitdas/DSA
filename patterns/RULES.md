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
- Do not create extra subsections under **Rules** by default. Split Rules further only when a pattern genuinely needs separate categories such as Movement, Complexity, or Edge Cases.
- Do not create a subsection just to make the structure look fuller. Every subsection should contain genuinely reusable knowledge.

Example:

```md
## 1. Introduction

### Definition

### When to use?

### Basic Idea

## 2. Concepts & Patterns

### Fixed Window

### Dynamic Window

### Rules

## 3. Problems Solved
```

Keep the overall structure consistent, while allowing Section 2's concept names to change according to the pattern.

## 3. Problem Entry Style

For each important problem, keep the entry concise and revision-oriented.

Use:

### LC XX — Problem Name

**Think / Recognition**
- How to recognize the problem/pattern.

**Core Idea**
- Short explanation of the approach.

**Important Code**
- Only important implementation details, initialization, or key lines that are easy to forget.
- When a key code line represents the main trick or reasoning, briefly explain **why it is needed / why it works**.
- Do not explain every ordinary line of code; focus on the implementation detail that is important for later revision.
- If there is no genuinely important code detail, omit this section.

Example:

```md
**Important Code**

```cpp
int target = -nums[i];
```

After fixing `nums[i]`, the remaining two elements must sum to `-nums[i]`, so this converts the remaining part into a Two Sum target.
```

The goal is to remember both **what to write** and **why the line is used**, so the idea can be reconstructed during revision.

**Keep in mind**
> One short, natural memory trigger that makes the idea click later.

**My Mistake**
- Include only mistakes Ranojit actually made while solving or debugging the problem.
- If there are meaningful mistakes, keep them to **at most two concise points**, formatted as **i)** and **ii)**.
- Do not force two points when there is only one meaningful mistake. In that case, keep one concise point.
- If there is no meaningful mistake, omit the **My Mistake** section entirely.
- Do not split one mistake artificially just to create two points.

Example:

```md
**My Mistake**
- i) I initially tried to force the problem into a two-pointer approach.
- ii) I assumed that using three pointers would make the solution O(n²), because I associated multiple pointers with 3Sum.
```

Do not turn every temporary thought, small observation, or normal part of the solving process into a mistake. Keep only mistakes that are useful for avoiding the same issue in a future problem/interview.

## 4. Sources for Problem Entries

Use two different sources for two different purposes:

- **ChatGPT conversation:** source of truth for Ranojit's actual attempts, debugging process, mistakes, misconceptions, and lessons.
- **GitHub / LeetSync submission:** source of truth for the final submitted implementation and the approach that was ultimately accepted.
- **Standard DSA reference:** use a reputable standard DSA book or reference resource as a conceptual cross-check when building a pattern, mainly to make sure important fundamentals are not missed.

The standard reference is a **supporting source**, not the source for Ranojit's personal notes. Do not reproduce textbook explanations or turn the pattern MD into textbook notes.

Never infer or invent a personal mistake from the final accepted GitHub code or from the standard reference.

When adding a problem entry, check the corresponding GitHub problem folder when useful to verify the final implementation, but personal mistakes must come from the actual solving discussion.

## 5. Problem-Solving Workflow

The learning process comes first:

1. Ranojit attempts the problem himself.
2. He runs/tests his code.
3. If stuck, gets TLE, runtime error, or cannot trace the issue, he brings the current attempt to ChatGPT.
4. ChatGPT should guide progressively rather than immediately giving the full solution, unless Ranojit explicitly asks for it.
5. After the problem is solved, record the meaningful learning in the pattern MD while it is fresh.

The goal is to teach reusable problem-solving and debugging habits, not just produce accepted code.

## 6. Revision Philosophy

The notes are for quick interview revision, not for reproducing a full LeetCode editorial.

The desired mental flow is:

**Problem → Recognition → Core Idea → Key Trick → Click**

Keep entries compact enough that Ranojit can scan them quickly and reconstruct the solution from memory.

Do not add full solutions, long explanations, or generic textbook material unless a specific detail is genuinely important for revision.

## 7. Keep in Mind

The **Keep in mind** line should sound natural and useful in a handwritten notebook.

Avoid artificial or repetitive flashcard-style wording such as:

> `Problem → trick`

Prefer a short sentence that captures the underlying idea, for example:

> Closest means minimum distance from target.

## 8. Problem-Specific Mistakes

- A mistake that is specific to one problem belongs beside that problem under **My Mistake**.
- Include only mistakes Ranojit actually made while solving or debugging.
- Keep problem-specific mistakes to **0–2 meaningful points**. Use **i)** and **ii)** when there are two distinct mistakes.
- Do not record temporary thoughts or minor observations unless they reveal a reusable misconception or debugging lesson.
- Do not create a separate general **My Mistakes & Lessons** section for the pattern; this avoids repeating lessons already captured beside the relevant problems.

## 9. Handwritten Notes vs GitHub MD

Ranojit's handwritten notebook may contain fuller explanations, traces, rough work, and personal reminders.

The GitHub pattern MD should be the cleaned, concise revision version.

They do not need to be identical.

## 10. GitHub Organization

Keep LeetSync-generated problem folders unchanged.

Pattern revision notes belong inside:

```text
patterns/
```

Example:

```text
DSA/
├── patterns/
│   ├── RULES.md
│   ├── two-pointer.md
│   ├── sliding-window.md
│   └── binary-search.md
├── 15-3sum/
├── 16-3sum-closest/
├── 27-remove-element/
└── ...
```

`patterns/` is the dedicated area for our revision notes.

## 11. New Pattern Rule

For every new pattern:

**Instructor notes first → Introduction + Concepts → Solve problems → Add each problem incrementally → Final cleanup after ~10–12 problems.**

The instructor's way of recognizing the pattern should be preserved in a cleaned-up form, because recognition is a major part of interview revision.

## 12. Concepts & Patterns Conciseness

The **Concepts & Patterns** section should contain only the **core, reusable concepts/patterns** needed to recognize and apply the pattern.

- Keep this section concise and revision-oriented; do not turn it into a textbook chapter.
- Use a small number of clear core patterns rather than many separate subsections.
- Problem-specific tricks, counting techniques, implementation details, debugging details, and one-off observations should normally stay inside the relevant **Problems Solved** entry or as short supporting rules.
- Do not create a separate major concept for something unless it is genuinely reusable across multiple problems in the pattern.
- Preserve important instructor concepts, but compress them into the core patterns and short supporting rules instead of removing the underlying knowledge.

## 13. Interview-Important ⭐

Use a **⭐** beside a problem when it is worth prioritizing for interview and handwritten revision.

A problem may receive ⭐ when it meets **at least one** of these reasons:

- **High interview value** — commonly asked or especially important for interview preparation.
- **Important pattern/variation** — represents a core variation that is useful for recognizing or applying the pattern elsewhere.
- **Reusable technique/trick** — teaches a technique, implementation idea, or reasoning trick that transfers to many problems.
- **Personal difficulty** — Ranojit struggled with the problem or found an important misconception/debugging issue in it, making it valuable to revisit.

Keep stars selective; do not star most or all problems just because they are useful.

The ⭐ is a **revision-priority marker**, not a statement that unstarred problems are unimportant or should not be solved.

All regular problems that Ranojit solves can still be recorded in the GitHub pattern MD. The ⭐ only identifies the problems that should receive priority in handwritten/interview revision.

Do not add a separate priority field when the ⭐ can communicate the same information cleanly.
