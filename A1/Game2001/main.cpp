#include <iostream>
#include <cassert>
#include "ArrayBase.h"
#include "OrderedArray.h"
#include "UnorderedArray.h"
using namespace std;
int main()
{
	OrderedArray<int> array(3);

	array.push(4);

	array.push(64);

	array.push(8);

	array.push(16);

	array.push(32);

	array.push(2);

	array.push(64);



	cout << "Ordered array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}


	return 0;
}