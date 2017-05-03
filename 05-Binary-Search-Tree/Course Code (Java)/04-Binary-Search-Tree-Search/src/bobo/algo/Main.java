package bobo.algo;

import java.util.Vector;

public class Main {

    // 测试二分搜索树和顺序查找表之间的性能差距
    // 二分搜索树的性能远远优于顺序查找表
    public static void main(String[] args) {

        // 使用圣经作为我们的测试用例
        String filename = "bible.txt";
        Vector<String> words = new Vector<String>();
        if(FileOperations.readFile(filename, words)){
            System.out.println( "There are totally " + words.size() + " words in " + filename );
            System.out.println();

            // 测试 BST
            long startTime = System.currentTimeMillis();

            // 统计圣经中所有词的词频
            // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
            // 在这里只做性能测试用
            BST<String, Integer> bst = new BST<String, Integer>();
            for (String word: words) {
                Integer res = bst.search(word);
                if (res == null)
                    bst.insert(word, new Integer(1));
                else
                    bst.insert(word, res + 1);
            }

            // 输出圣经中god一词出现的频率
            if( bst.contain("god") )
                System.out.println("'god' : " + bst.search("god") );
            else
                System.out.println("No word 'god' in " + filename);

            long endTime = System.currentTimeMillis();
            System.out.println("BST , time: " + (endTime - startTime) + "ms.");

            System.out.println();


            // 测试顺序查找表 SST
            startTime = System.currentTimeMillis();

            // 统计圣经中所有词的词频
            // 注: 这个词频统计法相对简陋, 没有考虑很多文本处理中的特殊问题
            // 在这里只做性能测试用
            SST<String, Integer> sst = new SST<String, Integer>();
            for (String word: words) {
                Integer res = sst.search(word);
                if (res == null)
                    sst.insert(word, new Integer(1));
                else
                    sst.insert(word, res + 1);
            }

            // 输出圣经中god一词出现的频率
            if( sst.contain("god") )
                System.out.println("'god' : " + sst.search("god") );
            else
                System.out.println("No word 'god' in " + filename);

            endTime = System.currentTimeMillis();
            System.out.println("SST , time: " + (endTime - startTime) + "ms.");

        }
    }
}
