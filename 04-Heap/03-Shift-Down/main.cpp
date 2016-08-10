#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;


template<typename Item>
class MaxHeap{

private:
    Item *data;

    void shiftUp(int k){
        while( k > 1 && data[k/2] < data[k] ){
            swap( data[k/2], data[k] );
            k /= 2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[j] < data[j+1] ) j ++;
            if( data[k] >= data[j] ) break;
            swap( data[k] , data[j] );
            k = j;
        }
    }

public:
    int count;

    MaxHeap(int capacity){
        data = new Item(capacity+1);
        count = 0;
    }

    ~MaxHeap(){
        delete[] data;
    }

    void insert(Item item){
        data[++count] = item;
        shiftUp(count);
    }

    Item delMax(){
        assert( count > 0 );
        Item ret = data[1];
        swap( data[1] , data[count] );
        count --;
        shiftDown(1);
        return ret;
    }
};

int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.count<<endl;

    return 0;
}