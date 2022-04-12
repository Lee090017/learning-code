/*
 * @Author: your name
 * @Date: 2022-04-12 21:08:41
 * @LastEditTime: 2022-04-12 21:46:57
 * @LastEditors: Please set LastEditors
 * @Description: 初始化列表、类对象作为类成员，静态成员函数
 * @FilePath: \learningCode\project_02\classTest4.cpp
 */

#include <iostream>
using namespace std;

//类对象作为对象成员
class Phone{
public:
    string p_name;

    Phone(string a) : p_name(a){

    }
};

class Person{
public:
    string m_name;
    int m_age;
    int m_height;
    Phone m_phone;//手机

    //传统的初始化方式
    // Person(string name, int age, int height){
    //     m_name = name;
    //     m_age = age;
    //     m_height = height;
    // }

    //初始化列表
    Person():m_name("Mary"),m_age(10),m_height(180),m_phone("HuaWei"){
        
    }

    //隐式转换 Phone m_phone = "xxxx"; Phone m_phone = Phone("xxxx"); 
    Person(string a, int b, int c, string d):m_name(a),m_age(b),m_height(c),m_phone(d){
        
    }

    //静态成员函数
    //所有的对象共享同一个函数
    //静态成员函数只能访问静态成员
    //该静态成员可以通过对象或者类名访问

    static void func(){
        cout << "static void func()调用 " << count << " 次" << endl;
        count++;
        // m_name = "leege";
    }

    //静态成员
    static int count;

private:
    static void pfunc(){
        cout << "private static void func()调用 " << endl;
    } 


};

int Person::count = 0;//静态成员初始化


void test01(){
    Person p;
    cout << p.m_name << endl;
    cout << p.m_age << endl;
    cout << p.m_height << endl;
}

void test02(){
    Person p("John",45,168,"iPhone");
    cout << p.m_name << endl;
    cout << p.m_age << endl;
    cout << p.m_height << endl;
    cout << p.m_phone.p_name << endl;
}

void test03(){
    Person p1;
    p1.func();
    Person::func();//类名调用
    // p1.pfunc();//类外访问不到私有静态成员函数
}

int main(){

    //初始化列表
    //构造函数():属性1(值1)，属性2(值2)。。。{}
    test01();
    cout << "====================" << endl;
    test02(); //
    cout << "====================" << endl;
    test03(); //

    return 0;
}