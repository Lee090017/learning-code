/*
 * @Author: your name
 * @Date: 2022-04-21 21:39:03
 * @LastEditTime: 2022-04-22 21:45:04
 * @LastEditors: Please set LastEditors
 * @Description: 文件操作
 * @FilePath: \learningCode\project_03\fileTest..cpp
 */
#include<iostream>
#include<fstream>//头文件包含
#include<string>
using namespace std;
/*
  写操作 ofstream
  读操作 ifstream
  读写操作 fstream

写文件步骤如下：

1.包含头文件
#include <fstream>
2.创建流对象
ofstream ofs;
3.打开文件
ofs.open(“文件路径”,打开方式);  ios::in ios::out ios::binary ios::ate ios::app ios::trunc
二进制写需要组合：ios::binary | ios::out
4.写数据
ofs << “写入的数据”;
5.关闭文件
ofs.close();
*/

//写文件
void test01(){
    ofstream ofs;//创建对象 output file stream
    ofs.open("test.txt",ios::out);//指定打开方式
    ofs << "姓名：张三" <<endl;
    ofs << "性别：男" <<endl;
    ofs << "年龄：18" <<endl;//写内容
    ofs.close();//关闭文件

}

/*----------------------------------------------------------------
读文件

读文件步骤如下：
1.包含头文件
#include <fstream>
2.创建流对象
ifstream ifs;
3.打开文件并判断文件是否打开成功
ifs.open(“文件路径”,打开方式);
4.读数据
四种方式读取
5.关闭文件
ifs.close();

*/
void test02(){
    ifstream ifs;//创建输入流
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" <<endl;
        return;
    }
    //方式一
    // char buf[1024] = {0};
    // while(ifs >> buf){//一行一行读
    //     cout << buf << endl;
    // }
    //方式二
    // char buf[1024] = {0};
    // while(ifs.getline(buf,sizeof(buf))){//一行一行读
    //     cout << buf << endl;
    // }
    //方式三
    // string buf;
    // while (getline(ifs,buf))//一行一行读
    // {
    //     cout << buf << endl;
    // }
    //方式三
    char c;
    while(( c = ifs.get()) != EOF)//EOF end of file 一行一行读
    {
        cout << c;
    }
    ifs.close();
}


//二进制写
class Person{
public:
  char m_Name[64];//使用C字符串
  int m_Age;

};

void test03(){
    ofstream ofs;//可以将二步与一步合并
    ofs.open("person.txt", ios::binary | ios::out);
    Person p = {"John",45};
    ofs.write((const char *)&p,sizeof(Person));//函数原型需要const char *
    ofs.close();
}

//二进制读
void test04(){
    ifstream ifs;
    ifs.open("person.txt", ios::binary | ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
    }
    Person p;
    ifs.read((char *)&p,sizeof(Person));
    cout << p.m_Name << endl;
    cout << p.m_Age << endl;
    ifs.close();
}

int main(){
    test04();

    return 0;
}