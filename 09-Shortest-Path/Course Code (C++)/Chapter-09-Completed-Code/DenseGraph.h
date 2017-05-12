//
// Created by liuyubobobo on 9/28/16.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;

// 稠密图 - 邻接矩阵
template <typename Weight>
class DenseGraph{

private:
    int n, m;       // 节点数和边数
    bool directed;  // 是否为有向图
    vector<vector<Edge<Weight> *>> g;   // 图的具体数据

public:
    // 构造函数
    DenseGraph( int n , bool directed){
        assert( n >= 0 );
        this->n = n;
        this->m = 0;
        this->directed = directed;
        // g初始化为n*n的矩阵, 每一个g[i][j]指向一个边的信息, 初始化为NULL
        g = vector<vector<Edge<Weight> *>>(n, vector<Edge<Weight> *>(n, NULL));
    }

    // 析构函数
    ~DenseGraph(){

        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                if( g[i][j] != NULL )
                    delete g[i][j];
    }

    int V(){ return n;} // 返回节点个数
    int E(){ return m;} // 返回边的个数

    // 向图中添加一个边, 权值为weight
    void addEdge( int v, int w , Weight weight ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );

        // 如果从v到w已经有边, 删除这条边
        if( hasEdge( v , w  ) ){
            delete  g[v][w];
            if( v != w && !directed )
                delete g[w][v];
            m --;
        }

        g[v][w] = new Edge<Weight>(v, w, weight);
        if( v != w && !directed )
            g[w][v] = new Edge<Weight>(w, v, weight);
        m ++;
    }

    // 验证图中是否有从v到w的边
    bool hasEdge( int v , int w ){
        assert( v >= 0 && v < n );
        assert( w >= 0 && w < n );
        return g[v][w] != NULL;
    }

    // 显示图的信息
    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                if( g[i][j] )
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL\t";
            cout<<endl;
        }
    }

    // 邻边迭代器, 传入一个图和一个顶点,
    // 迭代在这个图中和这个顶点向连的所有边
    class adjIterator{
    private:
        DenseGraph &G;  // 图G的引用
        int v;
        int index;

    public:
        // 构造函数
        adjIterator(DenseGraph &graph, int v): G(graph){
            this->v = v;
            this->index = -1;   // 索引从-1开始, 因为每次遍历都需要调用一次next()
        }

        ~adjIterator(){}

        // 返回图G中与顶点v相连接的第一个边
        Edge<Weight>* begin(){
            // 索引从-1开始, 因为每次遍历都需要调用一次next()
            index = -1;
            return next();
        }

        // 返回图G中与顶点v相连接的下一个边
        Edge<Weight>* next(){
            // 从当前index开始向后搜索, 直到找到一个g[v][index]为true
            for( index += 1 ; index < G.V() ; index ++ )
                if( G.g[v][index] )
                    return G.g[v][index];
            // 若没有顶点和v相连接, 则返回NULL
            return NULL;
        }

        // 查看是否已经迭代完了图G中与顶点v相连接的所有边
        bool end(){
            return index >= G.V();
        }
    };
};

#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_DENSEGRAPH_H
