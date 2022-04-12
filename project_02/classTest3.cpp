/*
 * @Author: your name
 * @Date: 2022-04-12 17:04:20
 * @LastEditTime: 2022-04-12 21:07:29
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\classTest3.cpp
 */

/**
 * @file classTest3.cpp
 * @author your name (you@domain.com)
 * @brief ����ĳ�ʼ��������
 * @version 0.1
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */
#include<iostream>
#include<string>
using namespace std;

//���캯������������ �������ṩ�Դ��Ŀ�ʵ��
//���캯������Ҫ�������ڴ�������ʱΪ����ĳ�Ա���Ը�ֵ�����캯���ɱ������Զ����ã������ֶ����á� ����(){} ��дvoid
//������������Ҫ�������ڶ�������ǰϵͳ�Զ����ã�ִ��һЩ�������� ~����(){}

/**
 * ���캯���ĵ��ù���
Ĭ������£�c++���������ٸ�һ�������3������

1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)

2��Ĭ����������(�޲Σ�������Ϊ��)

3��Ĭ�Ͽ������캯���������Խ���ֵ����

���캯�����ù������£�

����û������вι��캯����c++�����ṩĬ���޲ι��죬���ǻ��ṩĬ�Ͽ�������

����û����忽�����캯����c++�������ṩ�������캯��
 * 
 */

class Person{
public:
    //���캯��
    /**
     * @brief Construct a new Person object
     * ���캯���ķ���
     * ��������Ϊ�� �вι�����޲ι���
     * �����ͷ�Ϊ�� ��ͨ����Ϳ�������
     */
    Person(){
        cout << "�޲ι��캯���ĵ���" << endl;
    }

    Person(string name){
        m_name = name;
        cout << "�вι��캯���ĵ���" << endl;
    }

    Person(int age,int height){
        m_age = age;
        Height = new int(height);
        cout << "�вι��캯���ĵ���" << endl;
    }

    //�������캯��
    /*
        ����ʱ��
        ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
        ֵ���ݵķ�ʽ��������������ֵ
        ֵ��ʽ���ؾֲ�����

    */

   //�������������ڴ��ظ��ͷŵ�����
    Person(const Person &p){
        m_age = p.m_age;
        // Height = p.Height;//ǳ����(������Ĭ��ʵ�ָ��д���)
        //���
        Height = new int(*p.Height);//���¿��ٶ����ڴ�
        cout << "�������캯���ĵ���" << endl;
    }

    //�������� �����������ͷ�
    ~Person(){
        //��������
        if(Height != NULL){
            delete Height;
            Height = NULL;
        }
        cout << "���������ĵ���" << endl; 
    }

    string getName(){
        return m_name;
    }

    int getAge(){
        return m_age;
    }

    int getHeight(){
        return *Height;
    }
    
private:
    string m_name;
    int m_age;
    int * Height;//�������ݴ��ڶ���

};

void test01(){
    Person p1("John");
    cout << p1.getName() << endl;
    Person p2(p1);
    cout << p2.getName() << endl;

}

void test02(){
    Person p1(18,172);
    cout << p1.getAge() << " " << p1.getHeight() << endl;
    Person p2(p1);
    cout << p2.getAge() << " " << p2.getHeight() << endl;

}

int main(){
    //���캯���ĵ���

    //���ŷ�
    // Person p1;
    // Person p2("lishu");
    // Person p3(p1);

    //��ʾ��
    // Person p4 = Person("wang");
    // Person("wangwu");//�������� �ص㣺��ǰִ�н�����ֱ���ͷ�
    //�����ÿ������캯����ʼ���������󣬱�������ΪPerson (p)  ===>  Person p;
    
    //��ʽת����
    // Person p5 = p1;//��������

    cout << "====================" << endl;
    //�����ǳ����
    test02();//ǳ������ɶ������ڴ��ظ��ͷţ�������ڶ������¿���һ���ڴ�

    system("pause");
    return 0;
}