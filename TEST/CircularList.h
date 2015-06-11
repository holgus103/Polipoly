#pragma once
#include <list>
#include <algorithm>

template <typename t>
class  CircularList{
	std::list < t > coreList;
public:
	void operator+=(t data){
		coreList.push_back(data);
	}
	typename std::list<t>::iterator begin(){ return coreList.begin(); }
	typename std::list<t>::iterator end(){ return coreList.end(); }
	void rndm()
	{
		std::random_shuffle(coreList.begin(), coreList.end());
	}
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
