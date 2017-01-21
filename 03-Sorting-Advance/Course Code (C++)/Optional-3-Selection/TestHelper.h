//
// Created by liuyubobobo on 22/01/2017.
//

#ifndef OPTIONAL_3_SELECTION_TESTHELPER_H
#define OPTIONAL_3_SELECTION_TESTHELPER_H

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

namespace TestHelper {

    int *generateOrderedArray(int n) {

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = i;

        return arr;
    }

    void shuffleArray(int arr[], int n){

        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            int j = rand() % (n-i)+i;
            swap( arr[i], arr[j]);
        }
    }
}
#endif //OPTIONAL_3_SELECTION_TESTHELPER_H
