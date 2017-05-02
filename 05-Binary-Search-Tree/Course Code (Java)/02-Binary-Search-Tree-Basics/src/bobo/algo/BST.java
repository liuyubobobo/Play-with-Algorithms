package bobo.algo;

// 二叉树
// 由于Key需要能够进行比较，所以需要extends Comparable<Key>
public class BST<Key extends Comparable<Key>, Value> {

    // 树中的节点为私有的类, 外界不需要了解二叉树节点的具体实现
    private class Node {
        private Key key;
        private Value val;
        private Node left, right;

        public Node(Key key, Value val, int size) {
            this.key = key;
            this.val = val;
            left = right = null;
        }
    }

    private Node root;  // 根节点
    private int count;  // 树种的节点个数

    // 构造函数, 默认构造一棵空二叉树
    public BST() {
        root = null;
        count = 0;
    }

    // 返回二叉树的节点个数
    int size() {
        return count;
    }

    // 返回二叉树是否为空
    boolean isEmpty() {
        return count == 0;
    }


    public static void main(String[] args) {
    }
}