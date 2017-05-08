package bobo.algo;

// 求无权图的联通分量
public class Component {

    Graph G;                    // 图的引用
    private boolean[] visited;  // 记录dfs的过程中节点是否被访问
    private int ccount;         // 记录联通分量个数
    private int[] id;           // 每个节点所对应的联通分量标记

    // 图的深度优先遍历
    void dfs( int v ){

        visited[v] = true;
        id[v] = ccount;

        for( int i: G.adj(v) ){
            if( !visited[i] )
                dfs(i);
        }
    }

    // 构造函数, 求出无权图的联通分量
    public Component(Graph graph){

        // 算法初始化
        G = graph;
        visited = new boolean[G.V()];
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

    // 返回图的联通分量个数
    int count(){
        return ccount;
    }

    // 查询点v和点w是否联通
    boolean isConnected( int v , int w ){
        assert v >= 0 && v < G.V();
        assert w >= 0 && w < G.V();
        return id[v] == id[w];
    }

    // 测试图的联通分量算法
    public static void main(String[] args) {

        // TestG1.txt
        String filename1 = "testG1.txt";
        SparseGraph g1 = new SparseGraph(13, false);
        ReadGraph readGraph1 = new ReadGraph(g1, filename1);
        Component component1 = new Component(g1);
        System.out.println("TestG1.txt, Component Count: " + component1.count());
        System.out.println();

        // TestG2.txt
        String filename2 = "testG2.txt";
        SparseGraph g2 = new SparseGraph(6, false);
        ReadGraph readGraph2 = new ReadGraph(g2, filename2);
        Component component2 = new Component(g2);
        System.out.println("TestG2.txt, Component Count: " + component2.count());
    }
}