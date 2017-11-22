//
// Created by liuyubobobo on 11/21/17.
//

#ifndef OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H
#define OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H

#include <cassert>

using namespace std;

namespace BinarySearch{

    // 二分查找法, 实现lower_bound
    // 即在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    template<typename T>
    int lower_bound(T arr[], int n, T target){

        assert(n >= 0);

        int l = 0, r = n;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(arr[mid] < target)
                l = mid + 1;
            else    // nums[mid] >= target
                r = mid;
        }
        return l;
    }

    // 二分查找法, 实现upper_bound
    // 即在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    template<typename T>
    int upper_bound(T arr[], int n, T target){

        assert(n >= 0);

        int l = 0, r = n;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(arr[mid] <= target)
                l = mid + 1;
            else    // nums[mid] > target
                r = mid;
        }
        return l;
    }
}

#endif //OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H
