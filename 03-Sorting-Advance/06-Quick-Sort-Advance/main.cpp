#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;


template <typename T>
int _partition(T arr[], int l, int r){

    T v = arr[l];
    int j = l;
    for( int i = l + 1 ; i <= r ; i ++ )
        if( arr[i] < v ){
            j ++;
            swap( arr[j] , arr[i] );
        }

    swap( arr[l] , arr[j]);

    return j;
}

template <typename T>
void _quickSort(T arr[], int l, int r){

    if( l >= r )
        return;

    int p = _partition(arr, l, r);
    _quickSort(arr, l, p-1 );
    _quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    _quickSort(arr, 0, n-1);
}


int main() {

    int n = 1000000;

    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete(arr1);
    delete(arr2);

    return 0;
}