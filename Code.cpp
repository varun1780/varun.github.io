#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <sstream>
#include<map>
#include <set>
#include<stack>
using namespace std;

// User structure

struct User

{
    int userID;
    string name;
    string email;
    string password;
    int age;
    string gender;
    string role;
    string membershipStatus;
    string lastLoginDate;
    vector<string> activityLog;
    vector<string> notifications;
    int loginAttempts;
    bool isAccountLocked;
    map<string, string> preferences;
    string history;
    set<string> twoFactorMethods;
    bool isActive;
};


// Book structure
struct Book
{
    int bookID;
    string bookName;
    string edition;
    string author;
    string publisher;
    string ISBN;
    string language;
    bool isAvailable;
};

// Borrowing and Returning structure
struct BorrowingReturn {
    int borrowID;              // Unique ID for the borrowing record
    int bookID;                // ID of the borrowed book
    int userID;                // ID of the user who borrowed the book
    string borrowerID;         // Unique ID of the borrower
    string borrowerName;       // Name of the borrower
    string borrowDate;         // Date when the book is borrowed
    string dueDate;            // Date when the book is due
    int loanPeriod;            // Loan period in days
    double fineCharges;        // Fine for overdue books
    string borrowerMembership; // Membership type of the borrower
    string returnDate;         // Date when the book is returned
    double lateReturnFee;      // Fee for late returns
    string conditionCheck;     // Notes on the condition of the book
};


struct ReportsAnalytics
{
    int reportID;
    string reportName;
    string reportDate;
    string description;
    int booksBorrowed;
    int booksReturned;
    int overdueBooks;
    string activityType;
    string popularBook;
    string topUser;
    string userStatus;
    string bookConditionRemarks;
};



// Function Declarations for User Management
void loadUsersFromFile(vector<User>& users);
void saveUsersToFile(const vector<User>& users);
void displayUsers(const vector<User>& users);
void addUser(vector<User>& users);

void searchUserByID(const vector<User>& users);
void updateUser(vector<User>& users);

void removeUser(vector<User>& users);
void displayTotalUsers(const vector<User>& users);
void sortUsersByName(vector<User>& users);

void displayUsersByMembershipStatus(const vector<User>& users, const string& status);
void activateUser(vector<User>& users, int userID);

void deactivateUser(vector<User>& users, int userID);

bool boyerMooreSearch(const string& text, const string& pattern);
void searchUserByName(const vector<User>& users);

void displayUsersByAgeGroup(const vector<User>& users, int minAge, int maxAge);
void promoteUserToAdmin(vector<User>& users);

void resetUserPassword(vector<User>& users);

void resetUserPassword(vector<User>& users, int userID);
void mergeUserAccounts(vector<User>& users) ;



// Analytics and Statistics Functions

void displayMembershipStatistics(const vector<User>& users);
void displayAverageUserAge(const vector<User>& users);
void displayGenderStatistics(const vector<User>& users);

void displayMostActiveUsers(const vector<User>& users, int topN);
void displayUsersByLastLoginDate(const vector<User>& users, const string& date);
void displayUserActivitySummary(const vector<User>& users);


// Customization and Notifications
void sendNotificationToUser(vector<User>& users);
void sendNotificationToAllUsers(vector<User>& users, const string& message);
void updateUserPreferences(vector<User>& users, int userID);
void personalizeUserInterface(vector<User>& users, int userID, const string& theme);

// Security and Access Management
void lockUserAccount(vector<User>& users, int userID);
void unlockUserAccount(vector<User>& users, int userID);
void trackUserLoginAttempts(vector<User>& users, int userID, int attemptCount);

void displayUsersByRole(const vector<User>& users, const string& role);
void implementTwoFactorAuthentication(vector<User>& users, int userID);

// Data Integrity and Backup
void backupUserDatabase(const vector<User>& users, const string& backupFileName);
void restoreUserDatabase(vector<User>& users, const string& backupFileName);


// Function Declarations for Book Management
void loadBooksFromFile(vector<Book>& books);
void saveBooksToFile(const vector<Book>& books);
void displayBooks(const vector<Book>& books);
void addBook(vector<Book>& books);
void searchBookByID(const vector<Book>& books);
void updateBook(vector<Book>& books);
void removeBook(vector<Book>& books);
void restoreLastDeletedBook(vector<Book>& books, stack<Book>& deletedBooks);
void displayTotalBooks(const vector<Book>& books);
void sortBooksByName(vector<Book>& books);
void displaysortedBooks(const vector<Book>& books);
void sortBooksByID(vector<Book>& books);
void displaysortedBooksid(const vector<Book>& books);
void searchBookByName(const vector<Book>& books);
void checkBookAvailability(const vector<Book>& books);
void markBookAsDamaged(vector<Book>& books, map<int, bool>& bookDamaged);  // Mark a book as damaged
void displayDamagedBooks(const vector<Book>& books, const map<int, bool>& bookDamaged);  // Display all damaged books
void reserveBook(vector<Book>& books, map<int, bool>& bookReserved);
void displayReservedBooks(const vector<Book>& books, const map<int, bool>& bookReserved);
void findBooksByKeywords(const vector<Book>& books, const string& keyword);
void markBookBorrowedOrReturned(vector<Book>& books, map<int, bool>& bookAvailability);


 // Function Declarations for Borrowing and Returning Management
void loadBorrowingFromFile(vector<BorrowingReturn>& borrowRecords);
void saveBorrowingToFile(const vector<BorrowingReturn>& borrowRecords);
void displayBorrowingRecords(const vector<BorrowingReturn>& borrowRecords);
void borrowBook(vector<BorrowingReturn>& borrowRecords, const vector<User>& users, const vector<Book>& books);
void returnBook(vector<BorrowingReturn>& borrowRecords, const vector<Book>& books);
void displayBorrowingRecords(const vector<BorrowingReturn>& borrowRecords);
void calculateFine(BorrowingReturn& record);


//Function prototypes
void loadReportsFromFile(vector<ReportsAnalytics>& reports);
void saveReportsToFile(const vector<ReportsAnalytics>& reports);
void displayReports(const vector<ReportsAnalytics>& reports);
void calculateTotalFines(const vector<ReportsAnalytics>& reports);
void findMostBorrowedBook(const vector<ReportsAnalytics>& reports);
void displayBooksBorrowed(const vector<ReportsAnalytics>& reports);
void displayBooksReturned(const vector<ReportsAnalytics>& reports);
void displayOverdueBooks(const vector<ReportsAnalytics>& reports);
void displayActivityType(const vector<ReportsAnalytics>& reports);
void displayPopularBooks(const vector<ReportsAnalytics>& reports);
void displayTopUsers(const vector<ReportsAnalytics>& reports);
void displayUserStatuses(const vector<ReportsAnalytics>& reports);
void displayBookConditionRemarks(const vector<ReportsAnalytics>& reports);
void sortReportsByDate(vector<ReportsAnalytics>& reports);
void searchReportsByCriteria(const vector<ReportsAnalytics>& reports);
void updateReport(vector<ReportsAnalytics>& reports);
void deleteReport(vector<ReportsAnalytics>& reports);
void addNewReport(vector<ReportsAnalytics>& reports);
void showMenu();

void displayReports(const vector<ReportsAnalytics>& reports); // Display all reports


// Load users from a file
void loadBooksFromFile(vector<Book>& books)
 {

    ifstream inputFile("book.txt"); // Open the file
    if (!inputFile)

        {

        cout << "Error opening the file." << endl;
        return;
    }



    string line;
    while (getline(inputFile, line))
        {
        // Assuming each line in the file contains a book's data
        stringstream ss(line);
        Book book;



        // Assuming the fields are separated by spaces and in the following order:
        // bookID, bookName, edition, author, publisher, ISBN, language
        ss >> book.bookID; // Read book ID

        // Read the rest of the fields
        ss.ignore(); // Ignore the space between bookID and bookName
        getline(ss, book.bookName, ','); // Read bookName until a comma
        getline(ss, book.edition, ','); // Read edition until a comma
        getline(ss, book.author, ','); // Read author until a comma
        getline(ss, book.publisher, ','); // Read publisher until a comma
        getline(ss, book.ISBN, ','); // Read ISBN until a comma
        getline(ss, book.language); // Read language until the end of the line

        books.push_back(book); // Add the book to the vector
    }



    inputFile.close(); // Close the file after reading
}

void saveBooksToFile(const vector<Book>& books)


