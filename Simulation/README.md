# 🚀 Simulation

This section contains problems that are solved by directly simulating the given process or system step-by-step.

---

## 🧠 What is Simulation?

Simulation involves mimicking the behavior of a system exactly as described in the problem, without relying on heavy optimizations.

The goal is simple:
👉 Follow the rules carefully  
👉 Track state changes correctly  
👉 Implement efficiently  

---

## 🔑 Key Patterns Covered

- Grid / Matrix Traversal  
- Directional Movement (4 & 8 directions)  
- Step-by-step state updates  
- Boundary-based movement  
- Real-world process simulation  

---

## 📂 Problems Included

### 1. Queens That Can Attack the King  
- **Pattern:** Simulation + Directional Traversal  
- **Idea:** Explore all 8 directions from the king to find attacking queens  

---

### 2. Champagne Tower  
- **Pattern:** Simulation + DP-like flow  
- **Idea:** Simulate overflow of liquid level by level  

---

### 3. Digit Sum Transformation  
- **Pattern:** Simulation + String Processing  
- **Idea:** Repeatedly transform digits until condition is met  

---

### 4. Robot Perimeter Movement  
- **Pattern:** Simulation + Math (Cycle Detection)  
- **Idea:**  
  - Robot moves along boundary in clockwise direction  
  - Movement repeats after completing one full perimeter  
  - Optimize using modulo with perimeter  
  - Handle edge case when steps = multiple of perimeter  

---

## 🎯 Why Simulation?

- Best when problem describes a **clear real-world process**  
- Easier to implement than complex algorithms  
- Builds strong **logic + attention to detail**  
- Common in **interviews for implementation skills**  

---

## ⚡ Key Takeaways

Use simulation when:
- The process is clearly defined step-by-step  
- State changes are important  
- Constraints allow direct implementation  

💡 Pro Tip:  
Always look for **hidden cycles** (like perimeter, rotations, repetition)  
→ This can reduce complexity from **O(n) to O(1)** 🚀
