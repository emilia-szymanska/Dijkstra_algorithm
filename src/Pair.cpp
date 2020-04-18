template <typename T>
bool Pair<T>::operator < (Pair<T> pair_to_compare)
{
	if(this->first < pair_to_compare.first) return true;
	else
		if(this->first == pair_to_compare.first)
			if(this->second < pair_to_compare.second) return true;
	return false;
}

template <typename T>
bool Pair<T>::operator > (Pair<T> pair_to_compare)
{
	if(this->first > pair_to_compare.first) return true;
	else
		if(this->first == pair_to_compare.first)
			if(this->second > pair_to_compare.second) return true;
	return false;
}
