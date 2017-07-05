package bobo.algo;

import java.util.ArrayList;

// 测试二分搜索树中的floor和ceil两个函数
public class Main {

    // 打乱数组顺序
    private static void shuffle(ArrayList arr){

        for(int i = arr.size()-1 ; i >= 0 ; i --){
            int pos = (int) (Math.random() * (i+1));
            Object t = arr.get(pos);
            arr.set(pos, arr.get(i));
            arr.set(i, t);
        }
    }

    // 测试二分搜索树中的floor和ceil两个函数
    public static void main(String[] args) {

        BST<Integer, Integer> bst = new BST<Integer, Integer>();

        //将[0, N)之间的偶数保存在nums中
        int N = 1000;
        ArrayList<Integer> nums = new ArrayList<Integer>();
        for(int i = 0 ; i < N ; i += 2)
            nums.add(i);
        int minNum = nums.get(0);
        int maxNum = nums.get(nums.size()-1);

        // 将nums乱序处理
        shuffle(nums);

        // 向二分搜索树中插入[0, N)之间的所有偶数
        for(Integer num: nums)
            bst.insert(num, num);

        // 对[0...N]区间里的N+1个数, 调用二分搜索树的floor和ceil, 查看其结果
        for( int i = 0 ; i < N ; i ++ ){

            // 测试floor
            Integer floorKey = bst.floor(new Integer(i));
            if(i % 2 == 0){
                if(i >= 0 && i < N) assert floorKey == i;
                else if(i < 0)      assert floorKey == null;
                else                assert floorKey == maxNum;
            }
            else{
                if(i - 1 >= 0 && i - 1 < N) assert floorKey == i - 1;
                else if(i - 1 < 0)          assert floorKey == null;
                else                        assert floorKey == maxNum;
            }

            System.out.print( "The floor of " + i + " is ");
            if( floorKey == null )
                System.out.println("NULL");
            else
                System.out.println(floorKey);


            // 测试ceil
            Integer ceilKey = bst.ceil(new Integer(i));
            if(i % 2 == 0) {
                if( i >= 0 && i < N ) assert ceilKey == i;
                else if(i < 0)        assert ceilKey == minNum;
                else                  assert ceilKey == null;
            }
            else{
                if(i + 1 >= 0 && i + 1 < N) assert ceilKey == i + 1;
                else if(i + 1 < 0)          assert ceilKey == minNum;
                else                        assert ceilKey == null;
            }

            System.out.print( "the ceil of " + i + " is ");
            if( ceilKey == null )
                System.out.println("NULL");
            else
                System.out.println(ceilKey);

            System.out.println();
        }
    }
}
