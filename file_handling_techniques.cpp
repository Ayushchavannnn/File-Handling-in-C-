#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(const string& fileName) {
    ofstream file(fileName);
    if (file) {
        file << "Welcome to File Handling in C++\n";
        file << "This file contains some initial data.\n";
        file.close();
        cout << "Data written to " << fileName << " successfully.\n";
    } else {
        cout << "Failed to open file for writing.\n";
    }
}

void appendFile(const string& fileName) {
    ofstream file(fileName, ios::app);
    if (file) {
        file << "Appending some additional data.\n";
        file.close();
        cout << "Data appended to " << fileName << " successfully.\n";
    } else {
        cout << "Failed to open file for appending.\n";
    }
}

void readFile(const string& fileName) {
    ifstream file(fileName);
    if (file) {
        string line;
        cout << "Reading from " << fileName << ":\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Failed to open file for reading.\n";
    }
}

int main() {
    string fileName = "data.txt";
    int choice;

    do {
        cout << "\n1. Write to file\n2. Append to file\n3. Read from file\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeFile(fileName);
                break;
            case 2:
                appendFile(fileName);
                break;
            case 3:
                readFile(fileName);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


