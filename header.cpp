#include "header.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
List<T>::List(){
	temp = NULL;
	head = NULL;
	tail = NULL;
}

template <class T>
void List<T>::addBook(T bookID, T bookTitle, T author) {
	Node* temp = new Node;
	temp->bookID = bookID;
	temp->bookTitle = bookTitle;
	temp->author = author;
	temp->next = NULL;
	if (head == NULL) {
		head = temp; 
		tail = temp;
		temp = NULL;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

template <class T>
void List<T>::addBookInput() {
	T bookID; 
	T bookTitle; 
	T author;

	cout << "Enter bookID, bookTitle, and book Author" << endl;
	cin.ignore();
	getline(cin, bookID);
	
	getline(cin, bookTitle);
	getline(cin, author);
	
	addBook(bookID, bookTitle, author);	
}

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
		temp = temp->next;
	}
}

template <class T>
void List<T>::deleteBook(int position) {
	Node* current = new Node;
	Node* previous = new Node;
	Node* next = new Node;
	current = head;
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

template <class T>
void List<T>::deleteHead() {
	Node* temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
}

/* Update {*** DOING ***}
template <class T>
void List<T> :: updateBook(int position) {
	Node* current = new Node;
}
*/

template class List<string>;
