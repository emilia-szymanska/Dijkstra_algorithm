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

		class iterator
		{
			node * node_element;
			
			public:
				iterator(node * newnode = nullptr) {this->node_element = newnode;}
				node & get_node() { return *node_element;}; 
				iterator & operator ++ ();
				iterator operator ++ (int);
				T & operator * () const;
				iterator & operator = (const iterator & Iter);
				bool operator !=  (const iterator & Iter) const;	

		};
		
		class const_iterator
		{
			node * node_element;
			
			public:
				const_iterator( node* newnode = nullptr) {this->node_element = newnode;}
				const node & get_node() const { return *node_element; }
				const_iterator & operator ++ ();
				const_iterator operator ++ (int);
				const T& operator * () const;
				const_iterator&	operator = (const const_iterator & Iter);
				bool operator!=(const const_iterator& Iter) const;
		};

		List(); 
		~List();
		List(const List & copy_list);
		void push_front(T value);
		void push_back(T value);
		void pop_front();
		void pop_back();
		const T & front() const;
		const T & back() const;
		bool empty();
		unsigned int size();
		node * return_node(unsigned int index); 
		void delete_node(node * to_delete);
		T & operator [] (unsigned int index);
		const T & operator [] (unsigned int index) const;
		List<T> & operator = (const List<T> & list_copy);
		iterator begin() {return List<T>::iterator(this->head);}
		iterator end() {return List<T>::iterator(nullptr);}
		const_iterator cbegin() const {return List<T>::const_iterator(this->head);}
		const_iterator cend() const {return List<T>::const_iterator(nullptr);}


	private:
		
		node * head;
		node * tail;
		unsigned int number_of_elements;

};

#include "../src/list.cpp"

#endif
