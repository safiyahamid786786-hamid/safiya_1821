# safiya_1821


# **Abstract**

The **Lab Management System** is a simple, terminal-based application developed in C for managing laboratory records effectively. The program allows users to store, retrieve, update, and delete laboratory information using a clean, menu-driven interface. Each lab record contains essential details such as lab ID, lab name, equipment list, technician name, and capacity. All data is stored persistently in a binary `.dat` file, ensuring that records remain intact across program restarts.

This lightweight, beginner-friendly project demonstrates the core concepts of **file handling**, **structures**, **persistent storage**, and **control flow** in C programming. Designed to support small institutions, colleges, and basic lab setups, the system provides an accessible and practical solution for managing laboratory information without the need for complex database systems.

---

# **Features of the Program**

✔ Add new lab records with details (lab name, equipment, technician, capacity, etc.)
✔ View all stored lab records in a clean, tabular format
✔ Search for labs by Lab ID
✔ Update existing lab information
✔ Delete lab records from the file
✔ Persistent data storage using a binary `.dat` file
✔ Fully terminal-based (CLI) interface for easy usage
✔ Automatically creates the data file if it does not exist
✔ Beginner-friendly coding structure with clear functions
✔ Handles missing file conditions smoothly
✔ Prevents duplicate Lab IDs

---

# **Technical Requirements**

## **1. System Requirements**

* **Operating System:** Windows / Linux / macOS
* **Terminal / Command Line Interface**
* **Minimum RAM:** 4 MB
* **Minimal disk space** for storing `labs.dat`

## **2. Software Requirements**

* **C Compiler:** GCC / Clang / MinGW / MSVC
* Any code editor (VS Code, Code::Blocks, Dev-C++, Turbo C, etc.)
* Optional: Make tool for using a Makefile

## **3. Programming Requirements**

* **Programming Language:** C
* Supported C Standards: **C89 / C99 / C11**
* Required header files:

  * `<stdio.h>`
  * `<stdlib.h>`
  * `<string.h>`

## **4. File Handling Requirements**

* Read and write access to the working directory
* Lab records stored in a **binary .dat file**
* System **automatically creates the file** if not present

## **5. Compilation Requirements**

* Code must compile without errors
* Recommended compilation flag: `-Wall` for warnings

---

# **Functional Requirements**

## **1. User Interface**

* Fully menu-driven
* Operates in the terminal
* Displays all options clearly
* Accepts and validates user input

## **2. Lab Record Operations**

* **Add Lab:** Insert new lab details
* **View Labs:** Display all stored lab records
* **Search Lab:** Find lab by its unique Lab ID
* **Update Lab:** Modify equipment, technician, or capacity
* **Delete Lab:** Remove a lab entry from the database

## **3. Data Management**

* Stores data persistently in `labs.dat`
* Automatically loads existing data
* Ensures data remains across sessions
* Handles new/missing data files gracefully

## **4. Program Flow**

* Menu-driven loop runs until user selects **Exit**
* Displays messages for success/error
* Provides confirmation before deletion
* Smooth navigation between options

screenshots 
<img width="610" height="496" alt="Screenshot 2025-11-27 202010" src="https://github.com/user-attachments/assets/e4d59798-62ce-4f03-a840-21a0b7c2a284" />
<img width="835" height="360" alt="Screenshot 2025-11-27 202021" src="https://github.com/user-attachments/assets/cb15f3f2-ac0f-46ba-902f-a72600f526e7" />
<img width="604" height="620" alt="Screenshot 2025-11-27 202052" src="https://github.com/user-attachments/assets/41c24687-6a01-4255-9a33-b330ea661a84" />
<img width="464" height="397" alt="Screenshot 2025-11-27 202039" src="https://github.com/user-attachments/assets/e030d986-bb52-41a9-93ee-b6b4812d7568" />
<img width="530" height="457" alt="Screenshot 2025-11-27 202030" src="https://github.com/user-attachments/assets/76375bf4-e198-4bed-9471-316bba71ea2d" />



# **How to Run the Program**

## **1. Compile the Program**

Open terminal in the directory where your file is saved:

```
gcc lab_management_system.c -o lab_management
```

## **2. Run the Executable**

### On Linux/macOS:

```
./lab_management
```

### On Windows:

```
lab_management.exe
```

## **3. Data File**

* The program creates **labs.dat** automatically if not found
* All lab records are saved and loaded from this file


