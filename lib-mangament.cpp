#include <iostream>
#include <string>

class Book
{
public:
    std::string name;
    std::string author;
    int id;
    Book *next;

    Book(const std::string &name, const std::string &author, int id)
        : name(name), author(author), id(id), next(nullptr) {}
};

class Student
{
public:
    std::string name;
    std::string email;
    std::string book;
    std::string author;
    int id;
    Student *next;

    Student(const std::string &name, const std::string &email, const std::string &book, const std::string &author, int id)
        : name(name), email(email), book(book), author(author), id(id), next(nullptr) {}
};

class Library
{
private:
    Book *start_lib;
    Student *start;

public:
    Library() : start_lib(nullptr), start(nullptr) {}

    ~Library()
    {
        while (start_lib)
        {
            Book *temp = start_lib;
            start_lib = start_lib->next;
            delete temp;
        }
        while (start)
        {
            Student *temp = start;
            start = start->next;
            delete temp;
        }
    }

    void initialize_lib()
    {
        add_book("The Kite Runner", "Khaled Hosseini", 101);
        add_book("To Kill A Mockingbird", "Harper Lee", 102);
        add_book("The Alchemist", "Paulo Coelho", 103);
        add_book("Pride And Prejudice", "Jane Austen", 104);
        add_book("A Tale Of Two Cities", "Charles Dickens", 105);
    }

    void display()
    {
        Student *ptr = start;
        while (ptr != nullptr)
        {
            std::cout << "\n\t************* Details of Students: **************\n";
            std::cout << "\n\t_________________________________________________\n";
            std::cout << "\n\t\t Student Name: " << ptr->name;
            std::cout << "\n\t\t Student Email: " << ptr->email;
            std::cout << "\n\t\t Name of Book Issued: " << ptr->book;
            std::cout << "\n\t\t Book ID: " << ptr->id;
            std::cout << "\n\t_________________________________________________\n";
            std::cout << "\n\n\t*************************************************\n";
            ptr = ptr->next;
        }
        std::cout << "\n\n\t Press any key to go to the main menu: ";
        std::cin.get();
        std::cin.get();
        system("cls"); // For Windows; use system("clear") on Linux
    }

