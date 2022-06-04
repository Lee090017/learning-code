/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-26 16:59:07
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-31 15:42:12
 * @FilePath: \learningCode\project_05\mapTest1.cpp
 * @Description: map
 * 
 * 
 * 
简介：
map中所有元素都是pair
pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
所有元素都会根据元素的键值自动排序

本质：
map/multimap属于关联式容器，底层结构是用二叉树实现。

优点：
可以根据key值快速找到value值

map和multimap区别：
map不允许容器中有重复key值元素
multimap允许容器中有重复key值元素
 * 
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

void printMap(map<int,string> &m){
    if(m.empty()){
        cout << "map is empty" << endl;
        return;
    }
    for(map<int,string>::iterator it = m.begin(); it != m.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << "====================" << endl;
}

/**
 * @brief 
 * 
构造：
map<T1, T2> mp; //map默认构造函数:
map(const map &mp); //拷贝构造函数

赋值：
map& operator=(const map &mp); //重载等号操作符
 * 
 */
void test01(){
    map<int,string> m1;//创建map容器

    //插入数据
    m1.insert(pair<int,string>(2,"Mike"));
    m1.insert(pair<int,string>(1,"Bob"));
    m1.insert(pair<int,string>(3,"Mary"));
    m1.insert(pair<int,string>(4,"Tang"));//按照key自动排序

    printMap(m1);

    map<int,string> m2(m1);//拷贝构造

    map<int,string> m3 = m2;
}

/**
 * @brief 
 * 
 * map的大小和交换
size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器
 * 
 */
void test02(){
    map<int,string> m1;//创建map容器
    printMap(m1);

    //插入数据
    m1.insert(pair<int,string>(2,"Mike"));
    m1.insert(pair<int,string>(1,"Bob"));
    m1.insert(pair<int,string>(3,"Mary"));
    m1.insert(pair<int,string>(4,"Tang"));//按照key自动排序

    cout << "size is " << m1.size() << endl;

    map<int,string> m2;//创建map容器

    //插入数据
    m2.insert(pair<int,string>(2,"Lee"));
    m2.insert(pair<int,string>(1,"Wang"));

    m1.swap(m2);
    printMap(m1);
    printMap(m2);
}

/**
 * @brief 
 * 
 * map插入和删除
 * 
insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key); //删除容器中值为key的元素。

 * 
 */
void test03(){
    map<int,string> m1;

    //插入数据的四种方式
    m1.insert(pair<int,string>(2,"Lee"));
    m1.insert(make_pair(1,"Wang"));//推荐写法
    m1.insert(map<int,string>::value_type(3,"Luo"));
    m1[4] = "Liu";//[]不建议插入，但可以用于访问

    cout << m1[5] << endl;//不推荐使用，若不存在键，将会创建一个新的空间

    printMap(m1);

    map<int,string>::iterator it = m1.begin();
    m1.erase(++it);//按迭代器删除
    cout << it->first << " " << it->second << endl;
    m1.erase(3);//按key删除
    printMap(m1);


}

/**
 * @brief 
 * 
 * map查找和统计
 * 
find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
count(key); //统计key的元素个数

 * 
 */
void test04(){
    map<int,string> m1;//创建map容器

    m1.insert(pair<int,string>(2,"Mike"));
    m1.insert(pair<int,string>(1,"Bob"));
    m1.insert(pair<int,string>(3,"Mary"));
    m1.insert(pair<int,string>(4,"Tang"));

    map<int,string>::iterator it = m1.find(5);//不存在返回end()
    if(it!=m1.end()){
        cout << it->first << " " << it->second <<endl;
    }else{
        cout << "key is not exit" << endl;
    }

    //map不存在出现key重复的值，但multimap可以出现
    cout << "key(3) number is " << m1.count(3) << endl;
}

class myCompare{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};

/**
 * @brief 
 * 
 * map排序
 * 
利用仿函数排序
逆序排列
 * 
 */
void test05(){
    map<int,string,myCompare> m1;//创建map容器

    m1.insert(pair<int,string>(2,"Mike"));
    m1.insert(pair<int,string>(1,"Bob"));
    m1.insert(pair<int,string>(3,"Mary"));
    m1.insert(pair<int,string>(4,"Tang"));//从大到小排序

    for(map<int,string,myCompare>::iterator it = m1.begin(); it != m1.end();it++){
        cout << it->first << " " << it->second << endl;
    }
    cout << "====================" << endl;
}

int main(){
    test05();

    return 0;
}