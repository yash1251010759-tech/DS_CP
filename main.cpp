#include <bits/stdc++.h>
using namespace std;

// Educational project only; this is not a medical diagnosis system.

struct Disease {
    string name;
    vector<string> symptoms;
};

struct TreeNode {
    string name;
    TreeNode *left, *right;

    TreeNode(string n) : name(n), left(NULL), right(NULL) {}
};

struct HistoryNode {
    string entry;
    HistoryNode* next;

    HistoryNode(string e) : entry(e), next(NULL) {}
};

HistoryNode* historyHead = NULL;

// ==================== BST ====================

TreeNode* insertDisease(TreeNode* root, string name) {
    if (root == NULL)
        return new TreeNode(name);

    if (name < root->name)
        root->left = insertDisease(root->left, name);
    else if (name > root->name)
        root->right = insertDisease(root->right, name);

    return root;
}

void deleteBST(TreeNode* root) {
    if (root == NULL) return;

    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

TreeNode* buildBST(const vector<Disease>& diseases) {
    TreeNode* root = NULL;

    for (const auto& d : diseases)
        root = insertDisease(root, d.name);

    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->name << '\n';
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->name << '\n';
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->name << '\n';
}

TreeNode* searchBST(TreeNode* root, string name) {
    if (!root || root->name == name)
        return root;

    if (name < root->name)
        return searchBST(root->left, name);

    return searchBST(root->right, name);
}

// ==================== FILE HANDLING ====================

// File format:
// Disease name
// Number of symptoms
// Symptom 1
// Symptom 2
// ...

bool saveDiseases(const vector<Disease>& diseases) {
    ofstream file("diseases.txt");

    if (!file) {
        cout << "Unable to save diseases.txt\n";
        return false;
    }

    for (const auto& d : diseases) {
        file << d.name << '\n';
        file << d.symptoms.size() << '\n';

        for (const auto& s : d.symptoms)
            file << s << '\n';
    }

    return true;
}

bool loadDiseases(vector<Disease>& diseases) {
    ifstream file("diseases.txt");

    if (!file) return false;

    vector<Disease> loaded;
    string name, countLine;

    while (getline(file, name)) {
        if (name.empty()) continue;

        if (!getline(file, countLine))
            return false;

        int count;

        try {
            count = stoi(countLine);
        } catch (...) {
            return false;
        }

        if (count < 0 || count > 1000)
            return false;

        Disease d;
        d.name = name;

        for (int i = 0; i < count; i++) {
            string symptom;

            if (!getline(file, symptom))
                return false;

            d.symptoms.push_back(symptom);
        }

        loaded.push_back(d);
    }

    if (loaded.empty())
        return false;

    diseases = loaded;
    return true;
}

void saveHistoryEntry(string entry) {
    ofstream file("history.txt", ios::app);

    if (file)
        file << entry << '\n';
}

void addToHistory(string entry) {
    HistoryNode* node = new HistoryNode(entry);
    node->next = historyHead;
    historyHead = node;

    saveHistoryEntry(entry);
}

void displayHistory() {
    cout << "\n===== CURRENT SESSION HISTORY =====\n";

    if (!historyHead) {
        cout << "No history available.\n";
        return;
    }

    for (HistoryNode* temp = historyHead;
         temp != NULL; temp = temp->next) {
        cout << temp->entry << '\n';
    }
}

void showSavedHistory() {
    ifstream file("history.txt");
    string line;

    cout << "\n===== SAVED HISTORY =====\n";

    if (!file) {
        cout << "No saved history file found.\n";
        return;
    }

    while (getline(file, line))
        cout << line << '\n';
}

// ==================== GRAPH ====================

// Bipartite graph: Disease nodes <-> Symptom nodes.

unordered_map<string, vector<string>> graph;

string diseaseNode(string name) {
    return "Disease: " + name;
}

string symptomNode(string name) {
    return "Symptom: " + name;
}

void buildGraph(const vector<Disease>& diseases) {
    graph.clear();

    for (const auto& d : diseases) {
        string dn = diseaseNode(d.name);
        graph[dn];

        unordered_set<string> used;

        for (const auto& s : d.symptoms) {
            if (!used.insert(s).second)
                continue;

            string sn = symptomNode(s);

            graph[dn].push_back(sn);
            graph[sn].push_back(dn);
        }
    }
}

void displayGraph() {
    cout << "\n===== DISEASE-SYMPTOM GRAPH =====\n";

    vector<string> nodes;

    for (const auto& p : graph)
        nodes.push_back(p.first);

    sort(nodes.begin(), nodes.end());

    for (const auto& node : nodes) {
        cout << node << " -> ";

        vector<string> neighbours = graph[node];
        sort(neighbours.begin(), neighbours.end());

        for (size_t i = 0; i < neighbours.size(); i++) {
            if (i) cout << ", ";
            cout << neighbours[i];
        }

        cout << '\n';
    }
}

// BFS traversal

void graphBFS() {
    string name;

    cout << "Enter disease name: ";
    getline(cin >> ws, name);

    string start = diseaseNode(name);

    if (!graph.count(start)) {
        cout << "Disease not found in graph.\n";
        return;
    }

    queue<string> q;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(start);

    cout << "\nBFS Traversal:\n";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        cout << current << '\n';

        vector<string> neighbours = graph[current];
        sort(neighbours.begin(), neighbours.end());

        for (const auto& next : neighbours) {
            if (!visited.count(next)) {
                visited.insert(next);
                q.push(next);
            }
        }
    }

    addToHistory("BFS: " + name);
}

