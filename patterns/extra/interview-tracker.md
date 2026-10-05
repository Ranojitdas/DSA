# Interview Frequency Tracker

This document tracks the most frequently asked LeetCode problems pattern-wise. It lists whether we have already solved them in our notes, and which companies (both Product-based FAANG and Service-based) frequently ask them in interviews.

## 1. Two Pointers

### ✅ Solved in our Notes
These are already in your `two-pointer.md` file:

| LC      | Problem Name                        | Frequency          | Target Companies                                                |
| :------ | :---------------------------------- | :----------------- | :-------------------------------------------------------------- |
| **15**  | 3Sum                                | 🔥 Extremely High   | **Product:** Meta, Amazon, Oracle. **Finance:** Goldman Sachs   |
| **167** | Two Sum II                          | 🔥 High            | **Product:** Amazon, Adobe. **Consult/Service:** Deloitte, TCS  |
| **283** | Move Zeroes                         | 🔥 High            | **Product:** Samsung, Walmart. **Consult/Service:** IBM         |
| **26**  | Remove Duplicates from Sorted Array | 🔥 High            | **Product:** Microsoft, Atlassian. **Consult:** HCLTech         |
| **75**  | Sort Colors (Dutch National Flag)   | 🔥 High            | **Product:** Microsoft, Oracle. **Service:** TCS, HCLTech       |
| **88**  | Merge Sorted Array                  | 🔥 High            | **Product:** Meta, Amazon. **Finance:** Goldman Sachs, Barclays |
| **977** | Squares of a Sorted Array           | ⭐ Medium           | **Product:** Meta, Google, Uber                                 |
| **18**  | 4Sum                                | ⭐ Medium           | **Product:** Amazon, Apple. **Finance:** Goldman Sachs          |
| **16**  | 3Sum Closest                        | ⭐ Medium           | **Product:** Meta, Amazon, Google                               |
| **27**  | Remove Element                      | ⭐ Medium           | **Product:** Adobe. **Consult/Service:** IBM, Accenture, TCS    |

### ❌ Not Yet Solved (To-Do List)
These are very important Two Pointer problems that we have not added to your notes yet:

| LC      | Problem Name              | Frequency          | Target Companies                                                    |
| :------ | :------------------------ | :----------------- | :------------------------------------------------------------------ |
| **42**  | Trapping Rain Water       | 🔥 Extremely High   | **Product:** Amazon, Google. **Finance:** Goldman Sachs, JP Morgan  |
| **11**  | Container With Most Water | 🔥 High            | **Product:** Meta, Flipkart, Swiggy. **Consult:** Deloitte          |
| **125** | Valid Palindrome          | 🔥 High            | **Product:** Oracle, Adobe. **Consult/Service:** KPMG, IBM, PayPal  |
| **344** | Reverse String            | ⭐ Medium           | **Product:** Samsung, Walmart. **Consult/Service:** HCLTech         |
| **161** | One Edit Distance         | ⭐ Medium           | **Product:** Meta, Google, Uber                                     |

## 2. Sliding Window

### ✅ Solved in our Notes
These are already in your `sliding-window.md` file:

| LC      | Problem Name                                     | Frequency          | Target Companies                                                     |
| :------ | :----------------------------------------------- | :----------------- | :------------------------------------------------------------------- |
| **3**   | Longest Substring Without Repeating Characters   | 🔥 Extremely High   | **Product:** Amazon, Microsoft, Meta. **Startup:** Swiggy, Atlassian |
| **76**  | Minimum Window Substring                         | 🔥 High            | **Product:** Meta, Google, LinkedIn. **Finance:** Goldman Sachs      |
| **209** | Minimum Size Subarray Sum                        | 🔥 High            | **Product:** Amazon, Oracle. **Finance:** JP Morgan                  |
| **1004**| Max Consecutive Ones III                         | 🔥 High            | **Product:** Meta, Microsoft, Walmart. **Consulting:** Deloitte      |
| **904** | Fruit Into Baskets                               | ⭐ Medium           | **Product:** Google, Amazon, Uber                                    |
| **643** | Maximum Average Subarray I                       | ⭐ Medium           | **Product:** Samsung, Adobe. **Service:** TCS                        |
| **1343**| Number of Sub-arrays of Size K and Avg >= T      | ⭐ Medium           | **Product:** Cisco, Oracle. **Consulting:** IBM                      |

## 3. Merge Intervals

### ✅ Solved in our Notes
These are already in your `merge-intervals.md` file:

| LC      | Problem Name              | Frequency          | Target Companies                                                     |
| :------ | :------------------------ | :----------------- | :------------------------------------------------------------------- |
| **56**  | Merge Intervals           | 🔥 Extremely High   | **Product:** Meta, Amazon, Microsoft, Apple. **Finance:** JP Morgan  |
| **57**  | Insert Interval           | 🔥 High            | **Product:** Google, Meta, Oracle. **Consulting:** Deloitte          |

### ❌ Not Yet Solved (To-Do List)
| LC      | Problem Name              | Frequency          | Target Companies                                                     |
| :------ | :------------------------ | :----------------- | :------------------------------------------------------------------- |
| **435** | Non-overlapping Intervals | 🔥 High            | **Product:** Meta, Amazon, Adobe. **Finance:** Goldman Sachs         |
| **252** | Meeting Rooms             | 🔥 High            | **Product:** Uber, Atlassian. **Service:** TCS, Cognizant            |
| **253** | Meeting Rooms II          | 🔥 Extremely High   | **Product:** Amazon, Google, Bloomberg, Snap                         |

## 4. Slow & Fast Pointer

### ✅ Solved in our Notes
These are already in your `slow-fast-pointer.md` file:

| LC      | Problem Name              | Frequency          | Target Companies                                                     |
| :------ | :------------------------ | :----------------- | :------------------------------------------------------------------- |
| **141** | Linked List Cycle         | 🔥 Extremely High   | **Product:** Microsoft, Amazon. **Service:** TCS, IBM                |
| **142** | Linked List Cycle II      | 🔥 High            | **Product:** Meta, Cisco, Samsung. **Finance:** Morgan Stanley       |
| **287** | Find the Duplicate Number | 🔥 High            | **Product:** Amazon, Microsoft. **Finance:** Goldman Sachs           |
| **876** | Middle of the Linked List | 🔥 High            | **Product:** Adobe, Walmart. **Consulting:** PayPal, Deloitte        |
| **202** | Happy Number              | ⭐ Medium           | **Product:** Google, Uber. **Service:** Accenture                    |

## 5. Kadane's Algorithm

### ✅ Solved in our Notes
These are already in your `kadane-algorithm.md` file:

| LC      | Problem Name              | Frequency          | Target Companies                                                     |
| :------ | :------------------------ | :----------------- | :------------------------------------------------------------------- |
| **53**  | Maximum Subarray          | 🔥 Extremely High   | **Product:** Amazon, Microsoft. **Startup/Product:** LinkedIn, Uber  |
| **152** | Maximum Product Subarray  | 🔥 High            | **Product:** Amazon, Microsoft. **Finance:** Goldman Sachs, Barclays |

---
*Note: This list is highly tailored for Freshers! Top-tier FinTechs (Goldman Sachs, JP Morgan) and Big Tech (Amazon, Oracle) love optimization questions that reduce O(N²) to O(N), like 3Sum and Trapping Rain Water. Great product/startup companies for freshers (Walmart, Adobe, Atlassian, Swiggy, PayPal) heavily favor fundamental array/string manipulations like Valid Palindrome, Move Zeroes, and Reverse String.*
