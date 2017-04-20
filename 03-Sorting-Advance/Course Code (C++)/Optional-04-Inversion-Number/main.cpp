#include <iostream>
#include "TestHelper.h"

using namespace std;

long long __merge( int arr[], int l, int mid, int r){

    int *aux = new int[r-l+1];
    for( int i = l ; i <= r ; i ++ )
        aux[i-l] = arr[i];

    long long res = 0;
    int j = l, k = mid + 1;
    for( int i = l ; i <= r ; i ++ ){
        if( j > mid ){
            arr[i] = aux[k-l];
            k ++;
        }
        else if( k > r ){
            arr[i] = aux[j-l];
            j ++;
        }
        else if( aux[j-l] <= aux[k-l] ){
            arr[i] = aux[j-l];
            j ++;
        }
        else{
            arr[i] = aux[k-l];
            k ++;
            res += (mid - j + 1);
        }
    }

    delete[] aux;

    return res;
}

long long __inversionCount(int arr[], int l, int r){

    if( l >= r )
        return 0;

    int mid = l + (r-l)/2;

    long long res1 = __inversionCount( arr, l, mid);
    long long res2 = __inversionCount( arr, mid+1, r);

    return res1 + res2 + __merge( arr, l, mid, r);
}

long long inversionCount(int arr[], int n){

    return __inversionCount(arr, 0, n-1);
}

int main() {

    int n = 1000000;

    cout<<"Test Inversion Count for Random Array, n = "<<n<<" :"<<endl;
    int* arr = TestHelper::generateRandomArray(n, 0, n);
    cout<<inversionCount(arr, n)<<endl<<endl;
    delete[] arr;

    cout<<"Test Inversion Count for Ordered Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateOrderedArray(n);
    cout<<inversionCount(arr, n)<<endl<<endl;
    delete[] arr;

    cout<<"Test Inversion Count for Inversed Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateInversedArray(n);
    cout<<inversionCount(arr, n)<<endl;
    delete[] arr;

    return 0;
}