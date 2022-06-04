/*
 * @Author: your name
 * @Date: 2022-04-19 16:58:01
 * @LastEditTime: 2022-04-20 16:58:48
 * @LastEditors: Please set LastEditors
 * @Description: 虚函数，抽象类，虚析构，纯析构
 * @FilePath: \learningCode\project_03\polymorphismTest2.cpp
 */
#include <iostream>
#include <string>
using namespace std;

//在使用多态时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数变为虚析构或者纯虚析构

//抽象类 无法实例化对象
class AbstractClass{
public:
    //纯虚函数
    virtual void func() = 0;
};

class Son:public AbstractClass{
public:
    void func(){
        cout << "子类实现父类纯虚函数" << endl;
    }
};

class Animal{
public:
    virtual void speak() = 0;

    Animal(){
        cout << "Animal的构造函数" << endl;
    }
    //父类指针在析构时，不会调用子类的析构函数，导致子类如果堆区有堆区属性，可能造成内存泄漏
    // virtual ~Animal(){//改为虚析构
    //     cout << "Animal的析构函数" << endl;
    // }

    //纯虚析构
    virtual ~Animal() = 0;

};

//纯虚析构需要定义
Animal::~Animal(){
    cout << "Animal的析构函数" << endl;
}

class Cat:public Animal{
public:
    string * m_name;

    Cat(string name){
        cout << "Cat构造函数" << endl;
        m_name = new string(name);
    }

    void speak(){
        cout << *m_name << "猫在叫" << endl;
    }

    ~Cat(){
        if(m_name != NULL){
            cout << "Cat析构函数" << endl;
            delete m_name;
            m_name = NULL;
        }
    }
};

void test01(){
    Son s;
    s.func();

    AbstractClass * f = new Son;
    f->func();
}

void test02(){
    Animal * c = new Cat("Tom");
    c->speak();
    delete c;
}

int main(){
    test01();
    test02();
    return 0;	
}
