/*
 * @Author: your name
 * @Date: 2022-04-29 18:07:28
 * @LastEditTime: 2022-04-29 19:14:08
 * @LastEditors: Please set LastEditors
 * @Description: set/multiset容器 集合
 * @FilePath: \learningCode\project_05\setTest.cpp
 */

/**
 * @brief 
 * 
 * 所有元素都会在插入时自动被排序
 * 
 * set/multiset属于关联式容器，底层结构是用二叉树实现。
 * 
 * set和multiset区别：
 * set不允许容器中有重复的元素
 * multiset允许容器中有重复的元素
 */

#include<iostream>
#include<string>
#include<set>
#include<list>
using namespace std;

void printSet(const set<int>& s){
    if(s.empty()){
        cout << "set is empty" << endl;
        return;
    }
    for(set<int>::const_iterator i = s.begin(); i != s.end(); i++){
        cout << (*i) << " ";
    }
    cout << endl;
}

/**
 * @brief 
 * 
 * set构造和赋值
 * 
构造：
set<T> st; //默认构造函数：
set(const set &st); //拷贝构造函数

set可以传入不同的迭代器的起始和结束位置进行初始化
如：数组、list、vector、deque，set

以下初始化也可以：
① set<int> set = {1,2,3,4};
② set<int> set{1,2,3,4};
③ set<int> set({1,2,3,4});

赋值：
set& operator=(const set &st); //重载等号操作符
 */

void test01(){
    set<int> s1;
    for(int i=10;i> 0;i--){
        s1.insert(i);//插入数据只有insert方式
    }
    printSet(s1);//set将对插入数据自动排序
    s1.insert(1);
    s1.insert(1);
    printSet(s1);//set不允许插入重复的值

    //将list变为set
    list<int> l1 = {1,2,3,4,1,1,1};
    set<int> l2(l1.begin(),l1.end());
    printSet(l2);//自动删除重复数据
    
}

/**
 * @brief 
 * 
 * set大小和交换
 * 
size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器
 */
void test02(){
    set<int> s1;
    printSet(s1);

    for(int i=10;i> 0;i--){
        s1.insert(i);
    }

    cout<< "size of set is " << s1.size() << endl;

    set<int> s2 = {1,2,3,4};

    s1.swap(s2);
    printSet(s1);
    printSet(s2);
    
}

/**
 * @brief 
 * 
 * set插入和删除
 * 
insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(Iterator pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem); //删除容器中值为elem的元素。
 */
void test03(){
    set<int> s1;

    for(int i=10;i> 0;i--){
        s1.insert(i);
    }

    set<int>::iterator it = s1.begin();
    s1.erase(++it);//删除2
    printSet(s1);
    
    s1.erase(5);//删除元素5
    printSet(s1);

    s1.clear();

}

/**
 * @brief 
 * 
 * set查找和统计
 * 
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数
 */
void test04(){
    set<int> s1 = {10,2,4,6,1,3};

    set<int>::iterator it =s1.find(10);

    if(it == s1.end()){
        cout << "can not find" << endl;
    }else{
        cout << (*it) << endl;
    }

    int num = s1.count(1);//统计1的个数

    cout << "num = " << num << endl;//对于set而言统计的结果要么0要么1


}

/**
 * @brief 
 * 
 * set和mutiset区别
 * 
set不可以插入重复数据，而multiset可以
set插入数据的同时会返回插入结果，表示插入是否成功
multiset不会检测数据，因此可以插入重复数据
 */
void test05(){
    set<int> s1;

    pair<set<int>::iterator,bool> ret = s1.insert(0);//返回迭代器和是否成功

    if(ret.second){
        cout << "success" << endl;
    }else{
        cout << "error" << endl;
    }

    ret = s1.insert(0);//第二次插入失败

    if(ret.second){
        cout << "success" << endl;
    }else{
        cout << "error" << endl;
    }

    multiset<int> m1;

    m1.insert(0);//
    m1.insert(0);//允许重复插入

    for(multiset<int>::iterator it = m1.begin(); it != m1.end(); it++){
        cout << (*it) << " " ;
    }
    cout << endl;


}

/**
 * @brief 
 * 
 * set排序 修改排序规则
 * 
利用仿函数，可以改变排序规则
 */
class MyCompare{//仿函数本质上是一个类型
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};

void test06(){
    set<int> s1= {10,30,20,50};
    printSet(s1);

    //改变规则
    set<int,MyCompare> s2(s1.begin(),s1.end());//再插入数据之前改变排序规则

    for(set<int,MyCompare>::iterator it = s2.begin(); it!=s2.end();it++){
        cout << (*it) << " ";
    }
    cout <<endl;
    

}
//自定义数据类型的排序,需要添加仿函数指定其排序规则
class Person{
public:
    string name;
    int age;

    Person(){}

    Person(string name,int age):name(name),age(age){}
};

class ComparePerson{
public:
    bool operator()(const Person &p1,const Person &p2){
        return p1.age < p2.age;
    }
};

void test07(){

    set<Person,ComparePerson> s1;
    s1.insert(Person("zhangsan",18));
    s1.insert(Person("lisi",20));
    s1.insert(Person("wangwu",15));

    for(set<Person,ComparePerson>::iterator it = s1.begin(); it!=s1.end();it++){
        cout << (*it).name << " : " << (*it).age << endl;
    }

}


int main(){
    test07();

    return 0;
}
