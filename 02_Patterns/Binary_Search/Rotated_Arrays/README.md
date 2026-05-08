# 🔄 Rotated Sorted Arrays

> “The array is still sorted… just hiding its order.” 🔍

Rotated array problems are one of the most important variations of Binary Search.

The challenge is not finding the target —
it’s identifying **which half is still sorted**.

---

# 🧠 Core Idea

In a rotated sorted array:

* At least **one half is always sorted**
* Use that sorted half to eliminate impossible regions

That single observation solves most rotated-array problems.

---

# 📂 Problems Included

```bash id="r2kjj8"
Rotated_Arrays/
├── search_rotated_sorted_array.cpp
├── find_minimum_rotated_array.cpp
```

---

# 🔥 Patterns Covered

| Problem                 | Key Idea                      |
| ----------------------- | ----------------------------- |
| Search in Rotated Array | Identify sorted half          |
| Find Minimum            | Minimum lies in unsorted half |

---

# ⚙️ Standard Logic

## 🔍 Identify Sorted Half

```cpp id="3oyj5r"
if(nums[left] <= nums[mid]) {
    // left half is sorted
}
else {
    // right half is sorted
}
```

---

# 💡 Important Observation

If:

```cpp id="x2o17n"
nums[mid] > nums[right]
```

then:

```text id="0p8x0q"
minimum lies in the right half
```

Otherwise:

```text id="m8z1z5"
minimum lies at mid or left half
```

---

# ⚠️ Common Mistakes

* Forgetting duplicates edge cases ❌
* Wrong boundary updates ❌
* Confusing sorted half logic ❌
* Using linear search unnecessarily ❌

---

# 🧠 What These Problems Teach

Rotated arrays improve:

* decision-based binary search ⚡
* pattern recognition 🔄
* boundary elimination thinking 🎯

---

# 🚀 Interview Insight

These problems are rarely about coding.

They are about answering:

```text id="k7y4vz"
“Which side can be safely discarded?”
```

That’s the real binary search mindset.

---

# 🔥 Key Takeaway

Binary Search is not just:

> “Find target.”

It is:

> “Use structure to eliminate search space efficiently.”

Rotated arrays are the perfect example of that idea.

---

# 🏁 Final Thought

Once you understand:

* sorted half detection
* boundary movement
* elimination logic

most rotated-array problems start feeling predictable. 🔥

---

⭐ If this helped, consider starring the repo!
