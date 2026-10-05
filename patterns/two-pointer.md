# Two Pointer

## 1. Introduction

### Definition

Two Pointer is a technique where two or more indices/pointers are used to process an array or linked list while avoiding unnecessary repeated scanning.

The pointers may move from **opposite directions**, in the **same direction**, or act as **boundaries of different regions**.

### When to use?

Think about Two Pointer when the problem involves:

- **Pairs** → find/check two elements
- **Triplets / Quads** → often fix one element, then use Two Pointer
- **Sorted array** → order gives information about pointer movement
- **Merge** → process two sorted sequences together
- **Remove / modify** → work in-place without another array
- **Rearrange / Partition** → move elements into required regions
- **O(1) extra space** → pointers can modify the array without another array

The key question is:

> **What does each pointer represent, and why can I safely move it?**

### Basic Idea

Use pointers to represent different positions or roles in the input. Move them based on the information the current state gives you, so that unnecessary positions are skipped instead of repeatedly scanned.

```text
Opposite direction:
left  →              ←  right

Same direction:
slow →
fast →
```

The exact pointer movement depends on the variation of the problem.

## 2. Concepts & Patterns

### Opposite Direction

Start one pointer at the beginning and one at the end.

```text
left  →              ←  right
```

Most useful when the array is sorted and we need to find a pair satisfying a condition.

For a target-sum problem:

- `sum < target` → `left++` to increase the sum
- `sum > target` → `right--` to decrease the sum
- `sum == target` → found the required pair

The sorted order is what makes these pointer movements safe.

### Same Direction

Both pointers move through the array in the same general direction, often with different roles.

Typical uses:

- Remove duplicates
- Remove elements
- Move/rearrange elements
- Maintain a valid portion of the array

A common idea is:

```text
slow → position to write/keep
fast → position to scan
```

### Fixed + Two Pointer

For triplet problems:

```text
fix i
 ↓
[i] [left] →       ← [right]
```

Instead of checking every combination with three nested loops:

1. Sort the array.
2. Fix one element `i`.
3. Use Two Pointer on the remaining part.

This turns the usual triplet search into **O(n²)** rather than O(n³).

Mental model:

> **Triplet → fix one → remaining Two Sum.**

The same idea extends to larger combination problems. For 4Sum, fix two elements (`i` and `j`) and use Two Pointer on the remaining part, giving **O(n³)** after sorting.

### Partition / Multiple Pointers

Pointers can represent boundaries between regions rather than simply searching for two values.

Example: Dutch National Flag:

```text
[ 0s | 1s | unknown | 2s ]
       ↑       ↑       ↑
      low     mid     high
```

Three pointers do **not** automatically mean O(n³) or O(n²).

If every pointer moves through the array in one pass, the total work can still be **O(n)**.

### Rules

**Generic Brute Force**
- For pair/triplet/subarray problems, the generic brute force is using nested loops (2 loops for pairs, 3 for triplets, etc.) to check every combination. Time complexity: **O(n²)** or **O(n³)**.

**Pointer movement**

- Every loop iteration should make progress.
- Before moving a pointer, ask what happens to the value/property being tracked.
- In a sorted array, pointer movement is safe only when we can explain why the discarded positions cannot give a valid/better answer.

**Complexity**

- Two pointers moving through the array once → often **O(n)**.
- Fixing one element and running Two Pointer again → often **O(n²)**.
- Fixing two elements and running Two Pointer → often **O(n³)**.
- The number of pointers does not determine complexity; repeated work and total pointer movement do.

**Debugging**

- Wrong Answer → trace pointer positions and movement logic.
- Runtime Error → check index boundaries (`0 ... n-1`).
- TLE → check loop progress and whether a scan is being repeated.
- In a pointer loop, every iteration should generally move a pointer or terminate.

**Constraints / Data Types**

- Check the input size to estimate possible time complexity.
- Check the value range before doing arithmetic.
- Adding several values near `10^9` can overflow a 32-bit `int`; use `long long` for the calculation when necessary.

## 3. Problems Solved

### Pair Problems

#### ⭐ LC 167 — Two Sum II

**Think / Recognition**
- Sorted array
- Pair + target sum
- → **Opposite-direction Two Pointer**

**Core Idea**
- Start `left` at the beginning and `right` at the end.
- `sum < target` → `left++`
- `sum > target` → `right--`

