# 🔍 Binary Search Patterns

> “Binary Search is not just searching.
> It’s the art of eliminating impossibilities.” ⚡

Binary Search is one of the most powerful problem-solving techniques in DSA.

Most people learn it as:

> “Find an element in a sorted array.”

But in interviews, Binary Search evolves into:

* boundary searching 📍
* rotated arrays 🔄
* optimization problems 🎯
* answer-space searching 🔍

---

# 🧠 What This Section Covers

This folder contains the most important Binary Search patterns:

* Classic Binary Search ⚙️
* Boundary Search 📍
* Rotated Arrays 🔄
* Binary Search on Answer 🎯

---

# 📂 Directory Structure

```bash id="gv0h0t"
Binary_Search/
│
├── classics/
│   ├── binary_search.cpp
│   ├── find_first_and_last_occurence.cpp
│   ├── search_insert_position.cpp
│
├── rotated_arrays/
│   ├── search_rotated_sorted_array.cpp
│   ├── find_minimum_rotated_array.cpp
│
├── binary_search_on_answer/
│   ├── sqrt_x.cpp
│   ├── koko_eating_bananas.cpp
│   ├── allocate_minimum_pages.cpp
│   ├── aggressive_cows.cpp
│   ├── ship_packages_within_d_days.cpp
```

---

# 🔥 Core Binary Search Patterns

| Pattern         | Key Idea                       |
| --------------- | ------------------------------ |
| Classic Search  | Eliminate half repeatedly      |
| Boundary Search | Find first/last valid position |
| Rotated Arrays  | Identify sorted half           |
| BS on Answer    | Search feasible answer space   |

---

# ⚙️ Standard Template

```cpp id="g49kr9"
while(left <= right) {

    int mid = left + (right - left) / 2;

    if(condition) {
        // eliminate one half
    }
}
```

---

# 💡 Most Important Insight

Binary Search always depends on one thing:

# 🎯 Monotonicity

There must exist a condition like:

```text id="dhmd0u"
FFFFTTTT
```

or:

```text id="x8bn4r"
TTTTFFFF
```

Once that pattern exists:

> Binary Search becomes possible.

---

# ⚠️ Common Mistakes

* Overflow in mid calculation ❌
* Infinite loops ❌
* Wrong boundary updates ❌
* Missing edge cases ❌
* Forgetting monotonic property ❌

---

# 🧠 What Binary Search Really Teaches

Binary Search improves:

* logical elimination ⚡
* decision making 🎯
* optimization thinking 📈
* boundary reasoning 📍

---

# 🚀 Interview Insight

Strong candidates don’t memorize Binary Search.

They ask:

```text id="byknit"
“What property allows me to discard half?”
```

That’s the real mindset.

---

# 🔥 Pattern Progression

This section moves from:

```text id="l4c0ic"
find element
```

to:

```text id="wnfhq8"
find best possible answer
```

That transition is what makes Binary Search truly powerful.

---

# 🏁 Final Thought

Once you master Binary Search patterns,
many “hard” interview problems start looking structured instead of random. 🔥

---

⭐ If this helped, consider starring the repo!
