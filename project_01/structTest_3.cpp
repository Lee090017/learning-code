/*
 * @Author: your name
 * @Date: 2022-04-11 16:39:28
 * @LastEditTime: 2022-04-11 17:10:09
 * @LastEditors: Please set LastEditors
 * @Description: 结构体案例3
 * @FilePath: \learningCode\project_01\structTest_3.cpp
 */

/**
 * @brief 
 * 
 * 设计一个英雄的结构体，包括成员的姓名、年龄、性别，创建结构体数组存放5名英雄，通过冒泡排序的算法
 * 将数组中的英雄按照年龄进行升序排序，最终打印排序结果
 * 
 */

#include<iostream>
#include<string>
using namespace std;

struct HeroInfo
{
    /* data */  
    string name;
    int age;
    string sex;
};


void Display_HeroArr(const HeroInfo * hero,int len);
void BubbleSortHero(HeroInfo hero[],int len);

int main(){
     struct HeroInfo heroArr[5];
     heroArr[0] = {"LiuBei",23,"man"};
     heroArr[1] = {"GuanYu",22,"man"};
     heroArr[2] = {"ZhangFei",20,"man"};
     heroArr[3] = {"ZhaoYun",21,"man"};
     heroArr[4] = {"DiaoChan",19,"woman"};

    Display_HeroArr(heroArr,5);
    BubbleSortHero(heroArr,5);
    cout << "=============" << endl;
    Display_HeroArr(heroArr,5);

    return 0;
}

void BubbleSortHero(HeroInfo hero[],int len){
    for(int i = len-1;i > 0;i--){
        for(int j = 0;j < i;j++){
            if(hero[j].age > hero[j+1].age){
                HeroInfo temp = hero[j];
                hero[j] = hero[j+1];
                hero[j+1] = temp;
            }
        }
    }
}

void Display_HeroArr(const HeroInfo * hero,int len){
    for(int i= 0;i <len; i++){
        cout << hero->name << " " << hero->age << " " << hero->sex << endl;
        hero++;
    }
}
