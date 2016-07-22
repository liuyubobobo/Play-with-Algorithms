#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"

using namespace std;


template <typename T>
int _partition(T arr[], int l, int r){

    T v = arr[l];
    int i = l+1, j = r;
    while( true ){
        // 从前到后找到第一个比v大的元素arr[i]
        while( i <= r && arr[i] <= v )
            i ++;

        // 从后到前找到第一个比v小的元素arr[j]
        while( j >= l+1 && arr[j] >= v )
            j --;

        if( i > j )
            break;

        swap( arr[i] , arr[j] );
    }

    // j == l 或者 arr[j]为最后一个比v小的数
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
    int* arr = SortTestHelper::generateRandomArray(n,0,n);

    SortTestHelper::testSort("Quick Sort", quickSort, arr, n);

    delete(arr);

    return 0;
}