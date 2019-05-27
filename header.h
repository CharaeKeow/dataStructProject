#ifndef HEADER_H
#define HEADER_H

template <class T>
class List {
private:
	
	struct Node {
		T bookID;
		T bookTitle;
		T author;
		T availability;
		Node* next;
	};
public:
	int count;
	Node* head, * tail, *temp;
	List();
	~List() {};
	void addBook(T bookID, T bookTitle, T author, T availability);
	void displayBook();
	void deleteBook(int position);
	void deleteHead();
	void updateBook(int position);
	void addBookInput();
};

#endif
