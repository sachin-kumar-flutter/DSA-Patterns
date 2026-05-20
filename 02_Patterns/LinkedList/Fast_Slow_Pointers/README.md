# ⚡ Fast & Slow Pointer Pattern

> “Two pointers moving at different speeds can reveal hidden structure.” 🔥

This section contains one of the most important linked list patterns in DSA:

# ⚡ Fast and Slow Pointers

Also known as:

```text id="7x4mqp"
Floyd’s Pointer Technique
```

This pattern is heavily used for:

* cycle detection 🔄
* middle finding 🎯
* palindrome checking 🔍
* distance-based traversal ⚡

---

# 📂 Problems Included

```bash id="5m1v8x"
fast_slow_pointers/
├── middle_of_linked_list.cpp
├── linked_list_cycle.cpp
├── linked_list_cycle_ii.cpp
├── remove_nth_node_from_end.cpp
├── palindrome_linked_list.cpp
```

---

# 🔥 Core Patterns Covered

| Pattern                    | Problem                  |
| -------------------------- | ------------------------ |
| Middle Finding             | Middle of Linked List    |
| Cycle Detection            | Linked List Cycle        |
| Cycle Entry Detection      | Linked List Cycle II     |
| Fixed Gap Traversal        | Remove Nth Node From End |
| Middle + Reverse + Compare | Palindrome Linked List   |

---

# ⚙️ Standard Fast-Slow Template

```cpp id="0v9k2r"
ListNode* slow = head;
ListNode* fast = head;

while(fast && fast->next) {

    slow = slow->next;

    fast = fast->next->next;
}
```

---

# 💡 The Biggest Insight

The pattern works because:

```text id="p8m3vx"
different traversal speeds create useful positional relationships
```

Examples:

* fast reaches end → slow reaches middle
* fast catches slow → cycle exists
* fixed gap → targeted node discovery

---

# 🔥 Important Fast-Slow Techniques

## 🎯 Middle Detection

```text id="7q2vpk"
fast moves 2x speed
```

Used in:

* Middle of Linked List
* Palindrome Linked List

---

## 🔄 Floyd’s Cycle Detection

```text id="m4x8wr"
fast eventually catches slow
```

Used in:

* Linked List Cycle
* Linked List Cycle II

---

## 📏 Fixed Gap Traversal

```text id="z3k1qm"
maintain n-node distance
```

Used in:

* Remove Nth Node From End

---

# ⚠️ Common Mistakes

* Wrong fast pointer movement ❌
* Null pointer access ❌
* Incorrect loop conditions ❌
* Forgetting dummy nodes ❌

---

# 🧠 What This Pattern Really Teaches

Fast-slow pointers improve:

* pointer visualization 🔗
* traversal mathematics ⚡
* space optimization 🎯
* linked list intuition 🧠

---

# 🚀 Interview Insight

Many linked list problems become easier once you recognize:

```text id="2x7mvp"
“Pointers don’t need to move at the same speed.”
```

That single realization unlocks many elegant O(1) space solutions.

---

# 🏁 Final Thought

A normal traversal asks:

```text id="8v1qkr"
“Where is the pointer now?”
```

Fast-slow pointers ask:

```text id="w5m2xp"
“What relationship exists between the pointers?”
```

That difference is what makes this pattern powerful. 🔥

---

⭐ If this helped, consider starring the repo!
