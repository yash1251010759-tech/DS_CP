#include <bits/stdc++.h>
using namespace std;

// structure of diseases
struct Disease {
string name;
vector<string> symptoms;
};

struct TreeNode{
    string diseaseName;
    TreeNode* left;
    TreeNode *right;

    TreeNode(string name){
        diseaseName=name;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertDisease(TreeNode* root, string name){
    if(root == NULL){
        return new TreeNode(name);
    }
    else if(name<root->diseaseName){
        root->left= insertDisease(root->left,name);
    }
    else if(name>root->diseaseName){
        root->right= insertDisease(root->right,name);
    }

    return root;
}

void inorderTraversal(TreeNode* root){
    if(root == NULL){
        return ;
    }
    inorderTraversal(root->left);
    cout << root->diseaseName << endl;
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root){
    if(root == NULL){
        return ;
    }
    cout << root->diseaseName << endl;
    preorderTraversal(root->left);
    
    preorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root){
    if(root == NULL){
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->diseaseName << endl;
    
}

TreeNode* searchDiseaseBST(TreeNode* root,string name){
    if(root == NULL){
        return NULL;
    }
    else if(name == root->diseaseName){
        return root;
    }
    else if(name< root->diseaseName){
        return searchDiseaseBST(root->left,name);
    }
    else{
        return searchDiseaseBST(root->right,name);
    }
}

void addToHistory(string name);

// structure of linked list
struct HistoryNode{
    string diseaseName;
    HistoryNode* next;
};
HistoryNode* historyHead = NULL;

// Display all diseases
void displayDiseases(const vector<Disease>& diseases) {
cout << "\n========== ALL DISEASES ==========\n";

                    
for (int i = 0; i < diseases.size(); i++) {
    cout << "\nDisease: " << diseases[i].name << "\n";
    cout << "Symptoms: ";

    for (int j = 0; j < diseases[i].symptoms.size(); j++) {
        cout << diseases[i].symptoms[j];

        if (j + 1 < diseases[i].symptoms.size()) {
            cout << ", ";
        }
    }

    cout << "\n";
}


}

void searchDiseases(const vector<Disease>& diseases){
    string userDisease;
    bool found = false;

    cout << "\n Enter disease name :" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userDisease);

    for(int i=0;i<diseases.size();i++){
        if(diseases[i].name==userDisease){
            addToHistory(diseases[i].name);
            found = true;
            cout << "Disease found :" << diseases[i].name << endl;
            cout << "Symptoms :";

            for(int j=0;j<diseases[i].symptoms.size();j++){
                cout << diseases[i].symptoms[j];

                if(j+1<diseases[i].symptoms.size()){
                    cout << ", ";
                }
            }
        }
    }

    if(!found){
        cout << "Disease not found in the dataset." << endl;
    }

}


void findDiseasesBySymptom(const vector<Disease>& diseases){
    string userSymptom;
    bool found = false;
    cout << "\nenter symptom :";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userSymptom);

    for(int i=0;i<diseases.size();i++){
        for(int j=0;j<diseases[i].symptoms.size();j++){
            if(diseases[i].symptoms[j]==userSymptom){
            found = true;
            cout << "Disease containing " << userSymptom << " :" << diseases[i].name << endl;
            }
        }
    }
    if(! found){
        cout << "Symptom not found." << endl;
    }
}

void addDisease(vector<Disease>& diseases){
    Disease d;
    string newDisease;
    
    
    

    cout << "Enter the new disease name :";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,newDisease);

    
    int n;
    cout << "enter the number of symptoms :";
    cin >> n;
    

    if (n <= 0) {
    cout << "Number of symptoms must be positive.";
    return;
    }

    vector<string> newSymptoms(n);

    cout << "enter the symptoms : ";
    for(int i=0;i<n;i++){
        cin >> newSymptoms[i];
    }
    d.name=newDisease;
    d.symptoms = newSymptoms;
    diseases.push_back(d);

    cout << "New disease added successfully!" << endl;
}


