# Kadane's Algorithm

## 1. Introduction

### Definition
Kadane's Algorithm is a linear-time technique for finding the maximum sum of a contiguous subarray. Its core idea is to track the best subarray sum ending at the current index and update the overall answer as we scan the array.

Related subarray problems may ask for a maximum or minimum sum or product. The product variation needs additional state because negative values can change the sign of a product.

### When to use?
Consider this pattern when:
- The problem asks about a **subarray**, meaning a contiguous part of an array.
- The goal is to find a maximum or minimum sum over a contiguous subarray.
- A solution can be built by deciding whether to extend a subarray ending at the previous index or start a new one.

### Basic Idea
At each index, decide whether to:
- Start a new subarray from the current element.
- Extend the previous subarray ending at the previous index.

Track the best result seen so far. This avoids checking every possible subarray.

## 2. Concepts & Patterns

### Maximum Sum Subarray
For each element, compare starting fresh at that element with extending the previous subarray:

```cpp
current = max(nums[i], current + nums[i]);
ans = max(ans, current);
```

- `current`: maximum sum of a subarray ending at the current index.
- `ans`: maximum sum found across all subarrays scanned so far.

Initialize both with `nums[0]` to handle arrays containing only negative values.

### Maximum Product Subarray
For product, track both the maximum and minimum product of a subarray ending at the current index.

A negative number can turn the previous minimum product into a new maximum, or the previous maximum into a new minimum.

For each value `x`, compare:
- `best * x`
- `worst * x`
- `x` (start a new subarray)

Update:
- `best` to the maximum of these three candidates.
- `worst` to the minimum of these three candidates.
- The overall answer using `best`.

### Rules
- A subarray is **contiguous**; a subsequence does not have to be.
- For maximum-sum Kadane, the state represents the best sum **ending at the current index**.
- For maximum-product variation, keep both maximum and minimum ending products because signs can flip.
- Initialize from the first element when the problem requires a non-empty subarray, so all-negative or all-negative-product cases are handled correctly.
- Standard Kadane scans the array once: **O(n) time and O(1) auxiliary space**.

## 3. Problems Solved

### 53. Maximum Subarray

**Think / Recognition**
- The problem asks for the largest sum of a **contiguous, non-empty subarray**.
- Use Kadane's Algorithm to track the best subarray sum ending at each index.

**Core Idea**
At each element, either extend the previous subarray or start a new subarray from the current element. Keep a separate variable for the maximum sum found so far.

**Important Code**
```cpp
int best = nums[0];
int ans = nums[0];

for (int i = 1; i < nums.size(); i++) {
    int b1 = best + nums[i];
    int b2 = nums[i];
    best = max(b1, b2);
    ans = max(ans, best);
}
return ans;
```

**Keep in mind**
- `best` is the maximum sum of a subarray ending at the current index.
- `ans` is the maximum sum found so far.
- Initialize both with `nums[0]`, not `0`, so all-negative arrays return the largest element rather than zero.

**Complexity**
- Time: **O(n)** — one traversal.
- Auxiliary space: **O(1)** — a fixed number of variables.

### 152. Maximum Product Subarray

**Think / Recognition**
- The problem asks for the maximum product of a **contiguous, non-empty subarray**.
- Use the maximum-product variation of Kadane's Algorithm because multiplying by a negative number can flip the maximum and minimum products.

**Core Idea**
At each element, consider starting a new subarray with the current value, extending the previous maximum product, or extending the previous minimum product. Track both the maximum and minimum products ending at the current index, plus a global answer.

**Important Code**
```cpp
int best = nums[0];
int worst = nums[0];
int ans = nums[0];

for (int i = 1; i < nums.size(); i++) {
    int b1 = best * nums[i];
    int b2 = worst * nums[i];
    int b3 = nums[i];

    best = max({b1, b2, b3});
    worst = min({b1, b2, b3});
    ans = max(ans, best);
}
return ans;
```

**Keep in mind**
- `best` is the maximum product of a subarray ending at the current index.
- `worst` is the minimum product of a subarray ending at the current index; it matters because a negative value can turn it into a large positive product.
- `ans` is the maximum product found so far.
- Consider all three candidates at each index: current value, previous `best` × current value, and previous `worst` × current value.
- Initialize `best`, `worst`, and `ans` with `nums[0]` to handle arrays with negative values and avoid incorrectly returning zero.

**Complexity**
- Time: **O(n)** — one traversal.
- Auxiliary space: **O(1)** — a fixed number of variables.
