/*
 * @Author: your name
 * @Date: 2022-04-13 16:54:30
 * @LastEditTime: 2022-04-13 18:11:12
 * @LastEditors: Please set LastEditors
 * @Description: 运算符重载(加号、左移（输出）、递增)
 * @FilePath: \learningCode\project_02\operatorOverloadingTest1.cpp
 */
#include<iostream>
#include<string>
using namespace std;

class Person{

    friend ostream & operator<<(ostream &cout,Person &p);

private:
    string idCad;
    string phone;

public:
    int salary;
    int age;

    Person():salary(1000),age(18){

    }

    Person(int salary, int age,string idCad,string phone){
        this->salary = salary;
        this->age = age;
        this->idCad = idCad;
        this->phone = phone;
    }

    //成员函数重载加法运算符 本质：Person p3 = p1.operator+(p2)
    // Person operator+(Person &p){
    //     Person temp;
    //     temp.salary = p.salary + this->salary;
    //     temp.age = p.age + this->age;
    //     return temp;
    // }

    //成员函数 左移运算符重载
    //一般不会利用成员函数重载左移运算符，因为cout在左侧
    // void operator<<(cout){

    // }

    //成员函数 递增运算符
    //前置递增
    Person& operator++(){//返回引用是为了对一个对象进行加法操作
        age++;
        return *this;
    }

    //后置递增
    //这个int代表占位参数，用于区分前置和后置操作
    Person operator++(int){//后置递增返回值，前置返回引用
        //先返回结果
        Person temp = *this;
        //再递增
        age++;
        //再返回结果
        return temp;
    }


};

//全局函数重载 本质：Person p3 = operator+(p1,p2)
Person operator+(Person &p1,Person &p2){
        Person temp;
        temp.salary = p1.salary + p2.salary;
        temp.age = p1.age + p2.age;
        return temp;
}

//全局函数重载左移运算符 本质operator<<(cout,p) 简化cout << p
ostream & operator<<(ostream &cout,Person &p){
    // cout << "IdCad = " << p.idCad << " phone = " << p.phone;
    cout << "age = " << p.age;
    return cout;//链式编程
}


//加法运算符重载
void test01(){
    Person p1(1000,25,"s190131142","15874128596");
    Person p2(2000,35,"s190121678","18672415504");
    Person p3 = p1 + p2;//重载加号
    cout << "p3's salary is " << p3.salary << endl;
    cout << "p3's age is " << p3.age << endl;
}

void test02(){
    Person p1(1000,25,"s190131142","15874128596");
    cout << p1 << " end" <<endl;
}

void test03(){
    Person p;
    cout << ++(++p) << endl;
}

void test04(){
    Person p;
    // cout << p++ << endl;
    Person temp = p++;
    cout << temp << endl;
    cout << p << endl;

    // int a = 1;
    // int temp = (++a)++;
    // cout << temp << endl;
    // cout << a << endl;
}

int main(){ 
    cout << "==================" <<endl;
    test01();
    cout << "==================" <<endl;
    test02();
    cout << "==================" <<endl;
    test03();
    cout << "==================" <<endl;
    test04();
    return 0;
}