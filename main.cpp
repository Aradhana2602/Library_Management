#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// ---------------- Book Class ----------------
class Book {
    int id;
    string title;
    string author;
    bool issued;

public:
    Book(int i, string t, string a, bool is = false)
        : id(i), title(t), author(a), issued(is) {}

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool isIssued() { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }

    string toCSV() {
        return to_string(id) + "," + title + "," + author + "," + (issued ? "1" : "0");
    }

    static Book fromCSV(string line) {
        stringstream ss(line);
        string idStr, title, author, issuedStr;
        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, issuedStr, ',');
        return Book(stoi(idStr), title, author, issuedStr == "1");
    }

    void display() {
        cout << id << " | " << title << " | " << author
             << " | " << (issued ? "Issued" : "Available") << endl;
    }
};

// ---------------- Library Class ----------------
class Library {
    vector<Book> books;
    string filename;

public:
    Library(string f) : filename(f) { loadBooks(); }

    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        saveBooks();
        cout << "Book Added Successfully!\n";
    }

    void viewBooks() {
        cout << "\n--- Book List ---\n";
        for (auto &b : books) {
            b.display();
        }
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to Issue: ";
        cin >> id;
        for (auto &b : books) {
            if (b.getId() == id) {
                if (!b.isIssued()) {
                    b.issueBook();
                    saveBooks();
                    cout << "Book Issued Successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void loadBooks() {
        ifstream fin(filename);
        string line;
        while (getline(fin, line)) {
            if (!line.empty())
                books.push_back(Book::fromCSV(line));
        }
        fin.close();
    }

    void saveBooks() {
        ofstream fout(filename);
        for (auto &b : books) {
            fout << b.toCSV() << "\n";
        }
        fout.close();
    }
};

// ---------------- Main ----------------
int main() {
    Library lib("books.csv");
    int choice;

    do {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n2. View Books\n3. Issue Book\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: lib.addBook(); break;
        case 2: lib.viewBooks(); break;
        case 3: lib.issueBook(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
