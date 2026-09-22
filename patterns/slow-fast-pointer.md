undefined

### ⭐ LC 876 — Middle of the Linked List

**Problem**
> Given the head of a singly linked list, return its middle node. If there are two middle nodes, return the second one.

**Think / Recognition**
- Linked list + need to find the middle → consider Slow & Fast Pointer.
- One pointer moves 1 step while the other moves 2 steps.
- When `fast` reaches the end, `slow` is at the middle.

**Brute Force**
- Traverse the list once to find its length.
- Calculate the middle position.
- Traverse again from `head` to the middle.
- Time: `O(n)`, Space: `O(1)`.
- Two passes are used, so this can be done more directly with Slow & Fast Pointer.

**Pseudocode**
~~~text
slow = head
fast = head

while fast exists and fast->next exists:
    slow = slow->next
    fast = fast->next->next

return slow
~~~

**Keep in mind**
> The pointer speed does not determine the Big-O by itself. Both pointers make only a linear number of forward movements through the list, so the total time is `O(n)`.

**My Mistake**
- No meaningful implementation mistake recorded for this problem.

**Complexity**
- Time: `O(n)`
- Space: `O(1)`
