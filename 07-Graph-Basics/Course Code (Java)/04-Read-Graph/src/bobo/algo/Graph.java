package bobo.algo;

// 图的抽象类
public abstract class Graph {

    protected int n;  // 节点数
    protected int m;  // 边数
    protected boolean directed;   // 是否为有向图

    // 构造函数
    public Graph( int n , boolean directed ){
        assert n >= 0;
        this.n = n;
        this.m = 0;    // 初始化没有任何边
        this.directed = directed;
    }

    public int V(){ return n;} // 返回节点个数
    public int E(){ return m;} // 返回边的个数

    public void addEdge( int v , int w ){
        System.out.println("In concrete graph need to add an edge to the graph data.");
    }

    // 验证图中是否有从v到w的边
    boolean hasEdge( int v , int w ){
        System.out.println("Always return false in abstract graph.");
        return false;
    }

    // 显示图的信息
    void show(){
        System.out.println("In concrete graph, print the graph data.");
    }

}
