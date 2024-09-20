#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to represent a Book
struct Book {
    string title;
    string author;
    string isbn;
    bool available;

    Book(string t, string a, string i) : title(t), author(a), isbn(i), available(true) {}
};

// Structure to represent a Borrower
struct Borrower {
    string name;
    string borrowedISBN;
    time_t borrowDate;

    Borrower(string n, string isbn) : name(n), borrowedISBN(isbn), borrowDate(time(nullptr)) {}
};

// Function declarations
void addBook(vector<Book>& books);
void searchBooks(const vector<Book>& books);
void checkoutBook(vector<Book>& books, vector<Borrower>& borrowers);
void returnBook(vector<Book>& books, vector<Borrower>& borrowers);
void calculateFine(const Borrower& borrower);

int main() {
    vector<Book> books;         // List of books in the library
    vector<Borrower> borrowers; // List of borrowers
    char option;

    cout << "Welcome to the Library Management System!\n";

    // Main loop for user interaction
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add a Book\n";
        cout << "2. Search for Books\n";
        cout << "3. Checkout a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Exit the System\n";
        cout << "Please enter your choice (1-5): ";
        cin >> option;

        switch (option) {
            case '1':
                addBook(books);
                break;
            case '2':
                searchBooks(books);
                break;
            case '3':
                checkoutBook(books, borrowers);
                break;
            case '4':
                returnBook(books, borrowers);
                break;
            case '5':
                cout << "Thank you for using the Library Management System. Goodbye!\n";
                return 0; // Exit the program
            default:
                cout << "Oops! That’s not a valid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to add a new book to the library
void addBook(vector<Book>& books) {
    string title, author, isbn;
    cin.ignore(); // Clear the input buffer
    cout << "Let's add a new book to the library.\n";
    cout << "Enter the book title: ";
    getline(cin, title);
    cout << "Enter the book author: ";
    getline(cin, author);
    cout << "Enter the book ISBN: ";
    getline(cin, isbn);
    books.push_back(Book(title, author, isbn)); // Add book to the list
    cout << "Success! The book '" << title << "' has been added to the library.\n";
}

// Function to search for books based on title, author, or ISBN
void searchBooks(const vector<Book>& books) {
    string query;
    cin.ignore(); // Clear the input buffer
    cout << "What book are you looking for? Enter the title, author, or ISBN: ";
    getline(cin, query);

    bool found = false;
    cout << "\nSearch Results:\n";
    for (const auto& book : books) {
        if (book.title.find(query) != string::npos ||
            book.author.find(query) != string::npos ||
            book.isbn == query) {
            cout << "Title: " << book.title << ", Author: " << book.author
                 << ", ISBN: " << book.isbn
                 << (book.available ? " [Available]" : " [Checked Out]") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Sorry, no books found matching your search.\n";
    }
}

// Function to checkout a book to a borrower
void checkoutBook(vector<Book>& books, vector<Borrower>& borrowers) {
    string isbn, name;
    cin.ignore(); // Clear the input buffer
    cout << "Let's check out a book!\n";
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Enter the ISBN of the book you wish to check out: ";
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn && book.available) {
            book.available = false; // Mark book as checked out
            borrowers.push_back(Borrower(name, isbn)); // Add borrower to the list
            cout << "Great! The book has been checked out to you.\n";
            return;
        }
    }
    cout << "Sorry, the book is either not found or already checked out.\n";
}

// Function to return a book and calculate any fines if applicable
void returnBook(vector<Book>& books, vector<Borrower>& borrowers) {
    string isbn;
    cin.ignore(); // Clear the input buffer
    cout << "Welcome back! Let's return a book.\n";
    cout << "Enter the ISBN of the book you are returning: ";
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn && !book.available) {
            book.available = true; // Mark book as available
            // Find the borrower and calculate fine
            for (const auto& borrower : borrowers) {
                if (borrower.borrowedISBN == isbn) {
                    calculateFine(borrower); // Calculate any fines
                    cout << "Thank you for returning the book!\n";
                    return;
                }
            }
        }
    }
    cout << "Sorry, the book is not found or was not checked out.\n";
}

// Function to calculate the fine for overdue books
void calculateFine(const Borrower& borrower) {
    time_t currentTime = time(nullptr);
    double seconds = difftime(currentTime, borrower.borrowDate);
    const int daysInFine = 14; // Assume a 14-day borrowing period
    const double fineRate = 0.50; // Assume ₹0.50 per day overdue

    // Calculate how many days overdue
    if (seconds > daysInFine * 86400) { // 86400 seconds in a day
        int daysOverdue = static_cast<int>(seconds / 86400) - daysInFine;
        double fine = daysOverdue * fineRate;
        cout << "You have a fine of ₹" << fine << " for being "
             << daysOverdue << " days overdue.\n";
    } else {
        cout << "No fines due. Thank you for returning on time!\n";
    }
}
