#include <iostream>
#include <ctime>
#include <ctime>
#include <algorithm>
#include "BST.h"

using namespace std;


void shuffle( int arr[], int n ){

    srand( time(NULL) );
    for( int i = n-1 ; i >= 0 ; i -- ){
        int x = rand()%(i+1);
        swap( arr[i] , arr[x] );
    }
}

int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    int n = 10000;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        //cout<<key<<" ";
        bst.insert(key,value);
    }
    //cout<<endl;


//    // test removeMin
//    while( !bst.isEmpty() ){
//        cout<<"min: "<<bst.minimum()<<endl;
//        bst.removeMin();
//        cout<<"After removeMin, size = "<<bst.size()<<endl;
//    }

    // test removeMax
    while( !bst.isEmpty() ){
        cout<<"max: "<<bst.maximum()<<endl;
        bst.removeMax();
        cout<<"After removeMax, size = "<<bst.size()<<endl;
    }

    // test remove
    // remove elements in random order
    int order[n];
    for( int i = 0 ; i < n ; i ++ )
        order[i] = i;
    shuffle( order , n );

    for( int i = 0 ; i < n ; i ++ )
        if( bst.contain( order[i] )){
            bst.remove( order[i] );
            cout<<"After remove "<<order[i]<<" size = "<<bst.size()<<endl;
        }

    return 0;
}