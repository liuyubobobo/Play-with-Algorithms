#include <iostream>
#include <algorithm>

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

public:
    int count;

    MaxHeap(int capacity){
        data = new Item(capacity+1);
        count = 0;
    }

    ~MaxHeap(){
        delete[] data;
    }
};

int main() {

    MaxHeap<int> maxheap = MaxHeap<int>(100);
    cout<<maxheap.count<<endl;

    return 0;
}