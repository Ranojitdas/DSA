# Two Pointer

## 1. Introduction

### What is Two Pointer?

Two Pointer is a technique where two or more indices/pointers are used to process an array or linked list while avoiding unnecessary repeated scanning.

The pointers may move from **opposite directions**, in the **same direction**, or act as **boundaries of different regions**.

### When should I think of Two Pointer?

Think about Two Pointer when the problem involves:

- **Pairs** → find/check two elements
- **Triplets / Quads** → often fix one element, then use Two Pointer
- **Sorted array** → order gives information about pointer movement
- **Merge** → process two sorted sequences together
- **Remove** → remove duplicates/elements in-place
- **Rearrange / Partition** → move elements into required regions
- **In-place / O(1) extra space** → pointers can modify the array without another array

### Recognition Map

```text
Array / Linked List
        │
        ├── Sorted / ordered ──────→ Opposite-direction pointers
        │                              │
        │                              ├── Pair / target sum
        │                              └── Triplet → Fix one + Two Pointer
        │
        ├── Remove / modify ───────→ Same-direction / slow-fast pointers
        │
        ├── Merge ─────────────────→ Two pointers on two sequences
        │
        └── Rearrange / partition ─→ Multiple pointers / boundaries
```

The key question is not **"Can I use two pointers?"** but **"What does each pointer represent, and why can I safely move it?"**

## 2. Concepts & Patterns

### 2.1 Opposite Direction

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

### 2.2 Same Direction

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

### 2.3 Fixed + Two Pointer

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

### 2.4 Partitioning / Multiple Pointers

Pointers can represent boundaries between regions rather than simply searching for two values.

Example: Dutch National Flag:

```text
[ 0s | 1s | unknown | 2s ]
       ↑       ↑       ↑
      low     mid     high
```

Three pointers do **not** automatically mean O(n³) or O(n²).

If every pointer moves through the array in one pass, the total work can still be **O(n)**.

### 2.5 How Pointer Movement Works

Before moving a pointer, ask:

> **If I move this pointer, what happens to the value/property I am tracking?**

For a sorted target-sum problem:

```text
sum < target → move left rightward → sum increases
sum > target → move right leftward → sum decreases
```

Never move a pointer just because it "looks right". There should be a reason that the discarded positions cannot give a better/valid answer.

### 2.6 Counting with Two Pointer

Sometimes the goal is not to find one valid pair/triplet, but to **count all valid combinations**.

If the array is sorted and, for fixed `i` and `left`, the largest possible `right` already gives a sum smaller than the target, then every smaller index between `left+1` and `right` is also valid.

```cpp
count += right - left;
```

This avoids checking each third element individually.

### 2.7 Why Two Pointer Can Be O(n)

Having two pointers does **not** mean O(n²).

For a single pass:

- `left` moves at most `n` times.
- `right` moves at most `n` times.
- Together they still perform O(n) total pointer movement.

For nested/repeated scans, the complexity can become larger.

Example:

- Two pointers scanning once → **O(n)**
- Fix `i` and run Two Pointer for every `i` → **O(n²)**

The important thing is **how many times the pointers travel through the data**, not simply how many pointers exist.

### 2.8 Debugging Two Pointer Problems

When debugging:

**Wrong Answer**
- Trace pointer positions and the condition that moves them.

**Runtime Error**
- Check whether an index can become invalid: valid array indices are `0 ... n-1`.

**TLE**
- Check whether the loop always makes progress.
- Ask: **"What changes in every iteration?"**
- If the same pointer state can repeat, suspect an infinite loop.

For pointer loops, every iteration should generally:

- move a pointer, or
- terminate.

Also test small boundary cases such as empty arrays, one element, two elements, all equal values, and already sorted/reversed input.

## 3. Problems Solved

### 3.1 Pair Problems

#### LC 167 — Two Sum II

