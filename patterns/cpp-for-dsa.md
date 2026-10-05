# C++ for DSA

This is the C++ foundation needed to comfortably solve DSA problems in LeetCode/interviews.

> Focus on using C++ for DSA, not learning every part of the language.

## Table of Contents
1. [OOP in C++ (Interview Basics)](#1-oop-in-c-interview-basics)
2. [Under the Hood (Interview Favorites)](#2-under-the-hood-interview-favorites)
3. [Arrays & Vector](#3-arrays--vector)
4. [Functions](#4-functions)
5. [References `&`](#5-references-)
6. [Pointers](#6-pointers)
7. [Strings](#7-strings)
8. [STL](#8-stl)
9. [HashMap / HashSet](#9-hashmap--hashset-unordered_map--unordered_set)
10. [Linked List Syntax](#10-linked-list-syntax)

---

## 1. OOP in C++ (Interview Basics)

Interviewers often ask C++ developers about OOP concepts to see if they understand how to structure code beyond simple functions.

### 1.1 Class vs Struct
In C++, they are almost exactly the same. The only difference is default visibility:
- `struct` members are **public** by default (which is why LeetCode uses `struct ListNode`).
- `class` members are **private** by default.

### 1.2 The Four Pillars of OOP
1. **Encapsulation:** Hiding data inside a class and using public methods (getters/setters) to access it.
2. **Abstraction:** Hiding complex implementation details (e.g., you use `vector.push_back()` without needing to know how memory is resized).
3. **Inheritance:** A child class deriving properties from a parent class.
4. **Polymorphism:** The ability to use a single interface for different types (e.g., Function Overloading, or Virtual Functions for runtime polymorphism).

### 1.3 Constructors and Destructors
- **Constructor:** A special function called automatically when an object is created. Used to initialize variables.
- **Destructor:** Called automatically when an object goes out of scope. Crucial in C++ for freeing memory (using `delete`) to prevent memory leaks.

---

## 2. Under the Hood (Interview Favorites)

Senior engineers love to ask *how* C++ data structures actually work.

### 2.1 How `std::vector` Works Internally
A `vector` is a dynamically allocated contiguous array. It tracks two things:
- **Size:** How many elements are currently in the vector.
- **Capacity:** How much total memory is currently allocated.

**What happens when you `push_back` and it's full?**
When `size == capacity`, the vector:
1. Allocates a new array on the heap (usually **double** the current capacity).
2. Copies all existing elements to the new array.
3. Deletes the old array.

*Interview flex:* Explain that because of this, `push_back` is **O(1) amortized** time, even though an individual push might take O(N) if a resize happens.

### 2.2 Stack vs Heap Memory
- **Stack:** Used for local variables (e.g., `int arr[5];`). Fast allocation. Automatically cleaned up when the function ends.
- **Heap:** Used for dynamic memory (e.g., using `new`). You control when it is freed (using `delete`). If you forget, it causes a **memory leak**. 
*Note:* A `std::vector` is an object on the stack, but the array it manages is allocated on the heap!

### 2.3 Pointer vs Reference
- **Pointer (`*`):** Stores a memory address. Can be reassigned. Can point to `nullptr`. 
- **Reference (`&`):** An alias for an existing variable. Must be initialized immediately. Cannot be reassigned. Cannot be `nullptr`. (Safer and easier to use, which is why we pass vectors by reference `vector<int>&`).

---

## 3. Arrays & Vector

### 3.1 Array vs Vector
- Array → fixed size.
- `vector` → dynamic size and heavily used in LeetCode.

```cpp
int arr[5];
vector<int> nums;
```

### 3.2 Creating / Initializing

```cpp
vector<int> nums = {1, 2, 3};
vector<int> nums(5);        // 5 zeros
vector<int> nums(5, 10);    // 5 elements, all 10
```

### 3.3 Accessing & Modifying

```cpp
nums[i];
nums[i] = 10;
```

Valid indexes are `0` to `nums.size() - 1`.

### 3.4 Size & Traversal

```cpp
nums.size();

for(int i = 0; i < nums.size(); i++) {
    cout << nums[i];
}
```

### 3.5 Common Vector Operations

```cpp
nums.push_back(5);
nums.pop_back();
nums.front();
nums.back();
nums.empty();
```

### 3.6 Passing Vector to a Function

```cpp
void solve(vector<int>& nums) {
    // modifies original vector
}
```

### 3.7 In-place vs New Vector
- **In-place:** modify the original vector.
- **Extra vector:** create another vector for the result.

Notice whether the problem requires in-place modification or O(1) extra space.

### 3.8 2D Vector

A 2D vector is a vector of vectors and is commonly used for matrices and grids.

**Initialize with values:**

```cpp
vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6}
};
```

**Create an empty 2D vector and add rows:**

```cpp
vector<vector<int>> matrix;

matrix.push_back({1, 2, 3});
matrix.push_back({4, 5, 6});
```

**Create fixed rows × columns:**

```cpp
vector<vector<int>> matrix(3, vector<int>(4, 0));
```

This creates a 3 × 4 matrix filled with `0`.

**Access an element:**

```cpp
matrix[row][col];
```

**Traverse:**

```cpp
for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
        cout << matrix[i][j];
    }
}
```

---

## 4. Functions

Only the basics needed for DSA.

### 4.1 Structure

```cpp
int add(int a, int b) {
    return a + b;
}
```

- Parameters → variables in the function definition.
- Arguments → actual values passed to the function.
- `return` sends a value back.
- `void` means the function does not return a value.

### 4.2 Multiple Parameters

```cpp
int findSum(vector<int>& nums, int target) {
    // ...
}
```

---

## 5. References `&`

### 5.1 What is a Reference?

A reference is another name for the same variable.

```cpp
int x = 10;
int& ref = x;
```

Changing `ref` changes `x`.

### 5.2 Reference vs Copy

```cpp
void change(int x) {
    x = 20;       // original does not change
}

void change(int& x) {
    x = 20;       // original changes
}
```

### 5.3 `vector<int>&`

```cpp
void solve(vector<int>& nums)
```

The function receives the original vector instead of making a copy, so changes affect the original vector.

### 5.4 `const &`

```cpp
void solve(const vector<int>& nums)
```

- Avoids copying the vector.
- Prevents the function from modifying it.

Useful when we only need to read the data.

---

## 6. Pointers

Pointers are especially important for linked lists and trees.

### 6.1 Basic Idea

A pointer stores the address of another variable.

```cpp
int x = 10;
int* p = &x;
```

- `&x` → address of `x`.
- `p` → stores that address.
- `*p` → value at that address.

### 6.2 `nullptr`

```cpp
int* p = nullptr;
```

Means the pointer is not pointing to an object.

### 6.3 Linked-List Access

```cpp
current->val;
current->next;
current = current->next;
```

`->` is used to access members through a pointer.

---

## 7. Strings

Only the commonly used DSA operations.

### 7.1 Creating & Accessing

```cpp
string s = "hello";
s[i];
```

### 7.2 Common Operations

```cpp
s.size();
s.length();
s.push_back('a');
s.pop_back();
s.substr(start, length);
```

### 7.3 Modifying Characters

```cpp
s[i] = 'x';
```

### 7.4 Useful Character Functions

```cpp
isdigit(c);
isalpha(c);
tolower(c);
toupper(c);
```

---

## 8. STL

STL is important throughout DSA. Focus on common containers and algorithms.

### 8.1 `pair`

```cpp
pair<int, int> p = {1, 2};
p.first;
p.second;
```

### 8.2 `stack`

LIFO — Last In, First Out.

```cpp
stack<int> st;
st.push(10);
st.top();
st.pop();
st.empty();
```

### 8.3 `queue`

FIFO — First In, First Out.

```cpp
queue<int> q;
q.push(10);
q.front();
q.pop();
q.empty();
```

### 8.4 `deque`

Insert/remove from both ends.

```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

### 8.5 `set`

Stores unique elements in sorted order.

```cpp
set<int> s;
s.insert(5);
s.erase(5);
s.find(5);
s.count(5);
```

### 8.6 `map`

Stores key-value pairs in sorted key order.

```cpp
map<int, string> mp;
mp[1] = "one";
mp.find(1);
mp.count(1);
```

### 8.7 `priority_queue`

Useful when we repeatedly need the largest/smallest element.

```cpp
priority_queue<int> pq;    // max heap
pq.push(5);
pq.top();
pq.pop();
```

Min heap:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

### 8.8 Common Algorithms

```cpp
sort(nums.begin(), nums.end());
reverse(nums.begin(), nums.end());
swap(a, b);
min(a, b);
max(a, b);
abs(x);
```

### 8.9 Iterators / `begin()` / `end()`

```cpp
nums.begin();
nums.end();
```

Commonly used with STL algorithms such as `sort`.

Remember: `end()` points one position after the last element.

---

## 9. HashMap / HashSet (`unordered_map` / `unordered_set`)

Very common in DSA for lookup and frequency counting.

### 9.1 HashMap → `unordered_map`

A HashMap stores **key-value pairs** and provides fast average-case lookup.

```cpp
unordered_map<int, int> freq;
```

### 9.2 Insert / Update

```cpp
freq[5]++;
freq[5] = 10;
```

### 9.3 Check if a Key Exists

```cpp
freq.find(5) != freq.end();
freq.count(5);
```

### 9.4 Frequency Counting

```cpp
unordered_map<int, int> freq;

for(int x : nums) {
    freq[x]++;
}
```

### 9.5 HashSet → `unordered_set`

Stores unique elements with fast average-case lookup.

```cpp
unordered_set<int> seen;
seen.insert(5);
seen.count(5);
seen.erase(5);
```

### 9.6 Map vs Set

- **HashMap** → key → value (`unordered_map`).
- **HashSet** → unique values only (`unordered_set`).
- `map` / `set` → sorted.
- `unordered_map` / `unordered_set` → not sorted; generally used for fast average-case lookup.

### 9.7 How `unordered_map` Stores Data

`unordered_map<Key, Value>` stores a mapping:

    key → value

Example:

```cpp
unordered_map<char, int> freq;

freq['A']++;
freq['A']++;
freq['B']++;
```

Conceptually:

    'A' → 2
    'B' → 1

`freq['A']` means **the value stored for key `'A'`**, not an array index.

Unlike a `vector`, an `unordered_map` does not store values at sequential numeric indexes.

### 9.8 Accessing Missing Keys

```cpp
freq['X'];
```

Using `operator[]` for a missing key creates that key with its default value.

Use `find()` or `count()` when you only want to check whether a key exists.

### 9.9 Comparing / Checking Frequencies

For frequency problems, compare the required frequency against the current frequency for each relevant key.

Example:

    needed:
    A → 2
    B → 1

    window:
    A → 3
    B → 1

The window satisfies the requirement because:

    window[A] >= needed[A]
    window[B] >= needed[B]

For performance-sensitive sliding-window problems, maintaining a separate count of satisfied requirements can avoid repeatedly comparing the entire frequency structure.


---

## 10. Linked List Syntax

Only the syntax needed to start solving linked-list problems.

### 10.1 Node Structure

Typical LeetCode node:

```cpp
struct ListNode {
    int val;
    ListNode* next;
};
```

### 10.2 Accessing a Node

```cpp
current->val;
current->next;
```

### 10.3 Moving Through the List

```cpp
current = current->next;
```

### 10.4 End of the List

```cpp
current == nullptr
```

---

## What I Need to Be Comfortable With for DSA

- **OOP Concepts:** Encapsulation, Abstraction, Inheritance, Polymorphism
- **Under the Hood:** How `std::vector` resizes, Stack vs Heap memory, Pointers vs References
- `vector` creation, indexing, traversal and common operations
- 2D vectors for basic matrix/grid problems
- Functions and parameters
- References, especially `vector<int>&`
- Basic pointers and `nullptr`
- Basic string operations
- Common STL containers and algorithms
- **HashMap / HashSet (`unordered_map` / `unordered_set`)** for lookup and frequency counting
- Basic `ListNode` syntax
