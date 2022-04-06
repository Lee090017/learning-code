/*
 * @Author: your name
 * @Date: 2022-04-04 20:37:17
 * @LastEditTime: 2022-04-06 16:06:08
 * @LastEditors: Please set LastEditors
 * @Description: 数据的输入
 * @FilePath: \learningCode\project_01\InputTest.cpp
 */

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	bool flag = 1;
	if (flag)
	{
		cout << "Please input a number:" << endl;//err
	}
	int x;
    bool y;
	cin >> x;
	cout << oct << x << endl;
	cout << dec <<  x << endl;
	cout << hex << x << endl;
	cout << "Please input a boolean:"<<endl;
	cin >> y;
	cout << boolalpha << y << endl;
	float f = 3.14f;
	cout << "Please input a float:"<<endl;
	cin >> f;
	cout << f << endl;
	cout << "Please input a string:"<<endl;
	string str = "";
	cin >> str;
	cout << str << endl;
	return 0;
}
