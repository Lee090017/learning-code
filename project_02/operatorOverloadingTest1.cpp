/*
 * @Author: your name
 * @Date: 2022-04-13 16:54:30
 * @LastEditTime: 2022-04-18 17:07:24
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
    int *m_age;

    Person():salary(1000),age(18){
        m_age = new int(18);
    }

    ~Person(){
        if(m_age != NULL){
            delete m_age;
            m_age = NULL;
        }
    }

    Person(int m_age){
        this->m_age = new int(m_age);
    }

    Person(int salary, int age,string idCad,string phone,int *m_age){
        this->salary = salary;
        this->age = age;
        this->idCad = idCad;
        this->phone = phone;
        this->m_age = m_age;
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

    //赋值运算符重载
    //对数据的值进行赋值
    Person & operator=(Person &p){
        //编译器提供的浅拷贝
        //m_age = p.m_age;

        //应该先判断是否有属性在堆区，如果有先释放干净，再做深拷贝
        if(m_age != NULL){
            delete m_age;
            m_age = NULL;
        }

        //深拷贝
        m_age = new int(*p.m_age);

        return *this;
    }

    //关系运算符
    bool operator==(Person &p){
        if(this->age == p.age && this->salary == p.salary){
            return 1;
        }
        return 0;
    }

    //函数调用运算符
    void operator()(string test){
        cout << test << endl;
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
    int* m1 = new int(18);
    int* m2 = new int(19);
    Person p1(1000,25,"s190131142","15874128596",m1);
    Person p2(2000,35,"s190121678","18672415504",m2);
    Person p3 = p1 + p2;//重载加号
    cout << "p3's salary is " << p3.salary << endl;
    cout << "p3's age is " << p3.age << endl;
}

void test02(){
    int* m1 = new int(18);
    Person p1(1000,25,"s190131142","15874128596",m1);
    cout << p1 << " end" <<endl;
}

void test03(){
    Person p;
    cout << ++(++p) << endl;
}

void test04(){
    Person p;
    // cout << p++ << endl;
    Person temp = (p++);
    cout << temp << endl;
    cout << p << endl;

    // int a = 1;
    // int temp = (++a)++;
    // cout << temp << endl;
    // cout << a << endl;
}

//测试赋值运算符
void test05(){
    Person p1(10);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;

    cout << "p1 m_age = " << *p1.m_age <<endl;
    cout << "p2 m_age = " << *p2.m_age <<endl;
    cout << "p3 m_age = " << *p3.m_age <<endl;
}

//关系运算符
void test06(){
    Person p1;
    Person p2;
    if(p1 == p2){
        cout << "p1 is as successful as p2" << endl;
    }else{
        cout << "p1 != p2" << endl;
    }
}

//函数调用运算符
void test07(){
    Person p;
    p("Hello world");
    //匿名对象
    // cout << Person()("aaa") << endl;
}

int main(){ 
    cout << "=========test01=========" <<endl;
    test01();
    cout << "=========test02=========" <<endl;
    test02();
    cout << "=========test03=========" <<endl;
    test03();
    cout << "=========test04=========" <<endl;
    // test04();
    cout << "=========test05=========" <<endl;
    test05();
    cout << "=========test06=========" <<endl;
    test06();
    cout << "=========test07=========" <<endl;
    test07();
    return 0;
}