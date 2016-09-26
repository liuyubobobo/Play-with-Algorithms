//
// Created by liuyubobobo on 9/26/16.
//

#ifndef INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_INDEXMINHEAP_H
#define INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_INDEXMINHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


template<typename Item>
class IndexMinHeap{

private:
    Item *data;
    int *indexes;
    int *reverse;

    int count;
    int capacity;

    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] > data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j]] > data[indexes[j+1]] )
                j += 1;

            if( data[indexes[k]] <= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    IndexMinHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(int index, Item item){
        assert( count + 1 <= capacity );
        assert( index + 1 >= 1 && index + 1 <= capacity );

        index += 1;
        data[index] = item;
        indexes[count+1] = index;
        reverse[index] = count+1;
        count++;
        shiftUp(count);
    }

    Item extractMin(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    Item getMin(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMinIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    bool contain( int index ){

        return reverse[index+1] != 0;
    }

    Item getItem( int index ){
        assert( contain(index) );
        return data[index+1];
    }

    void change( int index , Item newItem ){

        assert( contain(index) );
        index += 1;
        data[index] = newItem;

        shiftUp( reverse[index] );
        shiftDown( reverse[index] );
    }

};

#endif //INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_INDEXMINHEAP_H
