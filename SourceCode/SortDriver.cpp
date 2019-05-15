/*--------------------------------------------------------------------------||
||	Programmer:			Alexander Burton									||
||	Date Created:		4/26/2019											||
||	Version:			0.8.8.8												||
||	File:				SortDriver.cpp										||
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
||																			||
----------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "ABSortingClass.h"
//#include "ABFileHandler.h" //being built
const string humanWelcome = "Thank you for using this program!";
const string humanWelcome2 = " Coded by Alexander Burton.\n";
const string makeChoice = "Which sort would you like to choose?";
const string ssChoice = "A) ";
const string ssName = "Selection Sort";
const string qsChoice = "B) ";
const string qsName = "Quick Sort";
const string oqsChoice = "C) ";
const string oqsName = "Optimized Quick Sort";
const string itemSizeString = "How many items would you like sorted?";
const string itemRange = "The number can be between 1 and ";
using namespace std;
using namespace AB_SortingClass;
int main()
{
	bool goodInput = true;
	char choice = ' ';
	const int SSSIZE = 10;
	int itemSize = 0;
	int exitStatus = EXIT_SUCCESS;
	int RandomNumbers[MAX_SIZE];
	cout << humanWelcome << humanWelcome2 << endl;
	cout << makeChoice << endl << ssChoice << ssName << endl << qsChoice <<
		qsName << endl << oqsChoice << oqsName << endl;
	cin >> choice;
	while (cin.fail())
	{
		cout << "Please enter a proper value.\n";
		cin >> choice;
	}
	while (((toupper(choice) < 'A' || toupper(choice) > 'C'))
		&& ((choice < '1') || (choice > '3')))
	{
		cout << "Values are out of range." <<
			" Please choose a number between 1 and 3, or A,B, or C" << endl;
		cin >> choice;
		while (cin.fail())
		{
			cout << "Please enter a proper value.\n";
			cin >> choice;
		}
	}
	cout << itemSizeString << endl << itemRange << MAX_SIZE<<endl;
	cin >> itemSize;
	while (cin.fail())
	{
		cout << "Please enter a proper value.\n";
		cin >> itemSize;
	}
	while ((itemSize > MAX_SIZE) || (itemSize < 1))
	{
		cout << "please enter a value between 1 and " << MAX_SIZE<<endl;
		while (cin.fail())
		{
			cout << "Please enter a proper value.\n";
			cin >> itemSize;
		}
	}
	cout << "Randomizing Array." << endl;
	//fill array sequentially.
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		RandomNumbers[i] = (i + 1);
	}
	cout << "Initializing ";
	choice = toupper(choice);
	switch (choice)
	{
	case '1':
	case 'A':
		cout << ssName << "." << endl;
		selectionSort(RandomNumbers, 0, itemSize);
		break;
	case '2':
	case 'B':
		cout << qsName << "." << endl;
		quicksort(RandomNumbers, 0, itemSize-1);
		break;
	case '3':
	case 'C':
		cout << oqsName << "." << endl;
		optQuicksort(RandomNumbers, 0, itemSize-1, SSSIZE);
		break;
	}
	cout << "Sorting completed." << endl;
	cout << "Printing Array." << endl;
	printArr(RandomNumbers, itemSize);
	cout << endl << "Thank you for using this program." << 
		endl << "-Alexander Burton" << endl;
	cin.ignore();
	cin.get();
	return exitStatus;
}
//--------------------------------End of File---------------------------------