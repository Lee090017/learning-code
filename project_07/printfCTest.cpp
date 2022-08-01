/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 15:07:46
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-02 15:26:11
 * @FilePath: \learningCode\project_07\printfCTest.cpp
 * @Description: C++ 之printf函数
 */
#include<iostream>
using namespace std;
/*
1.整数
%d  //输出十进制
%o  //输出无符号整数的八进制
%x  //输出无符号整数的十六进制(字母小写)
%X	//输出无符号整数的十六进制(字母大写)

%5d		//输出宽度为5(右对齐)
%-5d	//输出宽度为5(左对齐)
%+5d	//输出宽度为5(输出符号)
%05d	//输出宽度为5(前面补0，而不是空格)
%#o		//输出八进制前的0(进制前的标识符)
%#x		//输出十六进制前的0x(进制前的标识符)

2.小数
%f		//输出小数(保留到小数点后6位)
%e,E	//科学计数法，保留到小数点后6位(1.234560e+02)
%g,G	

%10f	//输出宽度为10(多出不会被截断)
%10.3f	//输出宽度为10(保留到小数点后3位)

3.字符
%c		//输出单个字符
%s		//输出字符串

4.指针
%p		//输出指针指向的地址
*/


int main(){
    //整数
    int a = 12;
    
    printf("%d\n",a);//12

    printf("%o\n",a);//14
    
    printf("%x\n",a);//c

    printf("%05d\n",a);//00012

    printf("%#x\n",a);//0xc

    cout << "===================="  << endl;
    
    //小数

    float b = 1.23;

    printf("%f\n",b);//

    printf("%10f\n",b);//位数为10

    printf("%.5f\n",b);//小数点后5位小数

    b = 12346789;

    printf("%g\n",b);//自动取占位小的那部分

    cout << "====================" << endl;

    //字符
    int c = 65;

    printf("%d\n",c);//65
    printf("%c\n",c);//A

    char * s = "lishu";
    printf("%s\n",s);

    //指针
    int x = 1;
    int * p = &x;
    printf("address is %p\n",p);

    return 0;
}