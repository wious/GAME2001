#include <iostream>
#include <cassert>
#include "ArrayBase.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;
int main()
{
	int m_maxSize, m_growSize, m_numElements;

	OrderedArray <int> array(3);


	array.push(4);

	array.push(64);

	array.push(8);

	array.push(16);

	array.push(32);

	array.push(2);

	array.push(64);
	
    cout << "Current Array Stats... \n" << "MaxSize: " << m_maxSize << " " << "GrowSize: " << m_growSize << " " << "NumElements: " << m_numElements << "\n";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n\n";
	cout << " ";
	return 0;
}
//A1 by Feng Xiao 101100713