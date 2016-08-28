#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include "BST.h"
#include "SequenceST.h"

using namespace std;

int firstCharacterIndex(const string& s, int start){
    for( int i = start ; i < s.length() ; i ++ )
        if( isalpha(s[i]) )
            return i;
    return s.length();
}

string lowerS( const string& s){

    string ret = "";
    for( int i = 0 ; i < s.length() ; i ++ )
        ret += tolower(s[i]);
    return ret;
}

void readFile(const string& filename, vector<string> &words){

    string line;
    string contents = "";
    ifstream file(filename);
    if( file.is_open() ){
        while( getline(file, line))
            contents += ( line + "\n" );
        file.close();
    }

    int start = firstCharacterIndex(contents, 0);
    for( int i = start + 1 ; i <= contents.length() ; ){

        if( i == contents.length() || !isalpha(contents[i]) ){
            words.push_back( lowerS( contents.substr(start,i-start) ) );
            start = firstCharacterIndex(contents, i);
            i = start + 1;
            //cout<<start<<endl;
        }
        else{
            i ++;
        }
    }

    cout<<"There are totally "<<words.size()<<" words in "<<filename<<endl;
}

int main() {

    vector<string> words;
    readFile("bible.txt", words);

    // test BST
    time_t startTime = clock();
    BST<string, int> bst = BST<string,int>();
    for( vector<string>::iterator iter = words.begin(); iter != words.end() ; iter ++ ){
        //cout<<*iter<<endl;
        int* res = bst.search(*iter);
        if( res == NULL )
            bst.insert( *iter, 1 );
        else
            (*res) ++;
    }

    cout<<"'god' : "<<*bst.search("god")<<endl;
    time_t endTime = clock();
    cout<<"BST , time: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s."<<endl;

    cout<<endl;


    // test SST
    startTime = clock();
    SequenceST<string, int> sst = SequenceST<string,int>();
    for( vector<string>::iterator iter = words.begin(); iter != words.end() ; iter ++ ){
        //cout<<*iter<<endl;
        int* res = sst.search(*iter);
        if( res == NULL )
            sst.insert( *iter, 1 );
        else
            (*res) ++;
    }

    cout<<"'god' : "<<*sst.search("god")<<endl;

    endTime = clock();
    cout<<"SST , time: "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" s."<<endl;

    return 0;
}