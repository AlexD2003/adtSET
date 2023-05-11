#include "Set.h"
#include "SetITerator.h"

Set::Set() {
	//TODO - Implementation
	//constructor
	capacity = 10;
	length = 0;
	elements = new TElem[capacity];
}//Θ(1)


bool Set::add(TElem elem) {
	//TODO - Implementation
	int i = 0;
	//initial poz=0
	bool found = false;
	//found bool
	while (i <= length && found == false) {
		if (elements[i] == elem)
			//if an element is found,change found to true
			found = true;
		else
			i++;
	}
	if (found == true) {
		//if it is already present,ret false
		return false;
	}
	else {
		//resize formula
		capacity *= 2;
		TElem* newElements = new TElem[capacity];
		for (i = 0; i <= length; i++) {
			newElements[i] = elements[i];
		}
		elements = newElements;
	}
	//increase length and add elem
	length++;
	elements[length] = elem;
	return true;
}//O(length)


bool Set::remove(TElem elem) {
	
	int pos = -1;
	//search for elem in elements
	for (int i = 0; i <= length; i++) {
		if (elements[i] == elem) {
			pos = i;
			break;
		}
	}
	//if the element is not in the array, return false
	if (pos == -1) {
		return false;
	}
	//shift the elements
	for (int i = pos; i <= length - 1; i++) {
		elements[i] = elements[i + 1];
	}

	//decrease the size of the array by 1
	length--;
	return true;

}//O(length)

bool Set::search(TElem elem) const {
	//TODO - Implementation
	int i;
	//search for elem
	for (i = 0; i <= length; i++) {
		if (elements[i] == elem) {
			return true;
		}
	}
	return false;
}//O(n)


int Set::size() const {
	//TODO - Implementation
	return length;
}//Θ(1)


bool Set::isEmpty() const {
	//TODO - Implementation
	if (length == 0) {
		return true;
	}
	return false;
}//Θ(1)


Set::~Set() {
	//TODO - Implementation
	delete[]elements;
}//Θ(1)


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


