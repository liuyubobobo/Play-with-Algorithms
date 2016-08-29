//
// Created by liuyubobobo on 8/26/16.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


template<typename Key, typename Value>
class BST{

private:
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

        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }

    ~BST(){
        destroy(root);
        assert( count == 0 );
    }

    // 返回二叉树的元素个数
    int size(){
        return count;
    }

    // 返回二叉树是否为空
    int isEmpty(){
        return count == 0;
    }

    // 插入节点
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 检查二叉树是否包含键值为key的元素
    bool contain(Key key){
        return contain(root, key);
    }

    // 在二叉树中寻找键值为key的value值
    Value* search(Key key){
        return search(root, key);
    }

    // 从二叉树中删除最小值所在节点
    void removeMin(){
        root = removeMin( root );
    }

    // 从二叉树中删除最大值所在节点
    void removeMax(){
        root = removeMax( root );
    }

    // 从二叉树中删除键值为key的节点
    void remove(Key key){
        root = remove(root, key);
    }

    // 寻找最小的键值
    Key minimum(){
        Node* minNode = minimum(root);
        assert( minNode != NULL );
        return minNode->key;
    }

    // 寻找最大的键值
    Key maximum(){
        Node* maxNode = maximum(root);
        assert( maxNode != NULL );
        return maxNode->key;
    }

    // 前序遍历
    void preOrder(){
        preOrder(root);
    }

    // 中序遍历
    void inOrder(){
        inOrder(root);
    }

    // 后序遍历
    void postOrder(){
        postOrder(root);
    }

    // 层序遍历
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while( !q.empty() ){
            Node *node = q.front();
            q.pop();
            cout<<node->key<<" ";
            if( node->left )
                q.push(node->left);
            if( node->right )
                q.push(node->right);
        }
    }

private:
    // 向以node为根的二叉搜索树中,插入节点(key, value)
    // 返回插入新节点后的二叉搜索树的根
    Node* insert(Node* node, Key key, Value value){
        if( node == NULL ){
            count += 1;
            return new Node(key, value);
        }

        if( key == node->key )
            node->value = value;
        else if( key < node->key )
            node->left = insert(node->left, key, value);
        else // key > node->key
            node->right = insert(node->right, key, value);

        return node;
    }

    // 查看以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node* node, Key key){
        if( node == NULL )
            return false;

        if( key == node->key )
            return true;
        else if( key < node->key )
            return contain(node->left, key);
        else
            return contain(node->right, key);
    }

    // 在以node为根的二叉搜索树中查找key所对应的value
    Value* search(Node* node, Key key){

        if( node == NULL )
            return NULL;

        if( key == node->key )
            return &(node->value);
        else if( key < node->key )
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    Node* removeMin(Node* node){
        if( node == NULL )
            return NULL;

        if( node->left == NULL ){
            //cout<<"del node "<<node->key<<endl;
            Node* retNode = node->right;
            delete node;
            count --;
            return retNode;
        }
        else{
            node->left = removeMin( node->left );
            return node;
        }
    }

    Node* removeMax(Node* node){
        if( node == NULL )
            return NULL;

        if( node->right == NULL ){
            //cout<<"del node "<<node->key<<endl;
            Node* retNode = node->left;
            delete node;
            count --;
            return retNode;
        }
        else{
            node->right = removeMax( node->right );
            return node;
        }
    }

    Node* remove(Node* node, Key key){

        if( node == NULL )
            return NULL;

        if( key < node->key ){
            node->left = remove( node->left , key );
            return node;
        }
        else if( key > node->key ){
            node->right = remove( node->right, key );
            return node;
        }
        else{

            if( node->left == NULL){
                Node *retNode = node->right;
                delete node;
                count--;
                return retNode;
            }

            if( node->right == NULL ){
                Node *retNode = node->left;
                delete node;
                count--;
                return retNode;
            }

            assert( node->left != NULL && node->right != NULL );

            Node *delNode = node;
            Node *successor = new Node(minimum(node->right));
            count ++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete delNode;
            count --;

            return successor;
        }
    }

    Node* minimum(Node* node){
        if( node == NULL || node->left == NULL )
            return node;
        return minimum( node->left );
    }

    Node* maximum(Node* node){
        if( node == NULL || node->right == NULL )
            return node;
        return maximum( node->right );
    }

    // 对以node为根的二叉搜索树进行前序遍历
    void preOrder(Node* node){

        if( node != NULL){
            cout<<node->key<<" ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // 对以node为根的二叉搜索树进行中序遍历
    void inOrder(Node* node){

        if( node != NULL){
            inOrder(node->left);
            cout<<node->key<<" ";
            inOrder(node->right);
        }
    }

    // 对以node为根的二叉搜索树进行后序遍历
    void postOrder(Node* node){

        if( node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<" ";
        }
    }

    void destroy(Node* node){
        if( node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
            count--;
        }
    }
};

#endif //BINARY_SEARCH_TREE_BST_H