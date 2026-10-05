# DSA Implementation & Debugging Practice

> Purpose: Build the ability to convert a known DSA approach into correct C++ code on the first or second attempt.
>
> This is **not another C++ theory chapter**. It is a practical training sheet for implementation mistakes, tracing, TLE, runtime errors, and wrong answers.

---

## 1. Why This Practice Exists

I can often understand:
- what the problem is asking
- which pattern applies
- what the optimal approach is

But during implementation, I may miss:
- pointer movement
- loop termination
- boundary conditions
- `nullptr` safety
- what happens after the answer is found
- incorrect index ranges
- unnecessary repeated work
- incorrect variable updates

The goal is:

> **Approach → Code → Trace → Detect mistakes → Correct implementation**

---

## 2. The 5-Question Pre-Submission Checklist

### 1. Pointer / Index Safety

> Can any pointer or index be invalid here?

Check things like:

```cpp
arr[i]
arr[i + 1]
fast->next
fast->next->next
t->next
prev->next
```

Ask:

> What if this is the last element?
>
> What if this pointer is `nullptr`?

---

### 2. Loop Progress

> Does every iteration make progress?

For every loop, identify what changes:

```cpp
left++;
right--;
i++;
j++;
slow = slow->next;
fast = fast->next->next;
```

If nothing moves or changes, investigate immediately.

---

### 3. Loop Termination

> What exactly causes this loop to stop?

For example:

```cpp
while (fast != nullptr && fast->next != nullptr)
```

Ask:

> What eventually makes this condition false?

Never assume a loop will stop just because the algorithm is supposed to finish.

---

### 4. What Happens After Finding the Answer?

This is especially important.

Ask:

> Once I have found the answer, am I still continuing unnecessary code?

Example:

```cpp
if (condition) {
    answer = value;
}
```

Ask:

> Should I return?
>
> Should I break?
>
> Or should the algorithm actually continue?

---

### 5. Edge Cases

Mentally test small cases.

For arrays:

```text
empty
1 element
2 elements
already sorted
all same
```

For linked lists:

```text
empty list
1 node
2 nodes
cycle
no cycle
cycle at head
cycle near the end
```

Do not test only the normal example.

---

# 3. Debugging Classification

When the submission fails, first classify the problem.

## Wrong Answer

Think:

> **Logic / state problem**

Check:
- pointer movement
- conditions
- variable updates
- missing case
- incorrect result
- wrong interpretation of the problem

---

## Runtime Error

Think:

> **Boundary / memory safety problem**

Check:
- array index
- `nullptr`
- `next` pointer
- empty input
- out-of-range access

Especially inspect the line immediately before the crash.

---

## TLE

Think:

> **Progress / termination / complexity problem**

Ask:

```text
Does every loop make progress?

Can a pointer stop moving?

Can two loops repeatedly process the same elements?

Can I accidentally enter an infinite loop?

Did I implement O(n²) instead of O(n)?

Did I continue after already finding the answer?
```

---

# 4. Pointer Tracing

For pointer-based problems, don't only read the code.

**Track the actual positions.**

Example:

```cpp
slow = head;
fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```

Create a small table:

| Step | slow | fast |
|---|---|---|
| Start | 1 | 1 |
| 1 | 2 | 3 |
| 2 | 3 | 5 |
| 3 | ... | ... |

Ask:

> Where is each pointer after every iteration?

This is particularly important for:
- Linked Lists
- Fast & Slow Pointer
- Two Pointer
- Sliding Window

---

# 5. Pointer Safety Rules

Before writing:

```cpp
fast->next->next
```

think:

```text
Does fast exist?
Does fast->next exist?
```

Therefore:

```cpp
while (fast != nullptr && fast->next != nullptr)
```

is the usual safety condition.

Remember:

> `fast->next->next` cannot be safely evaluated if `fast` or `fast->next` is `nullptr`.

---

# 6. Pointer Roles

Don't just create variables.

Know what each pointer means.

Example:

```text
slow → moves 1 step
fast → moves 2 steps
```

Another linked-list problem:

```text
prev → node before the target
t    → current target node
```

Before debugging, say:

> What does each pointer represent?

If you cannot answer this, stop and trace the code.

---

# 7. Loop-State Thinking

For every loop, identify four things:

```text
1. Starting state
2. Condition
3. State change
4. Ending state
```

Example:

```cpp
while (left < right) {
    ...
    left++;
}
```

Think:

```text
Starting state → left < right
State change   → left increases
Ending state   → eventually left >= right
```

If you cannot explain these four things, the loop needs more inspection.

---

# 8. The "After This Line" Technique

When debugging, don't read the entire code repeatedly.

Stop at suspicious lines.

Ask:

> **After this line executes, what exactly is true?**

Example:

```cpp
slow = head;
```

Ask:

> Where is slow now?

Then:

```cpp
slow = slow->next;
```

Ask:

> Where is slow now?

Then:

```cpp
if (slow == fast)
```

