# 🧠 Design and Analysis of Algorithms (DAA) – Lab Applications
## 🧑‍🏫 Course Information

**Course:** Design and Analysis of Algorithms (DAA)
**Language Used:** C++
**Semester:** III
**Submitted by:** *Vaibhav Maroti Kandhare*
**Roll No:** 24141024
**Batch:** I2

### 💻 C++ Implementations (Concept + Real-world Applications)

This repository contains all **Design and Analysis of Algorithms (DAA)** lab applications implemented in **C++**.
Each experiment includes two parts:

* 🧩 **Concept Program:** A simple version demonstrating algorithm logic.
* 🚀 **Application Program:** A real-world problem using that algorithm.

---

## 📚 Experiment List with Explanations

| Experiment No. | Application Title           | Algorithms Implemented              | Files                                                                                    | Description                                                                                                                               |
| -------------- | --------------------------- | ----------------------------------- | ---------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| **01**         | Customer Database Search    | Binary Search                       | `BinarySearch.cpp`, `ApplicationBinary.cpp`                                              | A customer management application that allows quick searching of customer details based on their unique ID from a sorted database.        |
| **02**         | Product Sorting System      | Quick Sort, Merge Sort              | `QuickSort.cpp`, `MergeSort.cpp`, `ApplicationQuickSort.cpp`, `ApplicationMergeSort.cpp` | A product catalog management tool that arranges items by name or price to simplify product listing and comparison.                        |
| **03**         | Cargo Loading Optimization  | Fractional Knapsack                 | `Knapsack.cpp`, `ApplicationKnapsack.cpp`                                                | A logistics application that helps determine which cargo items to load into a truck to maximize value while staying within weight limits. |
| **04**         | File Merge Cost Minimizer   | Optimal Merge Pattern               | `OptimalMerge.cpp`, `ApplicationOptimalMerge.cpp`                                        | A file-handling system that calculates the least total cost required to merge several data files efficiently.                             |
| **05**         | Minimum Network Cost Finder | Kruskal’s and Prim’s MST Algorithms | `KruskalAlgo.cpp`, `PrimsAlgo.cpp`, `Application.cpp`                                    | A network design application used to plan the cheapest possible way to connect multiple offices or cities with minimal cable cost.        |
| **06**         | Shortest Path Finder        | Dijkstra’s Algorithm                | `DijkstraAlgo.cpp`, `ApplicationDijkstra.cpp`                                            | A city travel planner that finds the shortest distance between one source city and all other cities for route optimization.               |

---

## ⚙️ How to Compile and Run

Each experiment can be compiled and executed independently using any standard **C++ compiler**.

### Example (Windows / Linux):

```bash
# Compile and run a simple version
g++ Experiment_01/BinarySearch.cpp -o BinarySearch
./BinarySearch

# Compile and run the application version
g++ Experiment_01/ApplicationBinary.cpp -o ApplicationBinary
./ApplicationBinary
```

---

## 🧾 Sample Output (Example)

### Experiment 01 – Binary Search

```
Enter number of elements: 5
1 3 5 7 9
Enter element to search: 5
Element found at position 3
```

### Experiment 03 – Knapsack Application

```
Enter number of items: 3
Enter weight and value for each item:
10 60
20 100
30 120
Enter capacity: 50
Maximum value achievable: 240