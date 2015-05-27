#include "CircularList.h"

template <typename t>
CircularList<t>::CircularIterator::CircularIterator(){
	pointer = coreList.begin();
}

template <typename t>
t CircularList<t>::CircularIterator::operator*(){
	return pointer*;
}

template <typename t>
void CircularList<t>::CircularIterator::operator++(int){
	pointer++;
	if (pointer == coreList.end())
		pointer = coreList.begin();
}

template <typename t>
void CircularList<t>::CircularIterator::operator+=(int i){
	for (int j = 0; j < i; j++)
		(this*)++;
}