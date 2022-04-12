/*
 * @Author: your name
 * @Date: 2022-04-12 16:07:30
 * @LastEditTime: 2022-04-12 16:39:43
 * @LastEditors: Please set LastEditors
 * @Description: 类和对象
 * @FilePath: \learningCode\project_02\classTest1.cpp
 */
#include<iostream>
using namespace std;

const double PI = 3.14;

class Cirlcle{
    //访问权限
    //公共权限 public 类内可以访问 类外也可以访问

    //保护权限 protected 类内可以访问 类外不可以访问（子类可以访问父类的保护内容）

    //私有权限 private 类内可以访问 类外不可以访问

public:
    int m_r;

    double calculateZC(){
        return 2 * PI * m_r;
    }

};

class Person{
public:
    string m_name;
    void setPassword(int password){
        m_passwords = password;
    }

    void setCar(string car){
        m_car = car;
    }

    string getCar(){
        return m_car;
    }
protected:
    string m_car;
private:
    int m_passwords;

};

int main(){

    Cirlcle c1;
    c1.m_r = 10;
    cout << c1.calculateZC() << endl;

    Person p1;
    p1.m_name = "lishu";
    //p1.m_car = "BMW";//不可访问
    //p1.m_passwords = "123123";
    p1.setPassword(123123);
    p1.setCar("BMW");
    cout << p1.getCar() << endl;

    return 0;
}
