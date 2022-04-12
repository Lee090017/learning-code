/*
 * @Author: your name
 * @Date: 2022-04-12 16:28:22
 * @LastEditTime: 2022-04-12 17:02:13
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \learningCode\project_02\classTest2.cpp
 */

#include<iostream>
using namespace std;

/*----------------------------------------------------------------
struct 和 class的区别

*/

class class1{
    int m_A;//默认权限  私有
};

struct str1{
    int m_A;//默认权限 共有
};

//案例一：设计立方体
class Cube{
public:
    void setL(int L){
        m_L = L;
    }
    void setW(int W){
        m_W = W;
    }
    void setH(int H){
        m_H = H;
    }
    int getL(){
        return m_L;
    }
    int getW(){
        return m_W;
    }
    int getH(){
        return m_H;
    }
    int getVolume(){
        return m_L * m_W * m_H;
    }
    int getArea(){
        return m_L * m_W * 2 + m_L * m_H * 2 + m_H * m_W * 2;
    }
    //成员函数判断是否相等
    bool isEqual(Cube &c){
        if(m_L == c.getL() && m_W == c.getW() && m_H == c.getH()){
            return true;
        }
        return false;
    }
private:
    int m_L;
    int m_W;
    int m_H;
};

//利用全局函数判断两个立方体是否相等
bool isEqual(Cube &c1,Cube &c2){
    if(c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()){
        return true;
    }
    return false;
}


int main(){
    class1 C1;
    // C1.m_A = 10;
    struct str1 C2;
    C2.m_A = 10;

    Cube cube;
    cube.setL(10); 
    cube.setH(10); 
    cube.setW(10);
    cout << "cube's volume is " << cube.getVolume() << endl;
    cout << "cube's Area is " << cube.getArea() << endl;

    Cube another;
    another.setL(10); 
    another.setH(10); 
    another.setW(20);
    if(isEqual(cube,another)){
        cout << "c1 is same as c2" << endl;
    }else{
        cout << "c1 is not same as c2" << endl;
    }
    if(cube.isEqual(another)){
        cout << "c1 is same as c2" << endl;
    }else{
        cout << "c1 is not same as c2" << endl;
    }


    return 0;
}