**Think / Recognition**
- Sorted array
- Pair + target sum
- → **Opposite-direction Two Pointer**

**Core Idea**
- Start `left` at the beginning and `right` at the end.
- `sum < target` → `left++`
- `sum > target` → `right--`

**Keep in mind**
> Sorted order tells me which side can be safely discarded.

---

### 3.2 Array Modification / Removal

#### LC 26 — Remove Duplicates from Sorted Array

**Think / Recognition**
- Sorted array
- Remove duplicates in-place
- → **Same-direction pointers**

**Core Idea**
- One pointer tracks the position of the next unique value.
- The other scans the array.

**Keep in mind**
> One pointer scans; the other builds the valid portion.

#### LC 27 — Remove Element

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

**Keep in mind**
> Separate the scanning pointer from the position where valid elements are placed.

---

### 3.3 Triplet Problems

#### LC 15 — 3Sum

**Think / Recognition**
- Sorted array
- Triplets
- → **Fix one + Two Pointer**

**Core Idea**
- Sort the array.
- Fix `i`.
- Solve the remaining two-element target with `left` and `right`.
- Skip duplicates to avoid repeated triplets.

**Important Code**

For fixed `i`, the remaining two elements need:

```cpp
int target = -nums[i];
```

**Keep in mind**
> A triplet problem can become a Two Sum problem after fixing one element.

#### LC 16 — 3Sum Closest

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

**Important Code**

Initialize `result` with the first valid triplet:

```cpp
int result = nums[0] + nums[1] + nums[2];
```

Update it whenever a closer sum is found:

```cpp
if (abs(sum - target) < abs(result - target))
    result = sum;
```

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

**Important Code**

```cpp
if (sum1 < target)
    output += right - left;
```

**Keep in mind**
> When the largest possible third value is still valid, all smaller choices are valid too.

---

### 3.4 Partition / Rearrangement

#### LC 75 — Sort Colors

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

### 3.5 Other Applications

#### LC 977 — Squares of a Sorted Array

**Think / Recognition**
- Sorted array can contain negative values
- Need sorted squares
- → **Opposite-direction Two Pointer**

**Core Idea**
- Compare the absolute values at both ends.
- The larger absolute value produces the larger square.
- Fill the result from the end.

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

**Keep in mind**
> When merging in-place with free space at the end, fill from the back.

## 4. My Mistakes & Lessons

### Mistakes

- i) I sometimes focused on boundary conditions before clearly deciding what each pointer represented.
- ii) Independent `if` statements can both execute in the same loop iteration; pointer movement must be traced carefully.
- iii) I initially thought using three pointers would imply O(n²), because I connected it with 3Sum. The number of pointers is not the complexity; repeated scanning is.
- iv) In pointer loops, forgetting to move a pointer can cause an infinite loop/TLE.
- v) I learned to distinguish debugging by error type: **Wrong Answer → trace logic; Runtime Error → check boundaries; TLE → check progress and complexity.**

### Lessons

- Define pointer roles first; handle boundary conditions afterward.
- Every pointer movement needs a reason.
- In a sorted array, pointer movement is powerful because order tells us what can be discarded.
- Two Pointer is not one single technique. It includes opposite-direction, same-direction, fixed + two pointer, and partitioning/multiple-pointer approaches.
- The number of pointers does not determine complexity. **Total pointer movement and repeated scans do.**
- For triplets, think: **fix one → remaining Two Sum.**
- For counting problems, look for situations where one pointer position proves a whole range of choices valid at once.

### Things to Remember in Interviews

Before coding a Two Pointer problem, ask:

1. **Why Two Pointer?** What structure makes pointer movement safe?
2. **What does each pointer represent?**
3. **When should each pointer move?**
4. **What positions can I safely discard after moving it?**
5. **Does every loop iteration make progress?**
6. **How many times can each pointer move?**

> **Problem → Recognition → Pointer roles → Movement rule → Key trick → Code**