void commonSymptoms(const vector<Disease>& diseases){
    unordered_map<string,int> frequency;

    // count how many times each symptom appears across all diseases
    for(int i=0;i<diseases.size();i++){
        unordered_set<string> counted;
        for(int j=0;j<diseases[i].symptoms.size();j++){
            string symptom=diseases[i].symptoms[j];
            

            if(counted.insert(symptom).second){
               frequency[symptom]++;
            }
        }
    }
    cout << "\n =====COMMON SYMPTOMS=====\n";

    bool found =false;

    for(const auto& entry : frequency){
        if(entry.second >=2){
            cout << entry.first << " appears in " << entry.second << " diseases.\n";
            found =true;
        }
    }

    if(!found){
        cout << "No common symptoms found .\n";
    }
}

void symptomFrequency(const vector<Disease>& diseases){
       unordered_map<string,int> frequency;

       for(int i=0;i<diseases.size();i++){
            unordered_set<string> counted;
            for(int j=0;j<diseases[i].symptoms.size();j++){
                string symptom=diseases[i].symptoms[j];
                if(counted.insert(symptom).second){
                    frequency[symptom]++;
                }
            }
       }

       cout << "\n======SYMPTOM FREQUENCY=====\n";

       if(frequency.empty()){
        cout << "No symptoms available  in the dataset.\n";
        return ;
       }

       for(const auto& entry : frequency){
        cout << entry.first << " : " << entry.second << " diseases\n" ;
       }
}

void deleteDisease(vector<Disease>& diseases) {
string diseaseName;


cout << "Enter the name of the disease to be deleted: ";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, diseaseName);

bool found = false;

for (int i = 0; i < diseases.size(); i++) {
    if (diseases[i].name == diseaseName) {
        found = true;

        diseases.erase(diseases.begin() + i);

        cout << "Disease " << diseaseName
             << " deleted successfully!" << endl;

        break;
    }
}

if (!found) {
    cout << "Disease " << diseaseName
         << " was not found." << endl;
  }
}

void updateDisease(vector<Disease>& diseases){

    string diseaseName;


    cout << "Enter the name of the disease to be updated: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, diseaseName);

    bool found = false;

    for (int i = 0; i < diseases.size(); i++) {
    if (diseases[i].name == diseaseName) {
        found = true;
        int count;
        cout << "Enter the number of new symptoms of the "<< diseaseName << " that need to be updated : ";
        cin >> count; 

        if (count <= 0) {
        cout << "Number of symptoms must be positive.";
        return;
        }


        vector<string>s(count);
        cout << "\nEnter the new symptoms : ";
        for(int j=0;j<count;j++){
                cin >> s[j];
        }

        diseases[i].symptoms=s;

        cout << "\nThe updated Disease : " << diseases[i].name << " : " ;
        for(int k=0;k<diseases[i].symptoms.size();k++){
            cout << diseases[i].symptoms[k] << " ";
        }

        cout << endl;

        cout << "Disease " << diseaseName
             << " updated  successfully!" << endl;

        break;
    }
}
    if(!found){
        cout << "Disease " << diseaseName << " is not found. " << endl;
    }

}

void sortDiseases(vector<Disease>& diseases){
    sort(diseases.begin(),diseases.end(),[](const Disease& a, const Disease& b) {
    return a.name < b.name;
});
    cout << "The disease in the sorted order are :\n";
    for(int i=0;i<diseases.size();i++){
        cout << diseases[i].name << "\n";
    }
    
}

void sortSymptoms(vector<Disease>& diseases){
    unordered_map<string,int> frequency;

       for(int i=0;i<diseases.size();i++){
            unordered_set<string> counted;
            for(int j=0;j<diseases[i].symptoms.size();j++){
                string symptom=diseases[i].symptoms[j];
                if(counted.insert(symptom).second){
                    frequency[symptom]++;
                }
            }
       }

       vector<pair<string, int>> ans;
       for(auto& entry : frequency){
        ans.push_back({entry.first,entry.second});
       }

       sort(ans.begin(), ans.end(),
    [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }

        return a.first < b.first;
    }
);

       for(const auto& entry : ans){
        cout << entry.first << " : " << entry.second << " diseases\n" ;
       }
}

