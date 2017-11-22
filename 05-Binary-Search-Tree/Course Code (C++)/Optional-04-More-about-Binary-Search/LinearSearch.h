//
// Created by liuyubobobo on 11/21/17.
//

#ifndef OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_LINEARSEARCH_H
#define OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_LINEARSEARCH_H

#include <cassert>

using namespace std;

namespace LinearSearch{

    // 线性查找法, 在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 lower_bound
    template<typename T>
    int firstGreaterOrEqual(T arr[], int n, T target){

        assert(n >= 0);

        for(int i = 0 ; i < n ; i ++)
            if(arr[i] >= target)
                return i;
        return n;
    }

    // 线性查找法, 在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 upper_bound
    template<typename T>
    int firstGreaterThan(T arr[], int n, T target){

        assert(n >= 0);

        for(int i = 0 ; i < n ; i ++)
            if(arr[i] > target)
                return i;
        return n;
    }

    // 线性查找法, 在一个有序数组arr中, 寻找小于等于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    template<typename T>
    int lastLessOrEqual(T arr[], int n, T target){

        assert(n >= 0);

        for(int i = 0 ; i < n ; i ++)
            if(arr[i] > target)
                return i - 1;

        return n - 1;
    }

    // 线性查找法, 在一个有序数组arr中, 寻找小于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    template<typename T>
    int lastLessThan(T arr[], int n, T target){

        assert(n >= 0);

        for(int i = 0 ; i < n ; i ++)
            if(arr[i] >= target)
                return i - 1;

        return n - 1;
    }
}

#endif //OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_LINEARSEARCH_H
