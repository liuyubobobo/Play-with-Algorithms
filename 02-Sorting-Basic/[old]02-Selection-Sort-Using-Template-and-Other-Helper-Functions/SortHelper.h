#include <string>

using namespace std;

#ifndef INC_01_2_SELECTION_SORT_USING_TEMPLATE_SORTHELPER_H
#define INC_01_2_SELECTION_SORT_USING_TEMPLATE_SORTHELPER_H

int* generateRandomArray(int n, int range_l, int range_r);

template<typename T>
void printArray(T arr[], int n);

template<typename T>
bool isSorted(T arr[], int n);

template<typename T>
void testSort( const string &sortName, void (*sort)(T[],int) , T arr[], int n );

#endif //INC_01_2_SELECTION_SORT_USING_TEMPLATE_SORTHELPER_H
