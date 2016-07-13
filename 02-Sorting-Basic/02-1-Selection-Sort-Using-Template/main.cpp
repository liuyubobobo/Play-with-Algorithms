#include <iostream>
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}

int main() {

    // 测试泛型函数
    float a[4] = {4.4,3.3,2.2,1.1};
    selectionSort(a,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;

    // 测试泛型函数2
    string b[4] = {"D","C","B","A"};
    selectionSort(b,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<b[i]<<" ";
    cout<<endl;

    // 测试泛型函数3
    Student c[4] = { {"D",90} , {"C",100} , {"B",95} , {"A",95} };
    selectionSort(c,4);
    for( int i = 0 ; i < 4 ; i ++ )
        cout<<c[i];
    cout<<endl;

    return 0;
}