\# Assignment Specification — Mini Project 2 (MP2)



\*\*Course:\*\* cc1022 — Object Oriented Programming  

\*\*Program:\*\* CS/SE, SST, UMT  

\*\*Instructor:\*\* Syed Farooq Ali  

\*\*Total Marks:\*\* 200  

\*\*CLO3:\*\* Model a solution for a given problem using object-oriented principles



\---



\## Problem Statement



A traditional telephone directory is a book listing the names, addresses, and telephone numbers of people in a particular area. The task is to develop a telephone directory for UMT students using the Object Oriented Programming paradigm in C++.



File handling is \*\*not\*\* required — records are managed in memory using an array or linked list.



\---



\## Required Menu Structure



\### Main Menu

```

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

Telephone Directory: Main Menu

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

1\. Insert a new student

2\. Update an existing student

3\. Delete a record

4\. Search for a student (using name or ID)

5\. List directory

Select Option \[1, 2, 3, 4 or 5]:

```



\### Insert Menu

\- Prompt for ID, Name, Address, Phone Number

\- If ID already exists: display error, do not insert

\- Confirm save (1 = save, 0 = cancel)

\- Ask to insert another record \[y/n]



\### Update Menu

\- Search by ID or Name

\- Display current record

\- Confirm update \[y/n]

\- If yes, prompt for all new field values

\- Ask to update another record \[y/n]



\### Delete Menu

\- Search by ID

\- Display current record

\- Confirm delete \[y/n]

\- Ask to delete another record \[y/n]



\### Search Menu

\- Search by ID or Name

\- Display record if found, appropriate message if not

\- Ask to search another record \[y/n]



\### List Directory

\- Display all records with sequential numbering

\- Show total record count

\- Press 'm' to return to Main Menu



