/*
 * @Author: your name
 * @Date: 2022-04-18 17:20:47
 * @LastEditTime: 2022-04-18 17:20:47
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_03\extendTest1.cpp
 */
/*
 * @Author: your name
 * @Date: 2022-04-18 17:08:22
 * @LastEditTime: 2022-04-18 17:17:52
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\extendTest.cpp
 */

/**
 * @file extendTest.cpp
 * @author your name (you@domain.com)
 * @brief 继承
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
using namespace std;

class BasePage{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};

class Java : public BasePage{
public:
    void content(){
        cout << "Java学科视频" << endl;
    }
};

class Cpp : public BasePage{
public:
    void content(){
        cout << "C++学科视频" << endl;
    }
};

//语法：class 子类 : 继承方式 父类
//继承方式：公共继承、保护继承、私有继承

int main(){
    Java j;
    j.header();
    j.left();
    j.content();
    j.footer();

    return 0;
}

