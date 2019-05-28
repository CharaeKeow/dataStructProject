#include <iostream>
#include <fstream> //for file handling
#include <string> //we use string data type
#include <Windows.h>
//#include <stdio.h> //no longer needed
//#include <string.h>
using namespace std;
#include "header.h"

int main() {
	int choice; //For menu navigation
	int ans;
	int position; //position of book for its deletion

	//Load file and read item in file. Work in background without user knowing
	//ifstream infile;
	//ofstream outfile;
	string next, next2, next3, next4;
	List<string> list;

	//infile.open("infile.txt");
	fstream fs;
	fs.open ("infile.txt", fstream::in);

	//load the data into Linked List.
	/*
	while (getline(infile, next), getline(infile, next2), getline(infile, next3)) {
		list.addBook(next, next2, next3);
	} */

	while (getline(fs, next), getline(fs, next2), getline(fs, next3), getline(fs, next4)) {
		list.addBook(next, next2, next3, next4);
	}

	fs.close();
	
	//Menu.
	cout << "\nLibrary Book Management System" << endl;
	cout << "Version 001.001\n\n\n";

	//Switch or if?
	do {
		cout << "==== Main Menu ====\n\n";
		cout << "Choose your action. It is recommended that you read the docs" << "\n" << "first if you're first time user.\n\n"; //For ease of read purpose.
		cout << "1.Enter the program." << endl;
		cout << "2.Read the documentation." << endl;
		cout << "3.Exit." << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			do {
				cout << "Now, choose your action: " << endl << endl;
				cout << "1. Display book." << endl;
				cout << "2. Add book." << endl;
				cout << "3. Delete book." << endl;
				cout << "4. Update book." << endl;
				cout << "5. Search book." << endl;
				cout << "6. Book Count." << endl;
				cout << "7. Save." << endl;
				cout << "8. Go to main menu." << endl;
				cin >> ans;

				//switch statement to select menu.
				switch (ans) {
				case 1:
					list.displayBook();
					break;
				case 2:
					list.addBookInput();
					break;
				case 3: 
					cout << "Enter book position." << endl;
					cin >> position;						
					
					if (position == 1) { //if position = 1 - i.e. first node (head) - delete head
						list.deleteHead();
					}
					else {
						list.deleteBook(position); //else delete based on its position.
					}
					break;
				case 4: 
					cout << "Update book: " << endl;
					cout << "Enter book position: " << endl;
					cin >> position;
					list.updateBook(position);
					break;
				case 5:
					list.searchBook();
					break;
				case 6:
					cout << "Book Count" << list.count << endl;
				case 7:
					fs.open("infile.txt", fstream::out);
					list.temp = list.head;
					while (list.temp != NULL) {
						fs << list.temp->bookID << endl;
						fs << list.temp->bookTitle << endl;
						fs << list.temp->author << endl;
						fs << list.temp->availability << endl;
						list.temp = list.temp->next;											
					}
					break;
				case 8: //quitting condition
					ans = 8;
					break;
				} 
			} while (ans != 8);
			break;
		case 2:
			cout << "Documentation" << endl;
			//{*** TODO ***}
			ShellExecute(0, 0, "https://github.com/CharaeKeow/dataStructProject/blob/update/README.md", 0, 0, SW_SHOW);
			break;
		}
	} while (choice != 3);
				
	fs.close();
	
	return 0;
}

