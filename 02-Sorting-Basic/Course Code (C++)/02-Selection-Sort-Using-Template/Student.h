//
// Created by liuyubobobo on 7/12/16.
//

#ifndef INC_02_SELECTION_SORT_USING_TEMPLATE_STUDENT_H
#define INC_02_SELECTION_SORT_USING_TEMPLATE_STUDENT_H

#include <iostream>
#include <string>

using namespace std;


struct Student{

    string name;
    int score;

    // 重载小于运算法,定义Student之间的比较方式
    // 如果分数相等，则按照名字的字母序排序
    // 如果分数不等，则分数高的靠前
    bool operator<(const Student& otherStudent){
        return score != otherStudent.score ?
               score > otherStudent.score : name < otherStudent.name;
    }

    // 重载<<符号, 定义Student实例的打印输出方式
    // * 很多同学看到这里的C++语法, 头就大了, 甚至还有同学表示要重新学习C++语言
    // * 对于这个课程, 大可不必。C++语言并不是这个课程的重点,
    // * 大家也完全可以使用自己的方式书写代码, 最终只要能够打印出结果就好了, 比如设置一个成员函数, 叫做show()...
    // * 推荐大家阅读我在问答区向大家分享的一个学习心得: 【学习心得分享】请大家抓大放小，不要纠结于C++语言的语法细节
    // * 链接: http://coding.imooc.com/learn/questiondetail/4100.html
    friend ostream& operator<<(ostream &os, const Student &student){

        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //INC_02_SELECTION_SORT_USING_TEMPLATE_STUDENT_H