{
    ofstream outputFile("book.txt"); // Open the file for writing

    if (!outputFile)
        {

        cout << "Error opening the file for writing." << endl;
        return;
    }

    for (const auto& book : books)
        {
        // Write book data to the file in the following format:
        // bookID, bookName, edition, author, publisher, ISBN, language
        outputFile << book.bookID << ", "
                   << book.bookName << ", "
                   << book.edition << ", "
                   << book.author << ", "
                   << book.publisher << ", "
                   << book.ISBN << ", "
                   << book.language << endl;
    }

    outputFile.close(); // Close the file after writing



    cout << "Books saved to file successfully." << endl;


}


void displayBooks(const vector<Book>& books)


 {

        cout << left << setw(5) << "ID"
         << setw(40) << "Book Name"
         << setw(15) << "Edition"
         << setw(30) << "Author"
         << setw(20) << "Publisher"
         << setw(15) << "ISBN"
         << setw(10) << "Language" << endl;
    cout << string(135, '-') << endl;  // To create a separator line

    for (const auto& book : books)
        {




        cout << setw(5) << book.bookID
             << setw(40) << book.bookName
             << setw(15) << book.edition
             << setw(30) << book.author
             << setw(20) << book.publisher
             << setw(15) << book.ISBN
             << setw(10) << book.language << endl;
    }
}




// Add a new book
void addBook(vector<Book>& books)
{

    Book newBook;
    cout << "Enter Book ID: ";


    cin >> newBook.bookID;

    cout << "Enter Book Name: ";

    cin >> newBook.bookName;

    cout << "Enter Edition: ";

    cin >> newBook.edition;

    cout << "Enter Author: ";
    cin >> newBook.author;


    cout << "Enter Publisher: ";

    cin >> newBook.publisher;
    cout << "Enter ISBN: ";
    cin >> newBook.ISBN;

    cout << "Enter Language: ";

    cin >> newBook.language;

    books.push_back(newBook);
    cout << "Book added successfully.\n";



}

void searchBookByID(const vector<Book>& books)

{
    int searchID;
    cout << "Enter Book ID to search: ";



    // Read input and check if it is valid


    while (!(cin >> searchID))

        {

        cout << "Invalid input. Please enter a valid Book ID (integer): ";
        cin.clear();  // Clears the error flag


        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the incorrect input

    }


    bool found = false;


    // Debug: Print entered searchID
    cout << "Searching for Book ID: " << searchID << endl;

    // Loop through the books and search for the book with the matching ID

    for (const auto& book : books)

        {

        cout << "Checking Book ID: " << book.bookID << endl;  // Debug: print current book ID

        if (book.bookID == searchID)

       {

            // Match by bookID

            cout << "Book found: " << endl;
            cout << left << setw(10) << "Book ID"

                 << setw(30) << "Book Name"
                 << setw(15) << "Edition"

                 << setw(20) << "Author"
                 << setw(20) << "Publisher"

                 << setw(15) << "ISBN"
                 << setw(10) << "Language" << endl;

            cout << string(120, '-') << endl;
            // Display the matched book

            cout << left << setw(10) << book.bookID
                 << setw(30) << book.bookName

                 << setw(15) << book.edition
                 << setw(20) << book.author

                 << setw(20) << book.publisher

                 << setw(15) << book.ISBN
                 << setw(10) << book.language << endl;

            found = true;
            break;  // Exit the loop after displaying the found book

        }
    }


    if (!found)
        {

       cout << "No book found with ID " << searchID << endl;
    }
}


// Update book information

void updateBook(vector<Book>& books)


 {


    int id;
    cout << "Enter Book ID to update: ";
    cin >> id;



    auto it = find_if(books.begin(), books.end(), [id](const Book& book)

        {

        return book.bookID == id;



    });

      if (it != books.end())

      {


        cout << "Enter new book name: ";


        cin >> it->bookName;
        cout << "Enter new edition: ";


        cin >> it->edition;
        cout << "Enter new author: ";

        cin >> it->author;
        cout << "Enter new publisher: ";

        cin >> it->publisher;
        cout << "Enter new ISBN: ";


        cin >> it->ISBN;


        cout << "Enter new language: ";


        cin >> it->language;
        cout << "Book updated successfully.\n";
    }


    else
        {



        cout << "Book not found.\n";
    }
}


// For storing deleted books temporarily

void removeBook(vector<Book>& books, stack<Book>& deletedBooks)
{

    int bookID;
    cout << "Enter the Book ID to remove: ";
    cin >> bookID;


    auto it = find_if(books.begin(), books.end(), [bookID](const Book& book)

    {

        return book.bookID == bookID;

    });



    if (it != books.end())
    {
        // Push the deleted book into the stack for restoration

        deletedBooks.push(*it);
        books.erase(it);


        cout << "Book with ID " << bookID << " has been removed and stored for restoration.\n";
    }

    else
    {


        cout << "Book with ID " << bookID << " not found.\n";
    }

}


void restoreLastDeletedBook(vector<Book>& books, stack<Book>& deletedBooks)
   {

    if (!deletedBooks.empty())

     {
        Book restoredBook = deletedBooks.top();  // Retrieve the last deleted book

        deletedBooks.pop();                      // Remove it from the stack
        books.push_back(restoredBook);           // Re-add it to the books list



        cout << "The book has been successfully restored:\n";

        cout << "Book ID: " << restoredBook.bookID << "\n"

             << "Book Name: " << restoredBook.bookName << "\n"
             << "Author: " << restoredBook.author << "\n"

             << "Edition: " << restoredBook.edition << "\n";
    }
     else
        {

        cout << "No deleted books available to restore.\n";

    }

}

// Display total number of books
void displayTotalBooks(const vector<Book>& books)
{

cout << "Total number of books: " << books.size() << endl;

}


// Sort books by name
void sortBooksByName(vector<Book>& books)
{

    sort(books.begin(), books.end(), [](const Book& a, const Book& b)

        {

        return a.bookName < b.bookName;

    });

    cout << "Books sorted by name.\n";
    displaysortedBooks(books);  // Display the sorted books
}


void displaysortedBooks(const vector<Book>& books)
{

    if (books.empty())
        {

        cout << "No books available to display.\n";
        return;

    }

    cout << "Books List:\n";
    for (const auto& book : books)
        {

        cout << "Book ID: " << book.bookID << "\n";
        cout << "Name: " << book.bookName << "\n";
        cout << "Edition: " << book.edition << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Publisher: " << book.publisher << "\n";
        cout << "ISBN: " << book.ISBN << "\n";
        cout << "Language: " << book.language << "\n";
        cout << "----------------------------\n";

    }

}

// Sort books by ID
void sortBooksByID(vector<Book>& books)
{


    sort(books.begin(), books.end(), [](const Book& a, const Book& b)

        {

        return a.bookID < b.bookID;

    });

    cout << "Books sorted by ID.\n";
    displaysortedBooksid(books); // Display the sorted books
}

void displaysortedBooksid(const vector<Book>& books)
 {

    if (books.empty())
        {

        cout << "No books available to display.\n";
        return;

    }

    cout << "Books List:\n";
    for (const auto& book : books)

        {

        cout << "Book ID: " << book.bookID << "\n";
        cout << "Name: " << book.bookName << "\n";
        cout << "Edition: " << book.edition << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Publisher: " << book.publisher << "\n";
        cout << "ISBN: " << book.ISBN << "\n";
        cout << "Language: " << book.language << "\n";
        cout << "----------------------------\n";

    }
}

