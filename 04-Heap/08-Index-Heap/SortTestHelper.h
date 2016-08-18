//
// Created by liuyubobobo on 8/16/16.
//

#ifndef INC_08_INDEX_HEAP_SORTTESTHELPER_H
#define INC_08_INDEX_HEAP_SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;


namespace SortTestHelper {

    int *generateRandomArray(int n, int range_l, int range_r) {

        int *arr = new int[n];

        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % (range_r - range_l + 1) + range_l;
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes){

        int *arr = new int[n];
        for(int i = 0 ; i < n ; i ++ )
            arr[i] = i;

        srand(time(NULL));
        for( int i = 0 ; i < swapTimes ; i ++ ){
            int posx = rand()%n;
            int posy = rand()%n;
            swap( arr[posx] , arr[posy] );
        }

        return arr;
    }

    int *copyIntArray(int a[], int n){

        int *arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

    bool areSameIntArrs(int* arr, int* arr2, int n){

        std::sort(arr,arr+n);
        std::sort(arr2,arr2+n);
        for( int i = 0 ; i < n ; i ++ )
            if( arr[i] != arr2[i] )
                return false;
        return true;
    }

    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {

        T* arr2 = copyIntArray(arr, n);

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;

        assert(isSorted(arr, n));
        assert(areSameIntArrs(arr,arr2,n));
        delete[] arr2;
        return;
    }

};

#endif //INC_08_INDEX_HEAP_SORTTESTHELPER_H
