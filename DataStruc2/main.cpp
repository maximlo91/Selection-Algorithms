#pragma warning(disable:4996)
#include <iostream>
#include <time.h>
#include "person.h"
#include "general.h"
#include "bstreenode.h"
#include "bstree.h"
#include "heap.h"
using namespace std;


int Selection(Person persons[], int left, int right, int k, int &NumComp);
const Person& RandSelection(Person persons[], int n, int k, int &NumComp);
const Person& BST(Person persons[],  int n, int k, int& NumComp);
int Partition(Person persons[], int left, int right, int &NumComp);
const Person& selectHeap(Person persons[], int n, int k, int &NumComp);

int main()
{
	srand((unsigned)time(nullptr));

	int num, kSelection, numComp=0;
	cin >> num;
	Person* persons = Person::createPersonArray(num);
	Person* persons_1 = General::copyPersons(persons, num);
	Person* persons_2 = General::copyPersons(persons, num);
	cin >> kSelection;
	Person kSelectedPerson;
	
	kSelectedPerson = RandSelection(persons, num, kSelection, numComp);
	cout << "\n" << kSelectedPerson.getId() << " " << kSelectedPerson.getName() << "\n\n"
		<< "Rand Selection: " << numComp << "\n\n";
	
	kSelectedPerson = selectHeap(persons_1, num, kSelection, numComp);
	
	cout << "selectHeap: " << numComp << "\n\n";
	
	kSelectedPerson = BST(persons_2, num, kSelection, numComp);
	
	cout << "BST: " << numComp << "\n\n";

	delete[] persons;
	delete[] persons_1;
	delete[] persons_2;

	return 0;
}

//[Function 1] returns the k-value item at array .
//worst case efficiency : n^2 .
//avarage case efficiency : n .
const Person& RandSelection(Person persons[], int n, int k, int &NumComp)
{
	int index = Selection(persons, 0, n - 1, k - 1, NumComp);
	return persons[index];
}

//[Function 2] returns the k-value item at array .
//worst case efficiency : n + k*log(n) .
const Person& selectHeap(Person persons[], int n, int k, int &NumComp)
{
	MinimumHeap heap = MinimumHeap(persons, n); //floyd algoritm - efficiency allways : n .

	for (int i = 1;i <= k-1;i++) // iterations : k (approximated) .
	{
		heap.DeleteMin(); //efficiency at worst and avarage case : log(n) .
	}

	NumComp = heap.getCompares(); //efficiency allways : 1  .

	return heap.Min(); //efficiency allways : 1  .
}

//[Function 3] returns the k-value item at array .
//worst case efficiency : n^2
//avarage case efficiency : n*log(n).
const Person& BST(Person persons[], int n, int k, int& NumComp)
{
	BStree* T = new BStree(); // build binary search tree
	T->makeEmpty();
	for (int i = 0; i < n; i++)
	{
		T->Insert(persons[i].getId(), &persons[i]);
	}
	NumComp = T->getNumComp();
	BSTreeNode* kValueNode = T->FindKValue(k);
	Person* kValue = kValueNode->getData();
	delete T; // free binary search tree
	return *kValue;
}

//Selection algoritm , recursive function , returns the k-value item at array .
int Selection(Person persons[], int left, int right, int k, int &NumComp)
{
	int pivot = Partition(persons, left, right, NumComp);
	if (k == pivot)
	{
		return pivot;
	}
	else
	{
		if (k > pivot)
		{
			return Selection(persons, pivot + 1, right, k, NumComp);
		}
		else
		{
			return Selection(persons, left, pivot - 1, k, NumComp);
		}
	}

}

//Partition algoritm , returns random pivot index .
int Partition(Person persons[], int left, int right, int &NumComp)
{
	int pivot = left + (rand() % (right - left + 1));
	General::swapPersons(persons, left, pivot);
	bool flag = true;
	while (left != right)
	{
		if (flag)
		{
			NumComp++;//counts the comparison .
			if (persons[left] > persons[right]) 
			{
				General::swapPersons(persons, left, right);
				left++;
				flag = !flag;
			}
			else
			{
				right--;
			}
		}
		else
		{
			NumComp++;//counts the comparison .
			if (persons[left] > persons[right]) 
			{
				General::swapPersons(persons, left, right);
				right--;
				flag = !flag;
			}
			else
			{
				left++;
			}
		}

	}
	return left;
}

