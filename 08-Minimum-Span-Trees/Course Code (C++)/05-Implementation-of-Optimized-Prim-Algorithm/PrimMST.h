//
// Created by liuyubobobo on 9/26/16.
//

#ifndef INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_PRIMMST_H
#define INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_PRIMMST_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

// 使用优化的Prim算法求图的最小生成树
template<typename Graph, typename Weight>
class PrimMST{

private:
    Graph &G;                     // 图的引用
    IndexMinHeap<Weight> ipq;     // 最小索引堆, 算法辅助数据结构
    vector<Edge<Weight>*> edgeTo; // 访问的点所对应的边, 算法辅助数据结构
    bool* marked;                 // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<Weight>> mst;     // 最小生成树所包含的所有边
    Weight mstWeight;             // 最小生成树的权值

    // 访问节点v
    void visit(int v){

        assert( !marked[v] );
        marked[v] = true;

        // 将和节点v相连接的未访问的另一端点, 和与之相连接的边, 放入最小堆中
        typename Graph::adjIterator adj(G,v);
        for( Edge<Weight>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
            int w = e->other(v);
            // 如果边的另一端点未被访问
            if( !marked[w] ){
                // 如果从没有考虑过这个端点, 直接将这个端点和与之相连接的边加入索引堆
                if( !edgeTo[w] ){
                    edgeTo[w] = e;
                    ipq.insert(w, e->wt());
                }
                // 如果曾经考虑这个端点, 但现在的边比之前考虑的边更短, 则进行替换
                else if( e->wt() < edgeTo[w]->wt() ){
                    edgeTo[w] = e;
                    ipq.change(w, e->wt());
                }
            }
        }

    }
public:
    // 构造函数, 使用Prim算法求图的最小生成树
    PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<double>(graph.V())){

        assert( graph.E() >= 1 );

        // 算法初始化
        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        // Prim
        visit(0);
        while( !ipq.isEmpty() ){
            // 使用最小索引堆找出已经访问的边中权值最小的边
            // 最小索引堆中存储的是点的索引, 通过点的索引找到相对应的边
            int v = ipq.extractMinIndex();
            assert( edgeTo[v] );
            mst.push_back( *edgeTo[v] );
            visit( v );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~PrimMST(){
        delete[] marked;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    Weight result(){
        return mstWeight;
    };
};

#endif //INC_05_IMPLEMENTATION_OF_OPTIMIZED_PRIM_ALGORITHM_PRIMMST_H
