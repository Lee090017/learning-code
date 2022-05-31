/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-31 17:44:58
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-31 18:26:54
 * @FilePath: \learningCode\project_05\mapTest2.cpp
 * @Description: ���� map
 */
/**
 * 
 * ��˾��������10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����ĸ����Ź���
 * Ա����Ϣ�У����� ������ɣ����ŷ�Ϊ���߻����������з�
 * �����10��Ա�����䲿�ź͹���
 * ͨ��multimap������Ϣ�Ĳ��� key�����ű�ţ� valueԱ��
 * �ֲ�����ʾԱ����Ϣ 
 * 
 * 
 * 
 * 
 */

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<ctime>//���������
using namespace std;

class Employee{
public:
    string e_name;
    int e_salary;

    Employee(string name, int salary):e_name(name), e_salary(salary){

    }    
};

void printVector(vector<Employee> & v){
    for(vector<Employee>::iterator it = v.begin(); it != v.end(); it++){
        cout << it->e_name << ", " << it->e_salary << endl;
    }
}

void printMap(multimap<string,Employee> & m){
    for(multimap<string,Employee>::iterator it = m.begin(); it != m.end(); it++){
        cout << it->first << ": " << (it->second).e_name << ", " << (it->second).e_salary << endl;
    }
}

int main(){

    srand(time(0));

    //����10��Ա����vector����
    vector<Employee> empArr;
    for(int i = 0;i<10;i++){
        char c = 'A';
        string name = "";
        name += (c + i);//����
        int salary = rand() % (10000 - 4000 + 1) + 4000;//ȡ�� [ a , b ] �����������rand()%(b-a+1) +a
        empArr.push_back(Employee(name,salary));
    }
    // printVector(empArr);
    //�������� ȡÿ��Ա���������
    multimap<string,Employee> departMap;//
    string d_name[3] = {"�߻�","����","�з�"};
    for(vector<Employee>::iterator it = empArr.begin(); it != empArr.end(); it++){
        int id = rand() % 3; //
        departMap.insert(make_pair(d_name[id],*it));//
    }
    // printMap(departMap);
    //������ʾԱ����Ϣ
    int n_c = departMap.count("�߻�");
    int n_m = departMap.count("����");
    int n_y = departMap.count("�з�");
    multimap<string,Employee>::iterator it_c = departMap.find("�߻�");
    cout << "�߻����ţ�" << endl;
    while(it_c != departMap.end() && n_c > 0){
        cout << "������" << (it_c->second).e_name << "н�ʣ�" << (it_c->second).e_salary << endl;
        n_c--;
        it_c++;
    }
    cout << "====================" << endl;

    multimap<string,Employee>::iterator it_m = departMap.find("����");
    cout << "�������ţ�" << endl;
    while(it_m != departMap.end() && n_m > 0){
        cout << "������" << (it_m->second).e_name << "н�ʣ�" << (it_m->second).e_salary << endl;
        n_m--;
        it_m++;
    }
    cout << "====================" << endl;

    multimap<string,Employee>::iterator it_y = departMap.find("�з�");
    cout << "�з����ţ�" << endl;
    while(it_y != departMap.end() && n_y > 0){
        cout << "������" << (it_y->second).e_name << "н�ʣ�" << (it_y->second).e_salary << endl;
        n_y--;
        it_y++;
    }


    return 0;
}