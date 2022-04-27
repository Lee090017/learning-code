/*
 * @Author: your name
 * @Date: 2022-04-26 21:08:05
 * @LastEditTime: 2022-04-26 21:27:14
 * @LastEditors: Please set LastEditors
 * @Description: 类模板分文件编写
 * @FilePath: \learningCode\project_04\modelTest5.cpp
 */
#include<iostream>
#include<string>
using namespace std;
// #include "person.h"
//第一种解决方式，直接包含cpp源码
// #include "person.cpp"

//第二种解决方式，将h与cpp内容写在一起，后缀名改为.hpp
#include "person.hpp"

//类模板分文件编写的问题
//出现编译问题：因为类模板中的成员函数创建时机在调用阶段，一开始没有创建，导致文件编写时链接不到

// template<class T1, class T2>
// class Person{
// public:
//     Person(T1 a, T2 b);

//     void show();

//     T1 a;
//     T2 b;
// };

// template<class T1, class T2>
// Person<T1,T2>::Person(T1 a, T2 b){
//     this->a = a;
//     this->b = b;
// }

// template<class T1, class T2>
// void Person<T1,T2>::show(){
//     cout << "a = " << a << " b = " << b << endl;
// }

void test01(){
    Person<string,int> p("john",18);
    p.show();
}

int main(){
    test01();

    return 0;
}