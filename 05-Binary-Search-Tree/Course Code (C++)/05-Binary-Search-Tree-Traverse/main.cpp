#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

// 二分搜索树
template <typename Key, typename Value>
class BST{

private:
    // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
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
    // 构造函数, 默认构造一棵空二分搜索树
    BST(){
        root = NULL;
        count = 0;
    }

    // 析构函数, 释放二分搜索树的所有空间
    ~BST(){
        destroy( root );
    }

    // 返回二分搜索树的节点个数
    int size(){
        return count;
    }

    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root, key);
    }

    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value* search(Key key){
        return search( root , key );
    }

    // 二分搜索树的前序遍历
    void preOrder(){
        preOrder(root);
    }

    // 二分搜索树的中序遍历
    void inOrder(){
        inOrder(root);
    }

    // 二分搜索树的后序遍历
    void postOrder(){
        postOrder(root);
    }

private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
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

    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node, Key key){

        if( node == NULL )
            return false;

        if( key == node->key )
            return true;
        else if( key < node->key )
            return contain( node->left , key );
        else // key > node->key
            return contain( node->right , key );
    }

    // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
    Value* search(Node* node, Key key){

        if( node == NULL )
            return NULL;

        if( key == node->key )
            return &(node->value);
        else if( key < node->key )
            return search( node->left , key );
        else // key > node->key
            return search( node->right, key );
    }

    // 对以node为根的二叉搜索树进行前序遍历, 递归算法
    void preOrder(Node* node){

        if( node != NULL ){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 对以node为根的二叉搜索树进行中序遍历, 递归算法
    void inOrder(Node* node){

        if( node != NULL ){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }

    // 对以node为根的二叉搜索树进行后序遍历, 递归算法
    void postOrder(Node* node){

        if( node != NULL ){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }

    // 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
    void destroy(Node* node){

        if( node != NULL ){
            destroy( node->left );
            destroy( node->right );

            delete node;
            count --;
        }
    }
};


// 测试二分搜索树的前中后序遍历
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...m)的随机整数放进二分搜索树中
    int N = 10;
    int M = 100;
    for( int i = 0 ; i < N ; i ++ ){
        int key = rand()%M;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout<<key<<" ";
        bst.insert(key,value);
    }
    cout<<endl;

    // 测试二分搜索树的size()
    cout<<"size: "<<bst.size()<<endl<<endl;

    // 测试二分搜索树的前序遍历 preOrder
    cout<<"preOrder: "<<endl;
    bst.preOrder();
    cout<<endl;

    // 测试二分搜索树的中序遍历 inOrder
    cout<<"inOrder: "<<endl;
    bst.inOrder();
    cout<<endl;

    // 测试二分搜索树的后序遍历 postOrder
    cout<<"postOrder: "<<endl;
    bst.postOrder();
    cout<<endl;

    return 0;
}