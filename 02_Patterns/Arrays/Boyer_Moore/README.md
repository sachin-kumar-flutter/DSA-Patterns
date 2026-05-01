# 🗳️ Boyer–Moore Voting Algorithm

> “When elements fight, the majority survives.” ⚔️

A powerful pattern to find majority elements in **linear time and constant space** — one of the smartest tricks in array problems.

---

## 🧠 What is Boyer–Moore?

It’s a **voting algorithm** where:

* Different elements cancel each other ❌
* The dominant element survives ✅

Instead of counting everything, we **eliminate noise**.

---

## ⚙️ Variants Covered

### 1️⃣ Majority Element (> n/2) ⭐

* Only **one majority element possible**
* Use **one candidate + count**

⏱️ Time: `O(n)`
💾 Space: `O(1)`

---

### 2️⃣ Majority Element (> n/3) ⭐⭐

* At most **two elements possible**
* Use **two candidates + counts**
* Requires **verification pass**

⏱️ Time: `O(n)`
💾 Space: `O(1)`

---

## 📂 Folder Structure

```bash id="4f7xcs"
boyer_moore/
├── majority_element_n_by_2.cpp
├── majority_element_n_by_3.cpp
```

---

## 🎯 Core Idea

* Pair up **different elements → cancel them**
* Only elements with **high frequency survive**
* Final candidates must be **verified**

---

## 🧩 Generalization

| Condition | Max Candidates |
| --------- | -------------- |
| > n/2     | 1              |
| > n/3     | 2              |
| > n/k     | k - 1          |

💡 This pattern scales — that’s what makes it powerful.

---

## 🚀 When to Use?

Use Boyer–Moore when:

* You need **O(1) space**
* You suspect a **majority element exists**
* Hashmap feels like overkill

---

## ⚠️ Common Mistake

> “Candidate = answer” ❌

Always verify in second pass (except n/2 case when guaranteed).

---

## 🔥 Interview Tip

If asked:

👉 “Can you do it without extra space?”

This is your moment. Drop Boyer–Moore and watch the interviewer lean forward 😄

---

## 🏁 Final Thought

This algorithm looks simple…
but the idea behind it is deep:

> 👉 Eliminate instead of counting
> 👉 Think in terms of dominance

Master this, and you unlock a whole new way of thinking.

---

⭐ Star the repo if this helped!
