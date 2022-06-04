/*
 * @Author: your name
 * @Date: 2022-04-18 17:21:29
 * @LastEditTime: 2022-04-18 21:47:33
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_03\extendTest2.cpp
 */

#include<iostream>
#include<string>
using namespace std;

class A{
public:
    int a = 100;

    A(){
        cout << "A 的构造函数" << endl;
    }

    ~A(){
        cout << "A 的析构函数" << endl;
    }

    void func(){
        cout << "父类的function()" << endl;
    }

    void func(int){
        cout << "父类的function(int)" << endl;
    }

protected:
    int b;
private:
    int c;
};

//继承中构造和析构的顺序
/*
    先构造父亲，再构造儿子
    析构反之
*/
//继承同名成员处理方式
class B:public A{
    /*
    public:
        int a;
    protected:
        int b;
    不可访问
        int c;

    */
public:
    int a = 200;
    int aa;

    B(){
        cout << "B 的构造函数" << endl;
    }

    ~B(){
        cout << "B 的析构函数" << endl;
    }

    // void func(){
    //     cout << "子类的function()" << endl;
    // }

    void func(){
        cout << "子类的function()" << endl;
        a = 10;
        b = 10;
        // c = 10;//私有成员无法访问
    }
};

void testB(){
    B b;
    // b.b  =10;//保护权限类外无法访问
}

class C:protected A{
    /*
    protected:
        int a;
        int b;
    不可访问
        int c;

    */
public:

    void func(){
        a = 10;
        b = 10;
        // c = 10;//私有成员无法访问
    }
};

void testC(){
    C c;
    // c.a = 10;//保护权限类外无法访问
    // c.b = 10;
}

class D:private A{
    /*
    private:
        int a;
        int b;
    不可访问
        int c;

    */
public:
    void func(){
        a = 10;
        b = 10;
        // c = 10;//私有成员无法访问
    }
};



int main(){
    // A a;
    B b;
    // C c;
    //父类中所有的非静态成员变量属性将被子类继承下去，包括私有属性(被隐藏)
    cout << "size of son is " << sizeof(b) << endl;//20
    cout << "==================" << endl;
    cout << "同名变量子类的a是" << b.a << endl;//200
    //如果子类对象需要访问父类对象中的同名成员，需要加作用域
    cout << "同名变量父类的a是" << b.A::a << endl;//100
    cout << "====================" << endl;
    b.func();//子类
    b.A::func();//父类 父类的同名成员将被隐藏
    b.A::func(18);//父类  重载也需要作用域



    return 0;
}
