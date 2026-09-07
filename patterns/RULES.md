# DSA Pattern Notes — Rules

## 1. Pattern Workflow

- Before creating a new pattern MD, ask Ranojit for the notes from his instructor's video.
- Use those instructor notes to build the pattern's recognition signals and concepts.
- For a new pattern, write the **Introduction** and **Concepts & Patterns** sections before the problem-solving phase.
- Do not wait until 10–12 problems are solved to start recording problems.
- Add each solved problem to the pattern MD incrementally while the learning and mistakes are still fresh.
- After roughly 10–12 problems, review and clean up the pattern notes and summarize the most reusable lessons.

## 2. Pattern MD Structure

Every pattern gets its own `.md` file inside `patterns/`.

Use 4 main sections:

1. Introduction
2. Concepts & Patterns
3. Problems Solved
4. My Mistakes & Lessons

Keep the structure consistent across patterns.

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

**Keep in mind**
> One short, natural memory trigger that makes the idea click later.

**My Mistake**
- Include only mistakes Ranojit actually made while solving or debugging the problem.

Do not force a section when there is nothing meaningful to add.

## 4. Sources for Problem Entries

Use two different sources for two different purposes:

- **ChatGPT conversation:** source of truth for Ranojit's actual attempts, debugging process, mistakes, misconceptions, and lessons.
- **GitHub / LeetSync submission:** source of truth for the final submitted implementation and the approach that was ultimately accepted.

Never infer or invent a personal mistake from the final accepted GitHub code.

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

## 8. Personal Mistakes & Lessons

- A mistake that is specific to one problem belongs beside that problem.
- General or repeated mistakes can also be summarized in **My Mistakes & Lessons**.
- Do not invent mistakes or add generic mistakes just to fill space.
- Prefer the smallest useful wording that preserves what Ranojit actually learned.

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
