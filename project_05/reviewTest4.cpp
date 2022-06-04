/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-26 16:26:59
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-26 16:56:36
 * @FilePath: \learningCode\project_05\reviewTest4.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file reviewTest4.cpp
 * @author your name (you@domain.com)
 * @brief 复习 set 和 multiset 和 pair对组
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<set>
#include<string>
using namespace std;

//仿函数
class myCompare{
public:
    bool operator()(int a, int b){
        return a>b;
    }    
};

void printSet(const set<int> & s) {
    if(s.empty()){
        cout << "set is empty" << endl;
        return;
    }else{
        for(set<int>::const_iterator i = s.begin();i!=s.end();i++){
            cout << *i << " ";
        }
        cout << endl;
    }
}

void test01(){
    set<int> s1 = {1,5,3,2,4,1};
    printSet(s1);//自动排序,滤除重复元素

    s1.insert(10);
    s1.insert(7);

    set<int>::iterator it1 = s1.begin();
    set<int>::iterator it2 = s1.erase(it1);//返回下一个元素的迭代器

    printSet(s1);
    cout << "it2:" << *it2 << endl;

    //查找
    set<int>::iterator it3 = s1.find(4);
    cout << "it3:" << &it3 << endl;

    cout << "count:" << s1.count(10) << endl;

    multiset<int> m1 = {1,5,3,2,4,1};
    cout << m1.size() << endl;//可以插入重复数据

    //仿函数自定义排序
    set<int,myCompare> s2 = {1,5,3,2,4,1};
    for(set<int,myCompare>::iterator it = s2.begin(); it != s2.end();it++){
        cout << *it << " ";
    }
    cout << endl;//


}

//pair对组
void test02(){
    pair<string,int> p1("lee",10);
    cout << p1.first << " " << p1.second << endl;

    pair<string,int> p2 = make_pair("Don",77);
    cout << p2.first << " " << p2.second << endl;
}

int main(){
    test02();


    return 0;
}