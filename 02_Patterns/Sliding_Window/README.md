# 🪟 Sliding Window Patterns

> “Don’t recompute the whole answer.
> Slide the solution forward.” ⚡

Sliding Window is one of the most powerful patterns for solving:

* Strings 🔤
* Arrays 📦
* Subarray / substring problems 🔁

The core idea is simple:

> Maintain a valid window and adjust it efficiently instead of checking every subarray.

---

# 🧠 What This Section Covers

This folder contains the **most important sliding window patterns** used in coding interviews:

* Fixed-size windows 📏
* Variable-size windows 🔄
* Frequency-based windows 🔢
* Minimum window problems 🎯
* Counting subarrays 📊

---

# 📂 Problems Included

```bash id="sqecao"
Sliding_Window/
├── max_sum_subarray_k.cpp
├── longest_substring_without_repeating.cpp
├── longest_repeating_character_replacement.cpp
├── min_window_substring.cpp
├── subarrays_with_k_distinct.cpp
├── find_all_anagrams.cpp
```

---

# 🔥 Core Sliding Window Patterns

| Pattern          | Key Idea               |
| ---------------- | ---------------------- |
| Fixed Window     | Add right, remove left |
| Variable Window  | Expand + shrink        |
| Frequency Window | Maintain counts        |
| Minimum Window   | Keep window valid      |
| Counting Window  | atMost(k) trick        |

---

# ⚙️ Standard Templates

## 📏 Fixed Size Window

```cpp id="t0i1rv"
for(int i = k; i < n; i++) {
    window += arr[i];
    window -= arr[i-k];
}
```

---

## 🔄 Variable Size Window

```cpp id="2lvvpy"
while(window is invalid) {
    shrink from left
}

expand right
update answer
```

---

# 💡 Golden Tricks

## 🎯 Minimum Window Logic

```cpp id="t4a6dx"
formed == required
```

Used in:

* Minimum Window Substring

---

## 📊 Counting Subarrays Trick

```cpp id="mz91i9"
exactly(k) = atMost(k) - atMost(k - 1)
```

Used in:

* Subarrays with K Distinct Integers

---

# ⚠️ Common Mistakes

* Forgetting to shrink window ❌
* Updating answer at wrong time ❌
* Mismanaging frequency counts ❌
* Using brute force unnecessarily ❌

---

# 🧠 What Sliding Window Really Teaches

Sliding window is not just about substrings.

It teaches:

* Efficient range processing ⚡
* Dynamic constraints 🎯
* Real-time window maintenance 🔄

---

# 🚀 Interview Insight

If you master sliding window well:

> Many “hard” substring problems start looking repetitive.

That’s the real power of patterns.

---

# 🏁 Final Thought

The goal is NOT:

> “Solve every substring problem.”

The goal is:

> “Recognize the window pattern instantly.” 🔥

---

⭐ If this helped, consider starring the repo!
