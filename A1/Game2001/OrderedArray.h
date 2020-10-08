#pragma once
#define _ORDREDARRAY_H_
#include <cassert>
#include "ArrayBase.h"

template<class T>
class OrderedArray :public Array<T>
{
public:

	int push(T val)
	{
		assert(a_array != NULL);

		if (m_numElements >= m_maxSize)
		{
			//Expand();
		}

		int i, k; // Did not declear it in for loop cus we can use "i" pass this for loop
		// Step1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (a_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index forward by one
		for (k = m_numElements; k > i; k--)// Moving backwards through the array starting at m_numElemets
		{
			a_array[k] = a_array[k - 1];
		}

		// Step 3: Insert val into index
		a_array[i] = val;

		m_numElements++;

		return i;
	}

	// Searching -- Binary Search -- Big O = O(Log N)
	int search(T searchKey)
	{
		assert(a_array != NULL);

		// Helper variables
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1)  // <-----Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of Bitwise operation. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we looking for
			if (a_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options already. Can;t find the item
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			else
			{
				// Step3 : Check which half of the array 
				if (a_array[current] < searchKey)
				{
					lowerBound = current + 1;
				}
				else
				{
					upperBound = current - 1;
				}
			}
		}

		return -1;
	}
	const T& operator[](int index)
	{
		assert(a_array != NULL && index < m_numElements);
		return a_array[index];
	}
private:
	T* a_array;

	int m_maxSize;
	int m_growSize;
	int m_numElements;
};