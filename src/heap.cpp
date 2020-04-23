template <typename T>
void swapping (T & a, T & b)
{
	T c;
	c = a;
	a = b;
	b = c;
}	

template <typename T>
void Heap<T>::addToHeap (const T & object)
{
	if(last_index == max_size) 
	{
		T * new_table = new T [2 * max_size + 1];
		max_size = 2 * max_size;
		for(unsigned int i = 0; i <= last_index; i++)
			new_table[i] = table[i]; 
		delete [] table;
		table = new_table;
	}

	unsigned int current_index;
	if(last_index == 0) table[1] = object;
	else
	{
		current_index = last_index + 1;
		table[current_index] = object;
		while (table[current_index] > table[current_index / 2]  && current_index / 2 != 0 )
		{
			swapping(table[current_index], table[current_index / 2]);
			current_index = current_index / 2;
		}	
	}
	last_index++;
}

template <typename T>
void Heap<T>::takeFromHeap ()
{
	unsigned int current_index = 1;
	if(this->isEmpty() == true) return;
	else
	{
		swapping(table[1], table[last_index]);
		last_index--;
		if(last_index == 0 || last_index == 1) return;
	
		while(1)
		{
			if(current_index * 2 > last_index) return;	// there are no sons
			else
			{
				T & left_son = table[current_index * 2];
				T & father = table[current_index];
				if(current_index * 2 == last_index)	//there is no right_son
				{
					if(left_son > father) swapping(left_son, father);
					return;
				}
				else					//there are both sons
				{
					T & right_son = table[current_index * 2 + 1];
	       				if(left_son > father ||  right_son > father)
					{
						if(left_son > right_son)
						{
							swapping(left_son, father);
							current_index = current_index * 2;		
						}
						else 
						{
							swapping(right_son, father);
							current_index = current_index * 2 + 1;
						}		
					}
					else return;
				
				}
			}
		}
	}
}

