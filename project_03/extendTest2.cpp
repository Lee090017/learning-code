/*
 * @Author: your name
 * @Date: 2022-04-18 17:21:29
 * @LastEditTime: 2022-04-18 21:47:33
 * @LastEditors: Please set LastEditors
 * @Description: ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_03\extendTest2.cpp
 */

#include<iostream>
#include<string>
using namespace std;

class A{
public:
    int a = 100;

    A(){
        cout << "A �Ĺ��캯��" << endl;
    }

    ~A(){
        cout << "A ����������" << endl;
    }

    void func(){
        cout << "�����function()" << endl;
    }

    void func(int){
        cout << "�����function(int)" << endl;
    }

protected:
    int b;
private:
    int c;
};

//�̳��й����������˳��
/*
    �ȹ��츸�ף��ٹ������
    ������֮
*/
//�̳�ͬ����Ա����ʽ
class B:public A{
    /*
    public:
        int a;
    protected:
        int b;
    ���ɷ���
        int c;

    */
public:
    int a = 200;
    int aa;

    B(){
        cout << "B �Ĺ��캯��" << endl;
    }

    ~B(){
        cout << "B ����������" << endl;
    }

    // void func(){
    //     cout << "�����function()" << endl;
    // }

    void func(){
        cout << "�����function()" << endl;
        a = 10;
        b = 10;
        // c = 10;//˽�г�Ա�޷�����
    }
};

void testB(){
    B b;
    // b.b  =10;//����Ȩ�������޷�����
}

class C:protected A{
    /*
    protected:
        int a;
        int b;
    ���ɷ���
        int c;

    */
public:

    void func(){
        a = 10;
        b = 10;
        // c = 10;//˽�г�Ա�޷�����
    }
};

void testC(){
    C c;
    // c.a = 10;//����Ȩ�������޷�����
    // c.b = 10;
}

class D:private A{
    /*
    private:
        int a;
        int b;
    ���ɷ���
        int c;

    */
public:
    void func(){
        a = 10;
        b = 10;
        // c = 10;//˽�г�Ա�޷�����
    }
};



int main(){
    // A a;
    B b;
    // C c;
    //���������еķǾ�̬��Ա�������Խ�������̳���ȥ������˽������(������)
    cout << "size of son is " << sizeof(b) << endl;//20
    cout << "==================" << endl;
    cout << "ͬ�����������a��" << b.a << endl;//200
    //������������Ҫ���ʸ�������е�ͬ����Ա����Ҫ��������
    cout << "ͬ�����������a��" << b.A::a << endl;//100
    cout << "====================" << endl;
    b.func();//����
    b.A::func();//���� �����ͬ����Ա��������
    b.A::func(18);//����  ����Ҳ��Ҫ������



    return 0;
}
