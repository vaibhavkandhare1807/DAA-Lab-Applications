# 🧠 Design and Analysis of Algorithms (DAA) – Lab Applications

**Course:** Design and Analysis of Algorithms (DAA)

**Language Used:** C++

**Semester:** III

**Submitted by:** *Vaibhav Maroti Kandhare*

**Roll No:** 24141024

**College/University:** Government College Of Engineering,Karad

### 💻 Concept + Real-world Implementations in C++

This repository contains all **DAA lab applications** implemented in **C++**.
Each experiment includes:

* A **simple version** — to understand the working of the algorithm.
* An **application version** — demonstrating how the algorithm is used in real-life or practical scenarios.

---

## 📚 List of Applications

| Sr. No. | Application Title                    | Algorithm Used                              | Files                                                       |
| ------- | ------------------------------------ | ------------------------------------------- | ----------------------------------------------------------- |
| 01      | Customer Database Search Application | Binary Search (Divide and Conquer)          | `simple_binary_search.cpp`, `binary_search_customer.cpp`    |
| 02      | Product Price Sorting Application    | Quick Sort (Divide and Conquer)             | `simple_quick_sort.cpp`, `quick_sort_products.cpp`          |
| 03      | Cargo Loading Optimization System    | Fractional Knapsack (Greedy Method)         | `simple_fractional_knapsack.cpp`, `fractional_knapsack.cpp` |
| 04      | File Merge Cost Analyzer             | Optimal Merge Pattern (Greedy Method)       | `simple_optimal_merge.cpp`, `optimal_merge_pattern.cpp`     |
| 05      | Office Network Cost Minimizer        | Kruskal’s Algorithm (Minimum Spanning Tree) | `simple_kruskal.cpp`, `kruskal_mst.cpp`                     |
| 06      | City Travel Distance Finder          | Dijkstra’s Algorithm (Shortest Path)        | `simple_dijkstra.cpp`, `dijkstra_shortest_path.cpp`         |

---

## ⚙️ How to Compile and Run

Each program can be compiled individually using `g++`:

```bash
# Example for running simple and application versions
g++ Experiment-01_BinarySearch/simple_binary_search.cpp -o simple_search
./simple_search

g++ Experiment-01_BinarySearch/binary_search_customer.cpp -o app_search
./app_search
```

---

## 🧾 Example Output

### Application 01 – Customer Database Search

```
Enter number of customers: 3
Enter customer details (ID Name):
101 John
102 Alice
103 Bob
Enter Customer ID to search: 102
Customer Found: Alice (ID: 102)
```

### Application 03 – Cargo Loading Optimization

```
Enter number of cargo items: 3
Enter truck capacity: 50
Enter cargo details (ID Name Weight Value):
1 Iron 10 60
2 Copper 20 100
3 Gold 30 120
Total Value Loaded: 240
Unused Capacity: 0
---
