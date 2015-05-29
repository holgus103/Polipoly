#include "CircularList.h"

template <typename t>
bool CircularList<t>::CircularIterator::operator++(int){
	pointer++;
	if (pointer == end){
		pointer = begin;
		return true;
	}
	return false;
}