// DFS traversal

void dfsVisit(string node, unordered_set<string>& visited) {
    visited.insert(node);
    cout << node << '\n';

    vector<string> neighbours = graph[node];
    sort(neighbours.begin(), neighbours.end());

    for (const auto& next : neighbours) {
        if (!visited.count(next))
            dfsVisit(next, visited);
    }
}

void graphDFS() {
    string name;

    cout << "Enter disease name: ";
    getline(cin >> ws, name);

    string start = diseaseNode(name);

    if (!graph.count(start)) {
        cout << "Disease not found in graph.\n";
        return;
    }

    unordered_set<string> visited;

    cout << "\nDFS Traversal:\n";
    dfsVisit(start, visited);

    addToHistory("DFS: " + name);
}

// Search diseases using graph

void graphSymptomSearch() {
    string symptom;

    cout << "Enter symptom: ";
    getline(cin >> ws, symptom);

    string node = symptomNode(symptom);

    if (!graph.count(node)) {
        cout << "Symptom not found in graph.\n";
        return;
    }

    cout << "\nDiseases connected to " << symptom << ":\n";

    for (const auto& neighbour : graph[node]) {
        if (neighbour.find("Disease: ") == 0)
            cout << neighbour.substr(9) << '\n';
    }

    addToHistory("Graph symptom search: " + symptom);
}

// ==================== DISEASE FUNCTIONS ====================

void displayDiseases(const vector<Disease>& diseases) {
    cout << "\n===== ALL DISEASES =====\n";

    for (const auto& d : diseases) {
        cout << "\nDisease: " << d.name << "\nSymptoms: ";

        for (size_t i = 0; i < d.symptoms.size(); i++) {
            if (i) cout << ", ";
            cout << d.symptoms[i];
        }

        cout << '\n';
    }

    if (diseases.empty())
        cout << "No diseases available.\n";
}

void searchDisease(const vector<Disease>& diseases) {
    string name;

    cout << "Enter disease name: ";
    getline(cin >> ws, name);

    for (const auto& d : diseases) {
        if (d.name == name) {
            cout << "Disease found: " << d.name << "\nSymptoms: ";

            for (size_t i = 0; i < d.symptoms.size(); i++) {
                if (i) cout << ", ";
                cout << d.symptoms[i];
            }

            cout << '\n';
            addToHistory("Disease search: " + name);
            return;
        }
    }

    cout << "Disease not found.\n";
}

void findDiseasesBySymptom(const vector<Disease>& diseases) {
    string symptom;
    bool found = false;

    cout << "Enter symptom: ";
    getline(cin >> ws, symptom);

    for (const auto& d : diseases) {
        if (find(d.symptoms.begin(), d.symptoms.end(), symptom)
            != d.symptoms.end()) {
            cout << d.name << '\n';
            found = true;
        }
    }

    if (!found)
        cout << "No matching diseases found.\n";
    else
        addToHistory("Symptom search: " + symptom);
}

unordered_map<string, int> getFrequency(
    const vector<Disease>& diseases) {

    unordered_map<string, int> frequency;

    for (const auto& d : diseases) {
        unordered_set<string> uniqueSymptoms(
            d.symptoms.begin(), d.symptoms.end());

        for (const auto& s : uniqueSymptoms)
            frequency[s]++;
    }

    return frequency;
}

