package bobo.algo;

// 顺序查找表
public class SST<Key extends Comparable<Key>, Value> {

    // 顺序查找表中的节点为私有的类, 外界不需要了解顺序查找法节点的具体实现
    // 我们的顺序查找表, 内部本质是一个链表
    private class Node {
        private Key key;
        private Value value;
        private Node next;

        public Node(Key key, Value value) {
            this.key = key;
            this.value = value;
            next = null;
        }
    }

    private Node head;  // 表头
    private int count;  // 顺序查找表中的节点个数

    // 构造函数
    public SST(){
        head = null;
        count = 0;
    }

    // 返回顺序查找表中的节点个数
    public int size(){
        return count;
    }

    // 返回顺序查找表是否为空
    public boolean isEmpty(){
        return count == 0;
    };

    // 向顺序查找表中插入一个新的(key, value)数据对
    public void insert(Key key, Value value){

        // 查找一下整个顺序表，肯是否存在同样大小的key
        Node node = head;
        while( node != null ){
            // 若在顺序表中找到了同样大小key的节点
            // 则当前节点不需要插入，将该key所对应的值更新为value后返回
            if( key.compareTo(node.key) == 0 ){
                node.value = value;
                return;
            }
            node = node.next;
        }

        // 若顺序表中没有同样大小的key，则创建新节点，将新节点直接插在表头
        Node newNode = new Node(key, value);
        newNode.next = head;
        head = newNode;
        count ++;
    }

    // 查看顺序查找表中是否包含键值为key的节点
    public boolean contain(Key key){

        Node node = head;
        while( node != null ){
            if( key.compareTo(node.key) == 0 )
                return true;
            node = node.next;
        }
        return false;
    }

    // 在顺序查找表中查找key所对应的value, 若value不存在, 则返回NULL
    public Value search(Key key){

        Node node = head;
        while( node != null ){
            if( key.compareTo(node.key) == 0 )
                return node.value;
            node = node.next;
        }
        return null;
    }

    // 在顺序查找表中删除(key,value)所对应的节点
    public void remove(Key key){

        if(head == null)
            return;

        // 如果待删除的节点就是头结点, 则需要特殊处理
        // 思考: 对于链表, 可以使用什么技术不去特殊处理头结点的特殊情况?
        // 更多和链表相关的算法问题, 欢迎大家看我的《玩儿转算法面试》课程 :)
        if( key.compareTo(head.key) == 0 ){
            Node delNode = head;
            head = head.next;
            delNode.next = null;
            count--;
            return;
        }

        Node node = head;
        while( node.next != null && node.next.key.compareTo(key) != 0 )
            node = node.next;

        if( node.next != null ){
            Node delNode = node.next;
            node.next = delNode.next;
            delNode.next = null;
            count --;
            return;
        }
    }
}