/*
 * @Author: your name
 * @Date: 2022-04-04 20:37:17
 * @LastEditTime: 2022-04-04 21:26:29
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_01\InputTest.cpp
 */

#include<iostream>
#include<stdlib.h>
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
	return 0;
}
