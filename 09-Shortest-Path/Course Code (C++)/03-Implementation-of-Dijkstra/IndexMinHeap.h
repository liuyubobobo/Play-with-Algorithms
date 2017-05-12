//
// Created by liuyubobobo on 9/28/16.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_INDEXMINHEAP_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_INDEXMINHEAP_H

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

// 最小索引堆
template<typename Item>
class IndexMinHeap{

private:
    Item *data;     // 最小索引堆中的数据
    int *indexes;   // 最小索引堆中的索引, indexes[x] = i 表示索引i在x的位置
    int *reverse;   // 最小索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置

    int count;
    int capacity;

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] > data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
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
    // 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
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

    // 返回索引堆中的元素个数
    int size(){
        return count;
    }

    // 返回一个布尔值, 表示索引堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向最小索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
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

    // 从最小索引堆中取出堆顶元素, 即索引堆中所存储的最小数据
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

    // 从最小索引堆中取出堆顶元素的索引
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

    // 获取最小索引堆中的堆顶元素
    Item getMin(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    // 获取最小索引堆中的堆顶元素的索引
    int getMinIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    // 看索引i所在的位置是否存在元素
    bool contain( int index ){

        return reverse[index+1] != 0;
    }

    // 获取最小索引堆中索引为i的元素
    Item getItem( int index ){
        assert( contain(index) );
        return data[index+1];
    }

    // 将最小索引堆中索引为i的元素修改为newItem
    void change( int index , Item newItem ){

        assert( contain(index) );
        index += 1;
        data[index] = newItem;

        shiftUp( reverse[index] );
        shiftDown( reverse[index] );
    }

};

#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_INDEXMINHEAP_H
