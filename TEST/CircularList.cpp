#include "CircularList.h"

template <typename t>
void CircularList<t>::operator+=(t data){
	coreList.push_back(data);
}
