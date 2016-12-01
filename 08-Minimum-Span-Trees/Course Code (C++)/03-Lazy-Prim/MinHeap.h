//
// Created by liuyubobobo on 9/24/16.
//

#ifndef INC_03_LAZY_PRIM_MINHEAP_H
#define INC_03_LAZY_PRIM_MINHEAP_H

#include <algorithm>
#include <cassert>

using namespace std;


template<typename Item>
class MinHeap{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k/2] > data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] < data[j] ) j ++;
            if( data[k] <= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:

    MinHeap(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    MinHeap(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MinHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    Item extractMin(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    Item getMin(){
        assert( count > 0 );
        return data[1];
    }

    void show(){
        cout<<"| ";
        for( int i = 1 ; i <= count ; i ++ )
            cout<<data[i]->wt()/*<<","<<data[i]*/<<" | ";
        cout<<endl;
    }
};

#endif //INC_03_LAZY_PRIM_MINHEAP_H
