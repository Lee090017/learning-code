/*
 * @Author: your name
 * @Date: 2022-04-12 17:04:20
 * @LastEditTime: 2022-04-12 21:07:29
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\classTest3.cpp
 */

/**
 * @file classTest3.cpp
 * @author your name (you@domain.com)
 * @brief 对象的初始化和清理
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */
#include<iostream>
#include<string>
using namespace std;

//构造函数和析构函数 编译器提供自带的空实现
//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用。 类名(){} 不写void
//析构函数：主要作用在于对象销毁前系统自动调用，执行一些清理工作。 ~类名(){}

/**
 * 构造函数的调用规则
默认情况下，c++编译器至少给一个类添加3个函数

1．默认构造函数(无参，函数体为空)

2．默认析构函数(无参，函数体为空)

3．默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下：

如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造

如果用户定义拷贝构造函数，c++不会再提供其他构造函数
 * 
 */

class Person{
public:
    //构造函数
    /**
     * @brief Construct a new Person object
     * 构造函数的分类
     * 按参数分为： 有参构造和无参构造
     * 按类型分为： 普通构造和拷贝构造
     */
    Person(){
        cout << "无参构造函数的调用" << endl;
    }

    Person(string name){
        m_name = name;
        cout << "有参构造函数的调用" << endl;
    }

    Person(int age,int height){
        m_age = age;
        Height = new int(height);
        cout << "有参构造函数的调用" << endl;
    }

    //拷贝构造函数
    /*
        调用时机
        使用一个已经创建完毕的对象来初始化一个新对象
        值传递的方式给函数参数传递值
        值方式返回局部对象

    */

   //用深拷贝解决堆区内存重复释放的问题
    Person(const Person &p){
        m_age = p.m_age;
        // Height = p.Height;//浅拷贝(编译器默认实现该行代码)
        //深拷贝
        Height = new int(*p.Height);//重新开辟堆区内存
        cout << "拷贝构造函数的调用" << endl;
    }

    //析构函数 将堆区数据释放
    ~Person(){
        //析构代码
        if(Height != NULL){
            delete Height;
            Height = NULL;
        }
        cout << "析构函数的调用" << endl; 
    }

    string getName(){
        return m_name;
    }

    int getAge(){
        return m_age;
    }

    int getHeight(){
        return *Height;
    }
    
private:
    string m_name;
    int m_age;
    int * Height;//将该数据存在堆区

};

void test01(){
    Person p1("John");
    cout << p1.getName() << endl;
    Person p2(p1);
    cout << p2.getName() << endl;

}

void test02(){
    Person p1(18,172);
    cout << p1.getAge() << " " << p1.getHeight() << endl;
    Person p2(p1);
    cout << p2.getAge() << " " << p2.getHeight() << endl;

}

int main(){
    //构造函数的调用

    //括号法
    // Person p1;
    // Person p2("lishu");
    // Person p3(p1);

    //显示法
    // Person p4 = Person("wang");
    // Person("wangwu");//匿名对象 特点：当前执行结束后将直接释放
    //不能用拷贝构造函数初始化匿名对象，编译器认为Person (p)  ===>  Person p;
    
    //隐式转换法
    // Person p5 = p1;//拷贝构造

    cout << "====================" << endl;
    //深拷贝和浅拷贝
    test02();//浅拷贝造成堆区的内存重复释放，深拷贝将在堆区重新开辟一块内存

    system("pause");
    return 0;
}