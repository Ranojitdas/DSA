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

- Sort by **start** before applying the one-pass merge logic.
- Maintain the current interval as `[start1, end1]`.
- On overlap: update `end1 = max(end1, end2)`.
- On no overlap: push the current interval to the result, then start the next interval.
- At the end, push the final interval.
- Typical complexity: **O(n log n)** time because of sorting and **O(n)** auxiliary/result space.

## 3. Problems Solved

_Interview discussion is completed before individual solved-problem entries are added, according to RULES.md._
