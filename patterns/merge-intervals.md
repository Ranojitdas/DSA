# Merge Intervals

## 1. Introduction

### Definition

Merge Intervals is a technique for working with ranges represented as pairs such as `[start, end]`. Overlapping intervals are combined into one interval that covers the complete range.

### When to use?

Look for problems involving:

- Ranges / intervals represented as `[start, end]`
- **Overlap** or conflict between intervals
- **Merge** or combine overlapping ranges
- Free time / simultaneous usage
- Room, load, CPU, or meeting schedules
- Finding whether intervals conflict or can be combined

### Basic Idea

First sort the intervals by **start time**. Then compare the current merged interval with the next interval:

- If they overlap, extend the current interval's end.
- If they do not overlap, save the current interval and start working with the next one.

## 2. Concepts & Patterns

### Sort by Start

Sort intervals in ascending order of their start value.

```cpp
sort(intervals.begin(), intervals.end());
```

After sorting, the next interval always starts at or after the current interval's start, so we only need to compare the current end with the next start.

### Detect Overlap

For:

```
[start1, end1]
[start2, end2]
```

after sorting by start:

- `end1 < start2` → **no overlap**
- `end1 >= start2` → **overlap**

### Merge Overlapping Intervals

When intervals overlap:

```
[start1, end1]
[start2, end2]
```

becomes:

```
[start1, max(end1, end2)]
```

Keep the earliest start and extend the end to the larger endpoint.

### Rules

**Generic Brute Force**
- For interval overlaps, the generic brute force is to compare every interval with every other interval using nested loops. Time complexity: **O(N²)**.

- Sort by **start** before applying the one-pass merge logic.
- Maintain the current interval as `[start1, end1]`.
- On overlap: update `end1 = max(end1, end2)`.
- On no overlap: push the current interval to the result, then start the next interval.
- At the end, push the final interval.
- Typical complexity: **O(n log n)** time because of sorting and **O(n)** auxiliary/result space.

## 3. Problems Solved

### ⭐ LC 56 — Merge Intervals

**Think / Recognition**
- Given a collection of ranges and asked to combine overlapping intervals.
- Sort by start time so potentially overlapping intervals are adjacent.

**Core Idea**
- Keep the current merged interval as `[start1, end1]`.
- If `start2 <= end1`, the intervals overlap, so update `end1 = max(end1, end2)`.
- If `start2 > end1`, save the current interval and start a new one.
- Push the final current interval after the loop.

**Core Logic**
```cpp
int start1 = intervals[0][0];
int end1  = intervals[0][1];

for(int i = 1; i < n; i++) {
    int start2 = intervals[i][0];
    int end2 = intervals[i][1];

    if(end1 >= start2) {
        end1 = max(end1, end2);
        continue;
    }
    res.push_back({start1, end1});
    start1 = start2;
    end1 = end2;
}
res.push_back({start1, end1});
```
Sorting is essential because it lets us process intervals from left to right and safely decide when the current merged interval is finished.

**Keep in mind**
> Sort first, then keep extending the current interval until the next one starts after its end.

**My Mistake**
- i) Initially treated sorting as `O(log n)`; the full sort is `O(n log n)`.
- ii) Initially considered the optimal solution's space as `O(1)`; the result vector can contain up to `n` intervals, so output space is `O(n)`.

### ⭐ LC 57 — Insert Interval

**Think / Recognition**
- Intervals are already sorted by start time.
- A new interval must be inserted while preserving order, then overlapping intervals must be merged.
- Because the input is already sorted, there is no need to sort again.

**Core Idea**
- Traverse the sorted intervals once.
- Insert `newInterval` before the first interval whose start is greater than `newInterval[0]`; otherwise append it after the traversal.
- Merge the resulting ordered intervals using the same overlap logic as LC 56.
- Handle the empty input case by returning the new interval.

**Core Logic**
```cpp
bool insert = false;
for(int i = 0; i < n; i++) {
    if(insert == false and intervals[i][0] > newInterval[0]) {
        res.push_back({newInterval});
        insert = true;
    }
    res.push_back({intervals[i]});
}
if(insert == false) {
    res.push_back({newInterval});
}

// ... Then apply standard LC 56 merge logic on the resulting array ...
```
The first part inserts the new interval without sorting; the second handles the case where it belongs after all existing intervals.

**Keep in mind**
> The intervals are already sorted—insert in the correct position, then merge in one pass.

**My Mistake**
- i) Initially missed the edge case where `intervals` is empty; accessing `res[0]` would be invalid.
- ii) Initially missed the case where `newInterval` belongs after all existing intervals; it must be appended when it was not inserted during the traversal.
