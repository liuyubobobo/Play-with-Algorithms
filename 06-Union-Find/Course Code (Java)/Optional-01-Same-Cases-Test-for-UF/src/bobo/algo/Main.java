package bobo.algo;

public class Main {

    // 对比UF1, UF2, UF3, UF4, UF5和UF6的时间性能
    // 在这里, 我们对于不同的UnionFind的实现, 使用相同的测试用例, 让测试结果更加准确
    public static void main(String[] args) {

        // 使用5000000的数据规模
        int n = 5000000;

        // 生成unionElements的测试用例
        Pair<Integer, Integer>[] unionTest = new Pair[n];
        for(int i = 0 ; i < n ; i ++){
            int a = (int)(Math.random()*n);
            int b = (int)(Math.random()*n);
            unionTest[i] = new Pair<Integer, Integer>(a, b);
        }

        // 生成isConnected的测试用例
        Pair<Integer, Integer>[] connectTest = new Pair[n];
        for(int i = 0 ; i < n ; i ++){
            int a = (int)(Math.random()*n);
            int b = (int)(Math.random()*n);
            connectTest[i] = new Pair<Integer, Integer>(a, b);
        }

        // 测试我们的UF1 ~ UF6

        // 100万数据对于UF1和UF2来说太慢了, 不再测试
//        UnionFind1 uf1 = new UnionFind1(n);
//        UnionFindTestHelper.testUF("UF1", uf1, unionTest, connectTest);
//
//        UnionFind2 uf2 = new UnionFind2(n);
//        UnionFindTestHelper.testUF("UF2", uf2, unionTest, connectTest);

        UnionFind3 uf3 = new UnionFind3(n);
        UnionFindTestHelper.testUF("UF3", uf3, unionTest, connectTest);

        UnionFind4 uf4 = new UnionFind4(n);
        UnionFindTestHelper.testUF("UF4", uf4, unionTest, connectTest);

        UnionFind5 uf5 = new UnionFind5(n);
        UnionFindTestHelper.testUF("UF5", uf5, unionTest, connectTest);

        UnionFind6 uf6 = new UnionFind6(n);
        UnionFindTestHelper.testUF("UF6", uf6, unionTest, connectTest);
    }
}
