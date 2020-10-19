#include <gtest/gtest.h>
#include "Sorting.h"
#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

bool checkSort(int array[], int size)
{
    int prv = 0; // Smallest possible value of entry is 0
    for (int i=0; i<size; i++)
    {
        if (prv > array[i])
            return false;
            
        prv = array[i];
    }

    return true;
}

void createArray(int array[], int size)
{
    srand((unsigned)time(NULL));
     
    for (int i=0; i<size; i++)
    {
        array[i] = (rand() % (2*size)); // between 0 and 2n
    }
}

int array_10[10];
int array_100[100];
int array_500[500];
int array_5000[5000];
int array_25000[25000];

TEST(BubbleSort, SmallSizes)
{
    auto t1 = Clock::now();
    int cur_array_1[10], i;
    for (i=0; i<10; i++)
        cur_array_1[i] = array_10[i];
    ASSERT_FALSE(checkSort(cur_array_1, 10));
    bubbleSort(cur_array_1, 10);
    ASSERT_TRUE(checkSort(cur_array_1, 10));
    auto t2 = Clock::now();
    std::cout 
        << "Bubble Sort 10: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_2[100];
    for (i=0; i<100; i++)
        cur_array_2[i] = array_100[i];
    ASSERT_FALSE(checkSort(cur_array_2, 100));
    bubbleSort(cur_array_2, 100);
    ASSERT_TRUE(checkSort(cur_array_2, 100));
    t2 = Clock::now();
    std::cout 
        << "Bubble Sort 100: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_3[500];
    for (i=0; i<500; i++)
        cur_array_3[i] = array_500[i];
    ASSERT_FALSE(checkSort(cur_array_3, 500));
    bubbleSort(cur_array_3, 500);
    ASSERT_TRUE(checkSort(cur_array_3, 500));
    t2 = Clock::now();
    std::cout 
        << "Bubble Sort 500: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(BubbleSort, MediumSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[5000], i;
    for (i=0; i<5000; i++)
        cur_array[i] = array_5000[i];
    ASSERT_FALSE(checkSort(cur_array, 5000));
    bubbleSort(cur_array, 5000);
    ASSERT_TRUE(checkSort(cur_array, 5000));
    auto t2 = Clock::now();
    std::cout 
        << "Bubble Sort 5000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(BubbleSort, LargeSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[25000], i;
    for (i=0; i<25000; i++)
        cur_array[i] = array_25000[i];
    ASSERT_FALSE(checkSort(cur_array, 25000));
    bubbleSort(cur_array, 25000);
    ASSERT_TRUE(checkSort(cur_array, 25000));
    auto t2 = Clock::now();
    std::cout 
        << "Bubble Sort 25000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(InsertionSort, SmallSizes)
{ 
    auto t1 = Clock::now();
    int cur_array_1[10], i;
    for (i=0; i<10; i++)
        cur_array_1[i] = array_10[i];
    ASSERT_FALSE(checkSort(cur_array_1, 10));
    insertionSort(cur_array_1, 10);
    ASSERT_TRUE(checkSort(cur_array_1, 10));
    auto t2 = Clock::now();
    std::cout 
        << "Insertion Sort 10: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_2[100];
    for (i=0; i<100; i++)
        cur_array_2[i] = array_100[i];
    ASSERT_FALSE(checkSort(cur_array_2, 100));
    insertionSort(cur_array_2, 100);
    ASSERT_TRUE(checkSort(cur_array_2, 100));
    t2 = Clock::now();
    std::cout 
        << "Insertion Sort 100: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_3[500];
    for (i=0; i<500; i++)
        cur_array_3[i] = array_500[i];
    ASSERT_FALSE(checkSort(cur_array_3, 500));
    insertionSort(cur_array_3, 500);
    ASSERT_TRUE(checkSort(cur_array_3, 500));
    t2 = Clock::now();
    std::cout 
        << "Insertion Sort 500: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(InsertionSort, MediumSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[5000], i;
    for (i=0; i<5000; i++)
        cur_array[i] = array_5000[i];
    ASSERT_FALSE(checkSort(cur_array, 5000));
    insertionSort(cur_array, 5000);
    ASSERT_TRUE(checkSort(cur_array, 5000));
    auto t2 = Clock::now();
    std::cout 
        << "Insertion Sort 5000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(InsertionSort, LargeSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[25000], i;
    for (i=0; i<25000; i++)
        cur_array[i] = array_25000[i];
    ASSERT_FALSE(checkSort(cur_array, 25000));
    insertionSort(cur_array, 25000);
    ASSERT_TRUE(checkSort(cur_array, 25000));
    auto t2 = Clock::now();
    std::cout 
        << "Insertion Sort 25000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(MergeSort, SmallSizes)
{ 
    auto t1 = Clock::now();
    int cur_array_1[10], i;
    for (i=0; i<10; i++)
        cur_array_1[i] = array_10[i];
    ASSERT_FALSE(checkSort(cur_array_1, 10));
    mergeSort(cur_array_1, 10);
    ASSERT_TRUE(checkSort(cur_array_1, 10));
    auto t2 = Clock::now();
    std::cout 
        << "Merge Sort 10: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_2[100];
    for (i=0; i<100; i++)
        cur_array_2[i] = array_100[i];
    ASSERT_FALSE(checkSort(cur_array_2, 100));
    mergeSort(cur_array_2, 100);
    ASSERT_TRUE(checkSort(cur_array_2, 100));
    t2 = Clock::now();
    std::cout 
        << "Merge Sort 100: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_3[500];
    for (i=0; i<500; i++)
        cur_array_3[i] = array_500[i];
    ASSERT_FALSE(checkSort(cur_array_3, 500));
    mergeSort(cur_array_3, 500);
    ASSERT_TRUE(checkSort(cur_array_3, 500));
    t2 = Clock::now();
    std::cout 
        << "Merge Sort 500: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(MergeSort, MediumSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[5000], i;
    for (i=0; i<5000; i++)
        cur_array[i] = array_5000[i];
    ASSERT_FALSE(checkSort(cur_array, 5000));
    mergeSort(cur_array, 5000);
    ASSERT_TRUE(checkSort(cur_array, 5000));
    auto t2 = Clock::now();
    std::cout 
        << "Merge Sort 5000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(MergeSort, LargeSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[25000], i;
    for (i=0; i<25000; i++)
        cur_array[i] = array_25000[i];
    ASSERT_FALSE(checkSort(cur_array, 25000));
    mergeSort(cur_array, 25000);
    ASSERT_TRUE(checkSort(cur_array, 25000));
    auto t2 = Clock::now();
    std::cout 
        << "Merge Sort 25000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}


TEST(QuickSort, SmallSizes)
{ 
    auto t1 = Clock::now();
    int cur_array_1[10], i;
    for (i=0; i<10; i++)
        cur_array_1[i] = array_10[i];
    ASSERT_FALSE(checkSort(cur_array_1, 10));
    quickSort(cur_array_1, 10);
    ASSERT_TRUE(checkSort(cur_array_1, 10));
    auto t2 = Clock::now();
    std::cout 
        << "Quick Sort 10: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_2[100];
    for (i=0; i<100; i++)
        cur_array_2[i] = array_100[i];
    ASSERT_FALSE(checkSort(cur_array_2, 100));
    quickSort(cur_array_2, 100);
    ASSERT_TRUE(checkSort(cur_array_2, 100));
    t2 = Clock::now();
    std::cout 
        << "Quick Sort 100: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_3[500];
    for (i=0; i<500; i++)
        cur_array_3[i] = array_500[i];
    ASSERT_FALSE(checkSort(cur_array_3, 500));
    quickSort(cur_array_3, 500);
    ASSERT_TRUE(checkSort(cur_array_3, 500));
    t2 = Clock::now();
    std::cout 
        << "Quick Sort 500: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(QuickSort, MediumSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[5000], i;
    for (i=0; i<5000; i++)
        cur_array[i] = array_5000[i];
    ASSERT_FALSE(checkSort(cur_array, 5000));
    quickSort(cur_array, 5000);
    ASSERT_TRUE(checkSort(cur_array, 5000));
    auto t2 = Clock::now();
    std::cout 
        << "Quick Sort 5000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(QuickSort, LargeSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[25000], i;
    for (i=0; i<25000; i++)
        cur_array[i] = array_25000[i];
    ASSERT_FALSE(checkSort(cur_array, 25000));
    quickSort(cur_array, 25000);
    ASSERT_TRUE(checkSort(cur_array, 25000));
    auto t2 = Clock::now();
    std::cout 
        << "Quick Sort 25000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(RadixSort, SmallSizes)
{ 
    auto t1 = Clock::now();
    int cur_array_1[10], i;
    for (i=0; i<10; i++)
        cur_array_1[i] = array_10[i];
    ASSERT_FALSE(checkSort(cur_array_1, 10));
    radixSort(cur_array_1, 10);
    ASSERT_TRUE(checkSort(cur_array_1, 10));
    auto t2 = Clock::now();
    std::cout 
        << "Radix Sort 10: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_2[100];
    for (i=0; i<100; i++)
        cur_array_2[i] = array_100[i];
    ASSERT_FALSE(checkSort(cur_array_2, 100));
    radixSort(cur_array_2, 100);
    ASSERT_TRUE(checkSort(cur_array_2, 100));
    t2 = Clock::now();
    std::cout 
        << "Radix Sort 100: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
    
    t1 = Clock::now();
    int cur_array_3[500];
    for (i=0; i<500; i++)
        cur_array_3[i] = array_500[i];
    ASSERT_FALSE(checkSort(cur_array_3, 500));
    radixSort(cur_array_3, 500);
    ASSERT_TRUE(checkSort(cur_array_3, 500));
    t2 = Clock::now();
    std::cout 
        << "Radix Sort 500: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(RadixSort, MediumSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[5000], i;
    for (i=0; i<5000; i++)
        cur_array[i] = array_5000[i];
    ASSERT_FALSE(checkSort(cur_array, 5000));
    radixSort(cur_array, 5000);
    ASSERT_TRUE(checkSort(cur_array, 5000));
    auto t2 = Clock::now();
    std::cout 
        << "Radix Sort 5000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

TEST(RadixSort, LargeSizes)
{ 
    auto t1 = Clock::now();
    int cur_array[25000], i;
    for (i=0; i<25000; i++)
        cur_array[i] = array_25000[i];
    ASSERT_FALSE(checkSort(cur_array, 25000));
    radixSort(cur_array, 25000);
    ASSERT_TRUE(checkSort(cur_array, 25000));
    auto t2 = Clock::now();
    std::cout 
        << "Radix Sort 25000: "
        << std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count()
        << std::endl;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    // Populate the arrays
    createArray(array_10, 10);
    createArray(array_100, 100);
    createArray(array_500, 500);
    createArray(array_5000, 5000);
    createArray(array_25000, 25000);
    
    return RUN_ALL_TESTS();

}
