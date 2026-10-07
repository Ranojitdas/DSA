# Stack

## 1. Introduction

### Definition
A **Stack** is a LIFO (Last In, First Out) data structure. The most recently inserted element is the first one removed.

### When to use?
Think of Stack when the problem involves:
- The **most recent element** matters.
- Processing from **right to left** or reversing an order.
- **Matching, cancelling, or clearing** elements.
- Removing elements based on a condition involving recent elements.

### Basic Idea
Keep the elements that are currently relevant in a stack.

For every element, ask the universal Stack questions:
1. **When should I pop, and what should I pop?**
2. **When should I push?**
3. **Where/how should I store the result?**

## 2. Concepts & Patterns

### Simple Stack
Use a normal stack when the problem mainly needs LIFO behavior.

Common operations:
- `push()` — insert an element.
- `pop()` — remove the top element.
- `top()` — view the top element.
- `size()` — number of elements.
- `empty()` — check whether the stack is empty.

A stack is useful for **matching/cancelling** and **reversal**.

### Monotonic Stack
Maintain the stack in a specific order:
- **Increasing monotonic stack**
- **Decreasing monotonic stack**

When a new element violates the required order, **pop** elements until the order is restored.

A common template is:
- Process elements from the right when the answer depends on future elements.
- Pop elements that cannot be the required answer.
- The remaining stack top gives the relevant next element.
- Store the answer and push the current element/index.

### Greedy Stack
The instructor notes identify **Greedy Stack** as a third Stack type where a condition determines which elements should be kept or removed.

The specific condition is problem-dependent and should be identified from the problem rather than memorized as one fixed template.

### Rules
- **LIFO:** most recently pushed → first to pop.
- If only the most recent unresolved element matters, consider Stack.
- For matching/cancelling, compare the current element with `st.top()`.
- For reversal, pushing in one direction and popping gives the reverse order.
- For monotonic Stack, the key is deciding **what condition causes a pop** and which order the stack must maintain.

## 3. Problems Solved

### ⭐ LC 1047 — Remove All Adjacent Duplicates In String

**Think / Recognition**
- String where adjacent equal characters must cancel/remove each other.
- The current character needs to be compared with the **most recent remaining character**.
- → **Simple Stack / cancelling**

**Core Idea**
- Scan left to right.
- If the current character matches the stack top, pop the top because the adjacent pair cancels.
- Otherwise push the current character.
- The stack contains the remaining characters in order; pop them into a result and reverse it.

**Core Logic**
```cpp
if(st.empty() || st.top() != s[i])
    st.push(s[i]);
else
    st.pop();
```
The stack top represents the most recent character that is still present after previous cancellations.

**Keep in mind**
> When the current character can cancel the most recent remaining character, the stack naturally handles it.

### ⭐ LC 739 — Daily Temperatures

**Think / Recognition**
- For each day, find the next **greater** temperature.
- The answer depends on a future element.
- Repeated forward scanning is too slow on large inputs.
- → **Decreasing Monotonic Stack**

**Core Idea**
- Process from **right to left** so future temperatures are already available in the stack.
- Store **indices** in the stack so the distance to the next warmer day can be calculated.
- Pop indices whose temperatures are `<= temperatures[i]` because they cannot be the next warmer day for the current temperature.
- The remaining top is the nearest greater temperature.

**Core Logic**
```cpp
while(!st.empty() && temperatures[st.top()] <= temperatures[i])
    st.pop();

if(!st.empty())
    res[i] = st.top() - i;

st.push(i);
```
The stack stores candidate indices, not just temperatures, because the answer needs the index difference.

**Keep in mind**
> Scan from the right, remove temperatures that are not useful, and the stack top gives the next warmer day.

**My Mistake**
- i) I first tried forward scanning with a basic stack and `count`; the approach could work as brute force but was `O(n²)` and caused TLE.
- ii) When no warmer day existed, I initially pushed the number of days scanned instead of `0`.

### ⭐ LC 496 — Next Greater Element I

**Think / Recognition**
- For each element, find the next **greater** element to its right.
- The input relationship is naturally a next-greater query.
- → **Monotonic Stack**, followed by lookup for `nums1`.

**Core Idea**
- Process `nums2` from right to left.
- Pop elements `<= nums2[j]` because they cannot be the next greater element.
- The remaining stack top is the next greater value.
- Store that result for each position.
- Then answer `nums1` queries using the precomputed next-greater results.

**Core Logic**
```cpp
while(!st.empty() && st.top() <= nums2[j])
    st.pop();

res[j] = st.empty() ? -1 : st.top();
st.push(nums2[j]);
```
The stack keeps only useful greater-element candidates.

**Keep in mind**
> For Next Greater Element, pop everything that cannot beat the current value; the remaining top is the answer.
