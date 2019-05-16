#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Sorting
{
    private:
        string fileName;
        int numElements;

        double *quickSortArray;
        double *insertSortArray;
        double *mergeSortArray;
        double *gnomeSortArray;

	public:
		Sorting();
		~Sorting();

		    void setInputFile(string file);

        void quickSort(double array[], int left, int right);
        int partition(double array[], int left, int right);
        void insertionSort(double array[]);
        void mergeSort(double array[], int left, int right);
        void merge(double array[], int left, int middle, int right);
        void gnomeSort(double array[]);

        void sortAll();
        void swap(double array[], int a, int b);
};
