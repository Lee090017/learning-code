/*
 * @Author: your name
 * @Date: 2022-05-25 16:07:55
 * @LastEditTime: 2022-05-25 17:05:24
 * @LastEditors: Please set LastEditors
 * @Description: 复习容器 string vector
 * @FilePath: \learningCode\project_05\reviewTest1.cpp
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * @brief 
 * 复习string容器
 */
void test01(){
    string str1;
    str1 = "hello";
    str1 += " world";
    str1.append("!");

    cout << "str1: " << str1 << endl;

    int i1 = str1.find("ll");
    cout << "i1: " << i1 << endl;

    str1.replace(1,2," 00 ");
    cout << "str1: " << str1 << endl;

    string str2 = str1;
    string str3 = "abc";
    int c1 = str2.compare(str3);
    if(c1 == 0){
        cout << "str2 = str3" << endl;
    }else if(c1 > 0){
        cout << "str2 > str3" << endl;
    }else {
        cout << "str2 < str3" << endl;
    }

    //存取
    for(int i=0;i<str3.size();i++){
        // cout << str3[i] << " ";
        cout << str3.at(i) << " ";

    }
    cout << endl;

    str3.insert(1,3,'0');
    cout << "str3:" << str3 << endl;

    str3.erase(1,3);
    cout << "str3:" << str3 << endl;

    string str4 = str3.substr(1,2);
    cout << "str4:" << str4 << endl;
    return;
}

//迭代器打印vector数组
void printVector(vector<int>& v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * @brief 
 * 复习vector容器
 * 动态数组
 */
void test02(){
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    // printVector(v1);

    vector<int> v2(v1.begin(),v1.end());
    // printVector(v2);

    vector<int> v3;
    // v3 = v2;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);

    cout << "capacity = " << v3.capacity() << endl;
    cout << "size = " << v3.size() << endl;

    v3.resize(15);
    cout << "capacity = " << v3.capacity() << endl;
    cout << "size = " << v3.size() << endl;

    v2.pop_back();//尾删
    vector<int>::iterator it2 = v2.begin();
    // v2.insert(it2+1,2,10);
    // printVector(v2);
    v2.erase(it2+1,it2+3);
    printVector(v2);

    v2.clear();

    if(v2.empty()) cout << "v2 is empty" << endl;

    cout << v1.front() << endl;
    cout << v1.back() << endl;//返回元素

    //互换容器
    printVector(v1);
    printVector(v3);
    v1.swap(v3);
    printVector(v1);
    printVector(v3);

    //预留空间
    vector<int> v4;
    v4.reserve(100);
    cout << "capacity = " << v4.capacity() << endl;
    cout << "size = " << v4.size() << endl;

}

int main(){
    test02();

    return 0;
}