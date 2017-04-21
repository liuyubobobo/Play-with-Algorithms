#include <iostream>
#include "TestHelper.h"

using namespace std;

// 计算逆序数对的结果以long long返回
// 对于一个大小为N的数组, 其最大的逆序数对个数为 N*(N-1)/2, 非常容易产生整型溢出

// merge函数求出在arr[l...mid]和arr[mid+1...r]有序的基础上, arr[l...r]的逆序数对个数
long long __merge( int arr[], int l, int mid, int r){

    int *aux = new int[r-l+1];
    for( int i = l ; i <= r ; i ++ )
        aux[i-l] = arr[i];

    // 初始化逆序数对个数 res = 0
    long long res = 0;
    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int j = l, k = mid + 1;
    for( int i = l ; i <= r ; i ++ ){
        if( j > mid ){ // 如果左半部分元素已经全部处理完毕
            arr[i] = aux[k-l];
            k ++;
        }
        else if( k > r ){ // 如果右半部分元素已经全部处理完毕
            arr[i] = aux[j-l];
            j ++;
        }
        else if( aux[j-l] <= aux[k-l] ){ // 左半部分所指元素 <= 右半部分所指元素
            arr[i] = aux[j-l];
            j ++;
        }
        else{ // 右半部分所指元素 < 左半部分所指元素
            arr[i] = aux[k-l];
            k ++;
            // 此时, 因为右半部分k所指的元素小
            // 这个元素和左半部分的所有未处理的元素都构成了逆序数对
            // 左半部分此时未处理的元素个数为 mid - j + 1
            res += (long long)(mid - j + 1);
        }
    }

    delete[] aux;

    return res;
}

// 求arr[l..r]范围的逆序数对个数
// 思考: 归并排序的优化可否用于求逆序数对的算法? :)
long long __inversionCount(int arr[], int l, int r){

    if( l >= r )
        return 0;

    int mid = l + (r-l)/2;

    // 求出 arr[l...mid] 范围的逆序数
    long long res1 = __inversionCount( arr, l, mid);
    // 求出 arr[mid+1...r] 范围的逆序数
    long long res2 = __inversionCount( arr, mid+1, r);

    return res1 + res2 + __merge( arr, l, mid, r);
}

// 递归求arr的逆序数对个数
long long inversionCount(int arr[], int n){

    return __inversionCount(arr, 0, n-1);
}


int main() {

    int n = 1000000;

    // 测试1: 测试随机数组
    cout<<"Test Inversion Count for Random Array, n = "<<n<<" :"<<endl;
    int* arr = TestHelper::generateRandomArray(n, 0, n);
    cout<<inversionCount(arr, n)<<endl<<endl;
    delete[] arr;

    // 测试2: 测试完全有序的数组
    // 结果应该为0
    cout<<"Test Inversion Count for Ordered Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateOrderedArray(n);
    cout<<inversionCount(arr, n)<<endl<<endl;
    delete[] arr;

    // 测试3: 测试完全逆序的数组
    // 结果应改为 N*(N-1)/2
    cout<<"Test Inversion Count for Inversed Array, n = "<<n<<" :"<<endl;
    arr = TestHelper::generateInversedArray(n);
    cout<<inversionCount(arr, n)<<endl;
    delete[] arr;

    return 0;
}