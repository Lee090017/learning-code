/*
 * @Author: your name
 * @Date: 2022-04-20 17:01:31
 * @LastEditTime: 2022-04-20 17:28:23
 * @LastEditors: Please set LastEditors
 * @Description: 案例实现电脑组装
 * @FilePath: \learningCode\project_03\polymorphismTest3.cpp
 */
#include <iostream>
#include <string>
using namespace std;

class CPU{
public:
    virtual void calculate() = 0;
};

class GPU{
public:
    virtual void display() = 0;
};

class RAM{
public:
    virtual void store() = 0;
};

//具体厂商
class IntelCPU:public CPU{
public:
    void calculate(){
        cout << "英特尔处理器工作" << endl;
    }
};

class AMDCPU:public CPU{
public:
    void calculate(){
        cout << "锐龙处理器工作" << endl;
    }
};

class IntelGPU:public GPU{
public:
    void display(){
        cout << "英特尔显卡工作" << endl;
    }
};

class AMDGPU:public GPU{
public:
    void display(){
        cout << "锐龙处显卡工作" << endl;
    }
};

class IntelRAM:public RAM{
public:
    void store(){
        cout << "英特尔内存条工作" << endl;
    }
};

class AMDRAM:public RAM{
public:
    void store(){
        cout << "锐龙内存条工作" << endl;
    }
};

class Commputer{
public:
    Commputer(CPU *cpu,GPU *gpu,RAM *ram){
        this->cpu = cpu;
        this->gpu = gpu;
        this->ram = ram;
    }

    void work(){
        //调用实现接口
        cpu->calculate();
        gpu->display();
        ram->store();
    }

    ~Commputer(){
        if(cpu != NULL){
            delete cpu;
            cpu = NULL;
        }

        if(gpu != NULL){
            delete gpu;
            gpu = NULL;
        }
        
        if(ram != NULL){
            delete ram;
            ram = NULL;
        }
    }

private:
    CPU * cpu;
    GPU * gpu;
    RAM * ram;
};

void test01(){
    CPU * cpu = new IntelCPU;
    GPU * gpu = new AMDGPU;
    RAM * ram = new IntelRAM;
    Commputer * computer1 = new Commputer(cpu,gpu,ram);
    computer1->work();
    delete computer1;

}
int main(){
    test01();

    return 0;
}