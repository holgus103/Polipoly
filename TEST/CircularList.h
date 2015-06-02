#pragma once
#include <list>

template <typename t>
class  CircularList{
	std::list < t > coreList;
public:
	void operator+=(t data){
		coreList.push_back(data);
	}
	typename std::list<t>::iterator begin(){ return coreList.begin(); }
	typename std::list<t>::iterator end(){ return coreList.end(); }
	class CircularIterator{
		typename std::list< t >::iterator pointer;
		typename std::list< t >::iterator begin;
		typename std::list< t >::iterator end;
	public:
		CircularIterator(CircularList<t>& list){pointer = list.begin(); end = list.end(); begin = list.begin(); }
		CircularIterator(){};
			t operator*(){ return *pointer; }
			bool operator++(int){
				pointer++;
				if (pointer == end){
					pointer = begin;
					return true;
				}
				return false;
			}
	};
};
