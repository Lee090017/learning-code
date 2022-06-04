/*
 * @Author: your name
 * @Date: 2022-04-19 16:58:01
 * @LastEditTime: 2022-04-20 16:58:48
 * @LastEditors: Please set LastEditors
 * @Description: �麯���������࣬��������������
 * @FilePath: \learningCode\project_03\polymorphismTest2.cpp
 */
#include <iostream>
#include <string>
using namespace std;

//��ʹ�ö�̬ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
//�����ʽ���������е�����������Ϊ���������ߴ�������

//������ �޷�ʵ��������
class AbstractClass{
public:
    //���麯��
    virtual void func() = 0;
};

class Son:public AbstractClass{
public:
    void func(){
        cout << "����ʵ�ָ��ി�麯��" << endl;
    }
};

class Animal{
public:
    virtual void speak() = 0;

    Animal(){
        cout << "Animal�Ĺ��캯��" << endl;
    }
    //����ָ��������ʱ����������������������������������������ж������ԣ���������ڴ�й©
    // virtual ~Animal(){//��Ϊ������
    //     cout << "Animal����������" << endl;
    // }

    //��������
    virtual ~Animal() = 0;

};

//����������Ҫ����
Animal::~Animal(){
    cout << "Animal����������" << endl;
}

class Cat:public Animal{
public:
    string * m_name;

    Cat(string name){
        cout << "Cat���캯��" << endl;
        m_name = new string(name);
    }

    void speak(){
        cout << *m_name << "è�ڽ�" << endl;
    }

    ~Cat(){
        if(m_name != NULL){
            cout << "Cat��������" << endl;
            delete m_name;
            m_name = NULL;
        }
    }
};

void test01(){
    Son s;
    s.func();

    AbstractClass * f = new Son;
    f->func();
}

void test02(){
    Animal * c = new Cat("Tom");
    c->speak();
    delete c;
}

int main(){
    test01();
    test02();
    return 0;	
}
