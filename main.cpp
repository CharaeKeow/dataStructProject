#include "header.h"
#include <iostream>
using namespace std;

int main() {
	List<string> book;
	int choice, position;
	string BookID;
	string BookAuthor;
	string BookTitle;

	while (1) {
		cout << "\nWhat would you like to do?: " << endl;
		cout << "1. Show All Books" << endl;
		cout << "2. Add Books" << endl;
		cout << "3. Remove A Book" << endl;
		cout << "4. Search Books (Coming Soon)" << endl;
		cout << "5. Exit The Program" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << endl;
			book.displayBook(); // display all contacts
			cout << endl;
			break;
		case 2:
			cout << "\nEnter the Book ID: ";
			cin >> BookID;
			cout << "\nEnter the Book Title: ";
			cin >> BookTitle;
			cout << "\nEnter the Book Author: ";
			cin >> BookAuthor;
			book.addBook(BookID, BookTitle, BookAuthor); // create the contact in the linked list
			cout << endl;
			break;
		case 3:
			cout << "Enter the contact number of the contact you would like to remove: ";
			cin >> position;
			if (position == 1)
				book.deleteHead();
			else
				book.deleteBook(position); // delete contact from list
			break;
		case 5:
			exit(1);
			break;
		default:
			cout << "\n" << choice << " is not an option. Please select a valid option." << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
