/*
 * @Author: your name
 * @Date: 2022-04-29 17:38:42
 * @LastEditTime: 2022-04-29 17:54:59
 * @LastEditors: Please set LastEditors
 * @Description: list容器案例
 * @FilePath: \learningCode\project_05\listTest2.cpp
 */
#include<iostream>
#include<list>
#include<string>

using namespace std;

/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

*/

class Person{
public:
    string name;
    int age;
    int height;

    Person(string name, int age, int height):name(name), age(age), height(height){}

    Person(){}
    
};

bool myCompare(Person p1, Person p2){
    if(p1.age < p2.age){
        return true;
    }else if(p1.age > p2.age){
        return false;
    }else{
        return p1.height > p2.height;
    }
}

void printList(const list<Person> &l){
    if(l.empty()){
        cout << "Empty list" << endl;
        return;
    }
    for(list<Person>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << "姓名：" << (*it).name << "\t年龄：" << (*it).age << "\t身高：" << (*it).height << endl;
    }
}

int main(){
    list<Person> l1;
    l1.push_back(Person("zhangsan",18,180));
    l1.push_back(Person("lisi",15,180));
    l1.push_back(Person("wangwu",30,150));
    l1.push_back(Person("luoliu",12,180));
    l1.push_back(Person("fengqi",20,170));
    l1.push_back(Person("houba",18,170));
    l1.push_back(Person("yijiu",20,160));

    printList(l1);

    l1.sort(myCompare);

    cout << "====================排序后====================" << endl;

    printList(l1);


    return 0;
}