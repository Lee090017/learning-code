/*
 * @Author: your name
 * @Date: 2022-04-27 16:57:52
 * @LastEditTime: 2022-04-27 17:34:16
 * @LastEditors: Please set LastEditors
 * @Description: vector可以理解为数组
 * @FilePath: \learningCode\project_05\vectorTest1.cpp
 */
#include<iostream>
#include<vector>
#include<algorithm> //标准算法的头文件
#include<string>

using namespace std;
/**
 * @brief 
 * 
 * 容器vector
 * 算法：for_each
 * 迭代器：vector<int>::iterator
 * 
 */

//返回函数技术
void myPrint(int i){
    cout << i << endl;
}

void test01(){
    //创建vector容器
    vector<int> v;
    //向容器中插入数据
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    //通过迭代器访问
    // vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个位置

    // //遍历1
    // while(itBegin != itEnd){
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    //遍历2
    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
    //     cout << *it << endl;
    // }

    //遍历3  --- 利用STL提供遍历算法
    for_each(v.begin(), v.end(),myPrint);

}


class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

//自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("John",18);
    Person p2("Bob",20);
    Person p3("Lee",35);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){ ///*it 类型为 <Person>
        cout << "name = " << it->name << " age = " << (*it).age << endl; 
    }
}

//自定义数据类型的指针
void test03(){
    vector<Person*> v;
    Person p1("John",18);
    Person p2("Bob",20);
    Person p3("Lee",35);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++){
        cout << "name = " << (*it)->name << " age = " << (*it)->age << endl; 
    }

}

//容器嵌套容器
void test04(){
    vector<vector<Person>> v2;
    vector<Person> v11;
    Person p1("John",18);
    Person p2("Bob",20);
    v11.push_back(p1);
    v11.push_back(p2);
    vector<Person> v12;
    Person p3("Mary",28);
    Person p4("Jack",23);
    v12.push_back(p3);
    v12.push_back(p4);
    vector<Person> v13;
    Person p5("Lee",68);
    Person p6("Bruce",30);
    v13.push_back(p5);
    v13.push_back(p6);
    v2.push_back(v11);
    v2.push_back(v12);
    v2.push_back(v13);

    //遍历二维数组
    for(vector<vector<Person>>::iterator it1 = v2.begin(); it1 != v2.end(); it1++){
        for(vector<Person>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++){
            cout << "name = " << it2->name << " age = " << it2->age << " "; 
        }
        cout << endl;
    }
}


int main(){
    test04();

    return 0;
}