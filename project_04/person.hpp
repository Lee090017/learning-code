/*
 * @Author: your name
 * @Date: 2022-04-26 21:16:25
 * @LastEditTime: 2022-04-26 21:25:25
 * @LastEditors: Please set LastEditors
 * @Description: 类模板分开编写
 * @FilePath: \learningCode\project_04\person.cpp
 */
// #include "person.h"
//类外实现
#pragma once //防止头文件重复包含
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person{
public:
    Person(T1 a, T2 b);

    void show();

    T1 a;
    T2 b;
};

template<class T1, class T2>
Person<T1,T2>::Person(T1 a, T2 b){
    this->a = a;
    this->b = b;
}

template<class T1, class T2>
void Person<T1,T2>::show(){
    cout << "a = " << a << " b = " << b << endl;
}