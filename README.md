📚 Library Management System (C++)
A simple yet structured Library Management System built using C++ and Object-Oriented Programming (OOP) principles.

This project demonstrates how real-world systems like libraries can be modeled using classes, file handling, and modular design in C++. It uses a CSV file (books.csv) for persistent storage, ensuring data remains saved even after the program closes.

🌟 Project Overview
Managing books manually can be inefficient and error-prone. This console-based system provides a simple interface to:

Add books to a library

View available books

Issue books

Maintain persistent records using file handling

This project focuses on strengthening:

OOP concepts

File I/O operations

Data management using CSV

Console-based menu systems

Modular and structured C++ programming

🧠 Core Concepts Used
1️⃣ Object-Oriented Programming
The system is structured using classes to represent:

Books

Library operations

This makes the program:

Reusable

Organized

Easy to expand

2️⃣ File Handling (CSV Storage)
All book records are stored in:

books.csv
Each record includes:

Book ID

Title

Author

Availability status

When a book is issued, the CSV file is updated accordingly.

✨ Features
✔ Add new books with unique ID
✔ View all books in the system
✔ Issue books (updates availability)
✔ Persistent storage using CSV file
✔ Simple, user-friendly CLI interface

🏗️ Project Structure
Library_Management/
│
├── main.cpp        # Core application logic
├── books.csv       # Data storage file
└── README.md       # Project documentation
🚀 How to Run the Project
🔧 Step 1: Clone the Repository
git clone https://github.com/Aradhana2602/Library_Management.git
🔧 Step 2: Navigate into the Folder
cd Library_Management
🔧 Step 3: Compile the Code
If you are using g++:

g++ main.cpp -o library
🔧 Step 4: Run the Program
Windows:

library.exe
Mac/Linux:

./library
📋 Program Workflow
When you run the program, you’ll see a menu:

1. Add Book
2. View All Books
3. Issue Book
0. Exit
➤ Add Book
Enter book ID

Enter title

Enter author

Data gets stored in books.csv

➤ View Books
Displays all stored books

Shows availability status

➤ Issue Book
Enter book ID

If available → status changes to issued

If not → message displayed

💡 Example CSV Format
101,The Alchemist,Paulo Coelho,Available
102,Harry Potter,J.K. Rowling,Issued
