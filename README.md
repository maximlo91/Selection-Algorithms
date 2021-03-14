Selection Algorithms Project
Built as a C++ Console Application, on visual studio (solution provided)
can be compiled and run on non-VS IDE.
The program takes an input and shows the amount of comparisons that happen in 3 known selection algorithms as output.
The program makes use of Quickselect (randomized pivot partition), Minimal Heap and Binary Search Tree data structures.

-------------------------------------------------------------------------------------------------
Console Instructions :
The program builds a person array from the input provided.

The array is copied and sent into 3 different functions,
every function finds the k'th smallest element in the array (person's id).
each function updates the number of comparisons being made in the functions between ids.

the functions:
1) sends an array into selection, with a randomly selected pivot 
being sent into the partition function, if selected k is the pivot it returns it.
the function performes this recursively untill it finds the k element.
2) sends an array into heap function, the function then creates a min heap with floyd's algorithem
then the function removes k minimum numbers untill it reaches the k'th smallest.
3) sends an array into BST function, a BST is being created from the array,
and then the k'ths smallest element is being found with a function that traverses the BST
by the amount of left sub-tree nodes in each node untill it finds the k smallest node.

Input rules (must have new line between inputs) :
1) input 'n' number of persons to be created. 
2) input 'n' persons with data as (id name).
3) input 'k' to be selected as k'th smallest in all functions.

Each person's id must be unique, error checking is enabled to guarantee no duplicate id's
exists.

Output :
The program outputs all comparisons made by the 3 functions.
-------------------------------------------------------------------------------------------------
How to use test files:
Test files as .txt documents are located in /tests
after building the solution and/or compiling the program
copy the contents of the test file and paste inside console.
the program will produce the output. 
-------------------------------------------------------------------------------------------------
Example :

3
100 avi
101 tomer
102 michael
2

Output: 
101 tomer

Rand Selection: 2
selectHeap: 3
BST: 5
