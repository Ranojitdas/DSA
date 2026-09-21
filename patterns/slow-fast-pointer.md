# Slow & Fast Pointer

## 1. Introduction

### Definition

The Slow & Fast Pointer technique uses two pointers that start from the same point but move at different speeds.

- **Slow** moves one step at a time.
- **Fast** moves two steps at a time.

### When to use?

Look for clues such as:

- A **cycle / loop** in a linked list or another repetitive structure.
- Repetitive behaviour where one pointer moving faster can eventually catch another.
- Problems involving **arrays, numbers, linked lists, or strings** where two different movement speeds can reveal a cycle or repeated behaviour.
- A situation where two pointers can start from the same point and move at different speeds.

### Basic Idea

Think of two people running around a circular track:

- One runs slowly.
- One runs faster.
- If a cycle exists, the faster one can eventually catch the slower one.
- In pointer problems, this becomes a **meeting point** between `slow` and `fast`.

## 2. Concepts & Patterns

### Cycle Detection

Start both pointers at the same position.

~~~cpp
slow = head;
fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        // cycle found
}
~~~

The different speeds allow `fast` to catch `slow` when the structure contains a cycle.

### Different Pointer Speeds

- `slow` → moves 1 step.
- `fast` → moves 2 steps.
- Both initially start from the same point.
- The difference in speed is what makes the technique useful for detecting repetitive behaviour.

### Rules

- Always check pointer safety before doing `fast->next->next`.
- For a linked list, use `fast != nullptr && fast->next != nullptr` as the traversal condition.
- The number of pointers does not determine complexity by itself; analyze how many times the pointers move.
- If there is no cycle, `fast` eventually reaches `nullptr`.

## 3. Problems Solved
