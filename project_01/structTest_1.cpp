/*
 * @Author: your name
 * @Date: 2022-04-08 18:17:39
 * @LastEditTime: 2022-04-08 19:26:20
 * @LastEditors: Please set LastEditors
 * @Description: 结构体
 * @FilePath: \learningCode\project_01\structTest.cpp
 */

/**
 * @file structTest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 * 用户自定义的数据类型，允许存储不同的数据类型
 * 
 * 语法： struct 结构体名 { 结构体成员列表 };
 * 
 */

#include<iostream>
#include<string>
using namespace std;

//1.创建学生的数据类型 姓名、年龄、分数


struct Student {
    //成员列表
    string name;
    int age;
    int score; 
}s3; //在创建时就赋给其结构体变量

//结构体嵌套结构体
struct Teacher {
    int id;
    string name;
    int age;
    Student student;
};


void display_Student_01(Student stu);
void display_Student_02(Student * stu);

int main(){

    //通过学生类型创建具体的变量
    //struct关键字可以省略
    Student s1;
    s1.name = "zhangsan";
    s1.age  = 18;
    s1.score = 100;
    cout << s1.name << " " << s1.age << " " << s1.score << endl;

    struct Student s2 = {"lishu",25,90};
    cout << s2.name << " " << s2.age << " " << s2.score << endl;

    s3.name = "wangwu";
    s3.age  = 28;
    s3.score = 80;
    cout << s3.name << " " << s3.age << " " << s3.score << endl;
    cout << "====================" << endl;

    Student stuArr[3] = {{"aa",9,99},{"bb",8,88},{"cc",7,77}};
    for(int i = 0;i <3;i++){
        cout << stuArr[i].name << " " << stuArr[i].age << " " << stuArr[i].score << endl;
    }
    cout << "====================" << endl;

    //通过结构体指针访问结构体成员 需要使用 “->”
    Student * sp = &s1;
    sp->name = "zhaoquan";
    cout << s1.name << " " << s1.age << " " << s1.score << endl;

    cout << "====================" << endl;

    Teacher t1;
    t1.name = "laowang";
    t1.age = 45;
    t1.id = 10086;
    t1.student = {"luosir",25,99};

    cout << t1.id << " " << t1.name << " " << t1.age << " " << t1.student.name << endl;

    cout << "====================" << endl;
    //结构体做函数参数
    //值传递
    display_Student_01(s1);
    //地址传递
    // display_Student_02(&s1);
    cout << s1.name << " " << s1.age << " " << s1.score << endl;

    cout << "====================" << endl;



    return 0;
}

//打印学生所有信息
void display_Student_01(Student stu){
    stu.age = 100;
    cout << stu.name << " " << stu.age << " " << stu.score << endl;
}

//const 在结构体的使用
//指针可以节省内存空间，但是当函数只需要读操作不用写操作时
void display_Student_02(const Student * stu){
    // stu->age = 100;//使其内部值不能修改
    cout << stu->name << " " << stu->age << " " << stu->score << endl;
}