package bobo.algo;

import java.util.Vector;
import java.util.Stack;
import java.util.LinkedList;

public class ShortestPath {

    private Graph G;   // 图的引用
    private int s;     // 起始点
    private boolean[] visited;  // 记录dfs的过程中节点是否被访问
    private int[] from;         // 记录路径, from[i]表示查找的路径上i的上一个节点
    private int[] ord;          // 记录路径中节点的次序。ord[i]表示i节点在路径中的次序。


    // 构造函数, 寻路算法, 寻找图graph从s点到其他点的路径
    public ShortestPath(Graph graph, int s){

        // 算法初始化
        G = graph;
        assert s >= 0 && s < G.V();

        visited = new boolean[G.V()];
        from = new int[G.V()];
        ord = new int[G.V()];
        for( int i = 0 ; i < G.V() ; i ++ ){
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }
        this.s = s;

        // 无向图最短路径算法, 从s开始广度优先遍历整张图
        LinkedList<Integer> q = new LinkedList<Integer>();

        q.push( s );
        visited[s] = true;
        ord[s] = 0;
        while( !q.isEmpty() ){
            int v = q.pop();
            for( int i : G.adj(v) )
                if( !visited[i] ){
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
        }
    }

    // 查询从s点到w点是否有路径
    public boolean hasPath(int w){
        assert w >= 0 && w < G.V();
        return visited[w];
    }

    // 查询从s点到w点的路径, 存放在vec中
    public Vector<Integer> path(int w){

        assert hasPath(w) ;

        Stack<Integer> s = new Stack<Integer>();
        // 通过from数组逆向查找到从s到w的路径, 存放到栈中
        int p = w;
        while( p != -1 ){
            s.push(p);
            p = from[p];
        }

        // 从栈中依次取出元素, 获得顺序的从s到w的路径
        Vector<Integer> res = new Vector<Integer>();
        while( !s.empty() )
            res.add( s.pop() );

        return res;
    }

    // 打印出从s点到w点的路径
    public void showPath(int w){

        assert hasPath(w) ;

        Vector<Integer> vec = path(w);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            System.out.print(vec.elementAt(i));
            if( i == vec.size() - 1 )
                System.out.println();
            else
                System.out.print(" -> ");
        }
    }

    // 查看从s点到w点的最短路径长度
    // 若从s到w不可达，返回-1
    public int length(int w){
        assert w >= 0 && w < G.V();
        return ord[w];
    }

    // 测试无权图最短路径算法
    public static void main(String[] args) {

        String filename = "testG.txt";
        SparseGraph g = new SparseGraph(7, false);
        ReadGraph readGraph = new ReadGraph(g, filename);
        g.show();
        System.out.println();

        // 比较使用深度优先遍历和广度优先遍历获得路径的不同
        // 广度优先遍历获得的是无权图的最短路径
        Path dfs = new Path(g,0);
        System.out.print("DFS : ");
        dfs.showPath(6);

        ShortestPath bfs = new ShortestPath(g,0);
        System.out.print("BFS : ");
        bfs.showPath(6);
    }
}