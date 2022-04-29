/*
 * @Author: your name
 * @Date: 2022-04-27 17:35:24
 * @LastEditTime: 2022-04-28 16:04:49
 * @LastEditors: Please set LastEditors
 * @Description: string容器
 * @FilePath: \learningCode\project_05\stringTest1.cpp
 */
/**
 * 
 * char *是一个指针
 * string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器
 * 
 * 
 * 
 * 
 * */

#include<iostream>
#include<string>
using namespace std;

//string的构造函数
/**
 * @brief 
 * 
 * string(); //创建一个空的字符串 例如: string str;
 * string(const char* s); //使用字符串s初始化
 * string(const string& str); //使用一个string对象初始化另一个string对象
 * string(int n, char c); //使用n个字符c初始化
 * 
 */


void test01(){
    string s1;//默认构造

    const char * str = "hello world";//C语言风格字符串
    string s2(str);

    cout << "s2 = " << s2 << endl;

    string s3(s2);//拷贝构造的形式

    cout << "s3 = " << s3 << endl;

    string s4(10,'a');

    cout << "s4 = " << s4 << endl;

}

//string的赋值操作
/**
 * @brief 
 * 
 * string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
 * string& operator=(const string &s); //把字符串s赋给当前的字符串
 * string& operator=(char c); //字符赋值给当前的字符串
 * string& assign(const char *s); //把字符串s赋给当前的字符串
 * string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
 * string& assign(const string &s); //把字符串s赋给当前字符串
 * string& assign(int n, char c); //用n个字符c赋给当前字符串
 * 
 */
void test02(){
    string str1;
    str1 = "hello world";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = 'a';
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hello C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hello C++",5);//赋值前5个字符
    cout << "str5 = " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    string str7;
    str7.assign(3,'w');//3个w
    cout << "str7 = " << str7 << endl;
}

//string的拼接操作
/**
 * @brief 
 * 
string& operator+=(const char* str); //重载+=操作符
string& operator+=(const char c); //重载+=操作符
string& operator+=(const string& str); //重载+=操作符
string& append(const char *s); //把字符串s连接到当前字符串结尾
string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s); //同operator+=(const string& str)
string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
 * 
 */
void test03(){
    string str1 = "I";
    str1 += " like game";
    cout << "str1 = " << str1 << endl;

    str1 += '!';
    cout << "str1 = " << str1 << endl;

    string str2 = "LoL DNF";
    str1 += str2;
    cout << "str1 = " << str1 << endl;

    string str3 = "I";
    str3.append(" love");
    cout << "str3 = " << str3 << endl;

    str3.append(" game over",5);
    cout << "str3 = " << str3 << endl;

    str3.append(str2);
    cout << "str3 = " << str3 << endl;

    str3.append(str2,4,3);//从4开始3个字符
    cout << "str3 = " << str3 << endl;

}

//string的查找和替换操作
/**
 * @brief 
 * 
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
 * 
 */
void test04(){
    string str1 = "abcdefgde";
    int pos1 = str1.find("de");
    if(pos1 == -1) cout << "未找到字符串" <<endl;
    cout << "pos1 = " << pos1 << endl;

    //find从左向右查 rfind查右向左查找
    int pos2 = str1.rfind("de");
    cout << "pos2 = " << pos2 << endl;

    //替换
    string str2 = " 000 ";
    str1.replace(1,2,str2);//从1开始的两个字符进行替换
    cout << "str1 = " << str1 << endl;

}

//string的比较
/**
 * @brief 
 * 
 * 字符串之间的比较 是按照字符的ASCII码进行对比的 =返回0 >返回1 <返回-1
int compare(const string &s) const; //与字符串s比较
int compare(const char *s) const; //与字符串s比较

== 与 compare的区别
只是单纯比较，用==，返回值是bool类型的true或false；
需要返回值判断的，等价于C语言的strcmp，用compare.
 * 
 */
void test05(){
    string str1 = "zello";
    string str2 = "hello";
    if(str1.compare(str2) == 0){
        cout << "str1 = str2" << endl;
    }else if(str1.compare(str2) > 0){
        cout << "str1 > str2" << endl;
    }else{
        cout << "str1 < str2" << endl;
    }

}

//string的存取
/**
 * @brief 
 * 
char& operator[](int n); //通过[]方式取字符
char& at(int n); //通过at方法获取字符
 * 
 */
void test06(){
    string str1 = "hello";

    cout << "str1 = " << str1 << endl;

    //通过[]访问
    for(int i = 0;i < str1.size();i++){
        cout << str1[i] << " ";
    }
    cout << endl;

    //通过at访问
    for(int i = 0;i < str1.size();i++){
        cout << str1.at(i) << " ";
    }
    cout << endl;

    //写操作
    str1[0] = 'x';
    cout << "str1 = " << str1 << endl;

    str1.at(1) = 'x';
    cout << "str1 = " << str1 << endl;
}

//string的插入与删除
/**
 * @brief 
 * 
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c); //在指定位置插入n个字符c
string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
 * 
 */
void test07(){
    string str1 = "hello";
    str1.insert(1,"111");
    cout << "str1 = " << str1 << endl;

    str1.erase(1,3);//从1开始删3个字符
    cout << "str1 = " << str1 << endl;

}

//string子串获取
/**
 * @brief 
 * 
string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
 * 
 */
void test08(){
    string str1 = "hello";
    string subStr = str1.substr(1,3);
    cout << "subStr = " << subStr << endl;

    //实用操作
    string email = "zhangsan@163.com";
    //获取用户名
    int pos = email.find('@');
    string name = email.substr(0,pos);
    cout << "Your name is " << name << endl;
}

int main(){
    test08();

    return 0;
}
