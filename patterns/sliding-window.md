# Sliding Window

## 1. Introduction

- Sliding Window is used to work with a **continuous range** of elements in an array or string.
- The window is represented by two pointers, usually `left` and `right`.
- Both pointers move in the **same direction** as the window slides through the input.
- The window can **expand** or **shrink** depending on the condition of the problem.

### Recognition Signals

Think about Sliding Window when:

- The problem is on an **array or string**.
- It asks about a **subarray or substring** — a continuous part of the original input.
- We need something such as:
  - maximum / minimum
  - longest / shortest
  - sum / count / average
  - a condition such as **at most `k`**, **at least `k`**, or **exactly `k`**

### Basic Mental Model

```text
left                         right
  ↓                            ↓
[---------------------------------]
          current window

right++  → expand the window
left++   → shrink the window
```

## 2. Concepts & Patterns

### Fixed-Size Window

Use this when the required window length is fixed, such as a subarray/substring of length `k`.

```text
Window size = k

[  window  ] → slide right
```

Instead of recalculating every window from scratch, maintain the current window's information and update it when the window moves:

```text
new window = old window - outgoing element + incoming element
```

This is especially useful for running **sum, count, average, maximum/minimum with an appropriate structure**, etc.

### Dynamic-Size Window

Use this when the window length is not fixed and must change according to a condition.

General flow:

```text
right++  → expand

condition violated?
    ↓
left++   → shrink until valid
```

The important idea is that `left` and `right` both move forward; we adjust the window rather than restarting a scan.

### Window Movement Rules

- `right++` → **expand** the window and include a new element.
- `left++` → **shrink** the window and remove the leftmost element.
- Keep track of the information needed for the current window, then update the answer while the window is valid or at the required point.
- Make sure every pointer movement makes progress so the window does not get stuck.

### Important Recognition Rule

**Subarray / substring = continuous part of the original array / string.**

If elements can be skipped, it is not a subarray/substring; it may instead be a subsequence or another type of selection.

### Common Goal Forms

Sliding Window commonly appears when finding:

- maximum / minimum
- longest / shortest valid window
- sum / count / average inside a window
- windows satisfying **at most `k`**, **at least `k`**, or **exactly `k`** conditions

## 3. Problems Solved

## 4. My Mistakes & Lessons
