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

    bool operator<(const Student& otherStudent){
        return score != otherStudent.score ?
               score > otherStudent.score : name < otherStudent.name;
    }

    friend ostream& operator<<(ostream &os, const Student &student){

        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //INC_02_SELECTION_SORT_USING_TEMPLATE_STUDENT_H
