#include <iostream>
#include <ctime>
#include <cassert>
#include <algorithm>
#include "TestHelper.h"

using namespace std;

int partition( int nums[], int l, int r ){

    int p = rand()%(r-l+1) + l;
    swap( nums[l] , nums[p] );

    int j = l; //[l+1...j] < p ; [lt+1..i) > p
    for( int i = l + 1 ; i <= r ; i ++ )
        if( nums[i] < nums[l] )
            swap(nums[i], nums[++j]);

    swap(nums[l], nums[j]);

    return j;
}

int __selection( int nums[], int l, int r, int k ){

    if( l == r )
        return nums[l];

    int p = partition( nums, l, r );

    if( p == k )
        return nums[p];
    else if( k < p )
        return __selection( nums, l, p-1, k);
    else // k > p
        return __selection( nums, p+1 , r, k );
}

int selection(int nums[], int n, int k) {

    srand(time(NULL));
    return __selection(nums, 0, n - 1, k);
}


int main() {

    int n = 10000;
    int* arr = TestHelper::generateOrderedArray(n);
    TestHelper::shuffleArray(arr, n);

    for( int i = 0 ; i < n ; i ++ ){
        assert( selection(arr, n, i) == i );
        cout<<"test "<<i<<" complete."<<endl;
    }
    cout<<"Test selection completed."<<endl;

    delete[] arr;

    return 0;
}