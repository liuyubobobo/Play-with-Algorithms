//
// Created by liuyubobobo on 11/21/17.
//

#ifndef OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H
#define OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H

#include <cassert>

using namespace std;

namespace BinarySearch{

    // 二分查找法, 在一个有序数组arr中, 寻找大于等于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 lower_bound
    template<typename T>
    int firstGreaterOrEqual(T arr[], int n, T target){

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

    // 二分查找法, 在一个有序数组arr中, 寻找大于target的元素的第一个索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回arr的元素个数 n
    // 相当于 upper_bound
    template<typename T>
    int firstGreaterThan(T arr[], int n, T target){

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

    // 二分查找法, 在一个有序数组arr中, 寻找小于等于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    template<typename T>
    int lastLessOrEqual(T arr[], int n, T target){

        assert(n >= 0);

        int l = -1, r = n - 1;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(arr[mid] > target)
                r = mid - 1;
            else    // nums[mid] <= target
                l = mid;
        }

        return l;
    }

    // 二分查找法, 在一个有序数组arr中, 寻找小于target的元素的最大索引
    // 如果存在, 则返回相应的索引index
    // 否则, 返回 -1
    template<typename T>
    int lastLessThan(T arr[], int n, T target){

        assert(n >= 0);

        int l = -1, r = n - 1;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(arr[mid] >= target)
                r = mid - 1;
            else    // nums[mid] < target
                l = mid;
        }

        return l;
    }
}

#endif //OPTIONAL_03_LOWER_BOUND_AND_UPPER_BOUND_IN_BINARY_SEARCH_BINARYSEARCH_H
