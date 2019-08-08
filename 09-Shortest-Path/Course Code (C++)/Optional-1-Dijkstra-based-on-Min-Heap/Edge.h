//
// Created by liuyubobobo on 9/28/16.
//

#ifndef INC_03_IMPLEMENTATION_OF_DIJKSTRA_EDGE_H
#define INC_03_IMPLEMENTATION_OF_DIJKSTRA_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

// 边
template<typename Weight>
class Edge{
private:
    int a,b;    // 边的两个端点
    Weight weight;  // 边的权值

public:
    // 构造函数
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    // 空的构造函数, 所有的成员变量都取默认值
    Edge(){}

    ~Edge(){}

    int v(){ return a;} // 返回第一个顶点
    int w(){ return b;} // 返回第二个顶点
    Weight wt(){ return weight;}    // 返回权值

    // 给定一个顶点, 返回另一个顶点
    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    // 输出边的信息
    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    // 边的大小比较, 是对边的权值的大小比较
    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }
    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }
    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }
    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }
    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
};

#endif //INC_03_IMPLEMENTATION_OF_DIJKSTRA_EDGE_H
