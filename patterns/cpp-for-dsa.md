# C++ for DSA

This is the C++ foundation needed to comfortably solve DSA problems in LeetCode/interviews.

> Focus on using C++ for DSA, not learning every part of the language.

## 1. Arrays & Vector

### 1.1 Array vs Vector
- Array → fixed size.
- `vector` → dynamic size and heavily used in LeetCode.

```cpp
int arr[5];
vector<int> nums;
```

### 1.2 Creating / Initializing

```cpp
vector<int> nums = {1, 2, 3};
vector<int> nums(5);        // 5 zeros
vector<int> nums(5, 10);    // 5 elements, all 10
```

### 1.3 Accessing & Modifying

```cpp
nums[i];
nums[i] = 10;
```

Valid indexes are `0` to `nums.size() - 1`.

### 1.4 Size & Traversal

```cpp
nums.size();

for(int i = 0; i < nums.size(); i++) {
    cout << nums[i];
}
```

### 1.5 Common Vector Operations

```cpp
nums.push_back(5);
nums.pop_back();
nums.front();
nums.back();
nums.empty();
```

### 1.6 Passing Vector to a Function

```cpp
void solve(vector<int>& nums) {
    // modifies original vector
}
```

### 1.7 In-place vs New Vector
- **In-place:** modify the original vector.
- **Extra vector:** create another vector for the result.

Notice whether the problem requires in-place modification or O(1) extra space.

### 1.8 2D Vector

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

## 2. Functions

Only the basics needed for DSA.

### 2.1 Structure

```cpp
int add(int a, int b) {
    return a + b;
}
```

- Parameters → variables in the function definition.
- Arguments → actual values passed to the function.
- `return` sends a value back.
- `void` means the function does not return a value.

### 2.2 Multiple Parameters

```cpp
int findSum(vector<int>& nums, int target) {
    // ...
}
```

---

## 3. References `&`

### 3.1 What is a Reference?

A reference is another name for the same variable.

```cpp
int x = 10;
int& ref = x;
```

Changing `ref` changes `x`.

### 3.2 Reference vs Copy

```cpp
void change(int x) {
    x = 20;       // original does not change
}

void change(int& x) {
    x = 20;       // original changes
}
```

### 3.3 `vector<int>&`

```cpp
void solve(vector<int>& nums)
```

The function receives the original vector instead of making a copy, so changes affect the original vector.

### 3.4 `const &`

```cpp
void solve(const vector<int>& nums)
```

- Avoids copying the vector.
- Prevents the function from modifying it.

Useful when we only need to read the data.

---

## 4. Pointers

Pointers are especially important for linked lists and trees.

### 4.1 Basic Idea

A pointer stores the address of another variable.

```cpp
int x = 10;
int* p = &x;
```

- `&x` → address of `x`.
- `p` → stores that address.
- `*p` → value at that address.

### 4.2 `nullptr`

```cpp
int* p = nullptr;
```

Means the pointer is not pointing to an object.

### 4.3 Linked-List Access

```cpp
current->val;
current->next;
current = current->next;
```

`->` is used to access members through a pointer.

---

## 5. Strings

Only the commonly used DSA operations.

### 5.1 Creating & Accessing

```cpp
string s = "hello";
s[i];
```

### 5.2 Common Operations

```cpp
s.size();
s.length();
s.push_back('a');
s.pop_back();
s.substr(start, length);
```

### 5.3 Modifying Characters

```cpp
s[i] = 'x';
```

### 5.4 Useful Character Functions

```cpp
isdigit(c);
isalpha(c);
tolower(c);
toupper(c);
```

---

## 6. STL

STL is important throughout DSA. Focus on common containers and algorithms.

### 6.1 `pair`

```cpp
pair<int, int> p = {1, 2};
p.first;
p.second;
```

### 6.2 `stack`

LIFO — Last In, First Out.

```cpp
stack<int> st;
st.push(10);
st.top();
st.pop();
st.empty();
```

### 6.3 `queue`

FIFO — First In, First Out.

```cpp
queue<int> q;
q.push(10);
q.front();
q.pop();
q.empty();
```

### 6.4 `deque`

Insert/remove from both ends.

```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

### 6.5 `set`

Stores unique elements in sorted order.

```cpp
set<int> s;
s.insert(5);
s.erase(5);
s.find(5);
s.count(5);
```

### 6.6 `map`

Stores key-value pairs in sorted key order.

```cpp
map<int, string> mp;
mp[1] = "one";
mp.find(1);
mp.count(1);
```

### 6.7 `priority_queue`

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

### 6.8 Common Algorithms

```cpp
sort(nums.begin(), nums.end());
reverse(nums.begin(), nums.end());
swap(a, b);
min(a, b);
max(a, b);
abs(x);
```

### 6.9 Iterators / `begin()` / `end()`

```cpp
nums.begin();
nums.end();
```

Commonly used with STL algorithms such as `sort`.

Remember: `end()` points one position after the last element.

---

## 7. HashMap / HashSet (`unordered_map` / `unordered_set`)

Very common in DSA for lookup and frequency counting.

### 7.1 HashMap → `unordered_map`

A HashMap stores **key-value pairs** and provides fast average-case lookup.

```cpp
unordered_map<int, int> freq;
```

### 7.2 Insert / Update

```cpp
freq[5]++;
freq[5] = 10;
```

### 7.3 Check if a Key Exists

```cpp
freq.find(5) != freq.end();
freq.count(5);
```

### 7.4 Frequency Counting

```cpp
unordered_map<int, int> freq;

for(int x : nums) {
    freq[x]++;
}
```

### 7.5 HashSet → `unordered_set`

Stores unique elements with fast average-case lookup.

```cpp
unordered_set<int> seen;
seen.insert(5);
seen.count(5);
seen.erase(5);
```

### 7.6 Map vs Set

- **HashMap** → key → value (`unordered_map`).
- **HashSet** → unique values only (`unordered_set`).
- `map` / `set` → sorted.
- `unordered_map` / `unordered_set` → not sorted; generally used for fast average-case lookup.
### 7.7 How `unordered_map` Stores Data

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

### 7.8 Accessing Missing Keys

```cpp
freq['X'];
```

Using `operator[]` for a missing key creates that key with its default value.

Use `find()` or `count()` when you only want to check whether a key exists.

### 7.9 Comparing / Checking Frequencies

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

## 8. Linked List Syntax

Only the syntax needed to start solving linked-list problems.

### 8.1 Node Structure

Typical LeetCode node:

```cpp
struct ListNode {
    int val;
    ListNode* next;
};
```

### 8.2 Accessing a Node

```cpp
current->val;
current->next;
```

### 8.3 Moving Through the List

```cpp
current = current->next;
```

### 8.4 End of the List

```cpp
current == nullptr
```

---

## What I Need to Be Comfortable With for DSA

- `vector` creation, indexing, traversal and common operations
- 2D vectors for basic matrix/grid problems
- Functions and parameters
- References, especially `vector<int>&`
- Basic pointers and `nullptr`
- Basic string operations
- Common STL containers and algorithms
- **HashMap / HashSet (`unordered_map` / `unordered_set`)** for lookup and frequency counting
- Basic `ListNode` syntax
