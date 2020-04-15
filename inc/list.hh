#ifndef LIST_HH
#define LIST_HH

#include <iostream>
using namespace std;

template <typename T>
class List
{
	public:

		struct node
		{
			node * forward_pointer;
			node * backward_pointer;
			T content;

			node(T value)
			{
				content = value;
				forward_pointer = nullptr;
				backward_pointer = nullptr;
			}	
		};

		List(); 
		~List();
		void push_front(T value);
		void push_back(T value);
		void pop_front();
		void pop_back();
		const T & front() const;
		const T & back() const;
		bool empty();
		unsigned int size();
		T & operator [] (unsigned int index);
		const T & operator [] (unsigned int index) const;


	private:
		
		node * head;
		node * tail;
		unsigned int number_of_elements;

};

#include "../src/list.cpp"

#endif
