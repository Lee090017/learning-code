/*
 * @Author: your name
 * @Date: 2022-04-05 16:31:39
 * @LastEditTime: 2022-04-06 16:03:44
 * @LastEditors: Please set LastEditors
 * @Description: 数据类型
 * @FilePath: \learningCode\project_01\keyWords.cpp
 */
#include<iostream>
#include<string> //使用C++风格的字符串需要添加该头文件
#include<cstring> 
using namespace std;
int main(){
    
    // 给变量分配一个合适的内存空间

    //整型
    short a = 2; //短整型 2字节 (-2^15 ~ 2^15-1)
    int b = 10; //整型 4字节 (-2^31 ~ 2^31-1)
    long c = 20; //长整型 Windows为4字节，Linux为4字节(32位)，8字节(64位) (-2^31 ~ 2^31-1)
    long long d = 100; //长长整型 8字节 	(-2^63 ~ 2^63-1)

    //利用sizeof关键字可以统计数据类型所占内存大小 sizeof(数据类型/变量)
    cout << "short's size is " << sizeof(a) << endl;
    cout << "int's size is " << sizeof(b) << endl;
    cout << "long's size is " << sizeof(c) << endl;
    cout << "long long's size is " << sizeof(d) << endl;

    //实型
    //float 4字节 7位有效数字
    //double 8字节 15-16位
    float f1 = 1234567.1f;//默认编辑器将3.14作为double，需要添加f
    double d1 = 3.14;

    cout << "f1 = " << f1 << endl;

    //科学计数法
    float f2 = 3e2;// 3 * 10^2
    cout << "f2 = " << f2 << endl;

    //字符型
    char ch1 = 'a'; // 1个字节 97 'A' = 65
    cout << "ch1 = " << ch1 << endl;
    cout << "ch1 = " << (int)ch1 << endl;

    //转义字符
    // \r 回车 ； \n 换行 ； \\ 反斜杠 ； \t 水平制表
    cout << "====================" << endl;
    cout << "abcd\ref" << endl;
    cout << "====================" << endl;
    cout << "abcd\nef" << endl;
    cout << "====================" << endl;
    cout << "abcd\\ef" << endl;
    cout << "====================" << endl;
    cout << "abcd\tef" << endl;
    cout << "====================" << endl;


    //字符串
    //1.C风格的字符串 char 变量名[] = "字符串值"；
    char str1[] = "ABC";

    //2.C++ 风格字符串 string
    string str2 = "ABC";
    cout << str1 << endl;    
    cout << str2 << endl;    
    if(str1 == str2){
        cout << "str1==str2" << endl;    
    }

    // if(strcmp(str1, str2) == 0){
    //     cout << "str1==str2" << endl;    
    // }

    //布尔类型 1个字节
    bool b1 = true;
    bool b2 = 0;
    cout << b1 << endl;
    cout << b2 << endl;
    

    system("pause");
    return 0;
}