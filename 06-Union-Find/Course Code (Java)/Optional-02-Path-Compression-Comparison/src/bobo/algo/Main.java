package bobo.algo;

public class Main {

    public static void main(String[] args) {

        // 为了能够方便地看出两种路径压缩算法的不同,我们只使用有5个元素的并查集进行试验
        int n = 5;

        UnionFind5 uf5 = new UnionFind5(n);
        UnionFind6 uf6 = new UnionFind6(n);

        // 我们将我们的并查集初始设置成如下的样子
        //            0
        //           /
        //          1
        //         /
        //        2
        //       /
        //      3
        //     /
        //    4
        for(int i = 1 ; i < n ; i ++){
            uf5.parent[i] = i-1;
            uf6.parent[i] = i-1;
        }

        // 现在, 我们对两个并查集调用find(4)操作
        uf5.find(n-1);
        uf6.find(n-1);

        // 通过show, 我们可以看出, 使用迭代的路径压缩, 我们的并查集变成这个样子:
        //     0
        //    / \
        //   1   2
        //  / \
        // 3  4
        System.out.println("UF implements Path Compression by recursion:");
        uf5.show();

        System.out.println();

        // 使用递归的路径压缩, 我们的并查集变成这个样子:
        //     0
        //  / / \ \
        // 1 2   3 4
        System.out.println("UF implements Path Compression without recursion:");
        uf6.show();

        // 大家也可以调大n的值, 看看结果的不同:)
    }
}
