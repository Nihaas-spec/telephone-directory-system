# 📞 UMT Telephone Directory

A console-based telephone directory for UMT students, built using **Object Oriented Programming** principles in C++. Supports full CRUD operations — insert, update, delete, search, and list — through a clean menu-driven interface.

**Course:** Object Oriented Programming (cc1022) — 2nd Semester  
**Institution:** University of Management and Technology (UMT)  
**Language:** C++

---

## 🎯 Features

| Operation | Description |
|-----------|-------------|
| **Insert** | Add a new student record (ID, Name, Address, Phone) with duplicate ID detection |
| **Update** | Find a record by ID or name and update all fields |
| **Delete** | Locate and delete a record by ID with confirmation prompt |
| **Search** | Find a student by ID or full name |
| **List All** | Display every record in the directory with total count |

---

## 🎬 Demo

### Telephone Directory: Main Menu

Insert a new student

Update an existing student

Delete a record

Search for a student (by name or ID)

List directory
Select Option [1, 2, 3, 4 or 5]: 1

### Telephone Directory: Insert Menu

Enter ID: F2024266196
Enter Name: Muhammad Nihaas
Enter Address: Lahore, Pakistan
Enter Phone Number: 03001234567
Press 1 to save, 0 to cancel: 1
Record saved successfully.
Want to insert another record? [y/n]: n

### Telephone Directory: Search Menu

Enter ID or Name: Muhammad Nihaas
Record Found:
ID : F2024266196
Name : Muhammad Nihaas
Address : Lahore, Pakistan
Phone : 03001234567

---

## 🚀 Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (GCC, Clang, MSVC)

### Compile & Run

```bash
# Compile
g++ -std=c++11 -o telephone_directory src/main.cpp
```
```
# Run
./telephone_directory
```
On Windows (MinGW):
```
g++ -std=c++11 -o telephone_directory.exe src/main.cpp
telephone_directory.exe
```
## Project Structure
```
telephone-directory-system/
├── src/
│   └── main.cpp          # Full application source code
├── docs/
│   └── assignment.md     # Original assignment specification
├── screenshots/          # Sample output screenshots
├── README.md
└── .gitignore
```
## OOP Design
The project uses two classes:

Student — Models a single directory entry with fields: id, name, address, phone. Includes display() and readFrom() methods.

Directory — Manages the collection of Student objects. Encapsulates the internal array and record count, exposing clean public methods: insert(), update(), remove(), search(), listAll().

## OOP Concepts Demonstrated
Classes and Objects

Encapsulation (private data, public interface)

Member functions and method design

Object composition (Directory contains Student objects)

const correctness on read-only methods

## Author
Name	Student ID
M. Nihaas Bhatti	F2024266196
Instructor: Syed Farooq Ali — cc1022 OOP, SST, UMT

## License
MIT — free to use, modify, and distribute

---