bool boyerMooreSearch(const string& text, const string& pattern)
{
    int m = pattern.length();
    int n = text.length();

    if (m == 0 || n == 0) return false;

    vector<int> badChar(256, -1);

    // Fill the bad character array

    for (int i = 0; i < m; ++i)
        {

        badChar[pattern[i]] = i;
    }

    int s = 0;
    while (s <= n - m)
        {

        int j = m - 1;

        // Start matching from the end of the pattern
        while (j >= 0 && pattern[j] == text[s + j])
            {

            --j;
        }

        if (j < 0)
            {

            return true;
        }
        else
            {

            // Shift the pattern according to the bad character rule
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return false;
}

void searchBookByName(const vector<Book>& books)
{

    if (books.empty())
        {

        cout << "No books available to search. Please load book data first.\n";
        return;
    }

    string bookName;
    cout << "Enter the book name to search: ";

    cin.ignore();  // Clear the input buffer before taking a full-line input
    getline(cin, bookName);  // Get the full line input for book name


    bool found = false;

    for (const auto& book : books)
        {

        if (boyerMooreSearch(book.bookName, bookName))
        {

            cout << "Book found:\n";

            cout << "Book ID: " << book.bookID << "\n";
            cout << "Name: " << book.bookName << "\n";

            cout << "Edition: " << book.edition << "\n";
            cout << "Author: " << book.author << "\n";

            cout << "Publisher: " << book.publisher << "\n";
            cout << "ISBN: " << book.ISBN << "\n";

            cout << "Language: " << book.language << "\n";
            found = true;

        }
    }



    if (!found)
        {


        cout << "No book found with the name \"" << bookName << "\".\n";

    }
}


void checkBookAvailability(const vector<Book>& books)
{

    if (books.empty())
        {

        cout << "No books available to check. Please load book data first.\n";
        return;
    }

    int bookID;
    cout << "Enter the book ID to check availability: ";
    cin >> bookID;


    bool found = false;
    for (const auto& book : books)
        {


        if (book.bookID == bookID)
            {

            cout << "Book is available:\n";

            cout << "Name: " << book.bookName << "\n";
            cout << "Author: " << book.author << "\n";

            cout << "Publisher: " << book.publisher << "\n";
            found = true;

            break;
        }
    }

    if (!found)
        {

       cout << "Book with ID " << bookID << " is not available.\n";
    }

}

void markBookAsDamaged(vector<Book>& books, map<int, bool>& bookDamaged)
{


    int bookID;
    cout << "Enter book ID to mark as damaged: ";

    cin >> bookID;
    bookDamaged[bookID] = true;

    cout << "Book with ID " << bookID << " has been marked as damaged." << endl;

}

void displayDamagedBooks(const vector<Book>& books, const map<int, bool>& bookDamaged)
{


    for (const auto& book : books)
        {

        if (bookDamaged.find(book.bookID) != bookDamaged.end())
        {


            cout << "ID: " << book.bookID << ", Title: " << book.bookName
                 << ", Author: " << book.author << ", Publisher: " << book.publisher

                 << " (Damaged)" << endl;
        }
    }
}

void reserveBook(vector<Book>& books, map<int, bool>& bookReserved)
{


    int bookID;
    cout << "Enter the Book ID to reserve: ";

    cin >> bookID;


    // Check if the book exists
    auto it = find_if(books.begin(), books.end(), [bookID](const Book& book)
    {

        return book.bookID == bookID;
    });

    if (it != books.end())
        {

        // Check if the book is already reserved
        if (bookReserved[bookID])
        {

            cout << "Book ID " << bookID << " is already reserved.\n";
        }
    else
        {

            bookReserved[bookID] = true;
            cout << "Book ID " << bookID << " (" << it->bookName << ") has been reserved.\n";

        }
    }
    else
    {

        cout << "No book found with ID " << bookID << ".\n";
    }
}

void displayReservedBooks(const vector<Book>& books, const map<int, bool>& bookReserved)
{
    cout << "Reserved Books:\n";

    bool hasReservedBooks = false;

    for (const auto& book : books)
        {

        if (bookReserved.find(book.bookID) != bookReserved.end() && bookReserved.at(book.bookID))
        {


            cout << "ID: " << book.bookID << ", Name: " << book.bookName
                 << ", Author: " << book.author << ", Publisher: " << book.publisher

                 << ", Edition: " << book.edition << ", ISBN: " << book.ISBN
                 << ", Language: " << book.language << "\n";

            hasReservedBooks = true;
        }
    }


    if (!hasReservedBooks)
        {


        cout << "No books are currently reserved.\n";
    }
}


// Function to find books that contain a specific keyword in their bookName, author, publisher, or ISBN
void findBooksByKeywords(const vector<Book>& books, const string& keyword)
{


    bool found = false;

    for (const auto& book : books)
        {

        // Check if keyword is in the bookName, author, publisher, or ISBN

        if (book.bookName.find(keyword) != string::npos ||
            book.author.find(keyword) != string::npos ||

            book.publisher.find(keyword) != string::npos ||
            book.ISBN.find(keyword) != string::npos ||

            book.language.find(keyword) != string::npos) {


            cout << "Book ID: " << book.bookID << "\n";
            cout << "Book Name: " << book.bookName << "\n";
            cout << "Edition: " << book.edition << "\n";
            cout << "Author: " << book.author << "\n";

            cout << "Publisher: " << book.publisher << "\n";
            cout << "Language: " << book.language << "\n";
            cout << "ISBN: " << book.ISBN << "\n";

            cout << "---------------------------\n";
            found = true;
        }
    }

    if (!found)
        {

        cout << "No books found with the keyword: " << keyword << endl;
    }
}

void markBookBorrowedOrReturned(vector<Book>& books, map<int, bool>& bookAvailability)
{

    if (books.empty())
        {

        cout << "No books available to borrow or return. Please load book data first.\n";
        return;
    }

    int bookID;
    char action;

    cout << "Enter the book ID: ";
    cin >> bookID;

    cout << "Enter action (B for Borrow, R for Return): ";
    cin >> action;

    bool found = false;


    for (const auto& book : books)
        {

        if (book.bookID == bookID)
        {


            found = true;
            if (action == 'B' || action == 'b')
                {

                if (bookAvailability[bookID])
                {


                    cout << "Book \"" << book.bookName << "\" has already been borrowed.\n";
                }
                else
                    {

                    bookAvailability[bookID] = true;
                    cout << "Book \"" << book.bookName << "\" marked as borrowed.\n";

                }
            }
            else if (action == 'R' || action == 'r')
                {

                if (!bookAvailability[bookID])
                {


                    cout << "Book \"" << book.bookName << "\" was not borrowed.\n";
                }
                else
                    {


                    bookAvailability[bookID] = false;
                    cout << "Book \"" << book.bookName << "\" marked as returned.\n";

                }
            }
            else
                {

                cout << "Invalid action.\n";
            }

            break;
        }
    }

    if (!found)
        {

        cout << "Book with ID " << bookID << " not found.\n";
    }
}


// Load borrowing and returning records from a file
void loadBorrowingFromFile(vector<BorrowingReturn>& borrowRecords)
{

    string filename;
    cout << "Enter the filename to load borrowing records from: ";

    cin >> filename;


    ifstream file(filename);
    if (!file)
        {

        cerr << "Error: Could not open file \"" << filename << "\".\n";
        return;
    }



    borrowRecords.clear();
    BorrowingReturn temp;

    while (file >> temp.borrowID >> temp.bookID >> temp.userID >> temp.borrowerID >> temp.borrowerName
                >> temp.borrowDate >> temp.dueDate >> temp.loanPeriod >> temp.fineCharges

                >> temp.borrowerMembership >> temp.returnDate >> temp.lateReturnFee >> temp.conditionCheck)
                {


        borrowRecords.push_back(temp);
    }

    if (borrowRecords.empty())
        {

        cout << "No valid borrowing records loaded. File might be empty or invalid.\n";

    }
    else
        {

        cout << "Borrowing records successfully loaded from file \"" << filename << "\".\n";


    }
}

// Save borrowing and returning records to a file
void saveBorrowingToFile(const vector<BorrowingReturn>& borrowRecords)
{

    string filename;

    cout << "Enter the filename to save borrowing records to: ";

    cin >> filename;

    ofstream file(filename);
    if (!file)
        {

        cerr << "Error: Could not open file \"" << filename << "\".\n";

        return;

    }

    for (const auto& record : borrowRecords)
        {


        file << record.borrowID << " " << record.bookID << " " << record.userID << " "

             << record.borrowerID << " " << record.borrowerName << " " << record.borrowDate << " "

             << record.dueDate << " " << record.loanPeriod << " " << record.fineCharges << " "

             << record.borrowerMembership << " " << record.returnDate << " " << record.lateReturnFee << " "

             << record.conditionCheck << endl;

    }

    cout << "Borrowing records successfully saved to file \"" << filename << "\".\n";
}

// Display borrowing and returning records in a tabular format
void displayBorrowingRecords(const vector<BorrowingReturn>& borrowRecords)
{

    if (borrowRecords.empty())
        {


        cout << "No borrowing records to display. Please load borrowing records first.\n";
        return;

    }

    cout << left << setw(10) << "Borrow ID"

         << setw(10) << "Book ID"
         << setw(10) << "User ID"

         << setw(20) << "Borrower Name"
         << setw(15) << "Borrow Date"

         << setw(15) << "Due Date"
         << setw(10) << "Loan Period"
         << setw(12) << "Fine Charges"

         << setw(20) << "Membership Status"
         << setw(15) << "Return Date"

         << setw(15) << "Late Return Fee"
         << setw(30) << "Condition Check" << endl;
    cout << string(150, '-') << endl;


    for (const auto& record : borrowRecords)
        {

        cout << left << setw(10) << record.borrowID

             << setw(10) << record.bookID
             << setw(10) << record.userID
             << setw(20) << record.borrowerName

             << setw(15) << record.borrowDate
             << setw(15) << record.dueDate
             << setw(10) << record.loanPeriod

             << setw(12) << fixed << setprecision(2) << record.fineCharges
             << setw(20) << record.borrowerMembership
             << setw(15) << record.returnDate

             << setw(15) << fixed << setprecision(2) << record.lateReturnFee
             << setw(30) << record.conditionCheck << endl;
    }
}

// Borrow a book for a user
void borrowBook(vector<BorrowingReturn>& borrowRecords, const vector<User>& users, const vector<Book>& books)
{

    int userID, bookID;
    cout << "Enter User ID: ";
    cin >> userID;

    cout << "Enter Book ID: ";
    cin >> bookID;

    // Check if the user and book exist
    auto userIt = find_if(users.begin(), users.end(), [userID](const User& u) { return u.userID == userID; });

    auto bookIt = find_if(books.begin(), books.end(), [bookID](const Book& b) { return b.bookID == bookID; });


    if (userIt == users.end())
        {

        cout << "User not found.\n";

        return;

    }
    if (bookIt == books.end())
        {


        cout << "Book not found.\n";
        return;

    }

    BorrowingReturn newBorrow;

    newBorrow.borrowID = borrowRecords.size() + 1;

    newBorrow.bookID = bookID;

    newBorrow.userID = userID;

    newBorrow.borrowerID = userIt->userID;
    newBorrow.borrowerName = userIt->name;

    newBorrow.borrowDate = "2024-12-27"; // Assume today's date

    newBorrow.dueDate = "2025-01-10"; // Example: 2 weeks loan period

    newBorrow.loanPeriod = 14; // 14 days loan period

    newBorrow.fineCharges = 0;

    newBorrow.borrowerMembership = "Standard";

    newBorrow.returnDate = "";

    newBorrow.lateReturnFee = 0;

    newBorrow.conditionCheck = "Good";



    borrowRecords.push_back(newBorrow);
    cout << "Book successfully borrowed!\n";
}

// Return a borrowed book
void returnBook(vector<BorrowingReturn>& borrowRecords, const vector<Book>& books)
{

    int borrowID;

    cout << "Enter Borrow ID: ";

    cin >> borrowID;


    auto recordIt = find_if(borrowRecords.begin(), borrowRecords.end(), [borrowID](const BorrowingReturn& r) { return r.borrowID == borrowID; });



    if (recordIt == borrowRecords.end())
        {

        cout << "Borrowing record not found.\n";

        return;
    }

    string returnDate;

    cout << "Enter return date (YYYY-MM-DD): ";
    cin >> returnDate;


    recordIt->returnDate = returnDate;

    // Calculate fines if the return is late
    calculateFine(*recordIt);


    cout << "Book successfully returned!\n";
}

void calculateFine(BorrowingReturn& record)
{

    // Example logic: Calculate fine if the return date is later than the due date

    std::tm due_tm = {}, return_tm = {};

    // Parse dueDate

    std::istringstream due_ss(record.dueDate);
    due_ss >> std::get_time(&due_tm, "%Y-%m-%d");

    // Parse returnDate

    std::istringstream return_ss(record.returnDate);
    return_ss >> std::get_time(&return_tm, "%Y-%m-%d");


    // Check for parsing error
    if (due_ss.fail() || return_ss.fail())
        {

        std::cerr << "Error: Invalid date format\n";

        return;
    }

    time_t due_time = std::mktime(&due_tm);

    time_t return_time = std::mktime(&return_tm);

    // Calculate difference in days

    double diffDays = std::difftime(return_time, due_time) / (60 * 60 * 24);
    if (diffDays > 0)
        {

        record.lateReturnFee = diffDays * 0.5; // 0.5 is the fine per day

        std::cout << "Late return fee: " << record.lateReturnFee << "\n";
    }
    else
        {

        record.lateReturnFee = 0;
    }
}

////////////////////////////////////user management



void loadUsersFromFile(vector<User>& users)
{

    ifstream file("users.txt");
    string line;
    while (getline(file, line))
        {

        User user;
        stringstream ss(line);
        ss >> user.userID >> user.name >> user.email >> user.password >> user.age
           >> user.gender >> user.role >> user.membershipStatus >> user.lastLoginDate
           >> user.loginAttempts >> user.isAccountLocked >> user.isActive;
        users.push_back(user);
    }
}




// Function to save users to a file
void saveUsersToFile(const vector<User>& users)
{

    ofstream file("users.txt");
    for (const auto& user : users)
        {

        file << user.userID << " " << user.name << " " << user.email << " " << user.password << " "
             << user.age << " " << user.gender << " " << user.role << " " << user.membershipStatus << " "
             << user.lastLoginDate << " " << user.loginAttempts << " " << user.isAccountLocked << " "
             << user.isActive << endl;
    }
}




// Function to display all users
void displayUsers(const vector<User>& users)
{

    for (const auto& user : users)
        {

        cout << "ID: " << user.userID << ", Name: " << user.name << ", Email: " << user.email
             << ", Age: " << user.age << ", Gender: " << user.gender << ", Role: " << user.role
             << ", Status: " << user.membershipStatus << endl;
    }
}

// Function to add a user
void addUser(vector<User>& users)
{

    User user;
    cout << "Enter user details (ID, Name, Email, Password, Age, Gender, Role, Membership Status): ";
    cin >> user.userID >> user.name >> user.email >> user.password >> user.age >> user.gender
        >> user.role >> user.membershipStatus;
    user.isActive = true;
    users.push_back(user);
}

// Function to search a user by ID
void searchUserByID(const vector<User>& users)
{

    int id;
    cout << "Enter user ID to search: ";
    cin >> id;
    for (const auto& user : users)
        {

        if (user.userID == id)
        {

            cout << "User found: " << user.name << " (" << user.email << ")\n";
            return;
        }
    }

    cout << "User not found.\n";
}

// Function to update user information
void updateUser(vector<User>& users)
{

    int id;
    cout << "Enter user ID to update: ";
    cin >> id;
    for (auto& user : users)
        {

        if (user.userID == id)
        {

            cout << "Enter new details for " << user.name << ":\n";
            cout << "Format: [Name Email Password Age Gender Role MembershipStatus]\n";
            cin >> user.name >> user.email >> user.password >> user.age >> user.gender
                >> user.role >> user.membershipStatus;
            cout << "User details updated successfully.\n";
            return;
        }
    }

    cout << "User not found.\n";
}

// Function to remove a user
void removeUser(vector<User>& users)
{

    int id;
    cout << "Enter user ID to remove: ";
    cin >> id;
    auto it = remove_if(users.begin(), users.end(), [id](const User& user) { return user.userID == id; });

    if (it != users.end())
        {

        users.erase(it, users.end());
        cout << "User removed successfully.\n";
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Function to display total number of users
void displayTotalUsers(const vector<User>& users)
{

    cout << "Total Users: " << users.size() << endl;

}

// Function to sort users by name
void sortUsersByName(vector<User>& users)
{

    sort(users.begin(), users.end(), [](const User& a, const User& b)
         {

        return a.name < b.name;
    });

    cout << "Users sorted by name.\n";
}

// Function to display users by membership status
void displayUsersByMembershipStatus(const vector<User>& users, const string& status)
{

    for (const auto& user : users)
        {

        if (user.membershipStatus == status)
        {

            cout << "User: " << user.name << ", Status: " << user.membershipStatus << endl;
        }
    }

}

// Function to activate a user
void activateUser(vector<User>& users, int userID)
{

    for (auto& user : users)
        {

        if (user.userID == userID)
        {

            user.isActive = true;
            cout << "User activated.\n";
            return;
        }
    }

    cout << "User not found.\n";

}

// Function to deactivate a user
void deactivateUser(vector<User>& users, int userID)
{

    for (auto& user : users)
        {

        if (user.userID == userID)
        {

            user.isActive = false;
            cout << "User deactivated.\n";
            return;
        }
    }

    cout << "User not found.\n";

}

// Function to search for a user by name
 //   here linear search has used
// Function to preprocess the bad character heuristic
void preprocessBadChar(const string& pattern, vector<int>& badChar)
{

    int m = pattern.size();
    fill(badChar.begin(), badChar.end(), -1);

    for (int i = 0; i < m; ++i)
        {

        badChar[pattern[i]] = i; // Store the last occurrence of each character in the pattern

    }

}

// Boyer-Moore string matching function
void searchUserByName(const vector<User>& users)
{

    cout << "Enter the name of the user to search: ";
    string name;
    cin.ignore(); // Clear leftover input
    getline(cin, name); // Allow spaces in the name

    // Lambda for Boyer-Moore string matching
    auto boyerMooreSearch = [](const string& text, const string& pattern) -> bool
    {

        int n = text.size();
        int m = pattern.size();

        if (m > n) return false; // Pattern cannot be in text if it's longer

        vector<int> badChar(256, -1); // For extended ASCII characters

        // Preprocess the bad character heuristic
        for (int i = 0; i < m; ++i)
            {

            badChar[pattern[i]] = i;

        }

        int shift = 0;
        while (shift <= (n - m))
            {

            int j = m - 1;

            // Compare pattern from right to left
            while (j >= 0 && pattern[j] == text[shift + j])
                {

                --j;

            }

            if (j < 0)
                {

                return true; // Pattern found
            }
            else
                {

                // Calculate the shift using the bad character heuristic
                shift += max(1, j - badChar[text[shift + j]]);
            }
        }

        return false; // Pattern not found

    };

    // Search for the user by name using the embedded Boyer-Moore algorithm
    for (const auto& user : users)
        {

        if (boyerMooreSearch(user.name, name))
        {

            cout << "User found:\n";
            cout << "ID: " << user.userID << "\n"
                 << "Name: " << user.name << "\n"
                 << "Email: " << user.email << "\n"
                 << "Age: " << user.age << "\n"
                 << "Gender: " << user.gender << "\n"
                 << "Role: " << user.role << "\n"
                 << "Membership Status: " << user.membershipStatus << "\n"
                 << "Last Login Date: " << user.lastLoginDate << "\n";
            return;
        }
    }

    cout << "User not found.\n";

}

// Function to display users by age group
void displayUsersByAgeGroup(const vector<User>& users, int minAge, int maxAge)
{

    for (const auto& user : users)
        {

        if (user.age >= minAge && user.age <= maxAge)
        {

            cout << "User: " << user.name << ", Age: " << user.age << endl;

        }
    }

}

// Function to promote a user to admin
void promoteUserToAdmin(vector<User>& users)
{

    cout << "Enter the name of the user to promote to admin: ";
    string name;
    cin.ignore();  // Clear any leftover input
    getline(cin, name);  // Allow spaces in the name

    for (auto& user : users)
        {

        if (user.name == name)
        {

            user.role = "Admin";
            cout << "User " << user.name << " has been promoted to admin.\n";
            return;

        }
    }

    cout << "User not found.\n";

}

// Function to change user password
void resetUserPassword(vector<User>& users)
{

    cout << "Available Users:\n";
    for (const auto& user : users)
        {

        cout << "ID: " << user.userID << ", Name: " << user.name << "\n";

    }

    string userName;
    cout << "Enter the name of the user whose password you want to reset: ";
    cin.ignore(); // Clear any leftover input buffer
    getline(cin, userName);

    for (auto& user : users)
        {

        if (user.name == userName)
        {

            string newPassword;
            cout << "Enter new password for user " << user.name << ": ";
            cin >> newPassword;
            user.password = newPassword;
            cout << "Password updated successfully for user: " << user.name << ".\n";
            return;

        }
    }

    cout << "User with name '" << userName << "' not found.\n";

}


// Function to reset user password
void resetUserPassword(vector<User>& users, int userID)
{

    for (auto& user : users)
        {

        if (user.userID == userID)
        {

            string newPassword;
            cout << "Enter new password for user " << user.name << ": ";
            cin >> newPassword;
            user.password = newPassword;
            cout << "Password updated successfully for user: " << user.name << ".\n";
            return;

        }
    }

    cout << "User with ID " << userID << " not found.\n";

}

// Function to merge two user accounts
void mergeUserAccounts(vector<User>& users)
{

    int userID1, userID2;

    // Prompt the user for the IDs
    cout << "Enter the first user ID (to keep): ";
    cin >> userID1;
    cout << "Enter the second user ID (to merge): ";
    cin >> userID2;

    auto it1 = find_if(users.begin(), users.end(), [userID1](const User& user) { return user.userID == userID1; });
    auto it2 = find_if(users.begin(), users.end(), [userID2](const User& user) { return user.userID == userID2; });

    if (it1 != users.end() && it2 != users.end())
        {

        // Merge activity logs and notifications
        it1->activityLog.insert(it1->activityLog.end(), it2->activityLog.begin(), it2->activityLog.end());
        it1->notifications.insert(it1->notifications.end(), it2->notifications.begin(), it2->notifications.end());

        // Remove the second user
        users.erase(it2);
        cout << "User accounts successfully merged.\n";
    }
    else
        {

        cout << "One or both user IDs not found.\n";

    }

}


// Additional functions can be implemented similarly as needed.
// Analytics and Statistics Functions

// Function to display membership statistics
void displayMembershipStatistics(const vector<User>& users)
{

    map<string, vector<string>> membershipStats;

    // Group user names by membership status
    for (const auto& user : users)
        {

        membershipStats[user.membershipStatus].push_back(user.name);

    }

    // Display the membership statistics with user names
    for (const auto& entry : membershipStats)
        {

        cout << entry.first << " (" << entry.second.size() << " users):\n";
        for (const auto& name : entry.second)
        {

            cout << "  - " << name << "\n";

        }
    }

}


// Function to display the average user age
void displayAverageUserAge(const vector<User>& users)
{

    if (users.empty())
        {

        cout << "No users available to calculate the average age.\n";
        return;

    }

    int totalAge = 0;
    for (const auto& user : users)
        {

        totalAge += user.age;

    }

    cout << "Average user age: " << static_cast<double>(totalAge) / users.size() << endl;

}

// Function to display gender statistics
void displayGenderStatistics(const vector<User>& users)
{

    map<string, int> genderStats;
    for (const auto& user : users)
        {

        genderStats[user.gender]++;

    }

    for (const auto& entry : genderStats)
        {

        cout << entry.first << ": " << entry.second << " users\n";

    }
}

// Function to display the most active users
void displayMostActiveUsers(const vector<User>& users, int topN)
{

    vector<User> sortedUsers = users;
    sort(sortedUsers.begin(), sortedUsers.end(), [](const User& a, const User& b)
         {

        return a.activityLog.size() > b.activityLog.size();

    });

    for (int i = 0; i < topN && i < sortedUsers.size(); ++i)
        {

        cout << "User: " << sortedUsers[i].name
             << ", Activities: " << sortedUsers[i].activityLog.size() << endl;

    }

}

// Function to display users based on the last login date
void displayUsersByLastLoginDate(const vector<User>& users, const string& date)
{

    for (const auto& user : users)
        {

        if (user.lastLoginDate >= date)
        {

            cout << "User: " << user.name << ", Last Login: " << user.lastLoginDate << endl;

        }
    }

}

// Function to display user activity summary
void displayUserActivitySummary(const vector<User>& users)
{

    for (const auto& user : users)
        {

        cout << "User: " << user.name << ", Total Activities: " << user.activityLog.size() << endl;

    }

}

// Customization and Notifications

// Function to send a notification to a user

void sendNotificationToUser(vector<User>& users)
{

    int userID;
    string message;

    // Ask for the user ID
    cout << "Enter the User ID to send the notification: ";
    cin >> userID;

    // Ask for the notification message
    cout << "Enter the message to send: ";
    cin.ignore();  // To ignore any leftover newline character from previous input
    getline(cin, message);

    // Find the user by ID
    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });

    if (it != users.end())
        {

        it->notifications.push_back(message);

        cout << "Notification sent to " << it->name << ": " << message << endl;

    }
    else
        {

        cout << "User not found.\n";

    }
}


//Function to send a notification to all users
void sendNotificationToAllUsers(vector<User>& users, const string& message)
{

    for (auto& user : users)
        {

        user.notifications.push_back(message);
        cout << "Notification sent to " << user.name << ": " << message << endl;

    }

}

// Function to update user preferences
void updateUserPreferences(vector<User>& users, int userID)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (it != users.end())
        {

        cout << "Enter new preferences (key-value pairs):\n";
        string key, value;
        while (cin >> key >> value)
        {
            it->preferences[key] = value;
            cout << "Preference updated.\n";
        }
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Function to personalize user interface
void personalizeUserInterface(vector<User>& users, int userID, const string& theme)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });

    if (it != users.end())
        {

        it->preferences["theme"] = theme;
        cout << "User interface personalized with theme: " << theme << endl;

    }
    else
        {

        cout << "User not found.\n";
    }

}

