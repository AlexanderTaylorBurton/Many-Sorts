/*--------------------------------------------------------------------------||
||	Programmer:			Alexander Burton									||
||	Date Created:		4/26/2019											||
||	File:				ABSortingClass.cpp									||
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
----------------------------------------------------------------------------*/
#include "ABSortingClass.h"

namespace AB_SortingClass
{

	/*----------------------------------------------------------------------||
	||	Programmer:			Alexander Burton								||
	||	Date Created:		4/26/2019										||
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
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void quicksort(int* list, int low, int high)					||
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
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
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
	||		When calling the function from outside this scope, subtract 1	||
	||	from the third parameter.											||
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
	||	Function: optPartition												||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void optQuicksort(int* list, int low, int high)					||
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
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||		void optQuicksort(int* list, int low, int high)					||
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
	||	Function: Partition													||
	||																		||
	||	Function calls:														||
	||																		||
	||	Called by:															||
	||			void randomizeArr(int* list, int size)						||
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