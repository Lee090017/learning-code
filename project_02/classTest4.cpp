/*
 * @Author: your name
 * @Date: 2022-04-12 21:08:41
 * @LastEditTime: 2022-04-12 21:46:57
 * @LastEditors: Please set LastEditors
 * @Description: ��ʼ���б��������Ϊ���Ա����̬��Ա����
 * @FilePath: \learningCode\project_02\classTest4.cpp
 */

#include <iostream>
using namespace std;

//�������Ϊ�����Ա
class Phone{
public:
    string p_name;

    Phone(string a) : p_name(a){

    }
};

class Person{
public:
    string m_name;
    int m_age;
    int m_height;
    Phone m_phone;//�ֻ�

    //��ͳ�ĳ�ʼ����ʽ
    // Person(string name, int age, int height){
    //     m_name = name;
    //     m_age = age;
    //     m_height = height;
    // }

    //��ʼ���б�
    Person():m_name("Mary"),m_age(10),m_height(180),m_phone("HuaWei"){
        
    }

    //��ʽת�� Phone m_phone = "xxxx"; Phone m_phone = Phone("xxxx"); 
    Person(string a, int b, int c, string d):m_name(a),m_age(b),m_height(c),m_phone(d){
        
    }

    //��̬��Ա����
    //���еĶ�����ͬһ������
    //��̬��Ա����ֻ�ܷ��ʾ�̬��Ա
    //�þ�̬��Ա����ͨ�����������������

    static void func(){
        cout << "static void func()���� " << count << " ��" << endl;
        count++;
        // m_name = "leege";
    }

    //��̬��Ա
    static int count;

private:
    static void pfunc(){
        cout << "private static void func()���� " << endl;
    } 


};

int Person::count = 0;//��̬��Ա��ʼ��


void test01(){
    Person p;
    cout << p.m_name << endl;
    cout << p.m_age << endl;
    cout << p.m_height << endl;
}

void test02(){
    Person p("John",45,168,"iPhone");
    cout << p.m_name << endl;
    cout << p.m_age << endl;
    cout << p.m_height << endl;
    cout << p.m_phone.p_name << endl;
}

void test03(){
    Person p1;
    p1.func();
    Person::func();//��������
    // p1.pfunc();//������ʲ���˽�о�̬��Ա����
}

int main(){

    //��ʼ���б�
    //���캯��():����1(ֵ1)������2(ֵ2)������{}
    test01();
    cout << "====================" << endl;
    test02(); //
    cout << "====================" << endl;
    test03(); //

    return 0;
}