// Security and Access Management

// Function to lock a user account
void lockUserAccount(vector<User>& users, int userID)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (it != users.end())
        {

        it->isAccountLocked = true;
        cout << "User account locked.\n";
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Function to unlock a user account
void unlockUserAccount(vector<User>& users, int userID)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (it != users.end())
        {

        it->isAccountLocked = false;
        cout << "User account unlocked.\n";
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Function to track user login attempts
void trackUserLoginAttempts(vector<User>& users, int userID, int attemptCount)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (it != users.end())
        {

        it->loginAttempts = attemptCount;
        cout << "Login attempts tracked for user " << it->name << ": " << attemptCount << endl;
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Function to display users by role
void displayUsersByRole(const vector<User>& users, const string& role)
{

    for (const auto& user : users)
        {

        if (user.role == role)
        {

            cout << "User: " << user.name << ", Role: " << user.role << endl;
        }
    }

}

// Function to implement two-factor authentication for a user
void implementTwoFactorAuthentication(vector<User>& users, int userID)
{

    auto it = find_if(users.begin(), users.end(), [userID](const User& user) { return user.userID == userID; });
    if (it != users.end())
        {

        string method;
        cout << "Enter the two-factor authentication method (SMS, Email, App): ";
        cin >> method;
        it->twoFactorMethods.insert(method);
        cout << "Two-factor authentication implemented for user " << it->name << " with method: " << method << endl;
    }
    else
        {

        cout << "User not found.\n";
    }

}

// Data Integrity and Backup

// Function to backup the user database
void backupUserDatabase(const vector<User>& users, const string& backupFileName)
{

    ofstream backupFile(backupFileName);
    for (const auto& user : users)
        {

        backupFile << user.userID << " " << user.name << " " << user.email << " " << user.password << " "
                   << user.age << " " << user.gender << " " << user.role << " " << user.membershipStatus << " "
                   << user.lastLoginDate << " " << user.loginAttempts << " " << user.isAccountLocked << " "
                   << user.isActive << endl;
    }

    cout << "User database backed up to " << backupFileName << endl;

}

// Function to restore the user database
void restoreUserDatabase(vector<User>& users, const string& backupFileName)
{

    ifstream backupFile(backupFileName);
    string line;
    users.clear();
    while (getline(backupFile, line))
        {

        User user;
        stringstream ss(line);
        ss >> user.userID >> user.name >> user.email >> user.password >> user.age
           >> user.gender >> user.role >> user.membershipStatus >> user.lastLoginDate
           >> user.loginAttempts >> user.isAccountLocked >> user.isActive;
        users.push_back(user);
    }

    cout << "User database restored from " << backupFileName << endl;

}


// Function to trim spaces from a string
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to load reports from a file
void loadReportsFromFile(vector<ReportsAnalytics>& reports)
 {
    ifstream inputFile("Report.txt");
    if (!inputFile)
        {
        cout << "Error: Unable to open the file. Ensure 'Report.txt' exists in the correct directory." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line))
        {
        istringstream ss(line);
        ReportsAnalytics report;
        try {
            string temp;
            getline(ss, temp, ' ');
            if (temp.empty()) continue;
            report.reportID = stoi(trim(temp));

            getline(ss, report.reportName, ' ');
            getline(ss, report.reportDate, ' ');
            getline(ss, report.description, ' ');

            getline(ss, temp, ' ');
            report.booksBorrowed = stoi(trim(temp));

            getline(ss, temp, ' ');
            report.booksReturned = stoi(trim(temp));

            getline(ss, temp, ' ');
            report.overdueBooks = stoi(trim(temp));

            getline(ss, report.activityType, ' ');
            getline(ss, report.popularBook, ' ');
            getline(ss, report.topUser, ' ');
            getline(ss, report.userStatus, ' ');
            getline(ss, report.bookConditionRemarks);

            reports.push_back(report);
        } catch (const exception& e)
         {
            cout << "Error parsing line: " << line << "\nError: " << e.what() << endl;
        }
    }

    inputFile.close();
    cout << "Reports loaded successfully from file." << endl;
}

// Function to save reports to a file
void saveReportsToFile(const vector<ReportsAnalytics>& reports)
 {
    ofstream outputFile("Report.txt");
    if (!outputFile)
        {

        cout << "Error: Unable to open the file for writing." << endl;
        return;

    }

    for (const auto& report : reports)
        {

        outputFile << report.reportID << " "
                   << report.reportName << " "
                   << report.reportDate << " "
                   << report.description << " "
                   << report.booksBorrowed << " "
                   << report.booksReturned << " "
                   << report.overdueBooks << " "
                   << report.activityType << " "
                   << report.popularBook << " "
                   << report.topUser << " "
                   << report.userStatus << " "
                   << report.bookConditionRemarks << "\n";
    }

    outputFile.close();
    cout << "Reports saved successfully to file." << endl;
}

// Function to display all reports
void displayReports(const vector<ReportsAnalytics>& reports)
 {
    if (reports.empty())
        {
        cout << "No reports available to display." << endl;
        return;
    }

    cout << left << setw(5) << "ID"
         << setw(25) << "Report Name"
         << setw(15) << "Date"
         << setw(20) << "Description"
         << setw(10) << "Borrowed"
         << setw(10) << "Returned"
         << setw(10) << "Overdue"
         << setw(20) << "Activity Type"
         << setw(25) << "Popular Book"
         << setw(25) << "Top User"
         << setw(15) << "User Status"
         << setw(20) << "Condition Remarks" << endl;

    cout << string(170, '-') << endl;

    for (const auto& report : reports)
        {
        cout << setw(5) << report.reportID
             << setw(25) << report.reportName
             << setw(15) << report.reportDate
             << setw(20) << report.description
             << setw(10) << report.booksBorrowed
             << setw(10) << report.booksReturned
             << setw(10) << report.overdueBooks
             << setw(20) << report.activityType
             << setw(25) << report.popularBook
             << setw(25) << report.topUser
             << setw(15) << report.userStatus
             << setw(20) << report.bookConditionRemarks << endl;
    }
}

// Function to calculate and display total fines
void calculateTotalFines(const vector<ReportsAnalytics>& reports)
 {
    double totalFines = 0.0;
    for (const auto& report : reports)
        {

        totalFines += report.overdueBooks * 10.0; // Example fine calculation: $10 per overdue book
    }

    cout << "Total fines: $" << fixed << setprecision(2) << totalFines << endl;
}

// Function to find and display the most borrowed book
void findMostBorrowedBook(const vector<ReportsAnalytics>& reports)
{
    map<string, int> bookCount;
    for (const auto& report : reports)
        {

        bookCount[report.popularBook]++;

    }

    string mostBorrowedBook;
    int maxCount = 0;
    for (const auto& [book, count] : bookCount)
        {

        if (count > maxCount)
        {

            maxCount = count;
            mostBorrowedBook = book;
        }
    }


    if (!mostBorrowedBook.empty())
        {

        cout << "Most borrowed book: " << mostBorrowedBook << " (" << maxCount << " times)" << endl;
    }
    else

    {
        cout << "No data available for most borrowed book." << endl;
    }
}

// Individual feature display functions
void displayBooksBorrowed(const vector<ReportsAnalytics>& reports)
 {
    cout << "Books Borrowed:" << endl;
    for (const auto& report : reports)
        {

        cout << report.reportName << ": " << report.booksBorrowed << endl;
    }

}

void displayBooksReturned(const vector<ReportsAnalytics>& reports)

{
    cout << "Books Returned:" << endl;
    for (const auto& report : reports)
        {

        cout << report.reportName << ": " << report.booksReturned << endl;
    }

}

void displayOverdueBooks(const vector<ReportsAnalytics>& reports)
{

    cout << "Overdue Books:" << endl;
    for (const auto& report : reports)
        {

        cout << report.reportName << ": " << report.overdueBooks << endl;
    }

}

void displayActivityType(const vector<ReportsAnalytics>& reports)
{

    cout << "Activity Types:" << endl;
    for (const auto& report : reports)
        {

        cout << report.reportName << ": " << report.activityType << endl;

    }

}

void displayPopularBooks(const vector<ReportsAnalytics>& reports)
{

    cout << "Popular Books:" << endl;
    for (const auto& report : reports)


        {

        cout << report.reportName << ": " << report.popularBook << endl;
    }

}

void displayTopUsers(const vector<ReportsAnalytics>& reports)
 {
    cout << "Top Users:" << endl;
    for (const auto& report : reports)

        {

        cout << report.reportName << ": " << report.topUser << endl;
    }

}

void displayUserStatuses(const vector<ReportsAnalytics>& reports)
 {
    cout << "User Statuses:" << endl;
    for (const auto& report : reports)

        {

        cout << report.reportName << ": " << report.userStatus << endl;
    }

}

void displayBookConditionRemarks(const vector<ReportsAnalytics>& reports)
 {
    cout << "Book Condition Remarks:" << endl;
    for (const auto& report : reports)
        {

        cout << report.reportName << ": " << report.bookConditionRemarks << endl;
    }

}

// Function to sort reports by date
void sortReportsByDate(vector<ReportsAnalytics>& reports)
 {
    sort(reports.begin(), reports.end(), [](const ReportsAnalytics& a, const ReportsAnalytics& b)
          {
        return a.reportDate < b.reportDate;
    });
    cout << "Reports sorted by date." << endl;
}

// Function to search reports by criteria
void searchReportsByCriteria(const vector<ReportsAnalytics>& reports)
{
    string criteria;
    cout << "Enter search criteria (Report Name, Popular Book, Top User): ";
    cin.ignore();
    getline(cin, criteria);

    cout << "Search Results:" << endl;
    for (const auto& report : reports)
        {

        if (report.reportName.find(criteria) != string::npos ||
            report.popularBook.find(criteria) != string::npos ||
            report.topUser.find(criteria) != string::npos)
            {

            cout << report.reportName << " | " << report.popularBook << " | " << report.topUser << endl;
        }
    }
}

// Function to update a report
void updateReport(vector<ReportsAnalytics>& reports)
 {
    int reportID;
    cout << "Enter Report ID to update: ";
    cin >> reportID;

    auto it = find_if(reports.begin(), reports.end(), [reportID](const ReportsAnalytics& report)
                       {
        return report.reportID == reportID;
    });

    if (it != reports.end())
        {
        cout << "Enter new details for the report:\n";
        cout << "Report Name: ";
        cin.ignore();
        getline(cin, it->reportName);
        cout << "Report Date: ";
        getline(cin, it->reportDate);
        cout << "Description: ";
        getline(cin, it->description);
        cout << "Books Borrowed: ";
        cin >> it->booksBorrowed;
        cout << "Books Returned: ";
        cin >> it->booksReturned;
        cout << "Overdue Books: ";
        cin >> it->overdueBooks;
        cout << "Activity Type: ";
        cin.ignore();
        getline(cin, it->activityType);
        cout << "Popular Book: ";
        getline(cin, it->popularBook);
        cout << "Top User: ";
        getline(cin, it->topUser);
        cout << "User Status: ";
        getline(cin, it->userStatus);
        cout << "Book Condition Remarks: ";
        getline(cin, it->bookConditionRemarks);

        cout << "Report updated successfully." << endl;
    }
    else
    {

        cout << "Report with ID " << reportID << " not found." << endl;
    }

}

// Function to delete a report
void deleteReport(vector<ReportsAnalytics>& reports)
 {
    int reportID;
    cout << "Enter Report ID to delete: ";
    cin >> reportID;

    auto it = remove_if(reports.begin(), reports.end(), [reportID](const ReportsAnalytics& report)
                        {
        return report.reportID == reportID;
    });

    if (it != reports.end())

        {

        reports.erase(it, reports.end());
        cout << "Report deleted successfully." << endl;
    }
    else
        {

        cout << "Report with ID " << reportID << " not found." << endl;
    }

}

// Function to add a new report
void addNewReport(vector<ReportsAnalytics>& reports)

 {
    ReportsAnalytics newReport;
    cout << "Enter details for the new report:\n";
    cout << "Report ID: ";
    cin >> newReport.reportID;
    cout << "Report Name: ";
    cin.ignore();
    getline(cin, newReport.reportName);
    cout << "Report Date: ";
    getline(cin, newReport.reportDate);
    cout << "Description: ";
    getline(cin, newReport.description);
    cout << "Books Borrowed: ";
    cin >> newReport.booksBorrowed;
    cout << "Books Returned: ";
    cin >> newReport.booksReturned;
    cout << "Overdue Books: ";
    cin >> newReport.overdueBooks;
    cout << "Activity Type: ";
    cin.ignore();
    getline(cin, newReport.activityType);
    cout << "Popular Book: ";
    getline(cin, newReport.popularBook);
    cout << "Top User: ";
    getline(cin, newReport.topUser);
    cout << "User Status: ";
    getline(cin, newReport.userStatus);
    cout << "Book Condition Remarks: ";
    getline(cin, newReport.bookConditionRemarks);

    reports.push_back(newReport);
    cout << "New report added successfully." << endl;
}


void showMenu()
 {
    cout << "\nLibrary Report Management System\n";
    cout << "1. Load Reports from File\n";
    cout << "2. Display Reports\n";
    cout << "3. Calculate Total Fines\n";
    cout << "4. Find Most Borrowed Book\n";
    cout << "5. Books Borrowed\n";
    cout << "6. Books Returned\n";
    cout << "7. Overdue Books\n";
    cout << "8. Activity Type\n";
    cout << "9. Popular Book\n";
    cout << "10. Top User\n";
    cout << "11. User Status\n";
    cout << "12. Book Condition Remarks\n";
    cout << "13. Sort Reports by Date\n";
    cout << "14. Search Reports by Criteria\n";
    cout << "15. Update a Report\n";
    cout << "16. Delete a Report\n";
    cout << "17. Add a New Report\n";
    cout << "18. Save Reports to File\n";
    cout << "19. Exit\n";
    cout << "Enter your choice: ";
}
void printColoredWelcome()
{


    //cout << "\033[1;31mW\033[1;32me\033[1;33ml\033[1;34mc\033[1;35mo\033[1;36mm\033[1;37me\033[0m\n";
    cout << "\033[1;36m--------------------------------- Welcome to the Library Management System --------------------------------- 033[0m\n";
     cout << "\033[1;34m--- Library Management System ---\033[0m\n"; // Title in blue
    cout << "\033[1;31m1. Manage Users\033[0m\n";                   // Option 1 in red
    cout << "\033[1;32m2. Manage Books\033[0m\n";                   // Option 2 in green
    cout << "\033[1;33m3. Manage Borrowing & Returning\033[0m\n";   // Option 3 in yellow
    cout << "\033[1;35m4. Manage Reports & Analytics\033[0m\n";     // Option 4 in magenta
    cout << "\033[1;36m5. Exit\033[0m\n";                           // Option 5 in cyan
    cout << "\033[1;37mEnter your choice: \033[0m";                 // Input prompt in white

}



int main()
{

    printColoredWelcome();
    vector<User> users;
    vector<Book> books;
    stack<Book> deletedBooks; // Stack to store deleted books for restoration

    vector<BorrowingReturn> borrowRecords;  // Vector to store borrowing/returning records
    vector<ReportsAnalytics> reports;  // Vector to store report and analytic data
    int choice;

    do {
void printColoredMenu();
        cin >> choice;

        switch (choice) {
            case 1: { // User Management
                int userChoice;
                do {
                    cout << "\n--- User Management ---\n";
                    cout << "1. Load Users\n";
                    cout << "2. Save Users\n";
                    cout << "3. Display Users\n";
                    cout << "4. Add User\n";
                    cout << "5. Search User by ID\n";
                    cout << "6. Update User\n";
                    cout << "7. Remove User\n";
                    cout << "8. Display Total Users\n";
                    cout << "9. Sort Users by Name\n";
                    cout << "10. Search for a user by their name\n";
                    cout << "11. Display users within a specific age range\n";
                    cout << "12. Promote a user to Admin\n";
                    cout << "13. Change a user's password\n";
                    cout << "14. Reset a user's password\n";
                    cout << "15. Merge two user accounts\n";
                    cout << "16. Display membership statistics\n";
                    cout << "17. Display average user age\n";
                    cout << "18. Display gender statistics\n";
                    cout << "19. Display most active users\n";
                    cout << "20. Display users by last login date\n";
                    cout << "21. Display user activity summary\n";
                    cout << "22. Send notification to a user\n";
                    cout << "23. Send notification to all users\n";
                    cout << "24. Update user preferences\n";
                    cout << "25. Personalize user interface\n";
                    cout << "26. Lock a user account\n";
                    cout << "27. Unlock a user account\n";
                    cout << "28. Track user login attempts\n";
                    cout << "29. Display users by role\n";
                    cout << "30. Implement two-factor authentication\n";
                    cout << "31. Backup user database\n";
                    cout << "32. Restore user database\n";
                    cout << "33. Exit User Management\n";
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                        case 1:
                            loadUsersFromFile(users);
                            break;
                        case 2:
                            saveUsersToFile(users);
                            break;
                        case 3:
                            displayUsers(users);
                            break;
                        case 4:
                            addUser(users);
                            break;
                        case 5:
                            searchUserByID(users);
                            break;
                        case 6:
                            updateUser(users);
                            break;
                        case 7:
                            removeUser(users);
                            break;
                        case 8:
                            displayTotalUsers(users);
                            break;
                        case 9:
                            sortUsersByName(users);
                            break;
                        case 10:
                            searchUserByName(users);
                            break;
                        case 11:
                            displayUsersByAgeGroup(users, 18, 30);
                            break;
                        case 12:
                         promoteUserToAdmin(users);
                            break;
                        case 13:
                            resetUserPassword(users);

                            break;
                        case 14:
                            resetUserPassword(users, 1);
                            break;
                        case 15:
                            mergeUserAccounts(users) ;
                            break;
                        case 16:
                            displayMembershipStatistics(users);
                            break;
                        case 17:
                            displayAverageUserAge(users);
                            break;
                        case 18:
                            displayGenderStatistics(users);
                            break;
                        case 19:
                            displayMostActiveUsers(users, 5);
                            break;
                        case 20:
                            displayUsersByLastLoginDate(users, "2024-01-01");
                            break;
                        case 21:
                            displayUserActivitySummary(users);
                            break;
                        case 22:
                            sendNotificationToUser(users);
                            break;
                        case 23:
                            sendNotificationToAllUsers(users, "Hello All Users!");
                            break;
                        case 24:
                            updateUserPreferences(users, 1);
                            break;
                        case 25:
                            personalizeUserInterface(users, 1, "Dark Theme");
                            break;
                        case 26:
                            lockUserAccount(users, 1);
                            break;
                        case 27:
                            unlockUserAccount(users, 1);
                            break;
                        case 28:
                            trackUserLoginAttempts(users, 1, 3);
                            break;
                        case 29:
                            displayUsersByRole(users, "Admin");
                            break;
                        case 30:
                            implementTwoFactorAuthentication(users, 1);
                            break;
                        case 31:
                            backupUserDatabase(users, "backupFile.txt");
                            break;
                        case 32:
                            restoreUserDatabase(users, "backupFile.txt");
                            break;
                        case 33:
                            cout << "Exiting User Management.\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (userChoice != 33);
                break;
            }








             case 2: { // Book Management
                int bookChoice;
                map<int, bool> bookDamaged; // Map to track damaged books
                map<int, bool> bookReserved; // Map to track reserved books
                map<int, bool> bookAvailability;
                string keyword;
                do {
                    cout << "\n--- Book Management ---\n";
                    cout << "1. Load Books from File\n";
                    cout << "2. Save Books to File\n";
                    cout << "3. Display All Books\n";
                    cout << "4. Add a Book\n";
                    cout << "5. Search Book by ID\n";
                    cout << "6. Update a Book\n";
                    cout << "7. Remove a Book\n";
                    cout << "8. Restore Last Deleted Book\n";
                    cout << "9. Display Total Books\n";
                    cout << "10. Sort Books by Name\n";
                    cout << "11. Sort Books by ID\n";
                    cout << "12. Search Book by Name\n";
                    cout << "13. Check Book Availability\n";
                    cout << "14. Mark a Book as Damaged\n";
                    cout << "15. Display Damaged Books\n";
                    cout << "16. Reserve a Book\n";
                    cout << "17. Display Reserved Books\n";
                    cout << "18. Find Books by Keywords\n";
                    cout << "19. Exit Book Management\n";
                    cout << "Enter your choice: ";
                    cin >> bookChoice;

                    switch (bookChoice) {
                        case 1:
                            loadBooksFromFile(books);
                            break;
                        case 2:
                            saveBooksToFile(books);
                            break;
                        case 3:
                            displayBooks(books);
                            break;
                        case 4:
                            addBook(books);
                            break;
                        case 5:
                            searchBookByID(books);
                            break;
                        case 6:
                            updateBook(books);
                            break;
                        case 7:
                            removeBook(books, deletedBooks);
                            break;
                        case 8:
                            restoreLastDeletedBook(books, deletedBooks);
                            break;
                        case 9:
                            displayTotalBooks(books);
                            break;
                        case 10:
                            sortBooksByName(books);
                            break;
                        case 11:
                            sortBooksByID(books);
                            break;
                        case 12:
                            searchBookByName(books);
                            break;
                        case 13:
                            checkBookAvailability(books);
                            break;
                        case 14:
                            markBookAsDamaged(books, bookDamaged);
                            break;
                        case 15:
                            displayDamagedBooks(books, bookDamaged);
                            break;
                        case 16:
                            reserveBook(books, bookReserved);
                            break;
                        case 17:
                            displayReservedBooks(books, bookReserved);
                            break;
                        case 18:
                            cout << "Enter keyword to search for books: ";
                            cin >> keyword;
                            findBooksByKeywords(books, keyword);
                            break;
                        case 19:
                            cout << "Exiting Book Management.\n";
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (bookChoice != 19);
                break;
            }


            case 3: { // Borrowing & Returning Management
                int borrowChoice;
                do {
                    cout << "\n--- Borrowing & Returning Management ---\n";
                    cout << "1. Load Borrowing Records\n";
                    cout << "2. Save Borrowing Records\n";
                    cout << "3. Display Borrowing Records\n";
                    cout << "4. Borrow a Book\n";
                    cout << "5. Return a Book\n";
                    cout << "6. Calculate Fine for a Borrowing Record\n";
                    cout << "7. Exit Borrowing & Returning Management\n";
                    cout << "Enter your choice: ";
                    cin >> borrowChoice;

                    switch (borrowChoice) {
                        case 1:
                            loadBorrowingFromFile(borrowRecords);
                            break;
                        case 2:
                            saveBorrowingToFile(borrowRecords);
                            break;
                         case 3:
                              displayBorrowingRecords(borrowRecords);
                              break;
                         case 4:
                             borrowBook(borrowRecords, users, books);
                             break;
                         case 5:
                             returnBook(borrowRecords, books);
                             break;
                        case 6: {
                            int borrowID;
                            cout << "Enter borrow ID to calculate fine: ";
                            cin >> borrowID;
                            // Find the record by borrow ID and calculate fine
                            break;
                        }
                        case 7: cout << "Exiting Borrowing & Returning Management.\n"; break;
                        default: cout << "Invalid choice. Please try again.\n";
                    }
                } while (borrowChoice != 7);
                break;
            }





               case 4: { // Reports & Analytics Management
                int reportChoice;
                do {
                   cout << "\nLibrary Report Management System\n";
    cout << "1. Load Reports from File\n";
    cout << "2. Display Reports\n";
    cout << "3. Calculate Total Fines\n";
    cout << "4. Find Most Borrowed Book\n";
    cout << "5. Books Borrowed\n";
    cout << "6. Books Returned\n";
    cout << "7. Overdue Books\n";
    cout << "8. Activity Type\n";
    cout << "9. Popular Book\n";
    cout << "10. Top User\n";
    cout << "11. User Status\n";
    cout << "12. Book Condition Remarks\n";
    cout << "13. Sort Reports by Date\n";
    cout << "14. Search Reports by Criteria\n";
    cout << "15. Update a Report\n";
    cout << "16. Delete a Report\n";
    cout << "17. Add a New Report\n";
    cout << "18. Save Reports to File\n";
    cout << "19. Exit\n";
    cout << "Enter your choice: ";
        cin >> reportChoice;
                    switch (reportChoice) {
            case 1:
                loadReportsFromFile(reports);
                break;
            case 2:
                displayReports(reports);
                break;
            case 3:
                calculateTotalFines(reports);
                break;
            case 4:
                findMostBorrowedBook(reports);
                break;
            case 5:
                displayBooksBorrowed(reports);
                break;
            case 6:
                displayBooksReturned(reports);
                break;
            case 7:
                displayOverdueBooks(reports);
                break;
            case 8:
                displayActivityType(reports);
                break;
            case 9:
                displayPopularBooks(reports);
                break;
            case 10:
                displayTopUsers(reports);
                break;
            case 11:
                displayUserStatuses(reports);
                break;
            case 12:
                displayBookConditionRemarks(reports);
                break;
            case 13:
                sortReportsByDate(reports);
                break;
            case 14:
                searchReportsByCriteria(reports);
                break;
            case 15:
                updateReport(reports);
                break;
            case 16:
                deleteReport(reports);
                break;
            case 17:
                addNewReport(reports);
                break;
            case 18:
                saveReportsToFile(reports);
                break;
            case 19:
                {


                cout << "Exiting the program. Goodbye!" << endl;
                break;
                }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 19);

    return 0;
}




            case 5:
                { // Exit
                cout << "Exiting Library Management System.\n";
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);  // Keep looping until the user chooses to exit

    return 0;
}
