package bobo.algo;

import java.lang.reflect.Array;
import java.util.*;
import java.lang.*;

// 最大索引堆
public class IndexMaxHeap<Item extends Comparable> {

    protected Item[] data;      // 最大索引堆中的数据
    protected int[] indexes;    // 最大索引堆中的索引, indexes[x] = i 表示索引i在x的位置
    protected int[] reverse;    // 最大索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置
    protected int count;
    protected int capacity;

    // 构造函数, 构造一个空堆, 可容纳capacity个元素
    public IndexMaxHeap(int capacity){
        data = (Item[])new Comparable[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this.capacity = capacity;
    }

    // 返回索引堆中的元素个数
    public int size(){
        return count;
    }

    // 返回一个布尔值, 表示索引堆中是否为空
    public boolean isEmpty(){
        return count == 0;
    }

    // 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    public void insert(int i, Item item){

        assert count + 1 <= capacity;
        assert i + 1 >= 1 && i + 1 <= capacity;

        // 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
        assert !contain(i);

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        reverse[i] = count + 1;
        count ++;

        shiftUp(count);
    }

    // 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
    public Item extractMax(){
        assert count > 0;

        Item ret = data[indexes[1]];
        swapIndexes( 1 , count );
        reverse[indexes[count]] = 0;
        count --;
        shiftDown(1);

        return ret;
    }

    // 从最大索引堆中取出堆顶元素的索引
    public int extractMaxIndex(){
        assert count > 0;

        int ret = indexes[1] - 1;
        swapIndexes( 1 , count );
        reverse[indexes[count]] = 0;
        count --;
        shiftDown(1);

        return ret;
    }

    // 获取最大索引堆中的堆顶元素
    public Item getMax(){
        assert count > 0;
        return data[indexes[1]];
    }

    // 获取最大索引堆中的堆顶元素的索引
    public int getMaxIndex(){
        assert count > 0;
        return indexes[1]-1;
    }

    // 看索引i所在的位置是否存在元素
    boolean contain( int i ){
        assert  i + 1 >= 1 && i + 1 <= capacity;
        return reverse[i+1] != 0;
    }

    // 获取最大索引堆中索引为i的元素
    public Item getItem( int i ){
        assert contain(i);
        return data[i+1];
    }

    // 将最大索引堆中索引为i的元素修改为newItem
    public void change( int i , Item newItem ){

        assert contain(i);

        i += 1;
        data[i] = newItem;

        // 有了 reverse 之后,
        // 我们可以非常简单的通过reverse直接定位索引i在indexes中的位置
        shiftUp( reverse[i] );
        shiftDown( reverse[i] );
    }

    // 交换索引堆中的索引i和j
    // 由于有了反向索引reverse数组，
    // indexes数组发生改变以后， 相应的就需要维护reverse数组
    private void swapIndexes(int i, int j){
        int t = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = t;

        reverse[indexes[i]] = i;
        reverse[indexes[j]] = j;
    }

    //********************
    //* 最大索引堆核心辅助函数
    //********************

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    private void shiftUp(int k){

        while( k > 1 && data[indexes[k/2]].compareTo(data[indexes[k]]) < 0 ){
            swapIndexes(k, k/2);
            k /= 2;
        }
    }

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    private void shiftDown(int k){

        while( 2*k <= count ){
            int j = 2*k;
            if( j+1 <= count && data[indexes[j+1]].compareTo(data[indexes[j]]) > 0 )
                j ++;

            if( data[indexes[k]].compareTo(data[indexes[j]]) >= 0 )
                break;

            swapIndexes(k, j);
            k = j;
        }
    }

    // 测试 IndexMaxHeap
    public static void main(String[] args) {

        int N = 1000000;
        IndexMaxHeap<Integer> indexMaxHeap = new IndexMaxHeap<Integer>(N);
        for( int i = 0 ; i < N ; i ++ )
            indexMaxHeap.insert( i , (int)(Math.random()*N) );

    }
}