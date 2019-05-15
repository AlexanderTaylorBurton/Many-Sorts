/*--------------------------------------------------------------------------||
||	Programmer:			Alexander Burton									||
||	Date Created:		4/26/2019											||
||	Version:			0.8.8.8												||
||	File:				ABSortingClass.cpp									||
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
#include "ABSortingClass.h"

namespace AB_SortingClass
{

	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.1											||
	||	Function: Quicksort													||
	||																		||
	||	Function calls:														||
	||		void partition(T* list[], T* low, T* high)						||
	||		quicksort(list, low, pivot - 1)									||
	||																		||
	||	Called by:															||
	||		int main()														||
	||																		||
	||	Notes:																||
	||		When calling the function, subtract 1 from the third parameter.	||
	||																		||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.1.1.0		|| This is a quicksort(cont)||
	||	algorithm that partitions the data set, which entails moving all	||
	||	elements greater than a given pivot to one side, and elements less	||
	||	than to the other until the sort size is zero.						||
	||	n log(n) best case time complexity.									||
	||																		||
	||	04/28/2019	||	06:33PM	||	0.1.1.1		|| Fixed an issue with(cont)||
	||	sorting.															||
	||																		||
	||----------------------------------------------------------------------*/
	void quicksort(int* list, int low, int high)
	{
		if (low < high)
		{
			int pivot = partition(list, low, high);
			quicksort(list, low, pivot - 1);
			quicksort(list, pivot + 1, high);
		}
	}
	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.1											||
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void quicksort(int* list, int low, int high)					||
	||	Notes:																||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.0.1.0		|| This is a partition(cont)||
	||	algorithm that partitions the data set, which entails moving all	||
	||	elements greater than a given pivot to one side, and elements less	||
	||	than to the other until the sort size is zero.						||
	||	n log(n) best case time complexity.									||
	||																		||
	||	04/28/2019	||	06:33PM	||	0.1.1.1		|| Fixed an issue with(cont)||
	||	sorting.															||
	||																		||
	||----------------------------------------------------------------------*/
	int partition(int* list, int low, int high)
	{
		int pivot = list[high];
		int i = low;
		for (int j = low; j < high; j++)
		{
			if (list[j] < pivot)
			{
				swap(list[i], list[j]);
				i++;
			}
		}
		swap(list[i], list[high]);
		return i;
	}
	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.0											||
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||																		||
	||	Notes:																||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.0.1.0		|| This is a sorting(cont)	||
	||	algorithm that goes through 2 loops(nested) comparing two values	||
	||	and swapping relevent elements until the entire array is sorted.	||
	||	Exponential time.(n^2)												||
	||																		||
	||----------------------------------------------------------------------*/
	void selectionSort(int* list, int low, int size)
	{
		bool swapped = false;
		for (int i = low; i < size; i++)
		{
			swapped = false;
			for (int j = i; j < size; j++)
			{
				if (list[i] > list[j])
				{
					swap(list[i], list[j]);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}

	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.1											||
	||	Function: optimized Quicksort										||
	||																		||
	||	Function calls:														||
	||		void optPartition(list[], low, high)							||
	||		void optQuicksort(list, low, pivot)								||
	||		void optSelectionSort(int* list, int low, int size)				||
	||																		||
	||	Called by:															||
	||																		||
	||	Notes:																||
	||		When calling the function, subtract 1 from the third parameter.	||
	||																		||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.1.1.0		|| This is a quicksort(cont)||
	||	algorithm that partitions the data set, which entails moving all	||
	||	elements greater than a given pivot to one side, and elements less	||
	||	than to the other until the sort size is zero.						||
	||	n log(n) best case time complexity.									||
	||																		||
	||	04/28/2019	||	06:33PM	||	0.1.1.1		|| Fixed an issue with(cont)||
	||	sorting.															||
	||																		||
	||----------------------------------------------------------------------*/
	void optQuicksort(int* list, int low, int high, int ssSize)
	{
		if (low < high)//determine if left and right indicies overlap.
		{
			//if the distance between indices are greater than ssSize, then
			//Perform usual quicksort divide and conquer.
			if ((high - low) > ssSize)
			{
				//get pivot from partition.
				int pivot = optPartition(list, low, high);
				//quicksort left and right sides of array.
				optQuicksort(list, low, pivot - 1, ssSize);
				optQuicksort(list, pivot + 1, high, ssSize);
			}
			else
			{
				//distance between indicies is less than or equal to ssSize.
				//perform selection sort.
				optSelectionSort(list, low, high + 1);
			}
		}
	}
	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.1											||
	||	Function: optPartition												||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void optQuicksort(int* list, int low, int high)					||
	||	Notes:																||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.0.1.0		|| This is a partition(cont)||
	||	algorithm that partitions the data set, which entails moving all	||
	||	elements greater than a given pivot to one side, and elements less	||
	||	than to the other until the sort size is zero.						||
	||	n log(n) best case time complexity.									||
	||																		||
	||	04/28/2019	||	06:33PM	||	0.1.1.1		|| Fixed an issue with(cont)||
	||	sorting.															||
	||																		||
	||----------------------------------------------------------------------*/
	int optPartition(int* list, int low, int high)
	{
		//set the pivot to high.
		int pivot = list[high];
		//starting position.
		int i = low;
		for (int j = low; j < high; j++)
		{
			if (list[j] < pivot)
			{
				swap(list[i], list[j]);
				i++;
			}
		}
		swap(list[i], list[high]);
		return i;
	}
	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.0											||
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void optQuicksort(int* list, int low, int high)					||
	||																		||
	||	Notes:																||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.0.1.0		|| This is a sorting(cont)	||
	||	algorithm that goes through 2 loops(nested) comparing two values	||
	||	and swapping relevent elements until the entire array is sorted.	||
	||	Exponential time.(n^2) for use with optQuicksort					||
	||																		||
	||----------------------------------------------------------------------*/
	void optSelectionSort(int* list, int low, int size)
	{
		bool swaps;
		for (int i = low; i < size; i++)
		{
			swaps = false;
			for (int j = i; j < size; j++)
			{
				if (list[i] > list[j])
				{
					swaps = true;
					swap(list[i], list[j]);
				}
			}
			if (swaps == false)
				break;
		}
	}
	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
	||	Version:			0.1.1.0											||
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||			void randomizeArr(int* list, int size)						||
	||																		||
	||	Notes:																||
	||	Version History:													||
	||	Date:		||	Time:	||	Version:	||	Description:			||
	||	04/26/2019	||	05:37PM	||	0.1.1.0		|| This is a randomizer		||
	||	fucntion using a left index and a right index that point to an		||
	||	that has been passed in via pointer.								||
	||																		||
	||----------------------------------------------------------------------*/
	void randomizeArr(int* list, int size)
	{
		//Left index is the first index array. Right is the second.
		int leftIndex = 0, rightIndex = 0;
		//randomize array and vector
		for (int i = 0; i < size; ++i)
		{
			srand((int)time(0) + i);//randomize seed
			leftIndex = rand() % size;//left index is randomized
			for (int j = 0; j < size; ++j)
			{
				srand((int)time(0) + i + j);//randomize seed
				rightIndex = rand() % size;//right index is randomized
				while (rightIndex == leftIndex)
				{
					rightIndex = rand() % size;//right index is randomized
				}
				//swap array elements
				int temp = list[leftIndex];
				list[leftIndex] = list[rightIndex];
				list[rightIndex] = temp;
			}
		}
	}
	void printArr(int* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << " * " << setw(5) << arr[i];
			if ((i + 1) % 10 == 0)
				cout << " *" << endl;
		}
	}
};
//--------------------------------End of File---------------------------------