void commonSymptoms(const vector<Disease>& diseases) {
    auto frequency = getFrequency(diseases);
    bool found = false;

    cout << "\n===== COMMON SYMPTOMS =====\n";

    for (const auto& p : frequency) {
        if (p.second >= 2) {
            cout << p.first << " appears in "
                 << p.second << " diseases.\n";
            found = true;
        }
    }

    if (!found)
        cout << "No common symptoms found.\n";
}

void symptomFrequency(const vector<Disease>& diseases) {
    auto frequency = getFrequency(diseases);

    vector<pair<string, int>> result(
        frequency.begin(), frequency.end());

    sort(result.begin(), result.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

    cout << "\n===== SYMPTOM FREQUENCY =====\n";

    for (const auto& p : result)
        cout << p.first << " : "
             << p.second << " diseases\n";
}

void addDisease(vector<Disease>& diseases) {
    Disease d;

    cout << "Enter new disease name: ";
    getline(cin >> ws, d.name);

    for (const auto& old : diseases) {
        if (old.name == d.name) {
            cout << "Disease already exists.\n";
            return;
        }
    }

    int n;

    cout << "Enter number of symptoms: ";

    if (!(cin >> n) || n <= 0 || n > 100) {
        cout << "Invalid number of symptoms.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        string symptom;

        cout << "Enter symptom " << i + 1 << ": ";
        getline(cin >> ws, symptom);

        if (!symptom.empty())
            d.symptoms.push_back(symptom);
    }

    diseases.push_back(d);
    cout << "Disease added successfully.\n";
}

void deleteDisease(vector<Disease>& diseases) {
    string name;

    cout << "Enter disease name to delete: ";
    getline(cin >> ws, name);

    auto it = find_if(diseases.begin(), diseases.end(),
        [&](const Disease& d) {
            return d.name == name;
        });

    if (it == diseases.end()) {
        cout << "Disease not found.\n";
        return;
    }

    diseases.erase(it);
    cout << "Disease deleted successfully.\n";
}

void updateDisease(vector<Disease>& diseases) {
    string name;

    cout << "Enter disease name to update: ";
    getline(cin >> ws, name);

    auto it = find_if(diseases.begin(), diseases.end(),
        [&](const Disease& d) {
            return d.name == name;
        });

    if (it == diseases.end()) {
        cout << "Disease not found.\n";
        return;
    }

    int n;

    cout << "Enter new number of symptoms: ";

    if (!(cin >> n) || n <= 0 || n > 100) {
        cout << "Invalid number of symptoms.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    vector<string> updated;

    for (int i = 0; i < n; i++) {
        string symptom;

        cout << "Enter symptom " << i + 1 << ": ";
        getline(cin >> ws, symptom);

        if (!symptom.empty())
            updated.push_back(symptom);
    }

    it->symptoms = updated;
    cout << "Symptoms updated successfully.\n";
}

void sortDiseases(vector<Disease>& diseases) {
    sort(diseases.begin(), diseases.end(),
        [](const Disease& a, const Disease& b) {
            return a.name < b.name;
        });

    for (const auto& d : diseases)
        cout << d.name << '\n';
}

void topKSymptoms(const vector<Disease>& diseases) {
    auto frequency = getFrequency(diseases);

    vector<pair<string, int>> result(
        frequency.begin(), frequency.end());

    sort(result.begin(), result.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

    int k;

    cout << "Enter K: ";

    if (!(cin >> k) || k <= 0) {
        cout << "K must be positive.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    k = min(k, (int)result.size());

    for (int i = 0; i < k; i++)
        cout << result[i].first << " : "
             << result[i].second << " diseases\n";
}

void exportReport(const vector<Disease>& diseases) {
    ofstream file("report.txt");

    if (!file) {
        cout << "Unable to create report.txt\n";
        return;
    }

    file << "DISEASE-SYMPTOM RELATIONSHIP REPORT\n\n";

    for (const auto& d : diseases) {
        file << "Disease: " << d.name << "\nSymptoms: ";

        for (size_t i = 0; i < d.symptoms.size(); i++) {
            if (i) file << ", ";
            file << d.symptoms[i];
        }

        file << "\n\n";
    }

    auto frequency = getFrequency(diseases);

    file << "SYMPTOM FREQUENCY\n";

    for (const auto& p : frequency)
        file << p.first << " : "
             << p.second << " diseases\n";

    cout << "Report saved to report.txt\n";
}

// ==================== MENU ====================

int main() {
    vector<Disease> diseases = {
        {"Disease A", {"Fever", "Cough", "Fatigue"}},
        {"Disease B", {"Fever", "Headache", "Fatigue"}},
        {"Disease C", {"Cough", "Nausea", "Fatigue"}},
        {"Disease D", {"Fever", "Headache", "Nausea"}},
        {"Disease E", {"Cough", "Fatigue", "Headache"}}
    };

    if (loadDiseases(diseases)) {
        cout << "Loaded diseases.txt successfully.\n";
    } else {
        cout << "Using default dataset.\n";
        saveDiseases(diseases);
    }

    TreeNode* root = buildBST(diseases);
    buildGraph(diseases);

    int choice;

    do {
        cout << "\n============================================\n";
        cout << " DISEASE-SYMPTOM RELATIONSHIP ANALYZER\n";
        cout << "============================================\n";
        cout << "1. Display all diseases\n";
        cout << "2. Search disease\n";
        cout << "3. Find diseases by symptom\n";
        cout << "4. Find common symptoms\n";
        cout << "5. Show symptom frequency\n";
        cout << "6. Add disease\n";
        cout << "7. Delete disease\n";
        cout << "8. Update disease symptoms\n";
        cout << "9. Sort diseases\n";
        cout << "10. Top K symptoms\n";
        cout << "11. View current search history\n";
        cout << "12. BST inorder traversal\n";
        cout << "13. BST preorder traversal\n";
        cout << "14. BST postorder traversal\n";
        cout << "15. Search disease using BST\n";
        cout << "16. Display graph\n";
        cout << "17. Graph BFS traversal\n";
        cout << "18. Graph DFS traversal\n";
        cout << "19. Search diseases using graph\n";
        cout << "20. Show saved history from file\n";
        cout << "21. Export report\n";
        cout << "22. Save dataset\n";
        cout << "23. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        bool changed = false;

        switch (choice) {
            case 1:
                displayDiseases(diseases);
                break;

            case 2:
                searchDisease(diseases);
                break;

            case 3:
                findDiseasesBySymptom(diseases);
                break;

            case 4:
                commonSymptoms(diseases);
                break;

            case 5:
                symptomFrequency(diseases);
                break;

            case 6: {
                size_t oldSize = diseases.size();
                addDisease(diseases);
                changed = diseases.size() != oldSize;
                break;
            }

            case 7: {
                size_t oldSize = diseases.size();
                deleteDisease(diseases);
                changed = diseases.size() != oldSize;
                break;
            }

            case 8:
                updateDisease(diseases);
                changed = true;
                break;

            case 9:
                sortDiseases(diseases);
                changed = true;
                break;

            case 10:
                topKSymptoms(diseases);
                break;

            case 11:
                displayHistory();
                break;

            case 12:
                inorder(root);
                break;

            case 13:
                preorder(root);
                break;

            case 14:
                postorder(root);
                break;

            case 15: {
                string name;

                cout << "Enter disease name: ";
                getline(cin >> ws, name);

                if (searchBST(root, name)) {
                    cout << "Disease found in BST.\n";
                    addToHistory("BST search: " + name);
                } else {
                    cout << "Disease not found in BST.\n";
                }
                break;
            }

            case 16:
                displayGraph();
                break;

            case 17:
                graphBFS();
                break;

            case 18:
                graphDFS();
                break;

            case 19:
                graphSymptomSearch();
                break;

            case 20:
                showSavedHistory();
                break;

            case 21:
                exportReport(diseases);
                break;

            case 22:
                if (saveDiseases(diseases))
                    cout << "Dataset saved successfully.\n";
                break;

            case 23:
                saveDiseases(diseases);
                cout << "Dataset saved. Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Select 1-23.\n";
        }

        if (changed) {
            saveDiseases(diseases);

            deleteBST(root);
            root = buildBST(diseases);

            buildGraph(diseases);

            cout << "Dataset, BST, and graph updated.\n";
        }

    } while (choice != 23);

    deleteBST(root);

    while (historyHead) {
        HistoryNode* next = historyHead->next;
        delete historyHead;
        historyHead = next;
    }

    return 0;
}