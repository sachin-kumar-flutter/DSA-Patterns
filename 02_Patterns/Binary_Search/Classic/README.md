# 🔍 Classic Binary Search Patterns

> “Every time you eliminate half the search space,
> you get closer to elegance.” ⚡

This section contains the foundational Binary Search patterns that every programmer should master before moving to advanced variations.

These problems teach:

* boundary handling 🎯
* lower/upper bound logic 📍
* efficient searching in sorted arrays 🔄

---

# 📂 Problems Included

```bash id="j0z7r4"
Classic/
├── binary_search.cpp
├── find_first_and_last_occurence.cpp
├── search_insert_position.cpp
```

---

# 🧠 Core Patterns Covered

| Problem                 | Key Idea                  |
| ----------------------- | ------------------------- |
| Binary Search           | Eliminate half repeatedly |
| First & Last Occurrence | Boundary binary search    |
| Search Insert Position  | Lower bound logic         |

---

# ⚙️ Standard Binary Search Template

```cpp id="hq7d2n"
while(left <= right) {

    int mid = left + (right - left) / 2;

    if(nums[mid] == target) {
        return mid;
    }

    else if(nums[mid] < target) {
        left = mid + 1;
    }

    else {
        right = mid - 1;
    }
}
```

---

# 💡 Important Insights

## 🎯 Lower Bound

```text id="0t6q7j"
First index where nums[i] >= target
```

Used in:

* Search Insert Position
* First Occurrence

---

## 🎯 Boundary Search

Sometimes finding the target is NOT enough.

You may need:

* first occurrence
* last occurrence
* insertion point

That’s where boundary binary search becomes important.

---

# ⚠️ Common Mistakes

* Infinite loops ❌
* Overflow in mid calculation ❌
* Wrong boundary updates ❌
* Stopping too early after finding target ❌

---

# 🧠 What These Problems Really Teach

Classic Binary Search develops:

* logical elimination ⚡
* boundary reasoning 🎯
* monotonic thinking 📈

These ideas later extend into:

* rotated arrays 🔄
* binary search on answer 🔍
* lower/upper bound problems 📍

---

# 🚀 Interview Insight

Binary Search is not about memorizing code.

It’s about answering:

```text id="8l2y6m"
“What condition allows me to discard half?”
```

That’s the real skill.

---

# 🏁 Final Thought

Mastering classic binary search makes advanced variations feel natural.

Strong foundations always scale further. 🔥

---

⭐ If this helped, consider starring the repo!
