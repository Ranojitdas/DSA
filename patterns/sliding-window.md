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

### Dynamic Window Template

For a dynamic window, `right` normally moves forward through the array/string using a `for` loop.

```cpp
int left = 0;

for (int right = 0; right < n; right++) {
    // include nums[right]

    // update window information

    while (window is invalid) {
        // remove nums[left]
        left++;
    }

    // update answer
}
```

- `right` → expands the window and introduces new information.
- `left` → shrinks the window when the condition is violated.
- Update the window's information when elements enter or leave.

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

**Generic Brute Force**
- For substring/subarray problems, the generic brute force is using nested loops to generate all possible subarrays, usually O(N²) or O(N³).

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

**Core Logic**
```cpp
double initsum = 0;
for(int i = 0 ; i < k ; i++){
    initsum = initsum + nums[i];
}
double sum = initsum;
double output = sum / k;

while(right < n){
    sum = ((sum + nums[right]) - nums[left]);
    double avg = sum / k;
    if(avg > output) output = avg;
    left++; right++;
}
```

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

**Core Logic**
```cpp
while(high < n){
    sum = sum + nums[high];
    
    while(sum >= target){
        int len = high - low + 1;
        if(res >= len){
            res = len;
        }
        sum = sum - nums[low];
        low++;
    }
    high++;
}
```

Because all numbers are **positive**, removing elements from the left can only decrease the sum, so shrinking lets us search for the shortest valid window.

**Keep in mind**
> **Dynamic window → expand until valid, then shrink while valid.**

**My Mistake**
- i) I initially thought the `sum < target` case needed a separate answer condition. It doesn't—the window simply needs to expand. The `res == INT_MAX` check belongs at the end to handle the case where no valid subarray was ever found.

#### ⭐ LC 904 — Fruit Into Baskets

**Think / Recognition**
- Array
- Subarray → continuous range
- Maximum length
- At most `2` different fruit types
- → **Dynamic Sliding Window**

**Core Idea**
- Expand the window with `high` and store the frequency of each fruit type.
- If the window contains more than `2` different types, shrink from the left.
- Decrease the outgoing fruit's frequency and erase its type when the frequency becomes `0`.
- Update the maximum length after the window becomes valid again.

**Core Logic**
```cpp
for(high = 0; high < n; high++){
    f[fruits[high]]++;
    while(f.size() > 2){
        f[fruits[low]]--;
        if(f[fruits[low]] == 0){
            f.erase(fruits[low]);
        }
        low++;
    }
    if(f.size() <= 2){
        int len = high - low + 1;
        res = max(len, res);
    }
}
```

**Keep in mind**
> **When shrinking, `low` must move every time; erasing a fruit type is conditional.**

#### ⭐ LC 3 — Longest Substring Without Repeating Characters

**Think / Recognition**
- String
- Substring → continuous range
- Longest length
- No repeating characters
- → **Dynamic Sliding Window + HashMap**

**Core Idea**
- Expand the window with `high` and store the frequency of each character in the HashMap.
- If the current character becomes repeated, shrink from the left until the window is valid again.
- Update the maximum window length after removing the duplicate.

**Core Logic**
```cpp
for(high = 0; high < n ; high++){
    f[s[high]]++;
    while(f[s[high]] > 1){
        f[s[low]]--;
        low++;
    }
    int len = high - low + 1;
    res = max(len, res);
}
```

This `while` loop keeps the current window free of duplicate characters by shrinking from the left until the duplicate is removed.

**Keep in mind**
> **When a duplicate appears, shrink from the left until the window becomes unique again.**

#### ⭐ LC 1004 — Max Consecutive Ones III

**Think / Recognition**
- Binary array
- Subarray → continuous range
- Longest length
- Can flip at most `k` zeros
- → **Dynamic Sliding Window**

**Core Idea**
- Expand the window with `high`.
- Track the number of `1`s in the window using `freq`.
- The number of `0`s is `len - freq`.
- If the number of zeros becomes greater than `k`, shrink from the left until the window is valid again.
- Keep the maximum valid window length.

**Core Logic**
```cpp
for(high = 0; high < n; high++){
    if(nums[high] == 1) freq++;
    int len = high - low + 1;
    int diff = len - freq; // diff is the number of 0s
    
    while(diff > k){
        if(nums[low] == 1) freq--;
        low++;
        len = high - low + 1;
        diff = len - freq;
    }
    res = max(len, res);
}
```

Here, `diff` represents the number of zeros because:

> `window length - number of 1s = number of 0s`

**Keep in mind**
> **Window information must persist while the window moves; don't reset it every time `high` advances.**

**My Mistake**
- i) I initially declared `freq` inside the `for` loop, so it was reset to `0` every time `high` moved. `freq` represents information maintained across the current window, so it needs to persist outside the loop.

#### ⭐⭐⭐ LC 76 — Minimum Window Substring

**Think / Recognition**
- String
- Substring → continuous range
- Minimum / shortest valid window
- Window must contain all characters of `t` with the required frequencies
- → **Dynamic Sliding Window + Frequency Tracking**

**Core Idea**
- Maintain the required character frequencies from `t`.
- Expand the window with `high` and maintain the frequencies of characters currently inside the window.
- Once the window satisfies all required character frequencies, shrink from `low` while it remains valid.
- Every valid window is a candidate for the minimum.
- Store `start` and `res` together because they describe the same best window.

**Core Logic**
```cpp
for(high = 0; high < n; high++){
    have[s[high]]++;

    while(correct(have, needed)){
        int len = high - low + 1;
        if(res > len){
            res = len;
            start = low;
        }
        have[s[low]]--;
        low++;
    }
}
```

`low` is the **current** window's left boundary, while `start` is the left boundary of the **best window found so far**. Update both only when the current window is smaller.

**Keep in mind**
> **Presence is not enough; the window must satisfy the required frequency of every character in `t`.**

Also:

> **A nested `while` does not automatically make Sliding Window O(n). If `low` and `high` each move forward at most `n` times, the total pointer movement is O(n).**

**My Mistake**
- i) I initially treated `t` as an ordered sequence, but the characters can appear in any order; only their required frequencies matter.
- ii) I initially used `unordered_map<char,int>(256)` as if it were a 256-element array. Switching to fixed-size `vector<int>` frequency arrays made the constant-size character tracking explicit.

**Optimization**
- The submitted solution checks validity by scanning all 256 frequency positions in `correct()` each time.
- This is still **O(n)** because 256 is a fixed constant, but it adds a noticeable constant factor.
- A `count` variable can track how many required character occurrences are still missing, making the validity check **O(1)** instead of repeatedly scanning 256 entries.
- Overall time complexity remains **O(n)**, while the constant factor improves. Space is **O(1)** because the frequency arrays have a fixed size of 256.
