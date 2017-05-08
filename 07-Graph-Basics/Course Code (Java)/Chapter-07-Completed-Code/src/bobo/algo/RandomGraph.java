package bobo.algo;

// 对图G随机生成边,边的个数的期望值为E
public class RandomGraph {

    public RandomGraph( Graph graph, int V, int E){

        double p = (double)2*E / (V*(V-1));

        for( int i = 0 ; i < V ; i ++ )
            for( int j = i+1 ; j < V ; j ++ ){

                double randomValue = Math.random();
                if( randomValue < p ){
                    graph.addEdge(i,j);
                }
            }
    }
}
