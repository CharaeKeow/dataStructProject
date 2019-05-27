#include "header.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
List<T>::List(){
	temp = NULL; //all set to NULL as the list is still empty (for now) 
	head = NULL;
	tail = NULL;
}

template <class T>
void List<T>::addBook(T bookID, T bookTitle, T author) { //add book. Note that this method adds values to the end of the tail.
	Node* temp = new Node; 
	temp->bookID = bookID; //Might be a little bit confusing and ambiguous (as the name is same) 
	temp->bookTitle = bookTitle; //but it works! Set data to node.
	temp->author = author;
	temp->next = NULL; //Temp point to null as this is the last node (tail).
	if (head == NULL) { //if empty list,
		head = temp;  //temp will be both head and tail
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp; //if node is not empty, set temp as tail.
		tail = temp; 
	}
}

/*
  This function is rather similar to the above (addBook) function, just we want to make 2 separate
  function - i.e. addBook and addBookInput - for 2 different function. addBook will be used for adding
  book to the list when extracting data from the file while addBookInput will be used for adding
  book details from user's input. 
*/
template <class T>
void List<T>::addBookInput() { 
	T bookID; 
	T bookTitle; 
	T author;

	cout << "Enter bookID, bookTitle, and book Author" << endl; //Due some errors with getline(), we do this. Bad UX, though
	cin.ignore(); //Ignore the newline
	getline(cin, bookID); 	
	getline(cin, bookTitle);
	getline(cin, author);
	
	addBook(bookID, bookTitle, author);	//invoke addBook and pass user's input to the invoked function
	
	cout << "The list after adding a book is: " << endl;
	displayBook();
}

/*
  This function will display the linked list. We set a new pointer, temp, and set it to head and then we traverse
  from head to tail using (while loop) while print the node's data along the way. Note that we also declare a new variable,
  bookPosition, which is basically the position (starts from 1) of the book in the linked list. Why declare this bookPosition?
  Because this will makes the deletion and update process easier, as user only needs to enter the book position to delete or update
  a book from the book. As for display, we also print bookPosition alongside book's details.
*/
template <class T>
void List<T>::displayBook() {
	int bookPosition = 1;
	Node* temp = new Node; //declare new temp pointer
	temp = head; //set to start from head
	while (temp != NULL) { //Loop through the list while it's not empty
		cout << "Book Position: " << bookPosition <<endl;
		cout << "Book ID: " << temp->bookID << endl;
		cout << "Book Title: " << temp->bookTitle << endl;
		cout << "Book Author: " << temp->author << endl;
		cout << "\n";
		bookPosition++;
		temp = temp->next; //traverse to next node
		count++;
	}
}

/*
  As stated earlier, bookPosition is used to specify which book the user wanna delete. 
  So we will traverse from head until we reach at the desired position, 
  then we will delete the node. There is a condition to check if invalid position
  has been entered by user.
*/

template <class T>
void List<T>::deleteBook(int position) { 
	Node* current = new Node;
	Node* previous = new Node;
	Node* next = new Node;
	current = head;
	/*
	if (position > count) { 
		cout << "Invalid position!";
		return;
	}
	else if (position == count) {
		next =
	}
	*/
	
	for (int i = 1; i < position; i++) {
		if (current == NULL) {
			return; //nothing to delete, so return
		}
		previous = current;
		current = current->next;		
	}
	next = current->next;
	previous->next = current->next;
	delete current;	
}


//In case user wanna to head, there is no need for traversal.
template <class T>
void List<T>::deleteHead() {
	Node* temp = new Node;
	temp = head;
	head = head->next;
	delete temp;	
}

template <class T>
void List<T> :: updateBook(int position) {
	Node* current = new Node;
	Node* previous = new Node;
	Node* next = new Node;
	current = head;
	T newValue; // for enter new node's data value.
	int choice; // for choosing option during menu.
	/*
	--- NOTE ---	
	Previously, there is a bug when update the tail. Seems the method to traverse from head until
	the tail for update doesn't work. Which is weird. However, the fix is rather simple - we add a condition, 
	i.e. if the position we want to update is tail, we straightly point to there (rather then starting traverse
	from head to tail) and we update using the tail point to data (e.g. tail->bookID, etc). Also this is an
	early exit condition, it will return if the position is tail, as the code below is for updating node that
	is not tail.
	*/
	if (position == position){ 
		cin >> choice;
		if (choice == 1) {
			cout << "Enter new book ID: " << endl;
			cin.ignore();
			getline(cin, newValue);
			tail->bookID = newValue;
		}
		else if (choice == 2) {
			cout << "Enter new book title: " << endl;
			cin.ignore();
			getline(cin, newValue);
			tail->bookTitle = newValue;
		}
		else if (choice == 3) {
			cout << "Enter new book author: " << endl;
			cin.ignore();
			getline(cin, newValue);
			tail->author = newValue;
		}
		else {
			cout << "Sorry, that's invalid choice." << endl;
			cout << "No update";
			return; //No update, so no need to show the new updated value. Exit to menu.
		}

		//Show the updated value for that node only, as display all is a little bit overkill, I think.

		cout << "\n\nThe book details after update are: " << endl; 
		cout << "Book ID: " << tail->bookID << endl;
		cout << "Book Title: " << tail->bookTitle << endl;
		cout << "Author: " << tail->author << endl;
		return;
	}

	/*
	This is for updating the other node other than tail. As stated above - if you read them, great, otherwise
	it's fine, :( - we will traverse the node from head to the desired node.
	*/
	for (int i = 0; i < position; i++) { //For i < position, it will traverse forward. Note that this will stop once the position is reached.
		if (current == NULL) { //Early exit if list is empty
			return;
		}
		previous = current; 
		current = current->next; //Traverse forward
	}
	//A little prompt wouldn't hurt
	cout << "What do you want to update?" << endl;
	cout << "1. Book ID" << endl;
	cout << "2. Book Title" << endl;
	cout << "3. Author" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << "Enter new book ID: " << endl;
		cin.ignore();
		getline(cin, newValue);
		current->bookID = newValue;
	}
	else if (choice == 2) {
		cout << "Enter new book title: " << endl;
		cin.ignore();
		getline(cin, newValue);
		current->bookTitle = newValue;
	}
	else if (choice == 3) {
		cout << "Enter new book author: " << endl;
		cin.ignore();
		getline(cin, newValue);
		current->author = newValue;
	}
	else {
		cout << "Sorry, that's invalid choice." << endl;
		cout << "No update";
		return; //No update, so no need to show the new updated value. Exit to menu.
	}
	cout << "\n\nThe book details after update are: " << endl;
	cout << "Book ID: " << current->bookID << endl;
	cout << "Book Title: " << current->bookTitle << endl;
	cout << "Author: " << current->author << endl;
}

template class List<string>;
