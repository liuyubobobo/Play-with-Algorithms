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

    // 测试二分搜索树中的predecessor和successor两个函数
    public static void main(String[] args) {

        // 生成 0 到 N-1 一共 N 个数字的数组
        int N = 1000;
        ArrayList<Integer> nums = new ArrayList<Integer>();
        for( int i = 0 ; i < N ; i ++)
            nums.add(i);

        // 将数组中的数组乱序
        shuffle(nums);

        // 将这个N个数插入到二叉树中
        BST<Integer, Integer> bst = new BST<Integer, Integer>();
        for(Integer num: nums)
            bst.insert(num, num);

        // 测试前驱算法, 除了数字0没有前驱, 每个数字x的前驱应该为x-1
        for(int i = 0 ; i < N ; i ++) {
            if (i == 0) {
                assert bst.predecessor(i) == null;
                System.out.println("The predesessor of 0 is NULL");
            } else {
                assert bst.predecessor(i) == i - 1;
                System.out.println("The predesessor of " + i + " is " + (i - 1));
            }
        }

        System.out.println();

        // 测试后继算法, 除了数字没有N-1后继, 每个数字x的后继应该为x+1
        for(int i = 0 ; i < N ; i ++){
            if( i == N-1 ){
                assert bst.successor(i) == null;
                System.out.println("The successor of " + i + " is NULL");
            }
            else{
                assert bst.successor(i) == i+1;
                System.out.println("The successor of " + i + " is " + (i+1));
            }
        }
    }
}
