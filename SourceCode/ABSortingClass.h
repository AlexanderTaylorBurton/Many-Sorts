/*--------------------------------------------------------------------------||
||	Programmer:			Alexander Burton									||
||	Date Created:		4/26/2019											||
||	File:				ABSortingClass.h									||
||																			||
||	Functions:																||
||																			||
||		void quicksort(int* list, int low, int high);						||
||		int partition(int* list, int low, int high);						||
||		void selectionSort(int* list,int low, int size);					||
||		void optQuicksort(int* list, int low, int high, int ssSize);		||
||		int optPartition(int* list, int low, int high);						||
||		void optSelectionSort(int* list, int low, int size);				||
||																			||
||		void randomizeArr(int* list, int size);								||
||		void printArr(int* arr, int size);									||
||																			||
||	Variables:																||
||		N/A																	||
||																			||
----------------------------------------------------------------------------*/

#pragma once
#ifndef ABSORTINGCLASS_H
#define ABSORTINGCLASS_H
#include <vector>
#include <ctime>//for array randomization
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

namespace AB_SortingClass
{
	const int MAX_SIZE = 1000;
	//Array
	void quicksort(int* list, int low, int high);
	int partition(int* list, int low, int high);
	void selectionSort(int* list,int low, int size);
	void optQuicksort(int* list, int low, int high, int ssSize);
	int optPartition(int* list, int low, int high);
	void optSelectionSort(int* list, int low, int size);
	void combSort(int* list, int size);


	//randomizes an array.
	void randomizeArr(int* list, int size);
	void printArr(int* arr, int size);
}
#endif // !SORTINGCLASS_H
//--------------------------------End of File---------------------------------