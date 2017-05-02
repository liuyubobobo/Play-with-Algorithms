#include <iostream>

using namespace std;

template <typename Key, typename Value>
class BST{

private:
    // 树中的节点为私有的结构体, 外界不需要了解二叉树节点的具体实现
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root; // 根节点
    int count;  // 树中的节点个数

public:
    // 构造函数, 默认构造一棵空二叉树
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        // TODO: ~BST()
    }

    // 返回二叉树的节点个数
    int size(){
        return count;
    }

    // 返回二叉树是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向二叉树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

private:
    // 向以node为根的二叉搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二叉搜索树的根
    Node* insert(Node *node, Key key, Value value){

        if( node == NULL ){
            count ++;
            return new Node(key, value);
        }

        if( key == node->key )
            node->value = value;
        else if( key < node->key )
            node->left = insert( node->left , key, value);
        else    // key > node->key
            node->right = insert( node->right, key, value);

        return node;
    }
};


int main() {

    return 0;
}