#include <iostream>
#include <ctime>
#include "BST.h"

using namespace std;


int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    int n = 10;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        cout<<key<<" ";
        bst.insert(key,value);
    }
    cout<<endl;

    // test size
    cout<<"size: "<<bst.size()<<endl<<endl;

    // test preOrder
    cout<<"preOrder: ";
    bst.preOrder();
    cout<<endl<<endl;

    // test inOrder
    cout<<"inOrder: ";
    bst.inOrder();
    cout<<endl<<endl;

    // test postOrder
    cout<<"postOrder: ";
    bst.postOrder();
    cout<<endl<<endl;

    // test levelOrder
    cout<<"levelOrder: ";
    bst.levelOrder();
    cout<<endl<<endl;

    // test contain and search
    for( int i = 0 ; i < n ; i ++ ){
        //cout<<"TRY "<<i<<" -- ";
        if( bst.contain(i) ){
            int* res = bst.search(i);
            //cout<<"contain "<<i<<", value: "<<*res<<endl;
            assert( res != NULL && *res == i );
        }
        //else{
        //    cout<<"not conatin "<<i<<endl;
        //}
    }

    return 0;
}