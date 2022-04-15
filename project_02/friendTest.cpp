/*
 * @Author: your name
 * @Date: 2022-04-13 15:47:06
 * @LastEditTime: 2022-04-13 16:52:48
 * @LastEditors: Please set LastEditors
 * @Description: ��Ա
 * @FilePath: \learningCode\project_02\friendTest.cpp
 */

/**
 * @file friendTest.cpp
 * @author your name (you@domain.com)
 * @brief ��Ԫ��Ŀ�ľ�����һ������������ ������һ������˽�г�Ա
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
using namespace std;

class Buildings;//��Ҫ��ǰ����

class Girlfriend{
public:
    Girlfriend();

    void visit1();//��visit�������Է���Building��˽�г�Ա
    void visit2();//��visit���������Է���Building��˽�г�Ա

private:
    Buildings * g_building;

};

class Buildings{

    //������Ա���ú�����Buildings�ĺ����ѣ����Է���Buildings�е�˽�г�Ա
    friend void goodfriend(Buildings *building);
    friend class GoodGay;
    friend void Girlfriend::visit1();
    

public:
    string m_Sitingroom;

    Buildings(){
        m_Sitingroom = "����";
        m_Bedroom = "����";
    }

    Buildings(string s,string b);

private:
    string m_Bedroom;

};

//����д��Ա����
Buildings::Buildings(string s,string b){
    m_Sitingroom = s;
    m_Bedroom = b;
}


class GoodGay{
public:
    Buildings * building;

    GoodGay();

    void visit();

};

GoodGay::GoodGay(){
    building = new Buildings;
}

//2.������Ա
void GoodGay::visit(){
    cout << "���������ڷ���" << building->m_Sitingroom <<endl;
    cout << "���������ڷ���" << building->m_Bedroom <<endl;//��Ҫ���ø���Ϊ��Ա��
}

//1.ȫ�ֺ�������Ա
void goodfriend(Buildings *building){
    cout << "���������ڷ���" << building->m_Sitingroom <<endl;
    cout << "���������ڷ���" << building->m_Bedroom <<endl;//��Ҫ���ø�ȫ�ֺ���Ϊ��Ա
}


Girlfriend::Girlfriend(){
    g_building = new Buildings("����","������");
}

//3.��Ա��������Ա
void Girlfriend::visit1(){
    cout << "���������ڷ���" << g_building->m_Sitingroom <<endl;
    cout << "���������ڷ���" << g_building->m_Bedroom <<endl;
}

void Girlfriend::visit2(){
    cout << "���������ڷ���" << g_building->m_Sitingroom <<endl;
    // cout << "���������ڷ���" << building->m_Bedroom <<endl;
}

void test01(){
    Buildings b;
    goodfriend(&b);
}

void test02(){
    GoodGay g;
    g.visit();
}

void test03(){
    Girlfriend g;
    g.visit1();
}

int main() {
    test01();
    cout << "====================" << endl;
    test02();
    cout << "====================" << endl;
    test03();

    return 0;
}
