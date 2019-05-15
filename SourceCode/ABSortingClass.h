/*--------------------------------------------------------------------------||
||	Programmer:			Alexander Burton									||
||	Date Created:		4/26/2019											||
||	Version:			0.8.8.8												||
||	File:				ABSortingClass.h									||
||	Compiler Info:															||
||		Hardware:															||
||			MB:																||
||				Manu:		BaseBoard Manufacturer	ASUSTeK COMPUTER INC.	||
||				Chipset:	BaseBoard Product	P8Z77-V PRO					||
||																			||
||			CPU:															||
||				Chipset:	Intel(R) Core(TM) i7-3770 CPU @ 3.40GHz			||
||				Clock Rate:	3401 Mhz										||
||				Cores:		4												||
||				processors:	8												||
||																			||
||			RAM:															||
||				Manu:				Kingston								||
||				Capacity(indiv):	4GB										||
||				Count:				4										||
||				Capacity(total):	16.0GB									||
||				Type:				240-Pin DDR3 SDRAM DDR3 1333 (PC3 10600)||
||																			||
||		Software:															||
||				OS:			Windows 10 Home Edition							||
||				IDE:		Visual Studio 2019								||
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
||	Notes:																	||
||	Version History:														||
||	Date:		||	Time:	||	Version:	||	Description:				||
||	04/26/2019	||	05:37PM	||	0.0.0.0		|| This is a sorting class(cont)||
||	designed for Windows 10. It is intended to sort multiple objects of the	||
||	same type. Multiple sorting algorithms are planned for implementation.	||
||																			||
||	04/26/2019	||	06:55PM	||	0.2.0.0		|| two functions have been		||
||	implemented, but yet untested. Quicksort Algorithm is implemented.		||
||																			||
||	04/27/2019	||	06:55PM	||	0.2.1.2		|| quicksort algorithm is fixed	||
||	and selection sort is implemented.										||
||																			||
||	Version History:														||
||	Date:		||	Time:	||	Version:	||	Description:				||
||	04/26/2019	||	05:37PM	||	0.8.8.8		|| 8 functions have been(cont)	||
||	implemented and fixed in this version.									||
||																			||
----------------------------------------------------------------------------*/

#pragma once
#ifndef ABSORTINGCLASS_H
#define ABSORTINGCLASS_H
#include <vector>
#include <iostream>//Temporary
#include <ctime>//for array randomization
#include <iomanip>
#include <algorithm>
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


	//randomizes an array.
	void randomizeArr(int* list, int size);
	void printArr(int* arr, int size);
}
#endif // !SORTINGCLASS_H
//--------------------------------End of File---------------------------------