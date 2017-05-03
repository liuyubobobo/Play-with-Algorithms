//
// Created by liuyubobobo on 8/28/16.
//

#ifndef INC_04_BINARY_SEARCH_TREE_SEARCH_FILEOPS_H
#define INC_04_BINARY_SEARCH_TREE_SEARCH_FILEOPS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 文件相关操作
namespace FileOps{

    // 读取文件名称为filename中的内容，并将其中包含的所有词语放进words中
    int firstCharacterIndex(const string& s, int start){
        for( int i = start ; i < s.length() ; i ++ )
            if( isalpha(s[i]) )
                return i;
        return s.length();
    }

    // 将字符串s中的所有字母转换成小写之后返回
    string lowerS( const string& s){

        string ret = "";
        for( int i = 0 ; i < s.length() ; i ++ )
            ret += tolower(s[i]);
        return ret;
    }

    // 读取文件名称为filename中的内容，并将其中包含的所有词语放进words中
    bool readFile(const string& filename, vector<string> &words){

        // 文件读取
        string line;
        string contents = "";
        ifstream file(filename);
        if( file.is_open() ){
            while( getline(file, line))
                contents += ( line + "\n" );
            file.close();
        }
        else{
            cout<<"Can not open "<<filename<<" !!!"<<endl;
            return false;
        }

        // 简单分词
        // 这个分词方式相对简陋, 没有考虑很多文本处理中的特殊问题
        // 在这里只做demo展示用
        int start = firstCharacterIndex(contents, 0);
        for( int i = start + 1 ; i <= contents.length() ; )
            if( i == contents.length() || !isalpha(contents[i]) ){
                words.push_back( lowerS( contents.substr(start,i-start) ) );
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            }
            else
                i ++;

        return true;
    }

}

#endif //INC_04_BINARY_SEARCH_TREE_SEARCH_FILEOPS_H