**Core Logic**
```cpp
int i = 0;
int j = numbers.size() - 1;

while(i < j) {
    int sum = numbers[i] + numbers[j];
    if(sum == target) return {i + 1, j + 1};
    if(sum > target) j--;
    if(sum < target) i++;
}
```

Because the array is sorted, moving `left` increases the possible sum, while moving `right` decreases it. This lets us discard one side safely.

**Keep in mind**
> Sorted order tells me which side can be safely discarded.

---

### Array Modification / Removal

#### ⭐ LC 26 — Remove Duplicates from Sorted Array

**Think / Recognition**
- Sorted array
- Remove duplicates in-place
- → **Same-direction pointers**

**Core Idea**
- One pointer tracks the position of the next unique value.
- The other scans the array.

**Core Logic**
```cpp
int i = 0, j = 1;
while (j <= n) {
    if (nums[i] != nums[j]) {
        nums[i + 1] = nums[j];
        i++;
    } else j++;
}
```

`fast` scans for a new value; when it differs from the last kept value, `slow` moves forward and writes that unique value into the valid portion.

**Keep in mind**
> One pointer scans; the other builds the valid portion.

#### ⭐ LC 27 — Remove Element

**Think / Recognition**
- Remove a value in-place
- No need to preserve order
- → **Two pointers from both ends**

**Core Idea**
- `left` finds an element that should be removed.
- `right` finds an element that can replace it.
- Swap them and continue.

**Keep in mind**
> First define what each pointer is searching for; boundaries become easier afterward.

**My Mistake**
- i) I focused on boundary conditions before fully defining what `left` and `right` should represent.
- ii) Independent `if` statements could both execute in one loop iteration, so I accidentally moved pointers more than expected and had to pay closer attention to loop progress.

#### LC 283 — Move Zeroes

**Think / Recognition**
- Rearrange elements in-place
- Keep non-zero elements together
- → **Same-direction pointers**

**Core Idea**
- One pointer scans the array.
- Another tracks where the next non-zero element should go.

**Core Logic**
```cpp
int i = 0, j = i + 1;
while(j < n) {
    if (nums[i] == 0 and nums[j] == 0) j++;
    else if (nums[i] == 0) {
        int k = nums[i]; // manual swap
        nums[i] = nums[j];
        nums[j] = k;
        i++; j++;
    } else {
        i++; j++;
    }
}
```

`fast` searches for non-zero values, while `slow` marks the next position where a non-zero value should be placed.

**Keep in mind**
> Separate the scanning pointer from the position where valid elements are placed.

---

### Triplet Problems

#### ⭐ LC 15 — 3Sum

**Think / Recognition**
- Sorted array
- Triplets
- → **Fix one + Two Pointer**

**Core Idea**
- Sort the array.
- Fix `i`.
- Solve the remaining two-element target with `left` and `right`.
- Skip duplicates to avoid repeated triplets.

**Core Logic**
```cpp
int left = i + 1, right = n - 1;
while(right > left) {
    int sum = nums[left] + nums[right];
    if(sum == -(nums[i])) {
        result.push_back({nums[i], nums[left], nums[right]});
        left++;
        while(left < n and nums[left] == nums[left - 1]) left++;
        right--;
        while(right > 0 and nums[right] == nums[right + 1]) right--;
    }
    else if(sum > -(nums[i])) right--;
    else if(sum < -(nums[i])) left++;
}
```

This converts the remaining part of the 3Sum problem into a **Two Sum target**, while manually skipping duplicates to avoid repeating valid triplets.

**Keep in mind**
> A triplet problem can become a Two Sum problem after fixing one element.

#### ⭐ LC 16 — 3Sum Closest

**Think / Recognition**
- Array
- Sorted
- Triplet
- → **Fix one + Two Pointer**

**Core Idea**
- Sort the array.
- Fix one element `i`.
- Use `left` and `right` for the remaining two.
- Move pointers based on whether the current sum is smaller or larger than the target.
- Keep the sum that is closest to the target.

**Core Logic**
```cpp
int result = nums[0] + nums[1] + nums[2];
for (int i = 0; i < nums.size() - 2; i++) {
    int left = i + 1, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (abs(sum - target) < abs(result - target)) {
            result = sum;
        }
        if (sum < target) left++;
        else right--;
    }
}
```

