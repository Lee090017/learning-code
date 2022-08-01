/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-06-04 17:10:28
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-06-20 18:34:22
 * @FilePath: \learningCode\project_06\for_eachTest.cpp
 * @Description: 常见的遍历和查找算法
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;  //tab可以自动补全

/*
算法主要是由头文件 <algorithm> <functional> <numeric>组成。
 
<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
<functional>定义了一些模板类,用以声明函数对象。
*/


//1、常用的遍历算法 
/**
 * 遍历容器：
 * for_each(iterator beg, iterator end, _func);  
 * _func 函数或者函数对象
 */

//普通函数
void print01(int val){
    cout << val << " ";
}

//仿函数
class print02{
public:
    void operator()(int val){
        cout << val << " ";
    }    
};

void test01(){
    vector<int> v = {1,2,3,4,5,6,7,8};
    // for(int i=0; i<10; i++){
    //     v.push_back(i);
    // }
    // for_each(v.begin(), v.end(), print01);//普通函数函数名
    for_each(v.begin(), v.end(), print02());//仿函数函数对象

}

/*
搬运容器到另一个容器中:
transform(iterator beg1, iterator end1, iterator beg2, _func);
beg1 源容器开始迭代器
end1 源容器结束迭代器
beg2 目标容器开始迭代器
_func 函数或者函数对象
*/

class Transform{
public:
    int operator()(int x){
        // return x;//不做操作直接返回原数据
        return x + 1;
    }
};

void test02(){
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2;//目标容器需要提前开辟空间,否则搬运不进去
    v2.resize(v1.size());

    transform(v1.begin(), v1.end(),v2.begin(),Transform());

    for_each(v2.begin(), v2.end(), print02());
}

//2、常用的查找算法 
/**
find //查找元素
find_if //按条件查找元素
adjacent_find //查找相邻重复元素
binary_search //二分查找法
count //统计元素个数
count_if //按条件统计元素个数
 */

/*
find(iterator beg, iterator end, value);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
*/

class Person{
public:
    int m_age;
    string m_name;

    Person(int age, string name):m_age(age),m_name(name){

    }

    //find底层不知道如何比较自定义数据类型的元素大小 count同理需要重载
    bool operator==(const Person & p){
        if(this->m_age == p.m_age){ // && this->m_name == p.m_name){
            return true;
        }else return false;
    }

};

void test03(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it = find(v.begin(), v.end(),5);
    if(it == v.end()){
        cout << "It is not found" << endl;//未找到
    }else{
        cout << "The number is " << *it << endl;
    }

    cout << "====================" << endl;

    Person p1(10,"lishu");
    Person p2(18,"yanming");
    Person p3(15,"pengdaoming");

    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);

    //find查找自定义数据类型
    vector<Person>::iterator it1 = find(v1.begin(), v1.end(),p3);
    if(it1 == v1.end()){
        cout << "Person is not found" << endl;//未找到
    }else{
        cout << "The person is " << it1->m_name <<  " and age is " << it1->m_age << endl;
    }


}

/*
find_if(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 函数或者谓词（返回bool类型的仿函数）
*/
class Findif_over5{
public:
    bool operator()(int val){
        return val > 5;
    }
};

bool Findif_AgeOver18(const Person & p){
    return p.m_age >= 18;
}

void test04(){
    //1.查找内置的数据类型
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    vector<int>::iterator it = find_if(v.begin(), v.end(),Findif_over5());
    if(it == v.end()){
        cout << "Over 5 is not found" << endl;//未找到
    }else{
        cout << "The overing 5 number is " << *it << endl;
    }

    cout << "====================" << endl;

    //2.查找自定义数据类型

    Person p1(10,"lishu");
    Person p2(18,"yanming");
    Person p3(15,"pengdaoming");

    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);

    vector<Person>::iterator it1 = find_if(v1.begin(), v1.end(),Findif_AgeOver18);
    if(it1 == v1.end()){
        cout << "Person age overing 18 is not found" << endl;//未找到
    }else{
        cout << "The person is " << it1->m_name <<  " and age is " << it1->m_age << endl;
    }

}

/*
adjacent_find(iterator beg, iterator end);
// 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
// beg 开始迭代器
// end 结束迭代器
*/

void test05(){
    vector<int> v = {1,2,3,4,5,5,6,7,8}; //查找第一个相邻数字的迭代器位置
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if(it == v.end()){
        cout << "It is not found" << endl;//未找到
    }else{
        cout << "The number is " << *it << endl;//面试常见的算法
    }
}


/*
bool binary_search(iterator beg, iterator end, value);
// 查找指定的元素，查到 返回true 否则false
// 注意: 在无序序列中不可用
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
*/

void test06(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};//二分查找法适用于有序序列
    bool b = binary_search(v.begin(), v.end(),2);
    if(b){
        cout << "2 is exit" << endl;
    }else{
        cout << "2 is not found" << endl;//未找到
    }
}

/*
count(iterator beg, iterator end, value);
// 统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// value 统计的元素
*/

void test07(){
    //1.内置数据类型
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,5,5};//二分查找法适用于有序序列
    int num = count(v.begin(), v.end(),5);
    if(num > 0){
        cout << "5 has " << num << endl;
    }else{
        cout << "5 is not found" << endl;//未找到
    }
    cout << "================================================" << endl;

    Person p1(10,"lishu");
    Person p2(18,"yanming");
    Person p3(15,"pengdaoming");
    Person p4(15,"liming");
    Person p5(15,"daodao");

    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);

    cout << "number of age is same with PDM has " << count(v1.begin(), v1.end(),p3) << " number" << endl;

}

/*
count_if(iterator beg, iterator end, _Pred);
// 按条件统计元素出现次数
// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词
*/

bool countAge15(const Person &p){
    return p.m_age == 15;
}

void test08(){

    Person p1(10,"lishu");
    Person p2(18,"yanming");
    Person p3(15,"pengdaoming");
    Person p4(15,"liming");
    Person p5(15,"daodao");

    vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);

    cout << "number of age is 15 person is " << count_if(v1.begin(), v1.end(),countAge15);

}

int main() {
    test08();
    return 0;
}
