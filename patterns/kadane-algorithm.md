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

**Brute Force**
- Fix a starting index and extend the subarray one element at a time.
- Maintain a running sum and update the maximum after each extension.
- Time: **O(n²)**
- Auxiliary space: **O(1)**

**Core Idea**
At each element, compare starting fresh at that element with extending the previous subarray. Track the best sum ending at the current index and the overall maximum.

**Pseudocode**
```text
best = nums[0]
ans = nums[0]

for i from 1 to n - 1:
    best = maximum(nums[i], best + nums[i])
    ans = maximum(ans, best)

return ans
```

**Keep in mind**
- `best` is the maximum sum of a subarray ending at the current index.
- `ans` is the maximum sum found so far.
- Initialize both with `nums[0]`, not `0`, so all-negative arrays return the largest element rather than zero.

**Complexity**
- Brute force: **O(n²)** time, **O(1)** auxiliary space.
- Optimal: **O(n)** time, **O(1)** auxiliary space.

### 152. Maximum Product Subarray

**Think / Recognition**
- The problem asks for the maximum product of a **contiguous, non-empty subarray**.
- Negative values can flip product signs, so track both the maximum and minimum products ending at each index.

**Brute Force**
- Fix each starting index and extend the subarray one element at a time.
- Maintain a running product instead of recalculating each subarray from scratch.
- Update the answer with every running product.
- Time: **O(n²)**
- Auxiliary space: **O(1)**

**Core Idea**
At each element, consider three possibilities:
1. Start a new subarray with the current value.
2. Extend the previous maximum product.
3. Extend the previous minimum product.

Track both `best` and `worst` because multiplying by a negative number can turn the minimum product into the new maximum. Track `ans` separately for the best product found so far.

**Pseudocode**
```text
best = nums[0]
worst = nums[0]
ans = nums[0]

for i from 1 to n - 1:
    b1 = best * nums[i]
    b2 = worst * nums[i]
    b3 = nums[i]

    best = maximum(b1, b2, b3)
    worst = minimum(b1, b2, b3)
    ans = maximum(ans, best)

return ans
```

**Keep in mind**
- `best`: maximum product of a subarray ending at the current index.
- `worst`: minimum product ending at the current index; a negative value can turn it into a large positive product.
- `ans`: maximum product found so far.
- The three candidates are: current value, previous `best` × current value, and previous `worst` × current value.
- Initialize `best`, `worst`, and `ans` with `nums[0]` so negative values are handled correctly.

**Complexity**
- Brute force: **O(n²)** time, **O(1)** auxiliary space.
- Optimal: **O(n)** time, **O(1)** auxiliary space.
