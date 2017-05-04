//
// Created by liuyubobobo on 8/30/16.
//

#ifndef INC_10_THE_DISADVANTAGES_OF_BINARY_SEARCH_TREE_AND_MORE_TREES_SEQUENCEST_H
#define INC_10_THE_DISADVANTAGES_OF_BINARY_SEARCH_TREE_AND_MORE_TREES_SEQUENCEST_H

#include <iostream>
#include <cassert>

using namespace std;

// 顺序查找表
template<typename Key, typename Value>
class SequenceST{

private:
    // 顺序查找表中的节点为私有的结构体, 外界不需要了解顺序查找表中节点的具体实现
    // 我们的顺序查找表, 内部本质是一个链表
    struct Node{
        Key key;
        Value value;
        Node *next;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };

    Node* head; // 表头
    int count;  // 顺序查找表中的节点个数

public:
    // 构造函数
    SequenceST(){
        head = NULL;
        count = 0;
    }

    // 析构函数
    ~SequenceST(){
        while( head != NULL){
            Node *node = head;
            head = head->next;
            delete node;
            count --;
        }

        assert( head == NULL && count == 0 );
    }

    // 返回顺序查找表中的节点个数
    int size(){
        return count;
    }

    // 返回顺序查找表是否为空
    bool isEmpty(){
        return count == 0;
    };

    // 向顺序查找表中插入一个新的(key, value)数据对
    void insert(Key key, Value value){

        // 查找一下整个顺序表，肯是否存在同样大小的key
        Node *node = head;
        while( node != NULL ){
            // 若在顺序表中找到了同样大小key的节点
            // 则当前节点不需要插入，将该key所对应的值更新为value后返回
            if( key == node->key ){
                node->value = value;
                return;
            }
            node = node->next;
        }

        // 若顺序表中没有同样大小的key，则创建新节点，将新节点直接插在表头
        Node *newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        count ++;
    }

    // 查看顺序查找表中是否包含键值为key的节点
    bool contain(Key key){

        Node *node = head;
        while( node != NULL ){
            if( key == node->key )
                return true;
            node = node->next;
        }
        return false;
    }

    // 在顺序查找表中查找key所对应的value, 若value不存在, 则返回NULL
    Value* search(Key key){

        Node *node = head;
        while( node != NULL ){
            if( key == node->key )
                return &(node->value);
            node = node->next;
        }
        return NULL;
    }

    // 在顺序查找表中删除(key,value)所对应的节点
    void remove(Key key){

        if( head == NULL )
            return;

        // 如果待删除的节点就是头结点, 则需要特殊处理
        // 思考: 对于链表, 可以使用什么技术不去特殊处理头结点的特殊情况?
        // 更多和链表相关的算法问题, 欢迎大家看我的《玩儿转算法面试》课程 :)
        if( key == head->key ){
            Node* delNode = head;
            head = head->next;
            delete delNode;
            count--;
            return;
        }

        Node *node = head;
        while( node->next != NULL && node->next->key != key )
            node = node->next;

        if( node->next != NULL ){
            Node* delNode = node->next;
            node->next = delNode->next;
            delete delNode;
            count --;
            return;
        }
    }
};

#endif //INC_10_THE_DISADVANTAGES_OF_BINARY_SEARCH_TREE_AND_MORE_TREES_SEQUENCEST_H
