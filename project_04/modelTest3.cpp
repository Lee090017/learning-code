/*
 * @Author: your name
 * @Date: 2022-04-26 15:38:01
 * @LastEditTime: 2022-04-26 16:15:26
 * @LastEditors: Please set LastEditors
 * @Description: 模板---类模板
 * @FilePath: \learningCode\project_04\modelTest3.cpp
 */
#include<iostream>
#include<string>
using namespace std;

//类模板
//类模板和函数模板的区别
//1.类模板没有自动类型推导的使用方式
//2.类模板可以有默认参数

//类模板成员函数的创建时机
template<class NameType,class AgeType = int>//需要的数据类型
class Person{
public:
    NameType name;
    AgeType age;

    Person(NameType name,AgeType age){
        this->name = name;
        this->age = age;

    }

    void show(){
        cout << "name = " << name << " age = " << age << endl;
    }

};

class Person2{
public:
    void show(){
        cout << "Person2 is showing" << endl;
    }
};

//编译通过，当创建成员时
template<class T>
class TestPerson{
public:
    T obj;

    void func(){
        obj.show();
    }
};

void test01(){
    Person<string,int> p1("John",18);//只能用显示指定的方式
    // Person p1("John",18);//没有自动类型推导
    Person<string> p2("Mary",28);//有默认参数类型
    p1.show();
    p2.show();
}

void test02()
{
    TestPerson<Person2> tp;
    tp.func();
}

//类模板对象做函数参数
//1.指定传入类型(最常用)
void print01(Person<string,int>& p){
    p.show();
}

void test03(){
    Person<string,int> p1("John",18);
    print01(p1);
}

//2.参数模板化
template <class T1,class T2>
void print02(Person<T1,T2>& p){
    p.show();
    cout << "T1 name is " << typeid(T1).name() << endl;
    cout << "T2 name is " << typeid(T2).name() << endl;
}

void test04(){
    Person<string,int> p1("John",18);
    print02(p1);
}

//3.将整个类模板化
template <class T>
void print03(T &p){
    p.show();
    cout << "T name is " << typeid(T).name() << endl;
}

void test05(){
    Person<string,int> p1("John",18);
    print03(p1);
}

int main(){
    test01();
    test02();
    test03();
    test04();
    test05();

    return 0;
}