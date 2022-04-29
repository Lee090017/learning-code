/*
 * @Author: your name
 * @Date: 2022-04-28 21:16:56
 * @LastEditTime: 2022-04-28 21:49:11
 * @LastEditors: Please set LastEditors
 * @Description: 案例1：选手ABCDE，10个评委分别对每一名选手打分，去除最高分和最低分 取平均分
 * @FilePath: \learningCode\project_05\stlTest1.cpp
 */
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>
using namespace std;

class Person{
public:
    string name;
    int score;//平均分

    Person(string name, int score){
        this->name = name;
        this->score = score;
    }

    Person(){}
};

void createPerson(vector<Person> &v){
    for(int i=0; i<5; i++){
        string name = "Player_";
        name += (char)('A' + i);

        int score = 0;

        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v){
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        deque<int> d;//存放10个评委的分数
        int sum= 0;//总分
        for(int i = 0; i <10;i++){//0到10分
            int temp = rand() % 11;
            sum += temp;
            d.push_back(temp);
        }
        //公布评委分数
        for(int i = 0; i <d.size();i++){
            cout << d[i] << " ";
        }
        cout << endl;
        //去除最高分，最低分
        sort(d.begin(),d.end());
        int min = d.front();
        d.pop_front();
        cout << "去除一个最低分：" << min << endl;
        int max = d.back();
        d.pop_back();
        cout << "去除一个最高分：" << max << endl;
        sum = sum - min - max;
        int avg = sum / 8;//平均分
        (*it).score = avg;//赋值

    }

}

// void display(vector<Person> &v){
//     for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){

//     }
// }

int main(){

    //随机数种子
    srand((unsigned int)time(NULL));

    //创建5名选手
    vector<Person> v;
    createPerson(v);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).name << " " << (*it).score << endl;
    }

    //给无名选手打分
    setScore(v);

    //显示最后得分
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).name << " " << (*it).score << endl;
    }

    return 0;
}