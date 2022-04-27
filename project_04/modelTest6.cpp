/*
 * @Author: your name
 * @Date: 2022-04-26 21:29:00
 * @LastEditTime: 2022-04-26 21:44:54
 * @LastEditors: Please set LastEditors
 * @Description: 类模板和友员
 * @FilePath: \learningCode\project_04\modelTest6.cpp
 */
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1,T2> p){
    cout << "a = " << p.a << " b = " << p.b << endl;
}

//通过全局函数 打印Person信息

template<class T1, class T2>
class Person{

//全局函数 类内实现
friend void printPerson(Person<T1,T2> p){
    cout << "a = " << p.a << " b = " << p.b << endl;
}

//全局函数类外实现
//加空模板的参数列表，如果是全局函数函数，需要先声明
friend void printPerson2<>(Person<T1,T2> p);

public:
    Person(T1 a, T2 b){
        this->a = a;
        this->b = b;
    }

private:
    T1 a;
    T2 b;
};

//类外实现
// template<class T1, class T2>
// void printPerson2(Person<T1,T2> p){
//     cout << "a = " << p.a << " b = " << p.b << endl;
// }

void test01(){
    cout << "================成员函数类内实现================" << endl;
    Person<string,int> p("john",18);
    printPerson(p);
}

void test02(){
    cout << "================成员函数类外实现================" << endl;
    Person<string,int> p("john",18);
    printPerson2(p);
}

int main(){
    test01();
    test02();
    return 0;
}