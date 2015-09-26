#pragma once
#include <iterator>

template < typename t>
class CircularIterator{
	typename iterator<vector<t>> pointer;
	CircularIterator();
public:
	t& operator*();
	void operator++(int);
	void operator--(int);
};