#include <iostream>
#include <ctime>
#include "SequenceST.h"

using namespace std;


int main() {

    srand(time(NULL));
    SequenceST<int,int> sst = SequenceST<int,int>();

    int n = 100;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        sst.insert(key,value);
    }

    cout<<"size: "<<sst.size()<<endl<<endl;

    for( int i = 0 ; i < n ; i ++ ){
        if( sst.contain(i) ){
            int* res = sst.search(i);
            assert( res != NULL && *res == i );
        }
    }

    return 0;
}