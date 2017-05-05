package bobo.algo;

// 测试二分搜索树中的floor和ceil两个函数
public class Main {

    public static void main(String[] args) {

        BST<Integer, Integer> bst = new BST<Integer, Integer>();

        // 向二分搜索树中插入从2到20(不包括20)d的所有偶数
        for(int i = 2 ; i < 20 ; i += 2 )
            bst.insert(new Integer(i), new Integer(i));

        // 对[0...20]区间里的21个数, 调用二分搜索树的floor和ceil, 查看其结果
        for( int i = 0 ; i <= 20 ; i ++ ){

            Integer floorKey = bst.floor(new Integer(i));
            System.out.print( "The floor of " + i + " is ");
            if( floorKey == null )
                System.out.println("NULL");
            else
                System.out.println(floorKey);

            Integer ceilKey = bst.ceil(new Integer(i));
            System.out.print( "the ceil of " + i + " is ");
            if( ceilKey == null )
                System.out.println("NULL");
            else
                System.out.println(ceilKey);

            System.out.println();
        }
    }
}
