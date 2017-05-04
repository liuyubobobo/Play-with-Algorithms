package bobo.algo;

import java.util.Arrays;
import java.util.Collections;
import java.util.Vector;

public class Main {

    // 实验二分搜索树的局限性
    public static void main(String[] args) {

        // 我们使用文本量更小的共产主义宣言进行试验:)
        String filename = "communist.txt";
        Vector<String> words = new Vector<String>();

        if(FileOperations.readFile(filename, words)){

            System.out.println( "There are totally " + words.size() + " words in " + filename );
            System.out.println();


            // 测试1: 我们按照文本原有顺序插入进二分搜索树
            long startTime = System.currentTimeMillis();
            BST<String, Integer> bst = new BST<String, Integer>();
            for (String word: words) {
                Integer res = bst.search(word);
                if (res == null)
                    bst.insert(word, new Integer(1));
                else
                    bst.insert(word, res + 1);
            }

            // 我们查看unite一词的词频
            if( bst.contain("unite") )
                System.out.println("'unite' : " + bst.search("unite") );
            else
                System.out.println("No word 'unite' in " + filename);

            long endTime = System.currentTimeMillis();

            System.out.println("BST , time: " + (endTime - startTime) + "ms.");
            System.out.println();


            // 测试2: 我们按照文本原有顺序插入顺序查找表
            startTime = System.currentTimeMillis();
            SST<String, Integer> sst = new SST<String, Integer>();
            for (String word: words) {
                Integer res = sst.search(word);
                if (res == null)
                    sst.insert(word, new Integer(1));
                else
                    sst.insert(word, res + 1);
            }

            // 我们查看unite一词的词频
            if( sst.contain("unite") )
                System.out.println("'unite' : " + sst.search("unite") );
            else
                System.out.println("No word 'unite' in " + filename);

            endTime = System.currentTimeMillis();
            System.out.println("SST , time: " + (endTime - startTime) + "ms.");
            System.out.println();


            // 测试3: 我们将原文本排序后插入二分搜索树, 查看其效率
            startTime = System.currentTimeMillis();
            BST<String, Integer> bst2 = new BST<String, Integer>();
            Collections.sort(words);
            for (String word: words) {
                Integer res = bst2.search(word);
                if (res == null)
                    bst2.insert(word, new Integer(1));
                else
                    bst2.insert(word, res + 1);
            }

            // 我们查看unite一词的词频
            if( bst.contain("unite") )
                System.out.println("'unite' : " + bst2.search("unite") );
            else
                System.out.println("No word 'unite' in " + filename);

            endTime = System.currentTimeMillis();
            System.out.println("BST2 , time: " + (endTime - startTime) + "ms.");
        }
    }
}