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
