#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper function to convert string to lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Class to track grocery item frequencies
class GroceryTracker {
private:
    map<string, int> itemFrequency;  // Stores item name and frequency

public:
    // Load items from input file into the map
    void loadData(const string& filename) {
        ifstream inputFile(filename);
        string item;

        if (!inputFile.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }

        while (getline(inputFile, item)) {
            if (!item.empty()) {
                if (item.back() == '\r') item.pop_back();  // Handle Windows line endings
                if (!item.empty()) {
                    string lowerItem = toLower(item);
                    itemFrequency[lowerItem]++;
                }
            }
        }
        inputFile.close();
    }

    // Return frequency of a specific item
    int getFrequency(string item) {
        string lowerItem = toLower(item);
        auto it = itemFrequency.find(lowerItem);
        return (it != itemFrequency.end()) ? it->second : 0;
    }

    // Print all items with frequencies (Menu Option 2)
    void printFrequencies() {
        cout << "\nItem Frequency List:\n";
        cout << "---------------------\n";
        for (const auto& pair : itemFrequency) {
            string displayName = pair.first;
            if (!displayName.empty()) {
                displayName[0] = toupper(displayName[0]);
            }
            cout << displayName << " " << pair.second << endl;
        }
        cout << "---------------------\n";
    }

    // Print histogram with asterisks (Menu Option 3)
    void printHistogram() {
        cout << "\nItem Frequency Histogram:\n";
        cout << "-------------------------\n";
        for (const auto& pair : itemFrequency) {
            string displayName = pair.first;
            if (!displayName.empty()) {
                displayName[0] = toupper(displayName[0]);
            }
            cout << left << setw(12) << displayName << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
        cout << "-------------------------\n";
    }

    // Create frequency.dat backup file at program start
    void createBackupFile(const string& filename) {
        ofstream backupFile(filename);
        if (!backupFile.is_open()) {
            cerr << "Error: Could not create backup file " << filename << endl;
            return;
        }
        for (const auto& pair : itemFrequency) {
            string displayName = pair.first;
            if (!displayName.empty()) {
                displayName[0] = toupper(displayName[0]);
            }
            backupFile << displayName << " " << pair.second << endl;
        }
        backupFile.close();
        cout << "Backup file '" << filename << "' created successfully.\n";
    }
};


int main() {
    GroceryTracker tracker;
    const string inputFile = "CS210_Project_Three_Input_File.txt";
    const string backupFile = "frequency.dat";

    // Load data and create backup file
    tracker.loadData(inputFile);
    tracker.createBackupFile(backupFile);

    int choice = 0;

    // Menu loop
    while (choice != 4) {
        cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print frequency list\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string item;
            cout << "Enter the item name: ";
            getline(cin, item);
            int freq = tracker.getFrequency(item);
            cout << item << " appears " << freq << " time(s).\n";
            break;
        }
        case 2:
            tracker.printFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1-4.\n";
            break;
        }
    }

    return 0;
}