#ifndef HEADER_H
#define HEADER_H

template <class T>
class List {
private:
	struct Node {
		T bookID;
		T bookTitle;
		T author;
		Node* next;
	}; 
public:
	Node* head, * tail, *temp;
	List();
	~List() {};
	void addBook(T bookID, T bookTitle, T author);
	void displayBook();
	void deleteBook(int position);
	void deleteHead();
	//void updateBook();
};

#endif
