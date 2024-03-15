// FILE: dll.h
//
// AUTHOR: Josue Lopez
//
// Course/Class: CS302-002
//
// DATE: 6th November 2023
//
// Program: CS302-002-program2
//
// ****** NODE CLASS ******
//
// Node<TYPE>();
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating an Activity object and passing in
//     no values to the constructor.
//   - You will need to change if new private member variables are added,
//     otherwise, no maintainance is required for this.
//
// ~Node<TYPE>();
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//   - You will need to change if new private member variables are added,
//     otherwise, no maintainance is required for this. If new private member
//     variables are added, you new to set them to their 0 equivalant value(s).
//
// void set_prev(Node<TYPE>* ptr);
//   - use to set the value of the previous pointer of the Node
//   - requires no maintainance unless you change structure of the Node
//
// void set_next(Node<TYPE>* ptr);
//   - use to set the value of the next pointer of the Node
//   - requires no maintainance unless you change structure of the Node
//
// void set_data();
//   - use to set the date portion of the node, because this is
//     templated, you don't know the data but each class in the
//     activity.h file has overloaded insertion and extraction
//     operators and this is a wrapper function for cin >> data
//   - requires no maintainance unless you change how the insertion
//     operator works for whatever the data type is.
//
// Node<TYPE>* get_prev();
//   - use to get the value of the previous pointer inside the Node
//   - requires no maintainance unless you change structure of the Node
//
// Node<TYPE>* get_next();
//   - use to get the value of the next pointer inside the Node
//   - requires no maintainance unless you change structure of the Node
//
// void get_data() const;
//   - use to display the contents of the data of the Node
//   - requires no maintainance unless you change how the extraction
//     operator works for whatever the data type is.
//
// ****** DLL CLASS ******
//
// Dll<TYPE>();
//   - default constructor that is called to set all data to their 0 value.
//     you can call this by just creating an Activity object and passing in
//     no values to the constructor.
//   - You will need to change if new private member variables are added,
//     otherwise, no maintainance is required for this.
//
// ~Dll<TYPE>();
//   - default destructor that is automatically called when the object is
//     destroyed. You do not call this, it will be done automatically.
//   - You will need to change if new private member variables are added,
//     otherwise, no maintainance is required for this. If new private member
//     variables are added, you new to set them to their 0 equivalant value(s).
//
// void game_create();
//   - used to create a template for a game activity. This is called from the
//     main and creates nodes for a game to be played.
//   - no maintainance is required unless you decide to change the structure
//     of the class.
//
// void tour_create();
//   - used to create a template for a tour activity. This is called from the
//     main and creates nodes for a game to be played.
//   - no maintainance is required unless you decide to change the structure
//     of the class.
//
// void movie_create();
//   - used to create a template for a movie activity. This is called from the
//     main and creates nodes for a game to be played.
//   - no maintainance is required unless you decide to change the structure
//     of the class.
//
// bool operator++(); // prefix
//   - used to increment current pointer and move it forward one Node
//     example call: ++my_object;
//   - no maintainance is required unless you decide to change the operator
//     for the class.
//
// bool operator--(); // prefix
//   - used to decrement current pointer and move it back one Node
//     example call: --my_object;
//   - no maintainance is required unless you decide to change the operator
//     for the class.
//
// void display() const;
//   - used to get the contents of the data
//   - requires no maintainance unless you change how the extraction
//     operator works for whatever the data type is.
//
// void input();
//   - used to input contents to the data
//   - requires no maintainance unless you change how the insertion
//     operator works for whatever the data type is.

#ifndef DLL_H
#define DLL_H

#include <iostream>
using std::cout;
using std::endl;

template<typename TYPE>
class Node
{
	public:

		Node<TYPE>();
		~Node<TYPE>();

		void set_prev(Node<TYPE>* ptr);
		void set_next(Node<TYPE>* ptr);
		void set_data();

		Node<TYPE>* get_prev();
		Node<TYPE>* get_next();
		void get_data() const;

	private:
		TYPE data;
		Node<TYPE>* next;
		Node<TYPE>* prev;
};

