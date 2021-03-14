#include "heap.h"
#include "person.h"
#include "general.h"
#include <iostream>
#include <math.h>
using namespace std;

//returns left child .
int MinimumHeap::Left(int node) 
{
	return ((2 * node) + 1);
}

//returns right child .
int MinimumHeap::Right(int node) 
{
	return ((2 * node) + 2);
}

//returns parent .
int MinimumHeap::Parent(int node) 
{
	return (node - 1) / 2;
}

//Fixes the heap that has node as root .
void MinimumHeap::FixHeap(int node) 
{
	int index;
	int left;
	int right;
	int min = node ;

	do 
	{
		index = min;
		left = Left(min);
		right = Right(min);
		
		if (left < heapSize)
		{
			this->NumComp++; //counts the comparison .
			if (data[left] < data[min])
			{
				min = left;
			}
		}
		if (right < heapSize)
		{
			this->NumComp++; //counts the comparison .
			if (data[right] < data[min])
			{
				min = right;
			}
		}

		General::swapPersons(data, index, min);
	} 
	while (index != min);

}

//Constructor .
MinimumHeap::MinimumHeap(int max) 
{
	data = new Person[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
	NumComp = 0;
}

//Constructor .
MinimumHeap::MinimumHeap(Person A[],int n)
{
	maxSize = n;
	heapSize = n;
	data = A;
	allocated = 0;
	NumComp = 0;
	for (int i = (n / 2) - 1;i >= 0;i--) 
	{
		FixHeap(i);
	}
}

//Destructor .
MinimumHeap::~MinimumHeap() 
{
	if (allocated == 1) 
	{
		delete[] data;
	}
	data = nullptr;
}

//inserts Person to the heap .
void MinimumHeap::insert(Person item) 
{
	if (heapSize == maxSize) 
	{
		General::error("Error : Heap is full");
	}
	int index = heapSize;
	data[index] = item;
	this->NumComp++; //counts the comparison (at least one comparison).
	while( (index > 0) && (data[index] < data[Parent(index)]))
	{
		this->NumComp++; //counts the comparison (every iteration).
		General::swapPersons(data, index, Parent(index));
		index = Parent(index);
	}
	heapSize++;
}

//returns and deletes minimal person .
Person MinimumHeap::DeleteMin(void)
{
	if (heapSize == 0)
	{
		General::error("Error : Heap is empty");
	}
	Person min = data[0];
	data[0] = data[heapSize - 1];
	heapSize--;
	FixHeap(0);
	return min;
}

//returns minimal person (by reference) .
const Person& MinimumHeap::Min(void)
{
	return data[0];
}

//returns the comapres .
int MinimumHeap::getCompares() 
{
	return this->NumComp;
}
