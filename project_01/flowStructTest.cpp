/*
 * @Author: your name
 * @Date: 2022-04-06 16:22:07
 * @LastEditTime: 2022-04-06 17:38:22
 * @LastEditors: Please set LastEditors
 * @Description: 程序流程结构
 * @FilePath: \learningCode\project_01\flowStructTest.cpp
 */
#include<iostream>
using namespace std;
int main(){

    //if条件语句
    int score = 100;
    cout << "Please input score: " << endl;
    // cin >> score;
    if(score >= 600){
        cout << "You get a A" << endl;
    }else if(score < 600 && score >= 500){
        cout << "You get a B" << endl;
    }else{
        cout << "You get a C" << endl;
    }
    cout << "======================" << endl;

    //三目运算符 表达式1 ? 表达式2 ： 表达式3
    int a = 1;
    int b = 2;
    int c;
    c = a > b ? a : b;// c取a和b中的最大值
    cout << "c = " << c << endl;
    // 三目运算符返回的是变量，可以继续赋值
    (a > b ? a : b) = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "======================" << endl;

    //switch执行多条件分支语句
    //switch只能是整型或者字符型，不能是一个区间，但是其执行效率高
    int grade = 10;
    cout << "Please input grade: " << endl;
    // cin >> grade;
    switch(grade){
        case 10 :
            cout << "This movie is perfect" << endl;
            break;
        case 9 :
            cout << "This movie is great" << endl;
            break;
        case 8 :
            cout << "This movie is nice" << endl;
            break;
        case 7 :
            cout << "This movie is general" << endl;
            break;
        default :   
            cout << "This movie is boring" << endl;
            break;

    }
    cout << "======================" << endl;

    //while语句
    //打印9*9乘法表
    int i1 = 1; //行
    while(i1 < 10){
        int j1 = 1;//列
        int j2 = i1;
        while(j1 < j2){
            cout << j1 << "x" << j2 << "=" << j1*j2 << "\t";
            j1++;
        }
        cout << j1 << "x" << j2 << "=" << j1*j2 << endl;
        i1++;
    }

    //do-while语句，do-while将先执行一次循环语句在判断
    cout << "======================" << endl;
    int i2 = 0;
    do{
        i2++;
        cout << i2 << endl;
    }while(i2 <10);

    //水仙花数
    cout << "======================" << endl;
    int n1 = 100;
    do{
        int a = n1 % 10;
        int b = n1 / 10 % 10;
        int c = n1 / 100;
        if(a*a*a + b*b*b + c*c*c == n1){
            cout << n1 << endl;
        }
        n1++;
    }while(n1<=999);
    cout << "======================" << endl;

    //for循环
    //敲桌子 含7或者7的倍数跳过
    for(int i=1;i<=100;i++){
        int a = i/10;
        int b = i%10;
        if(a == 7 || b == 7 || i%7 == 0){
            cout << i << endl;
        }
    }
    cout << "======================" << endl;

    //break跳转语句
    //1.出现在switc语句中
    //2.出现在循环语句中
    //3.出现在嵌套循环语句中

    //continue跳转语句
    for(int i = 1;i < 100 ; i++){
        if(i%2==0){
            continue;
        }
        cout << i << endl;
    }
    cout << "======================" << endl;

    //goto跳转语句  无条件跳转  goto 标记;
    cout << "1" << endl;
    goto FLAG;
    cout << "2" << endl;
    cout << "3" << endl;
    FLAG:
    cout << "4" << endl;



    return 0;
}
