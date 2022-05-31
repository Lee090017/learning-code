/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-26 15:41:31
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-26 16:19:49
 * @FilePath: \learningCode\project_05\reviewTest3.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file reviewTest3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<list>
#include<string>

using namespace std;

class Person{
public:
    string m_Name;
    int m_Age;
    int m_Height;

    Person(string name, int age, int height):m_Name(name), m_Age(age), m_Height(height) {

    }

    Person(){

    }
};

bool comparePerson(Person &a, Person &b){
    if(a.m_Age < b.m_Age){
        return true;
    }else if(a.m_Age == b.m_Age){
        return a.m_Height > b.m_Height;
    }else{
        return false;
    }
}

void printList(list<int> &l){
    for(list<int>::iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

//自行定义排序规则
bool myCompare(int a,int b){
    return a < b;
}

void test01(){
    list<int> l1;
    l1.push_back(100);
    l1.push_back(200);
    l1.push_back(300);

    list<int> l2 = l1;
    printList(l2);

    list<int> l3 = {1,2,3};

    // l1.swap(l3);
    // printList(l1);
    // printList(l3);

    l1.push_front(400);
    l1.push_front(500);

    list<int>::iterator it1 = l1.begin();
    printList(l1);
    l1.insert(it1,1);//在500前面插入1
    l1.insert(it1,2);//在500前面插入2
    printList(l1);

    list<int>::iterator it2 = l1.erase(it1);//删除当前位置元素并返回下一个元素位置
    cout << "it2:" << *it2 << endl;

    cout << "front is " << l1.front() << endl;
    cout << "back is " << l1.back() << endl;

    //排序和反转
    l1.sort(myCompare); //
    printList(l1);

    l1.reverse();
    printList(l1);

    
}


/**
 * @brief 
 * 案例
 * 将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
 * 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
 */
void test02(){
    list<Person> l1;
    l1.push_back(Person("zhangsan",18,180));
    l1.push_back(Person("lisi",15,180));
    l1.push_back(Person("wangwu",30,150));
    l1.push_back(Person("luoliu",12,180));
    l1.push_back(Person("fengqi",20,170));
    l1.push_back(Person("houba",18,170));
    l1.push_back(Person("yijiu",20,160));

    l1.sort(comparePerson);

    for(list<Person>::iterator it = l1.begin(); it != l1.end();it++){
        cout << it->m_Name << ":\t" << it->m_Age << "\t" << it->m_Height << endl;
    }

}

int main(){
    test02();


    return 0;
}
