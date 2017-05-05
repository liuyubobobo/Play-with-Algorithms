//
// Created by liuyubobobo on 9/2/16.
//

#ifndef INC_04_OPTIMIZE_BY_SIZE_UNIONFIND1_H
#define INC_04_OPTIMIZE_BY_SIZE_UNIONFIND1_H

#include <iostream>
#include <cassert>

using namespace std;

// 我们的第一版Union-Find
namespace UF1 {

    class UnionFind {

    private:
        int *id;    // 我们的第一版Union-Find本质就是一个数组
        int count;  // 数据个数

    public:
        // 构造函数
        UnionFind(int n) {
            count = n;
            id = new int[n];
            // 初始化, 每一个id[i]指向自己, 没有合并的元素
            for (int i = 0; i < n; i++)
                id[i] = i;
        }

        // 析构函数
        ~UnionFind() {
            delete[] id;
        }

        // 查找过程, 查找元素p所对应的集合编号
        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        // 查看元素p和元素q是否所属一个集合
        // O(1)复杂度
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        // 合并元素p和元素q所属的集合
        // O(n) 复杂度
        void unionElements(int p, int q) {

            int pID = find(p);
            int qID = find(q);

            if (pID == qID)
                return;

            // 合并过程需要遍历一遍所有元素, 将两个元素的所属集合编号合并
            for (int i = 0; i < count; i++)
                if (id[i] == pID)
                    id[i] = qID;
        }
    };
}

#endif //INC_04_OPTIMIZE_BY_SIZE_UNIONFIND1_H
