#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Sorting.h"

using namespace std;

Sorting::Sorting(){};

Sorting::~Sorting()
{
    delete [] quickSortArray;
    delete [] insertSortArray;
    delete [] mergeSortArray;
    delete [] gnomeSortArray;
}

void Sorting::setInputFile(string file)
{
  string nElements;
  string line;
  double size;
  int numLine = 1;

  ifstream inputFile;
  inputFile.open(file.c_str());

  getline(inputFile, nElements);

  numElements = atoi(nElements.c_str());

  quickSortArray = new double[numElements];
  insertSortArray = new double[numElements];
  mergeSortArray = new double[numElements];
  gnomeSortArray = new double[numElements];

  for(int i = 0; i < numElements; ++i)
  {
    numLine++;

    getline(inputFile, line);

    try
    {
      size = atof(line.c_str());
    }
    catch(exception e)
    {
      cout << "Invalid Format, Try Again" << endl;
      return;
    }

    quickSortArray[i] = size;
    insertSortArray[i] = size;
    mergeSortArray[i] = size;
    gnomeSortArray[i] = size;
  }
  inputFile.close();
  sortAll();
}

void Sorting::quickSort(double array[], int left, int right)
{
    int index = partition(array, left, right);

    if (left < index - 1) //sorting left half
    {
        quickSort(array, left, index - 1);
    }
    if (index > right) //sorting right half
    {
        quickSort(array, index, right);
    }
}

int Sorting::partition(double array[], int left, int right)
{
    int pivot = array[(left + right) / 2]; //middle value become pivor

    while (left <= right)
    {
        while (array[left] < pivot) //put objects left of pivot in array
        {
            left++;
        }
        while (array[right] > pivot) //put object right of pivot in array
        {
            right--;
        }
        if (left <= right) //swap left and right objects
        {
            swap(array, left, right);
            left++;
            right--;
        }
    }
    return left;
}

void Sorting::insertionSort(double array[])
{
    for (int j = 1; j < numElements; ++j) //marker
    {
        double temp = array[j]; //storing marked item
        int k = j; //where to start shifting

        while (k > 0 && array[k-1] >= temp) //while left is larger, shift
        {
            array[k] = array[k-1];
            --k;
        }
        array[k] = temp; //put marked item in correct spot
    }
}

void Sorting::gnomeSort(double array[])
{
  int index = 0;

  while (index < numElements)
  {
    if (index == 0 || array[index-1] <= array[index])
    {
      ++index;
    }
    else
    {
      double temp = array[index];
      array[index] = array[index-1];
      array[--index] = temp;
    }
  }
}

void Sorting::mergeSort(double array[], int left, int right)
{
	if(left < right)
	{
		int middle = (left + (right - 1)) / 2;

		mergeSort(array, left, middle);
		mergeSort(array, middle+1, right);

		merge(array, left, middle, right);
	}
}

void Sorting::merge(double array[], int left, int middle, int right)
{
	int i;
  int j;
  int k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  double L[n1]; //temp arrays
  double R[n2];

  for(i = 0; i < n1; i++) //copying data to arrays L and R
  {
    L[i] = array[left + i];
  }
  for (j = 0; j < n2; j++)
  {
    R[j] = array[middle + 1 + j];
  }
  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }
}

void Sorting::sortAll()
{
    clock_t timeStart;
    clock_t timeEnd;
    float calcTime;

    cout << "\n     - SORTING -\n* ----------------- *\n";

    timeStart = clock(); //quick sort
    quickSort(quickSortArray, 0, numElements-1);
    timeEnd = clock();

    calcTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
    cout << "+ Quick Sort took " << calcTime << "ms to sort " << numElements << " numbers\n";

    timeStart = clock(); //insertion sort
    insertionSort(insertSortArray);
    timeEnd = clock();

    calcTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
    cout << "+ Insert Sort took " << calcTime << "ms to sort " << numElements << " numbers\n";

    timeStart = clock(); //gnome sort
    gnomeSort(gnomeSortArray);
    timeEnd = clock();

    calcTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
    cout << "+ Gnome Sort took " << calcTime << "ms to sort " << numElements << " numbers\n";

    timeStart = clock(); //merge sort
    mergeSort(mergeSortArray, 0, numElements-1);
    timeEnd = clock();

    calcTime = (float(timeEnd - timeStart)/CLOCKS_PER_SEC) * 1000;
    cout << "+ Merge Sort took " << calcTime << "ms to sort " << numElements << " numbers\n";

    cout << "\nSorting Completed\n" << endl;
}

void Sorting::swap(double array[], int a, int b)
{
    double temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