    void book_issue()
    {
        if (start_lib == nullptr)
        {
            std::cout << "\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
            std::cout << "\n\n\t Press any key to go to the main menu: ";
            std::cin.get();
            std::cin.get();
            system("cls");
            return;
        }

        Book *ptr = start_lib;
        int i = 1, id;
        std::cout << "\n\t*************** Books Available: ****************\n";
        while (ptr != nullptr)
        {
            std::cout << "\n\t_________________________________________________\n";
            std::cout << "\n\t Book " << i;
            std::cout << "\n\t Book Title: " << ptr->name;
            std::cout << "\n\t Name of Author: " << ptr->author;
            std::cout << "\n\t Book ID: " << ptr->id;
            std::cout << "\n\t_________________________________________________\n";
            ptr = ptr->next;
            i++;
        }

        std::cout << "\n\n\t Enter the Book ID: ";
        std::cin >> id;
        ptr = start_lib;
        bool found = false;
        while (ptr != nullptr)
        {
            if (ptr->id == id)
            {
                found = true;
                break;
            }
            ptr = ptr->next;
        }

        if (found)
        {
            std::string name, email;
            std::cout << "\n\t Enter Student Details:\n ";
            std::cout << "\n\t Enter your Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "\n\t Enter your Email: ";
            std::getline(std::cin, email);

            Student *new_student = new Student(name, email, ptr->name, ptr->author, ptr->id);
            std::cout << "\n\t Issue of Book ID " << new_student->id << " done successfully!\n";
            std::cout << "\n\n\t*************************************************\n";
            if (start == nullptr)
            {
                start = new_student;
            }
            else
            {
                Student *ptr2 = start;
                while (ptr2->next != nullptr)
                {
                    ptr2 = ptr2->next;
                }
                ptr2->next = new_student;
            }
            start_lib = delete_book(new_student->id);
            std::cout << "\n\n\t Press any key to go to the main menu: ";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
        else
        {
            std::cout << "\n\t\t      ...Invalid Option!...\n";
            std::cout << "\n\t\t      Press any key to try again: ";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
    }

    void book_return()
    {
        int id;
        std::cout << "\n\n\t*************** Books Submission: ****************\n";
        std::cout << "\n\n\t Enter your Book ID: ";
        std::cin >> id;

        Student *ptr = start;
        Student *preptr = nullptr;
        bool found = false;
        while (ptr != nullptr)
        {
            if (ptr->id == id)
            {
                found = true;
                break;
            }
            preptr = ptr;
            ptr = ptr->next;
        }

        if (found)
        {
            std::string bookname = ptr->book;
            std::string authorname = ptr->author;
            int book_id = ptr->id;

            if (preptr == nullptr)
            { // Node to delete is the first node
                start = ptr->next;
            }
            else
            {
                preptr->next = ptr->next;
            }
            delete ptr;

            add_book(bookname, authorname, book_id);

            std::cout << "\n\t Thank you! \n\t Do visit again! ";
            std::cout << "\n\n\t Press any key to go to the main menu: ";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
        else
        {
            std::cout << "\n\tSorry the book doesn't exist! Please recheck the entered ID";
            std::cout << "\n\t\t\t\t      Press any key to try again: ";
            std::cin.get();
            std::cin.get();
            system("cls");
        }
    }

    void add_book(const std::string &name, const std::string &author, int id)
    {
        Book *new_book = new Book(name, author, id);
        if (start_lib == nullptr)
        {
            start_lib = new_book;
        }
        else
        {
            Book *ptr = start_lib;
            while (ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            ptr->next = new_book;
        }
    }

    Book *delete_book(int id)
    {
        Book *ptr = start_lib;
        Book *preptr = nullptr;

        if (ptr != nullptr && ptr->id == id)
        {
            start_lib = ptr->next;
            delete ptr;
            return start_lib;
        }

        while (ptr != nullptr && ptr->id != id)
        {
            preptr = ptr;
            ptr = ptr->next;
        }

        if (ptr == nullptr)
            return start_lib;

        preptr->next = ptr->next;
        delete ptr;
        return start_lib;
    }

    void greetings()
    {
        std::cout << "\n\n";
        std::cout << "\t\t\t     ****************************************\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *     ----------------------------     *\n";
        std::cout << "\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n";
        std::cout << "\t\t\t     *     ----------------------------     *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     ****************************************\n";
        std::cout << "\n\n";
        std::cout << "\t\t\t     ****************************************\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *       ------------------------       *\n";
        std::cout << "\t\t\t     *           STUDENT LIBRARY            *\n";
        std::cout << "\t\t\t     *       ------------------------       *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     *       Mumbai,Maharashtra,India       *\n";
        std::cout << "\t\t\t     *     Email: studentlib@gmail.com      *\n";
        std::cout << "\t\t\t     *     Contact:8800991010,8800992020    *\n";
        std::cout << "\t\t\t     *                                      *\n";
        std::cout << "\t\t\t     ****************************************\n";
        std::cout << "\n\n\t\t\t             Press Enter to continue: ";
        std::cin.get();
    }

    void main_menu()
    {
        int choice;
        do
        {
            std::cout << "\n\n";
            std::cout << "\n\t\t\t*************************************************\n";
            std::cout << "\n\t\t\t\t      MAIN MENU: ";
            std::cout << "\n\t\t\t\t     1.ISSUE OF BOOKS ";
            std::cout << "\n\t\t\t\t     2.RETURN OF BOOKS ";
            std::cout << "\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ";
            std::cout << "\n\t\t\t\t     4.EXIT\n ";
            std::cout << "\n\t\t\t*************************************************\n";
            std::cout << "\n\t\t\t\t      Enter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                book_issue();
                break;
            case 2:
                book_return();
                break;
            case 3:
                display();
                break;
            case 4:
                std::exit(0);
            default:
                std::cout << "\n\t\t\t\t      ...Invalid Option!...\n";
                std::cout << "\n\t\t\t\t      Press Enter to try again: ";
                std::cin.get();
                std::cin.get();
                system("cls");
            }
        } while (choice != 4);
    }
};

int main()
{
    Library library;
    library.initialize_lib();
    library.greetings();
    library.main_menu();
    return 0;
}
