package bobo.algo;

// 二叉树
// 由于Key需要能够进行比较，所以需要extends Comparable<Key>
public class BST<Key extends Comparable<Key>, Value> {

    // 树中的节点为私有的类, 外界不需要了解二叉树节点的具体实现
    private class Node {
        private Key key;
        private Value value;
        private Node left, right;

        public Node(Key key, Value value) {
            this.key = key;
            this.value = value;
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

    // 向二叉树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }


    //********************
    //* 二叉树的辅助函数
    //********************

    // 向以node为根的二叉搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二叉搜索树的根
    private Node insert(Node node, Key key, Value value){

        if( node == null ){
            count ++;
            return new Node(key, value);
        }

        if( key.compareTo(node.key) == 0 )
            node.value = value;
        else if( key.compareTo(node.key) < 0 )
            node.left = insert( node.left , key, value);
        else    // key > node->key
            node.right = insert( node.right, key, value);

        return node;
    }

    public static void main(String[] args) {
    }
}