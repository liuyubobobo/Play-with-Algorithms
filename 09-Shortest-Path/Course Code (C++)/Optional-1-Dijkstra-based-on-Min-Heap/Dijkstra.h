//
// Created by liuyubobobo on 8/08/19.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Edge.h"

using namespace std;

// Dijkstra算法求最短路径
template<typename Graph>
class Dijkstra{

private:
    Graph &G;                   // 图的引用
    int s;                      // 起始点
    int *distTo;                // distTo[i]存储从起始点s到i的最短路径长度
    bool *marked;               // 标记数组, 在算法运行过程中标记节点i是否被访问
    vector<Edge<int>*> from;    // from[i]记录最短路径中, 到达i点的边是哪一条
                                // 可以用来恢复整个最短路径

public:
    // 构造函数, 使用Dijkstra算法求最短路径
    Dijkstra(Graph &graph, int s):G(graph){

        // 算法初始化
        assert( s >= 0 && s < G.V() );
        this->s = s;
        distTo = new int[G.V()];
        marked = new bool[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            distTo[i] = INT_MAX; // 注意：初始化，所有的距离为无穷
            marked[i] = false;
            from.push_back(NULL);
        }

        // 使用优先队列，堆顶元素保持当前找到的，距离源点最近的顶点
        auto comp = [this](int a, int b) { return this->distTo[a] > this->distTo[b]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        // 对于起始点s进行初始化
        distTo[s] = 0;
        from[s] = new Edge<int>(s, s, 0);
        pq.push(0);
        while(!pq.empty()){
            int v = pq.top();
            pq.pop();

            // 使用最小堆实现，这个判断很重要。如果 v 已经被处理了，则直接 continue
            if(marked[v]) continue;

            // distTo[v]就是s到v的最短距离
            marked[v] = true;

            // 对v的所有相邻节点进行更新
            typename Graph::adjIterator adj(G, v);
            for(Edge<int>* e = adj.begin() ; !adj.end() ; e = adj.next() ){
                int w = e->other(v);
                // 如果从s点到w点的最短路径还没有找到
                if( !marked[w] ){
                    // 如果w点以前没有访问过,
                    // 或者访问过, 但是通过当前的v点到w点距离更短, 则进行更新
                    if( from[w] == NULL || distTo[v] + e->wt() < distTo[w] ){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;

                        // 注意，我们使用最小堆，改变distTo以后，并不能改变优先队列中的元素排列
                        // 解决方案是，将w重复压进优先队列。此时，w在优先队列中的位置，会按照新更新的 distTo 计算
                        // 配合 56 行的判断，保证优先队列中虽然有重复元素，但是不会被重复处理
                        pq.push(w);
                    }
                }
            }
        }
    }

    // 析构函数
    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
        delete from[0];
    }

    // 返回从s点到w点的最短路径长度
    int shortestPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );
        return distTo[w];
    }

    // 判断从s点到w点是否联通
    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return marked[w];
    }

    // 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
    void shortestPath( int w, vector<Edge<int>> &vec ){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        stack<Edge<int>*> s;
        Edge<int> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( hasPathTo(w) );

        vector<Edge<int>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_DIJKSTRA_H
