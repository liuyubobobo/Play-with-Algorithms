//
// Created by liuyubobobo on 9/22/16.
//

#ifndef INC_05_DFS_AND_COMPONENTS_COMPONENTS_H
#define INC_05_DFS_AND_COMPONENTS_COMPONENTS_H

#include <iostream>
#include <cassert>
using namespace std;


// 求无权图的联通分量
template <typename Graph>
class Component{

private:
    Graph &G;       // 图的引用
    bool *visited;  // 记录dfs的过程中节点是否被访问
    int ccount;     // 记录联通分量个数
    int *id;        // 每个节点所对应的联通分量标记

    // 图的深度优先遍历
    void dfs( int v ){

        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G, v);
        for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
            if( !visited[i] )
                dfs(i);
        }
    }

public:
    // 构造函数, 求出无权图的联通分量
    Component(Graph &graph): G(graph){

        // 算法初始化
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            id[i] = -1;
        }

        // 求图的联通分量
        for( int i = 0 ; i < G.V() ; i ++ )
            if( !visited[i] ){
                dfs(i);
                ccount ++;
            }
    }

    // 析构函数
    ~Component(){
        delete[] visited;
        delete[] id;
    }

    // 返回图的联通分量个数
    int count(){
        return ccount;
    }

    // 查询点v和点w是否联通
    bool isConnected( int v , int w ){
        assert( v >= 0 && v < G.V() );
        assert( w >= 0 && w < G.V() );
        return id[v] == id[w];
    }
};

#endif //INC_05_DFS_AND_COMPONENTS_COMPONENTS_H
