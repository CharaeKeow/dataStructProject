#include <iostream>
#include <fstream> //for file handling
#include <string> //we use string data type
#include <iomanip> //for set width (setw())
using namespace std;
#include "header.h"

int main() {
	int choice; //For menu navigation
	int quit = 0; // for exit;

	//Load file and read item in file. Work in background without user knowing
	ifstream infile;
	ofstream outfile;
	string next, next2, next3;
	List<string> list;
	infile.open("infile.txt");
	outfile.open("outfile.txt");
	
	//load the data into Linked List.
	while (getline(infile, next), getline(infile,next2), getline(infile,next3)) {
		list.addBook(next, next2, next3);		
	}

	//Menu.
	cout << "\nLibrary Book Management System" << endl;
	cout << "Version 001.001\n\n\n";
	cout << "==== Main Menu ====\n\n";
	cout << "Choose your action. It is recommended that you read the docs" << "\n" << "first if you're first time user.\n\n"; //For ease of read purpose.
	cout << "1.Enter the program." << endl;
	cout << "2.Read the documentation." << endl;
	cout << "3.Exit." << endl;
	
	
	//Switch or if?
	while (1) {
		cin >> choice;
		switch (choice) {
		case 1:
			list.displayBook();
			break;
		case 2:
			int ans;
			while (1) {
				cout << "Add book?\n";
				cout << "1. Yes\n2. No\n";
				cin >> ans;
				if (ans == 1) {
					cout << "Enter book ID." << endl;
					cin.ignore();
					getline(std::cin, next);
					cout << "Enter book title." << endl;
					cin.ignore();
					getline(std::cin, next2);
					cout << "Enter book author" << endl;
					cin.ignore();
					getline(std::cin, next3);
					list.addBook(next, next2, next3);
				}
				else {
					exit(1);
					break;
				}
			}
			break;
		case 3:
			exit(1);
			break;
		} 
	}

	//need to tidy up this section - require user input after reading from file.
	/*
	int ans;
	do {
		cout << "Add book?\n";
		cout << "1. Yes\n2. No\n";		
		cin >> ans;
		if (ans == 1) {
			cout << "Enter book ID." << endl;
			cin.ignore();
			getline(std::cin, next);
			cout << "Enter book title." << endl;
			cin.ignore();
			getline(std::cin, next2);
			cout << "Enter book author" << endl;
			cin.ignore();
			getline(std::cin, next3);
			list.addBook(next, next2, next3);
		}		
	} while (ans == 1);
	*/

	//list.addBook("B024324", "Harry Potter and the Philosopher's Stone", "J.K. Rowling");
	//list.displayBook();
	

	//write the file out. Also works in background. Will make a save feature later.
	//Also, save automatically if the user exit (normal exit).
	list.temp = list.head;
	while (list.temp != NULL) {
		outfile << list.temp->bookID << endl;
		outfile << list.temp->bookTitle << endl;
		outfile << list.temp->author << endl;
		list.temp = list.temp->next;
	}
	

	infile.close();
	outfile.close();

	return 0;
}
