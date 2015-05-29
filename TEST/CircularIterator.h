#pragma once
#include <iterator>

template < typename t>
class CircularIterator{
	typename iterator<list<t>> pointer;
	CircularIterator();
public:
	t& operator*();
	void operator++(int);
};