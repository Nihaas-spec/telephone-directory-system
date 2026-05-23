// =============================================================================
// UMT Telephone Directory
// Course  : Object Oriented Programming (cc1022)
// Semester: 2nd Semester
// Author  : M. Nihaas Bhatti (F2024266196)
// Instructor: Syed Farooq Ali
// =============================================================================
//
// Description:
//   A console-based telephone directory for UMT students, built using OOP
//   principles in C++. Supports inserting, updating, deleting, searching,
//   and listing student records â€” all managed through a menu-driven interface.
//
// Compilation:
//   g++ -std=c++11 -o telephone_directory src/main.cpp
// =============================================================================

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ---------------------------------------------------------------------------
// Student â€” models a single directory entry
// ---------------------------------------------------------------------------
class Student {
public:
    string id;
    string name;
    string address;
    string phone;

    // Display this student's record
    void display(int recordNumber = -1) const {
        if (recordNumber >= 0)
            cout << "\nRecord " << recordNumber << "\n";
        cout << "ID      : " << id      << "\n"
             << "Name    : " << name    << "\n"
             << "Address : " << address << "\n"
             << "Phone   : " << phone   << "\n";
    }

    // Read new data into this student from stdin
    void readFrom() {
        cout << "Enter ID: ";
        cin  >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
    }
};

// ---------------------------------------------------------------------------
// Directory â€” manages the collection of Student records
// ---------------------------------------------------------------------------
class Directory {
    static const int MAX_SIZE = 100;
    Student students[MAX_SIZE];
    int     count;

public:
    Directory() : count(0) {}

    // --- Utilities ---

    bool isFull() const { return count >= MAX_SIZE; }
    bool isEmpty() const { return count == 0; }

    bool idExists(const string& id) const {
        for (int i = 0; i < count; i++)
            if (students[i].id == id) return true;
        return false;
    }

    // Returns index of record matching id or name, -1 if not found
    int findRecord(const string& key) const {
        for (int i = 0; i < count; i++)
            if (students[i].id == key || students[i].name == key)
                return i;
        return -1;
    }

    // --- CRUD Operations ---

    void insert() {
        char repeat;
        do {
            header("Insert Menu");

            if (isFull()) {
                cout << "Directory is full. Cannot insert more records.\n";
                return;
            }

            string id;
            cout << "Enter ID: ";
            cin  >> id;

            if (idExists(id)) {
                cout << "ID already exists. Cannot insert.\n";
            } else {
                cin.ignore();
                students[count].id = id;
                cout << "Enter Name: ";
                getline(cin, students[count].name);
                cout << "Enter Address: ";
                getline(cin, students[count].address);
                cout << "Enter Phone Number: ";
                getline(cin, students[count].phone);

                cout << "Press 1 to save, 0 to cancel: ";
                int save;
                cin >> save;

                if (save == 1) {
                    count++;
                    cout << "Record saved successfully.\n";
                } else {
                    cout << "Record not saved.\n";
                }
            }

            cout << "Want to insert another record? [y/n]: ";
            cin  >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }

    void update() {
        char repeat;
        do {
            header("Update Menu");

            cout << "Enter ID or Name: ";
            cin.ignore();
            string key;
            getline(cin, key);

            int idx = findRecord(key);
            if (idx == -1) {
                cout << "Record not found.\n";
            } else {
                cout << "Current Information:\n";
                students[idx].display();

                char confirm;
                cout << "Do you want to update this record? [y/n]: ";
                cin  >> confirm;
                cin.ignore();

                if (confirm == 'y' || confirm == 'Y') {
                    cout << "Enter New Information:\n";
                    string newId;
                    cout << "Enter ID: ";
                    cin  >> newId;

                    // Ensure updated ID doesn't clash with another record
                    if (newId != students[idx].id && idExists(newId)) {
                        cout << "That ID already belongs to another record. Update cancelled.\n";
                    } else {
                        cin.ignore();
                        students[idx].id = newId;
                        cout << "Enter Name: ";
                        getline(cin, students[idx].name);
                        cout << "Enter Address: ";
                        getline(cin, students[idx].address);
                        cout << "Enter Phone Number: ";
                        getline(cin, students[idx].phone);
                        cout << "Record updated successfully.\n";
                    }
                }
            }

            cout << "Do you want to update another record? [y/n]: ";
            cin  >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }

    void remove() {
        char repeat;
        do {
            header("Delete Menu");

            cout << "Enter ID: ";
            string id;
            cin  >> id;

            int idx = findRecord(id);
            if (idx == -1) {
                cout << "Record not found.\n";
            } else {
                cout << "Current Information:\n";
                students[idx].display();

                char confirm;
                cout << "Do you want to delete this record? [y/n]: ";
                cin  >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    for (int j = idx; j < count - 1; j++)
                        students[j] = students[j + 1];
                    count--;
                    cout << "Record deleted successfully.\n";
                }
            }

            cout << "Do you want to delete another record? [y/n]: ";
            cin  >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }

    void search() const {
        char repeat;
        do {
            header("Search Menu");

            cout << "Enter ID or Name: ";
            cin.ignore();
            string key;
            getline(cin, key);

            int idx = findRecord(key);
            if (idx == -1) {
                cout << "Record not found.\n";
            } else {
                cout << "Record Found:\n";
                students[idx].display();
            }

            cout << "Do you want to search another record? [y/n]: ";
            cin  >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }

    void listAll() const {
        header("Directory Members");

        if (isEmpty()) {
            cout << "No records found.\n";
        } else {
            for (int i = 0; i < count; i++)
                students[i].display(i + 1);
            cout << "\nTotal " << count << " record(s) shown successfully.\n";
        }

        char back;
        cout << "Press 'm' to return to Main Menu: ";
        cin  >> back;
    }

    // --- Helpers ---

    static void header(const string& title) {
        cout << "\n*************************************\n"
             << "Telephone Directory: " << title << "\n"
             << "*************************************\n";
    }
};

// ===========================================================================
// Entry Point
// ===========================================================================
int main() {
    Directory dir;
    int choice;

    while (true) {
        Directory::header("Main Menu");
        cout << "1. Insert a new student\n"
             << "2. Update an existing student\n"
             << "3. Delete a record\n"
             << "4. Search for a student (by name or ID)\n"
             << "5. List directory\n"
             << "6. Exit\n"
             << "Select Option [1-6]: ";

        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: dir.insert();  break;
            case 2: dir.update();  break;
            case 3: dir.remove();  break;
            case 4: dir.search();  break;
            case 5: dir.listAll(); break;
            case 6:
                cout << "Thank you for using the UMT Telephone Directory. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option. Please select 1 to 6.\n";
        }
    }
}