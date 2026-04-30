# ⚙️ STL Cheat Sheet (C++)

A quick reference for commonly used **Standard Template Library (STL)** components in C++.

---

## 📦 Containers

### 🔹 Vector

```cpp
vector<int> v;
v.push_back(10);
v.pop_back();
v.size();
```

---

### 🔹 Pair

```cpp
pair<int, int> p = {1, 2};
p.first;
p.second;
```

---

### 🔹 Stack (LIFO)

```cpp
stack<int> st;
st.push(10);
st.pop();
st.top();
```

---

### 🔹 Queue (FIFO)

```cpp
queue<int> q;
q.push(10);
q.pop();
q.front();
```

---

### 🔹 Deque

```cpp
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

---

## 🔼 Priority Queue (Heap)

### Max Heap

```cpp
priority_queue<int> pq;
```

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## 🗺️ Maps

### Map (Ordered)

```cpp
map<int, int> mp;
mp[1] = 10;
```

### Unordered Map

```cpp
unordered_map<int, int> ump;
```

---

## 🔢 Sets

### Set (Sorted, unique)

```cpp
set<int> s;
s.insert(5);
```

### Unordered Set

```cpp
unordered_set<int> us;
```

---

## ⚙️ Algorithms

### Sorting

```cpp
sort(v.begin(), v.end());              // ascending
sort(v.rbegin(), v.rend());            // descending
```

---

### Searching

```cpp
binary_search(v.begin(), v.end(), x);
```

---

### Min / Max

```cpp
*max_element(v.begin(), v.end());
*min_element(v.begin(), v.end());
```

---

### Reverse

```cpp
reverse(v.begin(), v.end());
```

---

### Count

```cpp
count(v.begin(), v.end(), x);
```

---

## 🔁 Iterators

```cpp
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it;
}
```

---

## ⚡ Time Complexity (Quick View)

| Container     | Insert   | Search   |
| ------------- | -------- | -------- |
| Vector        | O(1)     | O(n)     |
| Set / Map     | O(log n) | O(log n) |
| Unordered Map | O(1)*    | O(1)*    |

* Average case

---

## 💡 Key Insight

👉 STL helps you focus on **logic**, not implementation.

Use it wisely to:

* Reduce code complexity
* Improve performance
* Write clean solutions

---

## 🧾 Notes

* Prefer `unordered_map` for speed
* Use `set/map` when order matters
* Always check constraints before choosing container
