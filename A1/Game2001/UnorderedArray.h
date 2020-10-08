#pragma once
#include <cassert>
#include "ArrayBase.h"

template<class T>
class UnorderedArray : public Array<T>
{
public:
	// Constructor
	Array<T> ::Array;
	// Destructor
	~UnorderedArray() {}
	// Insertion
	void push(T val)
	{
		assert(Array<T>::m_array != NULL);	// Debugging purposes

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)
		{
			Array<T>::Expand();
		}

		// My array has space for the new value
		Array<T>::m_array[Array<T>::m_numElements] = val;
		Array<T>::m_numElements++;
	}
	// Searching (Linear search) -- Big-O = O(N)
	int search(T val)
	{
		assert(this->m_array != NULL);

		// Brute-force search
		for (int i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] == val)
			{
				return i;
			}
		}

		return -1;
	}

};
