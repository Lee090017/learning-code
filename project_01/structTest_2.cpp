/*
 * @Author: your name
 * @Date: 2022-04-11 15:04:11
 * @LastEditTime: 2022-04-11 16:37:47
 * @LastEditors: Please set LastEditors
 * @Description: 结构体案例
 * @FilePath: \learningCode\project_01\structTest_2.cpp
 */

/**
 * @brief 
 * 
 * 
 */

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

struct StudentTest
{
    /* data */
    string name;
    int score;
};

struct TeacherTest{
    string name;
    StudentTest student[5];
};

void display_TeacherTest(TeacherTest * teacher,int length);
void allocateSpace(TeacherTest teacher[],int len);

int main(){

    //若需要保证每次运行时的随机数均不同，需要加随机数种子
    srand((unsigned int)time(NULL));

    TeacherTest teacher[3];
    int len = sizeof(teacher) / sizeof(teacher[0]);
    allocateSpace(teacher,len);
    display_TeacherTest(teacher,len);

    return 0;
}

/**
 * @brief 
 * 为老师结构体赋值
 * @param teacher 
 * @param len 
 */
void allocateSpace(TeacherTest teacher[],int len){
    for(int i=0; i<len; i++){
        teacher[i].name = "Teacher_";//C++里面的字符串拼接，需要加号的左操作数或右操作数至少要有一个是string类的对象
        teacher[i].name += (char)(65+i);
        // 为学生赋值
        for(int j=0; j<5; j++){
            teacher[i].student[j].name = "Student_";
            teacher[i].student[j].name += (char)(65+j);
            teacher[i].student[j].score = rand() % 21 + 80;
        }
    }
}



/**
 * @brief 
 * 打印这个老师的数据
 * @param teacher 
 */
void display_TeacherTest(TeacherTest * teacher,int length){
    //统计数组长度
    for(int i=0;i < length;i++){
        cout << teacher->name << " is the teacher of class "<< i << endl;
        for(int j = 0;j< 5; j++){
            StudentTest student = teacher->student[j];
            cout << student.name << ":" << student.score <<endl;
        }
        teacher++;
    }  
}