template<typename TYPE>
class Dll
{
	public:

		Dll<TYPE>();
		~Dll<TYPE>();


		// additional functions here later
		void game_create();
		void tour_create();
		void movie_create();

		// operators
		bool operator++(); // prefix
		bool operator--(); // prefix

		void display() const;
		void input();


	private:
		void delete_all();
		Node<TYPE>* head;
		Node<TYPE>* current;
		Node<TYPE>* tail;
};

// *************************** NODE CLASS ***************************

template<typename TYPE>
Node<TYPE>::Node() : data(TYPE()), next{nullptr}, prev{nullptr} {}

template<typename TYPE>
Node<TYPE>::~Node()
{
	next = nullptr;
	prev = nullptr;
}

template<typename TYPE>
void Node<TYPE>::set_prev(Node<TYPE>* ptr)
{
	prev = ptr;
	return;
}

template<typename TYPE>
void Node<TYPE>::set_next(Node<TYPE>* ptr)
{
	next = ptr;
	return;
}

template<typename TYPE>
void Node<TYPE>::get_data() const
{
	cout << data << endl;
	return;
}

template<typename TYPE>
Node<TYPE>* Node<TYPE>::get_next()
{
	return next;
}

template<typename TYPE>
void Node<TYPE>::set_data()
{
	cin >> data;
	return;
}

template <typename TYPE>
Node<TYPE>* Node<TYPE>::get_prev()
{
	return prev;
}

// *************************** DLL CLASS ***************************

template<typename TYPE>
Dll<TYPE>::Dll() : head{nullptr}, current{nullptr}, tail{nullptr} {}

template<typename TYPE>
void Dll<TYPE>::delete_all()
{
	current = head->get_next();
	tail = current->get_next();
	delete head;
	delete current;
	delete tail;
	return;
}

template<typename TYPE>
Dll<TYPE>::~Dll()
{
	delete_all();
	head = nullptr;
	current = nullptr;
	tail = nullptr;
}

template<typename TYPE>
void Dll<TYPE>::game_create()
{
	head = new Node<TYPE>;
	current = new Node<TYPE>;
	tail = new Node<TYPE>;

	head->set_next(current);
	current->set_prev(head);
	current->set_next(tail);
	tail->set_prev(current);
	return;
}

template<typename TYPE>
void Dll<TYPE>::tour_create()
{
	head = new Node<TYPE>;
	cout << "Enter date and location of first tour stop:" << endl;
	head->set_data();

	current = head;
	tail = head;

	tail = new Node<TYPE>;
	cout << endl << "Enter date and location of second tour stop:" << endl;
	tail->set_data();

	head->set_next(tail);
	tail->set_prev(head);

	current = tail;

	tail = new Node<TYPE>;
	cout << endl << "Enter date and location of third tour stop:" << endl;
	tail->set_data();

	tail->set_prev(current);
	current->set_next(tail);
	current = head;

	return;
}

template<typename TYPE>
void Dll<TYPE>::movie_create()
{

	head = new Node<TYPE>;
	cout << "Enter date and first movie title:" << endl;
	head->set_data();

	current = head;
	tail = head;

	tail = new Node<TYPE>;
	cout << endl << "Enter date and second movie title:" << endl;
	tail->set_data();

	head->set_next(tail);
	tail->set_prev(head);

	current = tail;

	tail = new Node<TYPE>;
	cout << endl << "Enter date and third movie title:" << endl;
	tail->set_data();

	tail->set_prev(current);
	current->set_next(tail);
	current = head;
	return;
}

template<typename TYPE>
bool Dll<TYPE>::operator++()
{
	if(current == tail)
		return false; // cannot move forward
	current = current->get_next();
	return true; // can move forward
}

template<typename TYPE>
bool Dll<TYPE>::operator--()
{
	if(current == head)
		return false; // cannot move backwards
	current = current->get_prev();
	return true; // can move backwards
}

template<typename TYPE>
void Dll<TYPE>::display() const
{
	current->get_data();
	return;
}

template<typename TYPE>
void Dll<TYPE>::input()
{
	current->set_data();
	return;
}
#endif // DLL_h
