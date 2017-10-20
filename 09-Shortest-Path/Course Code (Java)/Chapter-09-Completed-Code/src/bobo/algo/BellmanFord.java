package bobo.algo;

import java.util.Vector;
import java.util.Stack;

// 使用BellmanFord算法求最短路径
public class BellmanFord<Weight extends Number & Comparable> {

    private WeightedGraph G;    // 图的引用
    private int s;              // 起始点
    private Number[] distTo;    // distTo[i]存储从起始点s到i的最短路径长度
    Edge<Weight>[] from;        // from[i]记录最短路径中, 到达i点的边是哪一条
                                // 可以用来恢复整个最短路径
    boolean hasNegativeCycle;   // 标记图中是否有负权环

    // 构造函数, 使用BellmanFord算法求最短路径
    public BellmanFord(WeightedGraph graph, int s){

        G = graph;
        this.s = s;
        distTo = new Number[G.V()];
        from = new Edge[G.V()];
        // 初始化所有的节点s都不可达, 由from数组来表示
        for( int i = 0 ; i < G.V() ; i ++ )
            from[i] = null;

        // 设置distTo[s] = 0, 并且让from[s]不为NULL, 表示初始s节点可达且距离为0
        distTo[s] = 0.0;
        from[s] = new Edge<Weight>(s, s, (Weight)(Number)(0.0)); // 这里我们from[s]的内容是new出来的, 注意要在析构函数里delete掉

        // Bellman-Ford的过程
        // 进行V-1次循环, 每一次循环求出从起点到其余所有点, 最多使用pass步可到达的最短距离
        for( int pass = 1 ; pass < G.V() ; pass ++ ){

            // 每次循环中对所有的边进行一遍松弛操作
            // 遍历所有边的方式是先遍历所有的顶点, 然后遍历和所有顶点相邻的所有边
            for( int i = 0 ; i < G.V() ; i ++ ){
                // 使用我们实现的邻边迭代器遍历和所有顶点相邻的所有边
                for( Object item : G.adj(i) ){
                    Edge<Weight> e = (Edge<Weight>)item;
                    // 对于每一个边首先判断e->v()可达
                    // 之后看如果e->w()以前没有到达过， 显然我们可以更新distTo[e->w()]
                    // 或者e->w()以前虽然到达过, 但是通过这个e我们可以获得一个更短的距离, 即可以进行一次松弛操作, 我们也可以更新distTo[e->w()]
                    if( from[e.v()] != null && (from[e.w()] == null || distTo[e.v()].doubleValue() + e.wt().doubleValue() < distTo[e.w()].doubleValue()) ){
                        distTo[e.w()] = distTo[e.v()].doubleValue() + e.wt().doubleValue();
                        from[e.w()] = e;
                    }
                }
            }
        }

        hasNegativeCycle = detectNegativeCycle();
    }

    // 判断图中是否有负权环
    boolean detectNegativeCycle(){

        for( int i = 0 ; i < G.V() ; i ++ ){
            for( Object item : G.adj(i) ){
                Edge<Weight> e = (Edge<Weight>)item;
                if( from[e.v()] != null && distTo[e.v()].doubleValue() + e.wt().doubleValue() < distTo[e.w()].doubleValue() )
                    return true;
            }
        }

        return false;
    }

    // 返回图中是否有负权环
    boolean negativeCycle(){
        return hasNegativeCycle;
    }

    // 返回从s点到w点的最短路径长度
    Number shortestPathTo( int w ){
        assert w >= 0 && w < G.V();
        assert !hasNegativeCycle;
        assert hasPathTo(w);
        return distTo[w];
    }

    // 判断从s点到w点是否联通
    boolean hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return from[w] != null;
    }

    // 寻找从s到w的最短路径, 将整个路径经过的边存放在vec中
    Vector<Edge<Weight>> shortestPath(int w){

        assert w >= 0 && w < G.V() ;
        assert !hasNegativeCycle ;
        assert hasPathTo(w) ;

        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        Stack<Edge<Weight>> s = new Stack<Edge<Weight>>();
        Edge<Weight> e = from[w];
        while( e.v() != this.s ){
            s.push(e);
            e = from[e.v()];
        }
        s.push(e);

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        Vector<Edge<Weight>> res = new Vector<Edge<Weight>>();
        while( !s.empty() ){
            e = s.pop();
            res.add(e);
        }

        return res;
    }

    // 打印出从s点到w点的路径
    void showPath(int w){

        assert( w >= 0 && w < G.V() );
        assert( !hasNegativeCycle );
        assert( hasPathTo(w) );

        Vector<Edge<Weight>> res = shortestPath(w);
        for( int i = 0 ; i < res.size() ; i ++ ){
            System.out.print(res.elementAt(i).v() + " -> ");
            if( i == res.size()-1 )
                System.out.println(res.elementAt(i).w());
        }
    }

    // 测试我们的Bellman-Ford最短路径算法
    public static void main(String[] args) {

        String filename = "testG2.txt";
        //String filename = "testG_negative_circle.txt";
        int V = 5;

        SparseWeightedGraph<Integer> g = new SparseWeightedGraph<Integer>(V, true);
        ReadWeightedGraph readGraph = new ReadWeightedGraph(g, filename);

        System.out.println("Test Bellman-Ford:\n");

        int s = 0;
        BellmanFord<Integer> bellmanFord = new BellmanFord<Integer>(g, s);
        if( bellmanFord.negativeCycle() )
            System.out.println("The graph contain negative cycle!");
        else
            for( int i = 0 ; i < V ; i ++ ){
                if(i == s)
                    continue;

                if(bellmanFord.hasPathTo(i)) {
                    System.out.println("Shortest Path to " + i + " : " + bellmanFord.shortestPathTo(i));
                    bellmanFord.showPath(i);
                }
                else
                    System.out.println("No Path to " + i );

                System.out.println("----------");
            }

    }
}
