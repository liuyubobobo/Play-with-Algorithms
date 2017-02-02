//
// Created by liuyubobobo on 02/02/2017.
//

#ifndef OPTIONAL_2_INVERSION_NUMBER_TESTHELPER_H
#define OPTIONAL_2_INVERSION_NUMBER_TESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;


namespace TestHelper {

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

    int *generateOrderedArray( int n ){

        return generateNearlyOrderedArray(n, 0);
    }

    int *generateInversedArray( int n ){

        int *arr = generateOrderedArray( n );
        for( int i = n/2 - 1 ; i >= 0 ; i -- )
            swap( arr[i] , arr[n-i-1]);
        return arr;
    }
};

#endif //OPTIONAL_2_INVERSION_NUMBER_TESTHELPER_H
