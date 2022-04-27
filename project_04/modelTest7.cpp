/*
 * @Author: your name
 * @Date: 2022-04-27 15:08:12
 * @LastEditTime: 2022-04-27 16:42:32
 * @LastEditors: Please set LastEditors
 * @Description: 案例：实现通用的数组类
 * @FilePath: \learningCode\project_04\modelTest7.cpp
 */

/**
 * @file modelTest7.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 实现通用数组类，要求如下：
 * 可以对内置数据类型以及自定义数据类型的数据进行存储
 * 将数组中的数据存储在堆区
 * 构造函数中可以传入数组的容量
 * 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
 * 提供尾插法和尾删法对数组中的数据进行增加和删除
 * 可以通过下标的方式访问数组中的元素
 * 可以获取数组中当前元素个数和数组的容量
 * 
 */
#include<iostream>
#include<string>
using namespace std;

//通用数据类
template<class T>
class MyArray{
private:
    T * pAddress;//存放数组
    int m_Capacity;//容量
    int m_Size;//大小
public:
    //构造函数
    MyArray(int m_Capacity){//传入容量
        this->m_Capacity = m_Capacity;
        this->pAddress = new T[m_Capacity];
        this->m_Size = 0;
    }

    //拷贝构造函数
    MyArray(const MyArray& p){
        this->m_Capacity = p.m_Capacity;
        this->m_Size = p.m_Size;
        //浅拷贝
        // this->pAddress = p.pAddress;
        //深拷贝
        this->pAddress = new T[p.m_Capacity];
        for (int i = 0;i < p.m_Size;i++){
            pAddress[i] = p.pAddress[i];
        }
    }

    //重写operator=赋值运算符
    MyArray& operator=(const MyArray &p){// a = b = c
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        this->m_Capacity = p.m_Capacity;
        this->m_Size = p.m_Size;
        this->pAddress = new T[p.m_Capacity];
        for (int i = 0;i < p.m_Size;i++){
            pAddress[i] = p.pAddress[i];
        }
        return *this;
    }

    //析构函数
    ~MyArray(){
        if(this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

    //尾插
    void addArray(const T & a){
        if(m_Size<m_Capacity){//当前数组个数未超过容量
            pAddress[m_Size] = a;
            m_Size++;
        }else{//扩容
            m_Capacity++;
            T * newSpace = new T[m_Capacity];//创建新空间
            for(int i = 0; i < m_Size; i++){
                newSpace[i] = pAddress[i];
            }
            delete[] pAddress;
            pAddress = newSpace;
            pAddress[m_Size] = a;
            m_Size++;
        }
    }

    //尾删
    void deleteArray(){
        if(m_Size == 0) return;
        m_Size--;
        // delete &pAddress[m_Size];
    }

    //通过下标的方式访问数组的元素
    void findIndex(int i){
        cout << this->pAddress[i] << " ";
    }

    //重载operator[]访问元素
    T& operator[](int index){//arr[0] = 100;

        return this->pAddress[index];
    }

    //获取元素个数和数组容量
    void showInfo(){
        cout << "m_Size = " << m_Size << endl;
        cout << "m_Capacity = " << m_Capacity << endl;
    }

};

//测试自定义数据类型
class Person{
public:
    string name;
    int age;

    Person(){}

    Person(string name,int age){
        this->name = name;
        this->age = age;
    }


};

//全局函数实现左移运算
ostream& operator<<(ostream& out,Person& person){
    cout << "name = " << person.name << " age = " << person.age;
    return out;
}

//测试增删查
void test01(){
    MyArray<int> arr(5);
    //添加数字
    for (int i = 0;i <5 ; i++){
        arr.addArray(i);
    }
    arr[2] = 100;
    //打印数字
    for (int i = 0;i <5 ; i++){
        cout << arr[i] << endl;
    }
    arr.deleteArray();
    arr.showInfo();
    arr.addArray(7);
    arr.addArray(8);
    arr.showInfo();
}

//测试拷贝构造和赋值
void test02(){
    MyArray<int> arr1(5);
    //添加数字
    for (int i = 0;i <5 ; i++){
        arr1.addArray(i);
    }
    MyArray<int> arr2(arr1);//拷贝构造
    // MyArray<int> arr2 = arr1;
    //打印数字
    for (int i = 0;i <5 ; i++){
        cout << arr2[i] << endl;
    }
    arr2.showInfo();

}

//测试自定义数据类型
void test03(){
    MyArray<Person> arr(5);
    Person p1("John",18);
    arr.addArray(p1);
    cout << arr[0]<< endl;
    arr.showInfo();
}

int main(){
    test03();

    return 0;
}
