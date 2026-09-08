# Sliding Window

## 1. Introduction

### Definition

Sliding Window is a technique for processing a **continuous range** of elements in an array or string by moving the window instead of repeatedly scanning the same elements.

### When to use?

Think about Sliding Window when the problem involves:

- **Subarray / substring** → continuous range
- **Longest / shortest** → find the best valid range
- **Maximum / minimum** → over a continuous range
- **Sum / count / frequency** → maintain information inside a range
- **At most / at least / exactly `k`** → window condition
- **Need to avoid repeated subarray/substring scanning** → maintain a moving window

The key question is:

> **Can I maintain a useful property of a continuous range while moving its boundaries?**

### Basic Idea

```text
left                         right
  ↓                            ↓
[---------------------------------]
          current window

right++  → expand
left++   → shrink
```

Keep a window `[left ... right]` and move its boundaries instead of restarting a scan for every new range.

## 2. Concepts & Patterns

### Fixed Window

Use this when the required window length is fixed, such as a subarray/substring of length `k`.

```text
Window size = k

[  window  ] → slide right
```

Maintain the information for the current window and update it when the window moves:

```text
new window = old window - outgoing element + incoming element
```

Useful for running **sum, count, average**, and other window information.

### Dynamic Window

Use this when the window length is not fixed and must change according to a condition.

General flow:

```text
right++  → expand

condition violated?
    ↓
left++   → shrink until valid
```

Both pointers move forward; we adjust the current window instead of restarting the scan.

### Window Movement

- `right++` → expand the window and include a new element.
- `left++` → shrink the window and remove the leftmost element.
- Maintain the information needed for the current window.
- Update the answer at the appropriate point based on the problem.

### Rules

- **Subarray / substring = continuous part** of the original array / string.
- If elements can be skipped, it is not a subarray/substring; it may be a subsequence or another type of selection.
- Every pointer movement should make progress so the window does not get stuck.
- Avoid recalculating the whole window when its information can be updated incrementally.

## 3. Problems Solved
