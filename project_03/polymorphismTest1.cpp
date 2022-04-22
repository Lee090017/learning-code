/*
 * @Author: your name
 * @Date: 2022-04-19 16:25:25
 * @LastEditTime: 2022-04-20 17:00:49
 * @LastEditors: Please set LastEditors
 * @Description: 多态
 * @FilePath: \learningCode\project_03\polymorphismTest1.cpp
 */

#include<iostream>
using namespace std;

/**
 * @brief 
 * 
 * 动态多态的条件
 * 1、有继承关系
 * 2、子类要重写父类的虚函数
 * 
 * 动态多态的使用
 * 父类的指针或引用 指向子类对象
 * 
 * 静态多态和动态多态的区别
 * 静态多态的函数地址早绑定，编译阶段确定函数地址
 * 动态多态的函数地址晚绑定，运行阶段确定函数地址
 * 
 */

class Animal{
public:
    virtual void speak(){
        cout<< "动物在叫" << endl;
    }
};

class Cat:public Animal{
public:
    void speak(){
        cout << "猫在叫" << endl;
    }
};

//Animal & animal = cat;
//地址早绑定，在编译阶段确定函数地址
//如果想执行猫，地址不能提前绑定，需要实现地址晚绑定

/**
 * 多态原理
 * 
 * Animal内部
 * 
 * vfptr - 虚函数（表）指针
 * 指向vftable（虚函数表）
 * 
 * &Animal::speak
 * 
 * v - virtual
 * f - function
 * ptr - pointer
 * 
 * Cat内部
 * 
 * &Animal::speak 经重写后 虚函数表内部会替换为子类的虚函数地址 -> &Cat::speak
 * 当父类指针指向子类的引用
 * 
 *  
 */
void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);
}

void test02(){
    Animal animal;
    cout << sizeof(animal) << endl;//64位 8
}

int main(){

    test01();
    test02();
    return 0;
}