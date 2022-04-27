/*
 * @Author: your name
 * @Date: 2022-04-26 16:17:53
 * @LastEditTime: 2022-04-26 21:06:51
 * @LastEditors: Please set LastEditors
 * @Description: 类模板和继承
 * @FilePath: \learningCode\project_04\modelTest4.cpp
 */

#include<iostream>
#include<string>
using namespace std;

/**
 * @brief 
 * 
 * 当子类继承的父类是一个类模板时，子类在声明的时候，要指定父类中T的类型，如果不指定，编译器将无法给子类分配内存
 * 
 * 
 */

//类模板嵌套
template<class T>
class Person{
public:
    T name;

    Person(T name){
        this->name = name;
    }

    //在以下情况下，必需使用初始值列表方式来初始化：

    //类成员包含const对象时。
    //在类A没有提供默认构造函数且被类B包含或者继承时，类B必需使用默认初始化方式初始化A。
    Person(){}

    void show(){
        cout << "Person class" << endl;
    }
};

template<class T>
class Company{
public:
    T person;

    Company(T p){
        person = p;
    }


    void print(){
        person.show();
    }
};

void test01(){
    Person<string> p("lee");
    Company<Person<string>> c(p);
    c.print();

    // Company<Person<string>> c(Person<string>("lee"));
    // c.print();
}

//类模板和继承
template <class T>
class Base{
public:
    T m;    
};

//必须知道T的数据类型才能继承
class Son:public Base<int>{
    
};

//如果想灵活地指定父类的T类型，子类也要变为模板
template<class T1,class T2>
class Son2: public Base<T1>{
public:
    T2 n;
    Son2(){
        cout << "T1 type is " << typeid(T1).name() << endl;
        cout << "T2 type is " << typeid(T2).name() << endl;
    }
};

void test02(){
    Son2<int,char> son;
}

//成员函数的类外实现
template<class T1, class T2>
class MyClass{
public:
    MyClass(T1 a, T2 b);
    // {
        // m_name = a;
        // m_age = b;
    // }

    void showMyClass();
    // {
    //     cout << "m_name = " << m_name << " m_age = " << m_age << endl;
    // }

    T1 m_name;
    T2 m_age;
};

//类模板的类外实现
//构造函数的内外实现
template<class T1, class T2>
MyClass<T1,T2>::MyClass(T1 a,T2 b){
    m_name = a;
    m_age = b;
}

template<class T1, class T2>
void MyClass<T1,T2>::showMyClass(){
    cout << "m_name = " << m_name << " m_age = " << m_age << endl;
}

void test03(){
    MyClass<string,int> mc("lee",18);
    mc.showMyClass();
}

int main(){
    test02();
    test03();

    

    return 0;
}