Ask:

> Why can they be equal here?

This turns debugging into a sequence of small questions instead of trying to understand the whole program at once.

---

# 9. Common Implementation Mistakes

## 9.1 Correct Algorithm, Wrong Pointer Movement

Example:

```cpp
fast = fast->next->next->next;
```

when the algorithm requires:

```cpp
fast = fast->next->next;
```

Ask:

> What is the exact movement described by the algorithm?

Don't change movement just because "faster should be better."

---

## 9.2 Correct Answer Found, But Loop Continues

Example:

```cpp
if (condition) {
    answer = value;
}
```

Ask:

> Do I need to continue after finding this?

Possible actions:

```cpp
return answer;
```

or

```cpp
break;
```

or continue intentionally if the algorithm requires it.

---

## 9.3 Missing Boundary Condition

Example:

```cpp
while (fast != nullptr) {
    fast = fast->next->next;
}
```

Ask:

> Is `fast->next` guaranteed to exist?

If not, this can crash.

---

## 9.4 Off-by-One

Common in:
- `for`
- `while`
- left/right pointers
- k-th position
- array indices
- linked-list positions

Remember:

> Array indices usually go from `0` to `n-1`.

---

## 9.5 Pointer Has the Wrong Role

Example:

You think:

```text
t = target node
```

but your code actually leaves:

```text
t = node before target
```

Then every following operation may be wrong.

Always know what the pointer represents.

---

# 10. Manual Trace Practice

Before running code, occasionally take a tiny input and manually execute it.

Example:

```text
1 → 2 → 3 → 4 → 5
```

Then write:

```text
slow = ?
fast = ?

iteration 1:
slow = ?
fast = ?

iteration 2:
slow = ?
fast = ?
```

For a cycle:

```text
1 → 2 → 3 → 4
        ↑     ↓
        ← ← ←
```

Trace until the pointers meet.

The purpose is not to solve the problem manually.

The purpose is to train:

> **Code → State → Next State**

---

# 11. Before Running Code

Do this:

### Step 1 — Explain the algorithm in one sentence

Example:

> "Use slow and fast pointers to detect whether they eventually meet."

### Step 2 — Identify variable roles

```text
slow → ?
fast → ?
answer → ?
```

### Step 3 — Identify loop termination

```text
Loop ends when → ?
```

### Step 4 — Identify dangerous accesses

```text
Possible nullptr → ?
Possible out-of-bounds → ?
```

### Step 5 — Test one tiny case mentally

Only then run the code.

---

# 12. After TLE

**Do not immediately rewrite the code.**

Use this sequence:

```text
TLE
 ↓
Which loop is running too long?
 ↓
What changes every iteration?
 ↓
Can that variable stop changing?
 ↓
Can the loop revisit the same state?
 ↓
Is there an unnecessary nested loop?
 ↓
Is the algorithm actually the expected complexity?
```

---

# 13. After Runtime Error

Use:

```text
Runtime Error
 ↓
Which line caused it?
 ↓
Which pointer/index is used there?
 ↓
Can it be nullptr/out of range?
 ↓
What was its value immediately before?
 ↓
Which condition should have protected it?
```

---

# 14. After Wrong Answer

Use:

```text
Wrong Answer
 ↓
Take smallest failing example
 ↓
Trace variables
 ↓
Find first point where expected != actual
 ↓
Check the condition/movement responsible
 ↓
Fix the smallest possible thing
```

Do not randomly change multiple lines.

---

# 15. 60-Second Pre-Submission Routine

Before clicking Submit:

```text
□ Do all pointers/indices stay valid?
□ Does every loop make progress?
□ What exactly terminates each loop?
□ What happens after I find the answer?
□ Did I handle the smallest input?
□ Did I accidentally add unnecessary work?
```

This should eventually become automatic.

---

# 16. Practice Tasks — Level 1: Read the Loop

For each snippet, answer the questions **without running the code**.

### Task 1 — Fast & Slow

```cpp
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
```

Write:
- slow movement:
- fast movement:
- termination condition:
- dangerous access:

---

### Task 2 — Two Pointer

```cpp
while (left < right) {
    if (arr[left] < arr[right]) {
        left++;
    } else {
        right--;
    }
}
```

Write:
- what changes?
- what guarantees progress?
- when does the loop stop?

---

### Task 3 — Linked List Traversal

```cpp
while (t != nullptr) {
    t = t->next;
}
```

Write:
- starting pointer:
- movement:
- termination:

---

### Task 4 — Find the Bug

What is unsafe here?

```cpp
while (fast != nullptr) {
    fast = fast->next->next;
}
```

Do not correct it immediately.

First identify the exact unsafe access.

---

### Task 5 — Find the Progress Problem

```cpp
while (left < right) {
    if (arr[left] == target) {
        cout << left;
    } else {
        left++;
    }
}
```

Ask:

> What can happen when `arr[left] == target`?

---

# 17. Practice Tasks — Level 2: Trace It

