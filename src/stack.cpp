template <typename T>
void Stack<T>::push(T value)
{
	this->stack_elements[number_of_elements] = value;
	this->number_of_elements++;
}

template <typename T>
void Stack<T>::pop()
{
	if(this->empty()) return;
	this->number_of_elements--;
}

template <typename T>
T Stack<T>::top()
{
	return this->stack_elements[number_of_elements - 1];
}

template <typename T>
bool Stack<T>::empty()
{
	return !(this->number_of_elements);
}

template <typename T>
unsigned int Stack<T>::Size()
{
	return this->number_of_elements;
}

