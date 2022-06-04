/*
 * @Author: your name
 * @Date: 2022-04-13 14:53:58
 * @LastEditTime: 2022-04-13 15:23:35
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\classTest5.cpp
 */

#include<iostream>
using namespace std;

class Person{
public:
    Person(int m_A){
        this->m_A = m_A;//this指针指向的被调用成员函数所属对象
    }

    Person(){

    }

    int m_A;//非静态成员变量 属于类的对象上

    char m_C;//内存对齐

    static int m_B;//静态成员变量 不属于类的对象上

    void func() {}//非静态成员函数 不属于类的对象上

    static void func2() {}//静态成员函数 不属于类的对象上

    //链式编程思想
    Person& sum(Person &p){//若返回的是值，则返回的是本地由拷贝构造函数产生的新对象
        this->m_A += p.m_A;
        return *this;
    }

};
int Person::m_B = 10;

void test01(){
    Person p;
    //空对象占用内存空间为 1
    //c++编译器会给每个空对象分配一个字节空间，是为了区分对象占内存的位置
    //空对象也应该有一个独一无二的地址
    cout << sizeof(p) << endl;
}

void test02(){
    Person p(18);
    cout << p.m_A << endl;
}

void test03(){
    Person p1(12);

    Person p2(18);

    p1.sum(p2).sum(p2).sum(p2).sum(p2);//12 + 18 + 18 + 18 + 18

    cout << p1.m_A << endl;//84
}

int main(){

    test01();
    test02();
    test03();

    return 0;
}
