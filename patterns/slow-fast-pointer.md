# Slow & Fast Pointer

## 1. Introduction

### Definition
The Slow & Fast Pointer technique uses two pointers that start from the same point but move at different speeds.
- Slow moves one step
- Fast moves two steps

### When to use?
- cycle/loop in linked list or repetitive structure
- repetitive behaviour where faster pointer can catch slower
- arrays, numbers, linked lists, strings where different speeds reveal cycle/repetition
- two pointers can start from the same point and move at different speeds

### Basic Idea
Think of a circular track: if two runners move at different speeds, the faster one eventually catches the slower one when a cycle exists.

## 2. Concepts & Patterns

### Cycle Detection
~~~cpp
slow = head;
fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
        // cycle found
    }
}
~~~

### Different Pointer Speeds
- Slow moves 1 step
- Fast moves 2 steps
- Both start from the same point
- The speed difference helps reveal cycles or locate positions such as the middle

### Repeated-State Cycle Detection
A cycle does not require a linked-list data structure. If a state always produces exactly one next state, we can treat the sequence like a linked structure.

For example, in Happy Number:

~~~text
n → SquaredValue(n) → SquaredValue(...) → ...
~~~

If a value repeats, the sequence has entered a cycle.

### Rules

**Generic Brute Force**
- For cycle detection, the generic brute force is using a HashSet to store visited nodes/states. If a state repeats, there is a cycle. Time complexity: **O(n)**, Space complexity: **O(n)**.

- Always check `fast != nullptr && fast->next != nullptr` before using `fast->next->next`
- The number of pointers does not determine complexity; analyze their total movement
- If there is no cycle, `fast` eventually reaches `nullptr`

## 3. Problems Solved

### ⭐ LC 141 — Linked List Cycle

**Think / Recognition**
- Linked list + possibility of a cycle/loop → consider Slow & Fast Pointer.

**Core Idea**
- Start `slow` and `fast` at `head`.
- Move `slow` by 1 and `fast` by 2.
- If a cycle exists, `fast` eventually catches `slow`.
- If `fast` reaches `nullptr`, there is no cycle.

**Core Logic**
```cpp
while(fast != nullptr and fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;

    if(slow == fast){
        return true;
    }
}
```
- Both safety checks are needed before `fast->next->next`.

**Keep in mind**
> Different pointer speeds can reveal a cycle because the faster pointer eventually catches the slower one inside the loop.

**My Mistake**
- i) Initially moved `fast` by 3 nodes instead of 2.
- ii) Initially thought increasing `fast`'s speed would improve the asymptotic complexity.

### ⭐ LC 876 — Middle of the Linked List

**Problem**
> Given the head of a singly linked list, return its middle node. If there are two middle nodes, return the second one.

**Think / Recognition**
- Linked list + need to find the middle → consider Slow & Fast Pointer.
- One pointer moves 1 step while the other moves 2 steps.
- When `fast` reaches the end, `slow` is at the middle.

**Core Logic**
```cpp
while(fast != nullptr and fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
}
```

**Keep in mind**
> The pointer speed does not determine the Big-O by itself. Both pointers make only a linear number of forward movements through the list, so the total time is `O(n)`.

**My Mistake**
- No meaningful implementation mistake recorded for this problem.

### ⭐ LC 142 — Linked List Cycle II

**Problem**
> Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return `nullptr`.

**Think / Recognition**
- Linked list + need to find the cycle entrance → consider Slow & Fast Pointer.
- First find a collision inside the cycle.
- Then reset `slow` to `head` and move both pointers one step at a time.
- Their second meeting point is the cycle entrance.

**Core Logic**
```cpp
while(fast != nullptr and fast->next != nullptr){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        output = slow;
        break;
    } 
}
```

**Keep in mind**
> The first meeting only proves that a cycle exists. Reset `slow` to `head`; moving both pointers one step at a time makes their next meeting point the cycle entrance.

**My Mistake**
- i) Initially continued the outer traversal after finding the cycle entrance instead of finishing the function immediately; used `break`/correct control flow after finding the answer.
- ii) Needed to distinguish the first collision point from the actual cycle entrance.

**Optimization**
- Increasing `fast`'s speed does not improve the asymptotic complexity.
- The standard 1-step / 2-step movement keeps the reasoning and implementation clean.

### ⭐ LC 202 — Happy Number

**Problem**
> Repeatedly replace a number with the sum of the squares of its digits. Return true if the process reaches 1; otherwise, it eventually enters a cycle.

**Think / Recognition**
- Repeatedly applying a function creates a sequence of states.
- A state always produces one next state → think of it like a linked structure.
- If a value repeats, the sequence contains a cycle.
- Need to distinguish reaching 1 from entering a cycle that does not contain 1.

**Core Logic**
```cpp
while(fast != 1){
    slow = SquaredValue(slow);
    fast = SquaredValue(fast);
    fast = SquaredValue(fast);

    if(slow == fast and slow != 1){
        return false;
    }
}
```

**Keep in mind**
> Slow & Fast Pointer is not limited to linked lists. It can detect a cycle whenever each state deterministically leads to one next state.

**My Mistake**
- i) Initially tried to find the correct while condition and considered checking only pointer collision.
- ii) Initially used an unnecessary `res` variable and `break`; simplified by returning directly when a non-1 cycle is detected.

### ⭐ LC 287 — Find the Duplicate Number

**Problem**
> Given an array containing n + 1 integers where each integer is in the range 1 to n, find the duplicate number without modifying the array and using O(1) extra space.

**Think / Recognition**
- Array values are valid indices → treat `nums[index]` as the next pointer.
- n + 1 positions with values in 1..n guarantees a repeated value.
- The repeated value creates a cycle in the index-to-value sequence.
- Find the cycle entrance → duplicate number.

**Core Logic**
```cpp
while(true){
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];

    if(slow == fast){
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        res = slow;
        break;
    }
}
```

**Keep in mind**
> Treat `nums[index]` as the next pointer. The duplicate is the entrance of the resulting cycle; the first collision only proves that a cycle exists.

**My Mistake**
- i) Initially had difficulty seeing how an array could form a cycle because it has a fixed end; the key was to treat each value as the next index.
- ii) Initially thought the first Slow/Fast collision directly identified the duplicate; the cycle entrance must be found after resetting `slow`.
