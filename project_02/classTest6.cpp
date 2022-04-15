/*
 * @Author: your name
 * @Date: 2022-04-13 15:26:09
 * @LastEditTime: 2022-04-13 15:46:04
 * @LastEditors: Please set LastEditors
 * @Description: 空指针调用成员函数、常函数、常对象
 * @FilePath: \learningCode\project_02\classTest6.cpp
 */

#include<iostream>
using namespace std;

//空指针调成员函数
class Person{
public:
    Person(){
        
    }

    void showClassName(){
        cout << "Person class" << endl;
    }

    void showAge(){
        //处理异常的操作
        if(this == NULL) return;
        cout << "Age = " << age << endl;//省略了 this->age
    }

    int age;
    mutable int m_age;//特殊变量，可以在常函数中修改

    //常函数
    //this指针本质是一个 指针常量 const Person * const this  
    void changeAge() const {//让this指向的值也不能修改
        // this = NULL;
        // age = 10;//常函数不能修改成员变量
        m_age = 10;
    }

};

void test01(){
    Person * p = NULL;
    p->showClassName();
    
    p->showAge();//异常，this对象为NULL
}

void test02(){
    const Person p;
    // p.age =  10;
    p.m_age = 10;//在常对象下也可以修改

    //常对象只能调用常函数
    p.changeAge();
    // p.showClassName();//常对象不能调用普通成员函数
}

int main(){
    test01();
    test02();

    return 0;
}
