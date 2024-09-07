# -Library-management-system-
Here's a description you could use for the GitHub repository containing the SQL code for the Library Management System:

---

# Library Management System SQL Scripts

This repository contains SQL scripts for setting up a simple Library Management System. The system includes various tables, stored procedures, and sample data to manage and query a library's books, borrowers, and loan transactions.

## Contents

### Schema Setup

- **`LibraryManagementSystemProcedure.sql`**: The main script that creates the database `db_LibraryManagement`, tables, and populates them with sample data.

### Tables

1. **`tbl_publisher`**: Stores information about publishers.
2. **`tbl_book`**: Stores book details and links to publishers.
3. **`tbl_library_branch`**: Stores details about library branches.
4. **`tbl_borrower`**: Stores information about borrowers.
5. **`tbl_book_loans`**: Tracks book loans including due dates.
6. **`tbl_book_copies`**: Stores the number of copies of each book in each branch.
7. **`tbl_book_authors`**: Associates books with their authors.

### Stored Procedures

1. **`bookCopiesAtAllSharpstown`**: Retrieves the number of copies of a specific book at the "Sharpstown" branch.
2. **`bookCopiesAtAllBranches`**: Retrieves the number of copies of a specific book at each library branch.
3. **`NoLoans`**: Lists all borrowers who do not currently have any books checked out.
4. **`LoanersInfo`**: Retrieves information on books loaned from the "Sharpstown" branch that are due today, including book titles and borrower details.
5. **`TotalLoansPerBranch`**: Provides the total number of books loaned out from each library branch.
6. **`BooksLoanedOut`**: Lists borrowers who have more than a specified number of books checked out.
7. **`BookbyAuthorandBranch`**: Retrieves the titles and number of copies of books authored by a specific author at a given branch.

## Usage

1. **Run the main script**: Execute the `LibraryManagementSystemProcedure.sql` script in your SQL Server environment to create the database, tables, and sample data.
2. **Execute Stored Procedures**: Use the provided stored procedures to query the database for various reports and insights.

## Prerequisites

- SQL Server or a compatible SQL environment.
- Basic understanding of SQL and database management.

