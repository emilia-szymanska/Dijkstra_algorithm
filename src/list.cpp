template <typename T>
typename List<T>::iterator & List<T>::iterator::operator ++()
{
	this->node_element = this->node_element->forward_pointer;
	return *this;
}


template <typename T>
typename List<T>::iterator List<T>::iterator::operator ++(int)
{
	List<T>::iterator tmp = *this;
	this->node_element = this->node_element->forward_pointer;
	return tmp;
}

template <typename T>
T & List<T>::iterator::operator *() const
{
	return this->node_element->content;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator =(const List<T>::iterator & Iter)
{
	this->node_element = Iter->node_element;
	return *this;
}

template <typename T>
bool List<T>::iterator::operator !=(const List<T>::iterator & Iter) const
{
	return this->node_element != Iter.node_element;
}



	
template <typename T>
List<T>::List()
{
	this->head = nullptr;
	this->tail = nullptr;
	this->number_of_elements = 0;
}

template <typename T>
List<T>::~List()
{
	while(!this->empty()) this->pop_front();
}
		
template <typename T>
List<T>::List(List & copy_list)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->number_of_elements = 0;
	for(auto it = copy_list.begin(); it != copy_list.end(); it++)
		this->push_back(*it);


}
	
template <typename T>
void List<T>::push_front(T value)
{
	node * new_element = new node(value);
	
	if(!this->empty())
	{
		this->head->backward_pointer = new_element;
		new_element->forward_pointer = this->head;
		this->head = new_element; 
	}
	else
	{
		this->head = new_element;
		this->tail = new_element;
	}

	this->number_of_elements++;
}

template <typename T>
void List<T>::push_back(T value)
{
	node * new_element = new node(value);
	
	if(!this->empty())
	{
		this->tail->forward_pointer = new_element;
		new_element->backward_pointer = this->tail;
		this->tail = new_element; 
	}
	else
	{
		this->head = new_element;
		this->tail = new_element;
	}

	this->number_of_elements++;
}

template <typename T>
void List<T>::pop_front()
{
	if(!this->empty())
	{
		if(this->size() == 1)
		{
			delete this->head;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->head = this->head->forward_pointer;
			delete this->head->backward_pointer;
			this->head->backward_pointer = nullptr;
		}
		this->number_of_elements--;	
	}	
	else
	{
		cout<<"Lista jest pusta"<<endl;
	}	
}

template <typename T>
void List<T>::pop_back()
{
	if(!this->empty())
	{
		if(this->size() == 1)
		{
			delete this->tail;
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			this->tail = this->tail->backward_pointer;
			delete this->tail->forward_pointer;
			this->tail->forward_pointer = nullptr;
		}
		this->number_of_elements--;	
	}	
	else
	{
		cout<<"Lista jest pusta"<<endl;
	}	
}

template <typename T>
const T & List<T>::front() const
{
	return this->head->content;
}

template <typename T>
const T & List<T>::back() const
{
	return this->tail->content;
}	

template <typename T>
bool List<T>::empty()
{
	return !(this->size());
}

template <typename T>
unsigned int List<T>::size()
{
	return this->number_of_elements;
}


template <typename T>
T & List<T>::operator [] (unsigned int index)
{

	/*if(index>=this->size() || index<0)
	{
		cerr<<"Bledna wartosc indeksu"<<endl;
	}*/
	node * tmp_ptr = this->head;
	
	for(unsigned int i = 0; i < index; i++)
		tmp_ptr = tmp_ptr->forward_pointer;

	return tmp_ptr->content;
}

template <typename T>
const T & List<T>::operator [] (unsigned int index) const
{

	/*if(index>=this->size() || index<0)
	{
		cerr<<"Bledna wartosc indeksu"<<endl;
	}*/
	node * tmp_ptr = this->head;
	
	for(unsigned int i = 0; i < index; i++)
		tmp_ptr = tmp_ptr->forward_pointer;


	return tmp_ptr->content;
}


template <typename T>
typename List<T>::node * List<T>::return_node(unsigned int index)
{
	node * tmp_ptr = this->head;
	
	for(unsigned int i = 0; i < index; i++)
		tmp_ptr = tmp_ptr->forward_pointer;
	
	return tmp_ptr;
}	


template <typename T>
void List<T>::delete_node(node * to_delete)
{
	if(this->head == to_delete)
	{
		this->pop_front();
		return;
	}
	if(this->tail == to_delete) 
	{
		this->pop_back();
	       	return;
	}
	
	to_delete->forward_pointer->backward_pointer = to_delete->backward_pointer;
	to_delete->backward_pointer->forward_pointer = to_delete->forward_pointer;		
	delete to_delete;
	this->number_of_elements--;
	return;
}
