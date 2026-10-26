# 🩺 Disease–Symptom Relationship Analyzer

A **C++-based Disease–Symptom Relationship Analyzer** developed as a Data Structures and Algorithms (DSA) project. The application manages disease records, analyzes symptom frequency, explores disease–symptom relationships using graphs, and demonstrates multiple data structures and algorithms.

The project integrates **Vectors, Hash Maps, Hash Sets, Singly Linked Lists, Binary Search Trees (BST), and Graphs** with file handling for persistent data storage.

> **Disclaimer:** This is an educational project intended to demonstrate data structures and algorithms. It is not a medical diagnosis system.

## ✨ Features

### 1. Disease Management

* Display all available diseases and their associated symptoms.
* Search for a specific disease.
* Find diseases associated with a particular symptom.
* Add new disease records.
* Update symptoms associated with existing diseases.
* Delete disease records.
* Prevent duplicate disease names during insertion.

### 2. Symptom Analysis

* Identify symptoms shared by multiple diseases.
* Calculate symptom frequency across diseases.
* Sort diseases alphabetically.
* Rank symptoms by frequency.
* Find the Top-K most frequent symptoms.
* Avoid counting duplicate symptoms within the same disease when calculating frequency.

### 3. Binary Search Tree (BST)

* Organize disease names using a Binary Search Tree.
* Search for a disease using the BST.
* Perform inorder traversal.
* Perform preorder traversal.
* Perform postorder traversal.
* Rebuild the BST when the disease dataset changes.

### 4. Graph Representation and Traversal

* Represent disease–symptom relationships using a bipartite graph.
* Display graph nodes and their connections.
* Perform Breadth-First Search (BFS).
* Perform Depth-First Search (DFS).
* Find diseases connected to a particular symptom using the graph.
* Rebuild the graph when disease records or symptoms change.

### 5. Search History

* Maintain recent search history using a Singly Linked List.
* Display the current session's search history.
* Save history entries to a file.
* View previously saved history entries.

### 6. File Handling and Reports

* Save disease records to `diseases.txt`.
* Load saved disease records when the application starts.
* Preserve disease data across program restarts.
* Store search history in `history.txt`.
* Generate a text report containing disease records and symptom frequency.
* Export reports to `report.txt`.

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Standard Library:** C++ STL
* **IDE:** Visual Studio Code
* **Data Storage:** Text files
* **Core Concepts:** Data Structures, Algorithms, Searching, Sorting, Graph Traversal, File Handling

## 🧠 Data Structures and Their Applications

| Data Structure / Algorithm | Application                                                                         |
| -------------------------- | ----------------------------------------------------------------------------------- |
| Vector                     | Stores disease records and their symptoms                                           |
| Hash Map (`unordered_map`) | Counts symptom frequency and represents graph adjacency lists                       |
| Hash Set (`unordered_set`) | Prevents duplicate symptom counting within a disease and tracks visited graph nodes |
| Sorting Algorithms         | Sorts disease names, graph nodes, and symptom frequency results                     |
| Singly Linked List         | Maintains recent search history                                                     |
| Binary Search Tree (BST)   | Organizes and searches disease names                                                |
| Graph                      | Represents relationships between diseases and symptoms                              |
| Queue                      | Supports BFS traversal                                                              |
| Recursion                  | Implements BST operations and DFS traversal                                         |
| File Handling              | Saves and loads disease data and search history, and generates reports              |

## 📂 Project Structure

```text
DS_CP/
├── main.cpp
├── diseases.txt
├── history.txt
├── report.txt
└── README.md
```

**Note:** `diseases.txt`, `history.txt`, and `report.txt` are generated or used by the application at runtime. Their presence in the repository depends on your local files and Git commits.

## 🚀 Getting Started

### Prerequisites

* A C++ compiler supporting C++11 or later.
* GCC/MinGW or another compatible C++ compiler.
* Visual Studio Code (recommended, but optional).

### 1. Clone the Repository

```bash
git clone https://github.com/yash1251010759-tech/DS_CP.git
```

### 2. Navigate to the Project Directory

```bash
cd DS_CP
```

### 3. Compile the Program

```bash
g++ -std=c++17 main.cpp -o analyzer
```

### 4. Run the Program

**Windows:**

```bash
.\analyzer.exe
```

**Linux/macOS:**

```bash
./analyzer
```

> **Important:** If your main source file has a different name, replace `main.cpp` in the compilation command with the correct filename.

## 💾 Data Persistence

The application supports file-based persistence through three text files:

| File           | Purpose                                             |
| -------------- | --------------------------------------------------- |
| `diseases.txt` | Stores disease names and their associated symptoms  |
| `history.txt`  | Stores search and graph-operation history entries   |
| `report.txt`   | Stores the exported disease–symptom analysis report |

When the application starts, it attempts to load disease records from `diseases.txt`. If the file cannot be loaded, the program uses its default sample dataset and attempts to save it.

Changes to disease records are saved to the dataset file. The BST and graph are rebuilt after changes to keep them synchronized with the in-memory dataset.

## 📋 Menu Options

The application provides the following menu operations:

| Option | Operation                    |
| -----: | ---------------------------- |
|      1 | Display all diseases         |
|      2 | Search disease               |
|      3 | Find diseases by symptom     |
|      4 | Find common symptoms         |
|      5 | Show symptom frequency       |
|      6 | Add disease                  |
|      7 | Delete disease               |
|      8 | Update disease symptoms      |
|      9 | Sort diseases                |
|     10 | Display Top-K symptoms       |
|     11 | View current search history  |
|     12 | BST inorder traversal        |
|     13 | BST preorder traversal       |
|     14 | BST postorder traversal      |
|     15 | Search disease using BST     |
|     16 | Display graph                |
|     17 | Graph BFS traversal          |
|     18 | Graph DFS traversal          |
|     19 | Search diseases using graph  |
|     20 | View saved history from file |
|     21 | Export analysis report       |
|     22 | Save dataset                 |
|     23 | Exit                         |

## 🎯 Project Objectives

* Apply fundamental and intermediate data structures to a practical problem.
* Understand the relationships between diseases and symptoms.
* Implement efficient searching and sorting techniques.
* Explore tree-based searching using a BST.
* Represent relationships through graph structures.
* Implement BFS and DFS graph traversal algorithms.
* Understand persistent data storage using file handling.
* Integrate multiple data structures into a single C++ application.

## 🔮 Future Improvements

* Implement individual BST node deletion instead of rebuilding the entire tree.
* Improve input validation and error handling.
* Add more efficient data retrieval and graph traversal features.
* Improve report formatting and analysis.
* Add comprehensive test cases for disease management and graph operations.
* Explore database integration for larger datasets.

## ⚠️ Limitations

* The application currently uses a sample educational dataset.
* Disease and symptom names are handled as text and are case-sensitive.
* The BST is rebuilt when disease data changes rather than being updated through individual BST insertion and deletion operations.
* The graph is maintained in memory and reconstructed from the disease dataset.
* The application does not provide medical advice or diagnose diseases.

## 👨‍💻 Project Information

**Project Name:** Disease–Symptom Relationship Analyzer
**Repository:** [DS_CP](https://github.com/yash1251010759-tech/DS_CP)
**Language:** C++
**Project Type:** Data Structures and Algorithms (DSA)

---

*Developed as an educational C++ project to demonstrate the practical application of data structures and algorithms.*
