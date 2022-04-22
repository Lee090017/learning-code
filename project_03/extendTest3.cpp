/*
 * @Author: your name
 * @Date: 2022-04-18 21:48:23
 * @LastEditTime: 2022-04-18 22:06:35
 * @LastEditors: Please set LastEditors
 * @Description: 同名静态成员语法
 * @FilePath: \learningCode\project_03\extendTest3.cpp
 */

#include<iostream>
#include<string>
using namespace std;

class Base{
public:
    static int b_a;

    int s_b = 100;

    static void func(){
        cout << "Base func"<< endl;
    }

};

int Base::b_a = 100;

//多继承
//引发成员重名，一般不建议
class OtherBase{
public:
    int s_b = 200;

};

class Son2:public Base,public OtherBase{

};

class Son:public Base{
public:
    static int b_a;

    static void func(){
        cout << "Son func"<< endl;
    }

};

int Son::b_a = 200;

//同名静态成员属性
void test01(){
    Son s;
    //通过对象访问
    cout<< "Son b_a = " << s.b_a << endl;//200
    cout<< "Base b_a = " << s.Base::b_a << endl;//200

    //通过类名
    cout<< "Son b_a = " << Son::b_a << endl;//200
    //第一个::表示通过类名的方式访问，第二个::表示Base作用域下
    cout<< "Base b_a = " << Son::Base::b_a << endl;//200
}

void test02(){
    Son s;
    s.func();
    s.Base::func();

}

void test03(){
    Son2 s;
    cout<< "size of s is " << sizeof(s) << endl;//父类大小之和

    cout << "Base s_b = " << s.Base::s_b << endl;
    cout << "Base s_b = " << s.OtherBase::s_b << endl;
}

int main(){
    test01();
    test02();
    test03();

    return 0;
}