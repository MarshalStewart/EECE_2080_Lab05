#include "Sorting.h"

// RIP ILAN 2020-2020

using namespace std;

// Bubble Sort
// Based on Textbook
void bubbleSort(int array[], int size)
{
    bool isSorted = false; // we are done
    int bubbles = 1; // num operations

    while (!isSorted && (bubbles < size))
    {
        isSorted = true;
        for (int i = 0; i < size - bubbles; i++)
        {
            int nxt = i + 1;
            int count = 0;
            if (array[i] > array[nxt])
            {
                int temp_1 = array[i], temp_2 = array[nxt];
                array[i] = temp_2;
                array[nxt] = temp_1;
                isSorted = false;
            }
        }

        bubbles++;

    }
}

// Insertion Sort
void insertionSort(int array[], int size)
{
    for (int r=1; r<size; r++)
    {
        int l = r;
        int nxtItem = array[r];
        while ((l > 0) && (array[l-1] > nxtItem))
        {
            array[l] = array[l-1];
            l--; 
        }
            array[l] = nxtItem;
    }
}

// Merge Sort
void mergeSort(int array[], int size)
{
    _mergeSort(array, 0, size-1);
}

void _mergeSort(int array[], int x, int y)
{
    if (x < y)
    {
        int mid = x + (y - x) / 2;
        
        _mergeSort(array, x, mid);
        _mergeSort(array, mid+1, y);

        merge(array, x, mid, y);
    }

}


void merge(int array[], int first, int mid, int last)
{
    // Size of arrays
    int size_1 = mid - first + 1;
    int size_2 = last - mid;

    // Create tmp arrays
    int left[size_1];
    int right[size_2];

    for (int i=0; i<(size_1); i++)
    {
        left[i] = array[first+i];
    }
    for (int j=0; j<(size_2); j++)
    {
        right[j] = array[mid+1+j];
    }

    // Sort till one array is empty
    int i = 0, j = 0;
    int count = first;
    while (i < size_1 && j < size_2)
    {
        if (left[i] <= right[j])
        {
            array[count] = left[i];
            i++;
        }
        else
        {
            array[count] = right[j];
            j++;
        }
        count++;
    }

    // if first array still not empty, empty
    while (i < size_1)
    {
        array[count] = left[i];
        i++;
        count++;
    }

    // if second array still not empty, empty
    while (j < size_2)
    {
        array[count] = right[j];
        j++;
        count++;
    }
}

// Quick Sort

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int array[], int low, int high)
{
    // Set pivot to last element
    int piv = array[high];
    int i = low-1;

    // Loop through array
    for(int j = low; j <= high - 1; j++)
    {
        // Check if less than piv
        if (array[j] < piv)
        {
            // move to the left and increment the count of items to the
            // left of pivot
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // Place pivot in middle
    swap(&array[i+1], &array[high]);
    return i+1;
}


void quickSort(int array[], int size)
{
    _quickSort(array, 0, size-1); 
}

void _quickSort(int array[], int first, int last)
{
    if (first < last)
    {
        int piv = partition(array, first, last);

        _quickSort(array, first, piv - 1);
        _quickSort(array, piv + 1, last);
    }
    
}

// Radix Sort (Strings)

int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max ;
}

void countSort(int array[], int size, int digit)
{
    int output[size];
    int count[10] = {0};

    for (int i=0; i<size; i++)
        count[(array[i] / digit) % 10]++;

    for (int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    for (int i=size-1; i>=0; i--)
    {
        output[count[(array[i] / digit) % 10] - 1] = array[i];
        count[(array[i] / digit) % 10]--;
    }

    for (int i=0; i<size; i++)
    {
        array[i] = output[i];
    }

}

void radixSort(int array[], int size)
{
    int max = getMax(array, size);

    for (int digit=1; max / digit > 0; digit*=10)
        countSort(array, size, digit);
    

}

#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#if 0
int main()
{
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " 
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
        << " nanoseconds" << std::endl;
}
#endif //0