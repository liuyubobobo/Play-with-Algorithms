#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "ShellSort.h"

using namespace std;

int main() {

    int n = 1000000;
    int T = 100;

    double time1 = 0.0, time2 = 0.0;
    for( int i = 0 ; i < T ; i ++ ) {
        int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
        int *arr2 = SortTestHelper::copyIntArray(arr1, n);

        time1 += SortTestHelper::testSort(mergeSort, arr1, n);
        time2 += SortTestHelper::testSort(shellSort, arr2, n);

        delete[] arr1;
        delete[] arr2;
    }

    cout << "Sorting "<<n<<" elements "<<T<<" times. Calculate the average run time."<<endl;
    cout << "Merge Sort Average Run Time: " << time1/T << " s"<<endl;
    cout << "Shell Sort Average Run Time: " << time2/T << " s"<<endl;

    return 0;
}