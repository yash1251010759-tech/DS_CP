# DS_CP
A C++-based Disease–Symptom Relationship Analyzer using multiple data structures, including vectors, hashing, heaps, and linked lists, to manage diseases, analyze symptom frequency, identify common symptoms, and find top-K symptoms.

# 🩺 Disease–Symptom Relationship Analyzer

A C++-based project that analyzes relationships between diseases and their associated symptoms using various Data Structures and Algorithms (DSA).

The project provides features for disease management, symptom analysis, frequency counting, and recent search history.

## ✨ Features

* **Display Diseases:** View all diseases and their associated symptoms.
* **Search Disease:** Search for a specific disease and view its symptoms.
* **Find Diseases by Symptom:** Identify diseases associated with a given symptom.
* **Common Symptoms:** Find symptoms shared by multiple diseases.
* **Symptom Frequency:** Count how many diseases are associated with each symptom.
* **Disease Management:** Add, update, and delete disease records.
* **Sort Diseases:** Display diseases in alphabetical order.
* **Sort Symptoms:** Rank symptoms by their frequency across diseases.
* **Top-K Symptoms:** Display the most frequently occurring symptoms.
* **Recent Search History:** Maintain a history of searched diseases using a Singly Linked List.

## 🛠️ Technologies Used

* **Language:** C++
* **Standard Library:** STL
* **IDE:** Visual Studio Code

## 🧠 Data Structures Used

| Data Structure     | Application                                               |
| ------------------ | --------------------------------------------------------- |
| Vector             | Store diseases and their symptoms                         |
| Hash Map           | Count symptom frequency                                   |
| Hash Set           | Avoid counting duplicate symptoms within the same disease |
| Sorting Algorithms | Sort diseases and rank symptoms                           |
| Singly Linked List | Maintain recent search history                            |

## 🚀 Getting Started

### Prerequisites

* A C++ compiler such as GCC or MinGW
* Visual Studio Code (optional)

### Installation

1. Clone the repository:

   ```bash
   git clone <YOUR_REPOSITORY_URL>
   ```

2. Navigate to the project directory:

   ```bash
   cd <YOUR_PROJECT_FOLDER>
   ```

3. Compile the source file:

   ```bash
   g++ main.cpp -o analyzer
   ```

4. Run the program:

   **Windows:**

   ```bash
   .\analyzer.exe
   ```

   **Linux/macOS:**

   ```bash
   ./analyzer
   ```

## 📂 Project Structure

```text
Disease-Symptom-Analyzer/
├── main.cpp
└── README.md
```

## 📊 Current Implementation

The project currently uses a sample educational dataset to demonstrate disease–symptom relationships and data structure operations.

New disease records and search history are maintained in memory during program execution. They are not yet persisted across program restarts.

## 🔮 Future Improvements

* Implement a Binary Search Tree (BST) for organizing and searching disease names.
* Implement a Graph to represent disease–symptom relationships.
* Add graph traversal algorithms such as BFS and DFS.
* Introduce file handling or database integration for persistent storage.
* Improve input validation and error handling.

## 🎯 Project Objective

The goal of this project is to apply fundamental Data Structures and Algorithms to a practical problem while developing a better understanding of data organization, searching, sorting, and relationship analysis.

---

**Developed as a C++ Data Structures and Algorithms project.**