We compare the **distance from the target**, not whether the sum itself is numerically smaller or larger. Starting `result` from an actual triplet is crucial because `0` may not be the closest possible sum.

**Keep in mind**
> Closest means minimum distance from target.

#### Triplets with Smaller Sum

**Think / Recognition**
- Sorted array
- Count triplets
- Condition is strictly `< target`
- → **Fix one + Two Pointer + counting**

**Core Idea**
- Sort the array.
- Fix `i` and use `left`/`right`.
- If the current sum is smaller than target, all choices from `left+1` through `right` are also valid.

**Core Logic**
```cpp
while (left < right) {
    int sum = nums[i] + nums[left] + nums[right];
    if (sum < target) {
        output += right - left;
        left++;
    } else {
        right--;
    }
}
```

When the largest possible third element `arr[right]` still gives a valid sum, every smaller third element between `left + 1` and `right` is also valid. `right - left` counts those choices at once.

**Keep in mind**
> When the largest possible third value is still valid, all smaller choices are valid too.

#### ⭐ LC 18 — 4Sum

**Think / Recognition**
- Sorted array
- Quadruplets
- Target sum
- → **Fix two + Two Pointer**

**Core Idea**
- Sort the array.
- Fix `i` and `j`.
- Use `left` and `right` on the remaining part.
- `sum < target` → `left++`
- `sum > target` → `right--`
- `sum == target` → record the quadruplet, then move both pointers while skipping duplicates.

This extends the 3Sum idea:

> **Quadruplet → fix two → remaining Two Sum.**

**Core Logic**

Because each `nums[i]` can be as large as `10^9`, the sum of four values can reach `4 × 10^9`, which does not fit in a 32-bit `int`.

```cpp
while (left < right) {
    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
    if (sum == target) {
        // Record and skip duplicates
    } else if (sum < target) left++;
    else right--;
}
```

The cast makes the arithmetic happen as `long long`, preventing integer overflow.

**Keep in mind**
> Always check constraints: input size helps with complexity, value range helps with data types.

**My Mistake**
- i) I initially missed the value constraints and used `int` for a sum that could reach `4 × 10^9`, causing signed integer overflow.

---

### Partition / Rearrangement

#### ⭐ LC 75 — Sort Colors

**Think / Recognition**
- Rearrange / partition
- Three values: `0`, `1`, `2`
- → **Multiple pointers / boundaries**

**Core Idea**
- Maintain regions for `0s`, `1s`, unknown values, and `2s`.
- Use `low`, `mid`, and `high` to expand the known regions.

**Keep in mind**
> Multiple pointers can still be O(n) when they are moving boundaries through one pass.

**My Mistake**
- i) I initially tried to force the problem into a two-pointer approach instead of recognizing that the pointers could represent different regions.
- ii) I assumed that using three pointers would make the solution O(n²), because I associated multiple pointers with 3Sum. Complexity depends on how the pointers move, not how many pointers there are.

---

### Other Applications

#### LC 977 — Squares of a Sorted Array

**Think / Recognition**
- Sorted array can contain negative values
- Need sorted squares
- → **Opposite-direction Two Pointer**

**Core Idea**
- Compare the absolute values at both ends.
- The larger absolute value produces the larger square.
- Fill the result from the end.

**Core Logic**

```cpp
int i = 0, j = n - 1, k = n - 1;
while(j >= i) {
    if(abs(nums[j]) >= abs(nums[i])) {
        res[k] = nums[j] * nums[j];
        j--; k--;
    } else {
        res[k] = nums[i] * nums[i];
        i++; k--;
    }
}
```

The largest square must come from one of the two ends, so we place the larger square at the current position from the back.

**Keep in mind**
> In a sorted array with negatives, the largest square can come from either end.

#### LC 88 — Merge Sorted Array

**Think / Recognition**
- Two sorted sequences
- Merge in-place
- → **Two pointers from the end**

**Core Idea**
- Compare the largest remaining values and fill the array from the back.
- Working backward avoids overwriting values that still need to be processed.

**Core Logic**

```cpp
int i = m - 1, j = n - 1, k = m + n - 1;
while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
    else nums1[k--] = nums2[j--];
}
while (j >= 0) nums1[k--] = nums2[j--];
```

We fill from the back because the extra space is at the end; placing the largest value there prevents overwriting unprocessed elements.

**Keep in mind**
> When merging in-place with free space at the end, fill from the back.
