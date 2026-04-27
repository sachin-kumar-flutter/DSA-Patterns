# 🔥 Boyer-Moore Voting Algorithm

## 🧠 What is this?
A powerful algorithm used to find elements that appear **more than a certain fraction of times** in an array.

It works using a clever idea:
👉 **Cancel out different elements to isolate the majority**

---

## 💡 Core Intuition
If an element appears more than ⌊n/k⌋ times, then:
- There can be **at most (k - 1)** such elements

We track:
- Candidates
- Their counts

And eliminate non-majority elements through cancellation.

---

## ⚡ General Pattern

| Case        | Max Candidates | Example |
|-------------|--------------|--------|
| n/2         | 1            | Majority Element |
| n/3         | 2            | Extended Majority |
| n/k         | k-1          | Generalized case |

---

## 🧩 Implemented Problems

### 1️⃣ Majority Element (n/2)
- Only one candidate possible
- Classic Boyer-Moore

### 2️⃣ Majority Element (n/3)
- Two candidates required
- Extended version of the algorithm

---

## 🚀 Algorithm Steps

### Phase 1: Find Candidate(s)
- Maintain candidate(s) and count(s)
- Increment if same
- Assign if count = 0
- Otherwise → cancel (decrement)

### Phase 2: Verification
- Count occurrences again
- Ensure they satisfy the condition

---

## ⏱️ Complexity
- Time: O(N)
- Space: O(1)

---

## 🧠 When to Use
Whenever you see:
- "Element appearing more than n/2"
- "More than n/3 times"
- "Frequent elements"

👉 Think:
**Boyer-Moore Voting Algorithm**

---

## 💬 Final Insight
This is not a greedy or hashmap problem.

👉 It’s a **mathematical cancellation technique**  
👉 Extremely important for interviews

---

## ✍️ Author
Sachin 🚀