void topKsymptoms(vector<Disease>& diseases){
    unordered_map<string,int> frequency;

       for(int i=0;i<diseases.size();i++){
            unordered_set<string> counted;
            for(int j=0;j<diseases[i].symptoms.size();j++){
                string symptom=diseases[i].symptoms[j];
                if(counted.insert(symptom).second){
                    frequency[symptom]++;
                }
            }
       }

       vector<pair<string, int>> ans;
       for(auto& entry : frequency){
        ans.push_back({entry.first,entry.second});
       }

       sort(ans.begin(), ans.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
         if (a.second != b.second) {
             return a.second > b.second;
         }

         return a.first < b.first;
        });

    if (ans.empty()) {
        cout << "No symptoms available.\n";
        return;
    }

       int k;

       cout << "Enter the value of k : ";
       cin >> k;

       cout << endl;
       if (k <= 0) {
        cout << "K must be positive.\n";
        return;
        }

        k = min(k, (int)ans.size()); 
        
       for(int i=0;i<k;i++){
        cout << ans[i].first << " : " << ans[i].second << " diseases\n" ;
       }
}

void addToHistory(string name){
    HistoryNode* newNode=new HistoryNode;

    newNode->diseaseName = name;
    newNode->next = historyHead;

    historyHead = newNode;
}

void displayHistory(){
    if(historyHead == NULL){
        cout << "\nNo search history is available!\n";
        return ;
    }
    HistoryNode* temp=historyHead;

    cout << "\n=====RECENT SEARCH HISTORY=====\n";

    while(temp!=NULL){
        cout << temp->diseaseName<<"\n";
        temp=temp->next;
    }
}


int main() {


// Sample educational dataset
vector<Disease> diseases = {
    {"Disease A", {"Fever", "Cough", "Fatigue"}},
    {"Disease B", {"Fever", "Headache", "Fatigue"}},
    {"Disease C", {"Cough", "Nausea", "Fatigue"}},
    {"Disease D", {"Fever", "Headache", "Nausea"}},
    {"Disease E", {"Cough", "Fatigue", "Headache"}}
};

TreeNode* root=NULL;

for(int i=0;i<diseases.size();i++){
    root = insertDisease(root,diseases[i].name);
}

int choice;

do {
    cout << "\n";
    cout << "============================================\n";
    cout << "   DISEASE-SYMPTOM RELATIONSHIP ANALYZER\n";
    cout << "============================================\n";

    cout << "1. Display All Diseases\n";
    cout << "2. Search Disease\n";
    cout << "3. Find Diseases by Symptom\n";
    cout << "4. Find Common Symptoms\n";
    cout << "5. Show Symptom Frequency\n";
    cout << "6. Add new disease\n";
    cout << "7. Delete diseases\n";
    cout << "8. Update diseases\n";
    cout << "9. Sort diseases\n";
    cout << "10. Sort Symptoms\n";
    cout << "11. Top K symptoms\n";
    cout << "12. View recent search history\n";
    cout << "13. BST Inorder Traversal\n";
    cout << "14. BST Preorder Traversal\n";
    cout << "15. BST Postorder Traversal\n";
    cout << "16. Search Disease Using BST\n";
    cout << "17. Exit\n";

    cout << "\nEnter your choice: ";

    if (!(cin >> choice)) {
        cout << "\nInvalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
    }

    switch (choice) {

        case 1:
            displayDiseases(diseases);
            break;

        case 2:
            searchDiseases(diseases);
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

        case 6:
            addDisease(diseases);
            break;

        case 7:
            deleteDisease(diseases);
            break;
        
        case 8:
            updateDisease(diseases);
            break;

        case 9:
            sortDiseases(diseases);
            break;
        
        
        case 10:
            sortSymptoms(diseases);
            break;

        case 11:
            topKsymptoms(diseases);
            break;
        case 12:
            displayHistory();
            break;

        case 13:
            inorderTraversal(root);
            break;
        
        case 14:
            preorderTraversal(root);
            break;

        case 15:
            postorderTraversal(root);
            break;
        
        case 16:{
            string name;
            cout << "Enter the disease name to search : ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,name);

            TreeNode* result=searchDiseaseBST(root,name);

            if(result != NULL){
                cout << "Disease found: " << result->diseaseName << endl;
            }
            else{
                cout << "Disease not found in BST.\n";
            }
            break;
        }

        case 17:
            cout << "\nThank you for using the analyzer!\n";
            break;


        default:
            cout << "\nInvalid choice! Select between 1 and 17.\n";
    }

} while (choice != 17);

return 0;  

}