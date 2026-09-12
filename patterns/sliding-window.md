# Sliding Window

## 1. Introduction

### Definition

Sliding Window is a technique for processing a **continuous range** of elements by moving the boundaries of a window instead of repeatedly scanning the same elements.

### When to use?

Think about Sliding Window when the problem involves:

- **Array / String**
- **Subarray / Substring** → continuous range
- **Max / Min**
- **Longest / Shortest**
- **Sum / Count / Average**
- **At most `k` / At least `k` / Exactly `k`**

If the problem is about a **subsequence** or another non-continuous selection, Sliding Window is generally not the first pattern to consider.

The key question is:

> **Are we finding something about a continuous range, and can we expand/shrink that range using two boundaries?**

### Basic Idea

Maintain a window using two boundaries, usually `left` and `right`.

```text
[ left ........ right ]
```

Instead of recalculating information for every range from scratch, update the current window as it moves.

```text
Old window:
[ 1  2  3 ] 4 5
  ↑     ↑
 left  right

Slide:
  1 [ 2  3  4 ] 5
      ↑     ↑
     left  right
```

The exact movement depends on whether the window is fixed-size or dynamic.

## 2. Concepts & Patterns

### Fixed Window

The window size remains constant, usually given by `k`.

Example:

```text
[ 1  2  3 ] 4 5
    ↓
  size = k
```

To slide the window:

- Add the new element entering from the right.
- Remove the old element leaving from the left.

Typical update:

```cpp
sum = sum + nums[right] - nums[left];
```

Useful for problems asking for a property of every subarray/substring of exactly `k` elements, such as maximum/minimum/sum/average.

### Dynamic Window

The window size changes depending on whether the current window satisfies a condition.

General idea:

```text
right++ → expand the window
left++  → shrink the window
```

Usually:

1. Expand with `right`.
2. Check whether the window is valid.
3. Shrink with `left` when necessary.
4. Update the answer when the required condition is satisfied.

### Window Movement

The important part is maintaining the information represented by the current window.

When expanding:

```text
right++
```

Add the new element's contribution.

When shrinking:

```text
left++
```

Remove the outgoing element's contribution.

This avoids repeatedly calculating the same range from scratch.

### Rules

- A **subarray / substring is continuous**; a subsequence does not have to be continuous.
- Fixed Window → window size usually stays `k`.
- Dynamic Window → window size changes according to a condition.
- Every pointer movement should make progress.
- Before moving `left`, understand why the current window is invalid or why shrinking is required.
- Before moving `right`, understand what information the newly included element adds to the window.
- Sliding Window is not automatically correct just because the problem says **subarray**; the window must have a property that can be maintained while its boundaries move.

## 3. Problems Solved

### Fixed Window

#### ⭐ LC 643 — Maximum Average Subarray I

**Think / Recognition**
- Array
- Subarray → continuous range
- Exactly `k` elements
- Maximum average
- → **Fixed-Size Sliding Window**

**Core Idea**
- Calculate the sum of the first `k` elements.
- Slide the window one position at a time.
- Add the new element entering from the right.
- Remove the element leaving from the left.
- Keep the maximum average seen so far.

Instead of recalculating every `k`-element sum:

```cpp
sum = sum + nums[right] - nums[left];
```

The window moves by one position while its size remains `k`.

**Keep in mind**
> **Fixed window → add the incoming element and remove the outgoing element.**

**My Mistake**
- i) I initially recalculated the sum starting from index `0` while increasing the right boundary, so I was not actually maintaining the current window. Once I changed it to add the incoming value and remove the outgoing value, the Sliding Window approach clicked.

#### LC 1343 — Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold

**Think / Recognition**
- Array
- Subarray → continuous range
- Exactly `k` elements
- Average ≥ threshold
- → **Fixed-Size Sliding Window**

**Core Idea**
- Calculate the sum of the first `k` elements.
- Check whether its average meets the threshold.
- Slide the window by removing the left element and adding the new right element.
- Check each window and count the ones whose average is ≥ `threshold`.

The same fixed-window structure from LC 643 applies here; the only difference is that instead of tracking the maximum average, we count valid windows.

**Keep in mind**
> **Same window pattern, different answer condition.**

**My Mistake**
- i) I initially forgot to initialize `output` to `0`, so the result was wrong by 2. Initializing `int output = 0` fixed the counting.

### Dynamic Window

#### ⭐ LC 209 — Minimum Size Subarray Sum

**Think / Recognition**
- Array
- Subarray → continuous range
- Minimum / shortest length
- Sum ≥ `target`
- Positive integers
- → **Dynamic Sliding Window**

**Core Idea**
- Expand the window by moving `high` and add `nums[high]` to `sum`.
- Once `sum >= target`, the window is valid.
- Shrink from the left while it remains valid, updating the minimum length each time.
- If no valid window is found, return `0`.

The important dynamic-window structure is:

```text
sum < target
→ expand right

sum >= target
→ update answer
→ shrink left
```

Because all numbers are **positive**, removing elements from the left can only decrease the sum, so shrinking lets us search for the shortest valid window.

**Keep in mind**
> **Dynamic window → expand until valid, then shrink while valid.**

**My Mistake**
- i) I initially thought the `sum < target` case needed a separate answer condition. It doesn't—the window simply needs to expand. The `res == INT_MAX` check belongs at the end to handle the case where no valid subarray was ever found.
