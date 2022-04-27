/*
 * @Author: your name
 * @Date: 2022-04-25 15:16:51
 * @LastEditTime: 2022-04-26 15:37:44
 * @LastEditors: Please set LastEditors
 * @Description: 模板---函数模板局限性，具体化函数模板
 * @FilePath: \learningCode\project_04\modeTest.cpp
 */

#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};


//模板的局限
template<typename T>
bool myCompare(T &a,T &b){
    if(a==b) return true;
    return false;
}
//利用具体化对的Person的版本实现代码，具体化优先调用
template<> bool myCompare(Person &p1,Person &p2){
    if(p1.name == p2.name && p1.age == p2.age){
        return true;
    }
    return false;
}

void test01(){
    Person p1("John",18);
    Person p2("Mary",20);
    bool result = myCompare(p1,p2);
    if(result){
        cout << "p1 = p2" << endl;
    }else{
        cout << "p2 != p2"<< endl;
    }

}


int main(){
    test01();

    return 0;
}