### Task 6 — Trace Slow/Fast

Given:

```text
1 → 2 → 3 → 4 → 5 → nullptr
```

Starting with:

```text
slow = 1
fast = 1
```

Trace both pointers until the loop stops.

Record every state.

---

### Task 7 — Trace a Cycle

Given:

```text
1 → 2 → 3 → 4
        ↑     ↓
        ← ← ←
```

Start:

```text
slow = head
fast = head
```

Trace until `slow == fast`.

Do not think about the final LeetCode answer yet.

Only trace the state.

---

### Task 8 — Find the First Wrong State

Take any previously solved DSA problem.

Run your accepted code manually on a tiny example.

Record:

```text
Expected state:
Actual state:
First point they differ:
Line responsible:
```

This is more useful than simply rereading the accepted solution.

---

# 18. Practice Tasks — Level 3: Rebuild Without Looking

Choose a problem you have already solved.

Do **not** open the previous solution.

Reconstruct:

```text
Problem
 ↓
Pattern
 ↓
Approach
 ↓
Variables
 ↓
Loop
 ↓
Conditions
 ↓
Termination
 ↓
Code
```

Then compare your new implementation with your old accepted implementation.

Record only:

```text
What I remembered correctly:
What I forgot:
What implementation detail I missed:
```

---

# 19. Practice Tasks — Level 4: Deliberate Debugging

For these tasks, the code contains a small bug.

Your job is to diagnose it **before** changing it.

### Task 9 — Wrong Pointer Speed

```cpp
slow = slow->next;
fast = fast->next->next->next;
```

Question:

> What assumption about fast movement is wrong?

---

### Task 10 — Missing Termination

```cpp
while (left < right) {
    if (nums[left] == target) {
        answer = left;
    }
}
```

Questions:

- What can cause TLE?
- Which variable is supposed to change?
- What should happen after finding the answer?

---

### Task 11 — Suspicious Dereference

```cpp
if (fast->next == nullptr) {
    return nullptr;
}

fast = fast->next->next;
```

Question:

> After this condition, is `fast->next->next` automatically safe?

Trace the pointer state carefully.

---

### Task 12 — Wrong Pointer Role

Suppose:

```text
prev → node 2
t    → node 3
```

and the target is node 3.

You execute:

```cpp
prev->next = t->next;
```

Question:

> What node is now skipped?

Then ask:

> Why is knowing the role of `prev` and `t` essential?

---

# 20. Practice Tasks — Level 5: TLE / Runtime / WA Diagnosis

For each scenario, identify the most likely category **before touching the code**.

### Task 13

The program never finishes.

First questions:
- Which loop?
- What changes?
- Can the same state repeat?

---

### Task 14

The program crashes when `fast->next->next` executes.

First questions:
- Is `fast` valid?
- Is `fast->next` valid?
- Which condition should have protected the access?

---

### Task 15

The program returns the wrong answer on a 1-element input.

First questions:
- What are the valid indexes?
- What does the loop assume about input size?
- What is the smallest valid state?

---

# 21. Personal Mistake Log

Whenever I make an implementation mistake, record only meaningful mistakes.

```md
### Problem: LC XXX

**Mistake**
- ...

**Why I missed it**
- ...

**How to catch it next time**
- ...
```

Do **not** record every typo.

Record mistakes that reveal a reusable weakness.

---

# 22. Mistake Patterns to Watch

Over time, look for repeated categories:

```text
□ Pointer movement
□ Pointer safety
□ Loop termination
□ Off-by-one
□ Wrong variable role
□ Missing edge case
□ Unnecessary work
□ Complexity mistake
□ Incorrect condition
□ State not updated
```

The goal is to reduce repeated mistakes, not to achieve zero mistakes immediately.

---

# 23. The Goal

The goal is NOT:

> "Never make a mistake."

The goal is:

```text
First attempt
    ↓
Small mistake
    ↓
Trace
    ↓
Understand why
    ↓
Recognize the same situation later
    ↓
Catch it earlier
    ↓
Eventually catch it before submission
```

That is implementation skill.

---

# 24. Understanding vs Implementation

There are three separate skills:

```text
1. Problem Understanding
        ↓
"What is being asked?"

2. Algorithmic Understanding
        ↓
"How can I solve it?"

3. Implementation
        ↓
"How exactly do I express that solution in code?"
```

I am currently strengthening **Skill 3**.

This does **not** mean I need to stop DSA and relearn C++ from zero.

I should strengthen implementation while continuing pattern-based DSA.

---

# 25. My Rule Going Forward

When solving a new problem:

```text
1. Understand the problem
2. Identify the pattern
3. Decide the approach
4. Write the code myself
5. Run it
6. If it fails → debug before asking for the answer
7. Trace the mistake
8. Fix it
9. Re-run
10. Only after accepted → interview discussion
```

The purpose of this practice is simple:

> **Make implementation mistakes teach me something instead of making me dependent on corrections.**
