#ifndef STACK_HH
#define STACK_HH

template <typename T>
class Stack
{
	T * stack_elements;
	unsigned int number_of_elements;

	public:
		Stack(unsigned int stack_size) {this->number_of_elements = 0; stack_elements = new T [stack_size];} 
		~Stack() {delete [] this->stack_elements;}
		void push(T value);
		void pop();
		T top();
		bool empty();
		unsigned int Size();

};

#include "../src/stack.cpp"

#endif
