# 📈 Stock Buy & Sell Problems

> “Buy low, sell high… but do it smart.” 💰

A classic set of problems that teach **greedy thinking, optimization, and dynamic decision making**.

---

## 🧠 Why These Problems Matter?

Stock problems are not just about prices — they teach:

* Decision making under constraints ⚖️
* Greedy strategies 🧠
* Transition to Dynamic Programming 🔄

These are **must-know interview patterns**.

---

## ⚙️ Variants Covered

### 1️⃣ Single Transaction (Best Time to Buy & Sell Stock) ⭐

* Only **one buy + one sell**
* Track **minimum price so far**

⏱️ Time: `O(n)`
💾 Space: `O(1)`

---

### 2️⃣ Multiple Transactions ⭐⭐

* Unlimited buys & sells
* Capture **every increasing slope**

⏱️ Time: `O(n)`
💾 Space: `O(1)`

---

## 📂 Folder Structure

```bash id="8t6rdm"
stock_problems/
├── best_time_buy_sell_stock_1.cpp
├── best_time_buy_sell_stock_2.cpp
```

---

## 🎯 Core Idea

* Don’t overcomplicate:

  * If profit exists → take it
  * If better opportunity later → wait

---

## 🧩 Pattern Progression

| Version  | Idea           | Technique    |
| -------- | -------------- | ------------ |
| Stock 1  | 1 transaction  | Min tracking |
| Stock 2  | Unlimited      | Greedy       |
| Stock 3  | At most 2      | DP           |
| Stock k  | k transactions | DP           |
| Cooldown | Constraints    | DP           |

💡 These problems evolve — mastering basics is key.

---

## 🚀 When to Use?

* When asked about **buy/sell decisions**
* When choices depend on **future profit**
* When you need **greedy optimization**

---

## ⚠️ Common Mistakes

* Trying brute force ❌
* Missing simple greedy insight ❌
* Overthinking transitions ❌

---

## 🔥 Interview Tip

If you say:

> “This is a greedy problem — we track min price or accumulate profit”

You instantly sound structured and confident.

---

## 🏁 Final Thought

Stock problems look easy…
but they quietly test:

> 👉 Greedy intuition
> 👉 Optimization thinking
> 👉 Problem pattern recognition

Master these, and harder DP versions become easier.

---

⭐ Star the repo if this helped!
