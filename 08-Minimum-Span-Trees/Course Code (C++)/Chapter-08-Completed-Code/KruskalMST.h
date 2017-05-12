//
// Created by liuyubobobo on 9/26/16.
//

#ifndef INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H
#define INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UF.h"
#include "Edge.h"

using namespace std;

// Kruskal算法
template <typename Graph, typename Weight>
class KruskalMST{

private:
    vector<Edge<Weight>> mst;   // 最小生成树所包含的所有边
    Weight mstWeight;           // 最小生成树的权值

public:
    // 构造函数, 使用Kruskal算法计算graph的最小生成树
    KruskalMST(Graph &graph){

        // 将图中的所有边存放到一个最小堆中
        MinHeap<Edge<Weight>> pq( graph.E() );
        for( int i = 0 ; i < graph.V() ; i ++ ){
            typename Graph::adjIterator adj(graph,i);
            for( Edge<Weight> *e = adj.begin() ; !adj.end() ; e = adj.next() )
                if( e->v() < e->w() )
                    pq.insert(*e);
        }

        // 创建一个并查集, 来查看已经访问的节点的联通情况
        UnionFind uf = UnionFind(graph.V());
        while( !pq.isEmpty() && mst.size() < graph.V() - 1 ){

            // 从最小堆中依次从小到大取出所有的边
            Edge<Weight> e = pq.extractMin();
            // 如果该边的两个端点是联通的, 说明加入这条边将产生环, 扔掉这条边
            if( uf.isConnected( e.v() , e.w() ) )
                continue;

            // 否则, 将这条边添加进最小生成树, 同时标记边的两个端点联通
            mst.push_back( e );
            uf.unionElements( e.v() , e.w() );
        }

        mstWeight = mst[0].wt();
        for( int i = 1 ; i < mst.size() ; i ++ )
            mstWeight += mst[i].wt();
    }

    ~KruskalMST(){ }

    // 返回最小生成树的所有边
    vector<Edge<Weight>> mstEdges(){
        return mst;
    };

    // 返回最小生成树的权值
    Weight result(){
        return mstWeight;
    };
};

#endif //INC_06_KRUSKAL_ALGORITHM_KRUSKALMST_H
