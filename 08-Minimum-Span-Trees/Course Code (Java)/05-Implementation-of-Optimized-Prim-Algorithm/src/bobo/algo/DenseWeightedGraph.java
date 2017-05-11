package bobo.algo;

import java.util.Vector;

// 稠密图 - 邻接矩阵
public class DenseWeightedGraph<Weight extends Number & Comparable>
        implements WeightedGraph{

    private int n;  // 节点数
    private int m;  // 边数
    private boolean directed;   // 是否为有向图
    private Edge<Weight>[][] g;         // 图的具体数据

    // 构造函数
    public DenseWeightedGraph( int n , boolean directed ){
        assert n >= 0;
        this.n = n;
        this.m = 0;    // 初始化没有任何边
        this.directed = directed;
        // g初始化为n*n的布尔矩阵, 每一个g[i][j]均为null, 表示没有任和边
        // false为boolean型变量的默认值
        g = new Edge[n][n];
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                g[i][j] = null;
    }

    public int V(){ return n;} // 返回节点个数
    public int E(){ return m;} // 返回边的个数

    // 向图中添加一个边
    public void addEdge(Edge e){

        assert e.v() >= 0 && e.v() < n ;
        assert e.w() >= 0 && e.w() < n ;

        if( hasEdge( e.v() , e.w() ) )
            return;

        g[e.v()][e.w()] = new Edge(e);
        if( e.v() != e.w() && !directed )
            g[e.w()][e.v()] = new Edge(e.w(), e.v(), e.wt());

        m ++;
    }

    // 验证图中是否有从v到w的边
    public boolean hasEdge( int v , int w ){
        assert v >= 0 && v < n ;
        assert w >= 0 && w < n ;
        return g[v][w] != null;
    }

    // 显示图的信息
    public void show(){

        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                if( g[i][j] != null )
                    System.out.print(g[i][j].wt()+"\t");
                else
                    System.out.print("NULL\t");
            System.out.println();
        }
    }

    // 返回图中一个顶点的所有邻边
    // 由于java使用引用机制，返回一个Vector不会带来额外开销,
    public Iterable<Edge<Weight>> adj(int v) {
        assert v >= 0 && v < n;
        Vector<Edge<Weight>> adjV = new Vector<Edge<Weight>>();
        for(int i = 0 ; i < n ; i ++ )
            if( g[v][i] != null )
                adjV.add( g[v][i] );
        return adjV;
    }
}