/*
 * @Author: your name
 * @Date: 2022-04-28 21:16:56
 * @LastEditTime: 2022-04-28 21:49:11
 * @LastEditors: Please set LastEditors
 * @Description: ����1��ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ� ȡƽ����
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
    int score;//ƽ����

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
        deque<int> d;//���10����ί�ķ���
        int sum= 0;//�ܷ�
        for(int i = 0; i <10;i++){//0��10��
            int temp = rand() % 11;
            sum += temp;
            d.push_back(temp);
        }
        //������ί����
        for(int i = 0; i <d.size();i++){
            cout << d[i] << " ";
        }
        cout << endl;
        //ȥ����߷֣���ͷ�
        sort(d.begin(),d.end());
        int min = d.front();
        d.pop_front();
        cout << "ȥ��һ����ͷ֣�" << min << endl;
        int max = d.back();
        d.pop_back();
        cout << "ȥ��һ����߷֣�" << max << endl;
        sum = sum - min - max;
        int avg = sum / 8;//ƽ����
        (*it).score = avg;//��ֵ

    }

}

// void display(vector<Person> &v){
//     for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){

//     }
// }

int main(){

    //���������
    srand((unsigned int)time(NULL));

    //����5��ѡ��
    vector<Person> v;
    createPerson(v);

    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).name << " " << (*it).score << endl;
    }

    //������ѡ�ִ��
    setScore(v);

    //��ʾ���÷�
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << (*it).name << " " << (*it).score << endl;
    }

    return 0;
}