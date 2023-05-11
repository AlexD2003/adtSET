#include "SetIterator.h"
#include "Set.h"


SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	currentPos = 0;
}//Θ(1)


void SetIterator::first() {
	//TODO - Implementation
	currentPos = 0;
}//Θ(1)


void SetIterator::next() {
	//TODO - Implementation
	currentPos++;
}//Θ(1)


TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (valid()) {
		return set.elements[currentPos];
	}
	else {
		return NULL_TELEM;
	}
}//Θ(1)

bool SetIterator::valid() const {
	//TODO - Implementation
	return currentPos < set.size();
}//Θ(1)



