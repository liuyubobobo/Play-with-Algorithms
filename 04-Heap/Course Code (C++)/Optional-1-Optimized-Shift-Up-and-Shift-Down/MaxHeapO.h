//
// Created by liuyubobobo on 4/25/17.
//

#ifndef OPTIONAL_1_OPTIMIZED_SHIFT_UP_AND_SHIFT_DOWN_MAXHEAPO_H
#define OPTIONAL_1_OPTIMIZED_SHIFT_UP_AND_SHIFT_DOWN_MAXHEAPO_H

#include <algorithm>
#include <cassert>

using namespace std;

// 将 ShiftUp 和 ShiftDown 函数使用类似插入排序算法的方式进行优化的最大堆
template<typename Item>
class MaxHeapO{

private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        Item e = data[k];
        while( k > 1 && data[k/2] < e ){
            //swap( data[k/2], data[k] );
            data[k] = data[k/2];
            k /= 2;
        }
        data[k] = e;
    }

    void shiftDown(int k){
        Item e = data[k];
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j+1] > data[j] ) j ++;
            if( e >= data[j] ) break;
            //swap( data[k] , data[j] );
            data[k] = data[j];
            k = j;
        }
        data[k] = e;
    }

public:

    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    MaxHeapO(int capacity){
        data = new Item[capacity+1];
        count = 0;
        this->capacity = capacity;
    }

    // 构造函数, 通过一个给定数组创建一个最大堆
    // 该构造堆的过程, 时间复杂度为O(n)
    MaxHeapO(Item arr[], int n){
        data = new Item[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i ++ )
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i -- )
            shiftDown(i);
    }

    ~MaxHeapO(){
        delete[] data;
    }

    // 返回堆中的元素个数
    int size(){
        return count;
    }

    // 返回一个布尔值, 表示堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 像最大堆中插入一个新的元素 item
    void insert(Item item){
        assert( count + 1 <= capacity );
        data[count+1] = item;
        shiftUp(count+1);
        count ++;
    }

    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    Item extractMax(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }

    // 获取最大堆中的堆顶元素
    Item getMax(){
        assert( count > 0 );
        return data[1];
    }
};

#endif //OPTIONAL_1_OPTIMIZED_SHIFT_UP_AND_SHIFT_DOWN_MAXHEAPO_H
