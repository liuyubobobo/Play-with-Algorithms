package bobo.algo;

public class Main {

    // 测试二分搜索树中的removeMin和removeMax
    public static void main(String[] args) {

        BST<Integer, Integer> bst = new BST<Integer, Integer>();

        // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
        int N = 100;
        int M = 100;
        for(int i = 0 ; i < N ; i ++){
            Integer key = new Integer((int)(Math.random()*M));
            // 为了后续测试方便,这里value值取和key值一样
            bst.insert(key, key);
        }
        // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

        // 测试 removeMin
        // 输出的元素应该是从小到大排列的
        System.out.println("Test removeMin: ");
        while( !bst.isEmpty() ){
            System.out.print("min: " + bst.minimum() + " , ");
            bst.removeMin();
            System.out.println("After removeMin, size = " + bst.size() );
        }
        System.out.println();


        for(int i = 0 ; i < N ; i ++){
            Integer key = new Integer((int)(Math.random()*M));
            // 为了后续测试方便,这里value值取和key值一样
            bst.insert(key, key);
        }
        // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

        // 测试 removeMax
        // 输出的元素应该是从大到小排列的
        System.out.println("Test removeMax: ");
        while( !bst.isEmpty() ){
            System.out.print("max: " + bst.maximum() + " , ");
            bst.removeMax();
            System.out.println("After removeMax, size = " + bst.size() );
        }
    }
}
