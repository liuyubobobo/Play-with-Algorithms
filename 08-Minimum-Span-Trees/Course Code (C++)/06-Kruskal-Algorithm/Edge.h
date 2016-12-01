//
// Created by Yuan Zhang on 9/26/16.
//

#ifndef INC_06_KRUSKAL_ALGORITHM_EDGE_H
#define INC_06_KRUSKAL_ALGORITHM_EDGE_H

#include <iostream>

using namespace std;


template<typename Weight>
class Edge{
private:
    int a, b;
    Weight weight;

public:
    Edge(int a, int b, Weight weight){
        this->a = a;
        this->b = b;
        this->weight = weight;
    }

    Edge(){}

    ~Edge(){}

    int v(){ return a;}

    int w(){ return b;}

    Weight wt(){ return weight;}

    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

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

    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }
};

#endif //INC_06_KRUSKAL_ALGORITHM_EDGE_H
