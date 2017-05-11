#include <iostream>
#include <cassert>
#include "SortTestHelper.h"

using namespace std;

// 最大索引堆
template<typename Item>
class IndexMaxHeap{

private:
    Item *data;     // 最大索引堆中的数据
    int *indexes;   // 最大索引堆中的索引, indexes[x] = i 表示索引i在x的位置
    int *reverse;   // 最大索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置

    int count;
    int capacity;

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
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
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]] )
                j += 1;

            if( data[indexes[k]] >= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    // 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
    IndexMaxHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
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

    // 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );

        // 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
        assert( !contain(i) );

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        reverse[i] = count+1;
        count++;

        shiftUp(count);
    }

    // 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // 从最大索引堆中取出堆顶元素的索引
    int extractMaxIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // 获取最大索引堆中的堆顶元素
    Item getMax(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    // 获取最大索引堆中的堆顶元素的索引
    int getMaxIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    // 看索引i所在的位置是否存在元素
    bool contain( int i ){
        assert( i + 1 >= 1 && i + 1 <= capacity );
        return reverse[i+1] != 0;
    }

    // 获取最大索引堆中索引为i的元素
    Item getItem( int i ){
        assert( contain(i) );
        return data[i+1];
    }

    // 将最大索引堆中索引为i的元素修改为newItem
    void change( int i , Item newItem ){

        assert( contain(i) );
        i += 1;
        data[i] = newItem;

        // 找到indexes[j] = i, j表示data[i]在堆中的位置
        // 之后shiftUp(j), 再shiftDown(j)
//        for( int j = 1 ; j <= count ; j ++ )
//            if( indexes[j] == i ){
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }

        // 有了 reverse 之后,
        // 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
        shiftUp( reverse[i] );
        shiftDown( reverse[i] );
    }

    // 测试索引堆中的索引数组index和反向数组reverse
    // 注意:这个测试在向堆中插入元素以后, 不进行extract操作有效
    bool testIndexesAndReverseIndexes(){

        int *copyIndexes = new int[count+1];
        int *copyReverseIndexes = new int[count+1];

        for( int i = 0 ; i <= count ; i ++ ){
            copyIndexes[i] = indexes[i];
            copyReverseIndexes[i] = reverse[i];
        }

        copyIndexes[0] = copyReverseIndexes[0] = 0;
        std::sort(copyIndexes, copyIndexes + count + 1);
        std::sort(copyReverseIndexes, copyReverseIndexes + count + 1);

        // 在对索引堆中的索引和反向索引进行排序后,
        // 两个数组都应该正好是1...count这count个索引
        bool res = true;
        for( int i = 1 ; i <= count ; i ++ )
            if( copyIndexes[i-1] + 1 != copyIndexes[i] ||
                    copyReverseIndexes[i-1] + 1 != copyReverseIndexes[i] ){
                res = false;
                break;
            }

        delete[] copyIndexes;
        delete[] copyReverseIndexes;

        if( !res ){
            cout<<"Error!"<<endl;
            return false;
        }

        for( int i = 1 ; i <= count ; i ++ )
            if( reverse[ indexes[i] ] != i ){
                cout<<"Error 2"<<endl;
                return false;
            }

        return true;
    }
};

// 使用最大索引堆进行堆排序, 来验证我们的最大索引堆的正确性
// 最大索引堆的主要作用不是用于排序, 我们在这里使用排序只是为了验证我们的最大索引堆实现的正确性
// 在后续的图论中, 无论是最小生成树算法, 还是最短路径算法, 我们都需要使用索引堆进行优化:)
template<typename T>
void heapSortUsingIndexMaxHeap(T arr[], int n){

    IndexMaxHeap<T> indexMaxHeap = IndexMaxHeap<T>(n);
    for( int i = 0 ; i < n ; i ++ )
        indexMaxHeap.insert( i , arr[i] );
    assert( indexMaxHeap.testIndexesAndReverseIndexes() );

    for( int i = n-1 ; i >= 0 ; i -- )
        arr[i] = indexMaxHeap.extractMax();
}

int main() {

    int n = 1000000;

    int* arr = SortTestHelper::generateRandomArray(n, 0, n);
    SortTestHelper::testSort("Heap Sort Using Index-Max-Heap", heapSortUsingIndexMaxHeap, arr, n);
    delete[] arr;

    return 0;
}