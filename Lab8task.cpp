#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Library {
public:
    Library(); // Constructor
    void addBook(const string& book); // Add book to the library
    void removeBook(const string& book); // Remove book from the library
    void printLibrary(); // Print the contents of the library

private:
    static const int MAX_BOOKS = 10; // Maximum number of books in the library
    string books[MAX_BOOKS]; // Array to store the books
    int numBooks; // Number of books currently in the library
};



Library::Library() {
    numBooks = 0; // Initialize the number of books to 0
}

void Library::addBook(const string& book) {
    if (numBooks < MAX_BOOKS) {
        books[numBooks] = book;
        numBooks++;
        cout << "Book added successfully" << endl;
    } else {
        cout << "Library is full. Cannot add more books" << endl;
    }
}

void Library::removeBook(const string& book) {
    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i] == book) {
            found = true;
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            cout << "Book removed successfully" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Book not found in the library" << endl;
    }
}

void Library::printLibrary() {
    cout << "Library contents:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << books[i] << endl;
    }
}


int main() {
    Library library;
    char command = ' ';

    while (command != 'q') {
        cout << "Enter command (a: add, r: remove, p: print, q: quit): ";
        cin >> command;
        cout << endl;

        switch (command) {
            case 'a': {
                string book;
                cout << "Enter book name: ";
                cin >> book;
                library.addBook(book);
                break;
            }
            case 'r': {
                string book;
                cout << "Enter book name: ";
                cin >> book;
                library.removeBook(book);
                break;
            }
            case 'p':
                library.printLibrary();
                break;
            case 'q':
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }

    return 0;
}