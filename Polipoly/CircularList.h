#pragma once
#include <list>

template <typename t>
class  CircularList{
	std::list < t > coreList;
public:
	void operator+=(t);
	class CircularIterator{
		typename std::list< t >::iterator pointer;
		CircularIterator();
		t operator*();
		void operator++(int);
		void operator+=(int);
	};
};
