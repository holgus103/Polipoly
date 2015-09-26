#pragma once
#include <vector>
#include <algorithm>

template <typename t>
class  CircularList{
	std::vector < t > coreList;
public:
	void operator+=(t data){
		coreList.push_back(data);
	}
	typename std::vector<t>::iterator begin(){ return coreList.begin(); }
	typename std::vector<t>::iterator end(){ return coreList.end(); }
	void rndm()
	{
		std::random_shuffle(coreList.begin(), coreList.end());
	}
	class CircularIterator{
		typename std::vector< t >::iterator pointer;
		typename std::vector< t >::iterator begin;
		typename std::vector< t >::iterator end;
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
			bool operator--(int){
				if (pointer == begin){
					pointer = end;
					pointer--;
					return true;
				}
				pointer--;
				return false;
			}
	};
};
