/*
 * @Author: Lee090017 455938969@qq.com
 * @Date: 2022-05-31 17:44:58
 * @LastEditors: Lee090017 455938969@qq.com
 * @LastEditTime: 2022-05-31 18:26:54
 * @FilePath: \learningCode\project_05\mapTest2.cpp
 * @Description: 案例 map
 */
/**
 * 
 * 公司今天招了10个员工（ABCDEFGHIJ），10民员工进入公司之后，需要指派员工在哪个部门工作
 * 员工信息有：姓名 工资组成；部门分为：策划、美术、研发
 * 随机给10名员工分配部门和工资
 * 通过multimap进行信息的插入 key（部门编号） value员工
 * 分部门显示员工信息 
 * 
 * 
 * 
 * 
 */

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<ctime>//随机数种子
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

    //创建10个员工到vector数组
    vector<Employee> empArr;
    for(int i = 0;i<10;i++){
        char c = 'A';
        string name = "";
        name += (c + i);//姓名
        int salary = rand() % (10000 - 4000 + 1) + 4000;//取得 [ a , b ] 的随机整数：rand()%(b-a+1) +a
        empArr.push_back(Employee(name,salary));
    }
    // printVector(empArr);
    //创建部门 取每个员工随机分组
    multimap<string,Employee> departMap;//
    string d_name[3] = {"策划","美术","研发"};
    for(vector<Employee>::iterator it = empArr.begin(); it != empArr.end(); it++){
        int id = rand() % 3; //
        departMap.insert(make_pair(d_name[id],*it));//
    }
    // printMap(departMap);
    //分组显示员工信息
    int n_c = departMap.count("策划");
    int n_m = departMap.count("美术");
    int n_y = departMap.count("研发");
    multimap<string,Employee>::iterator it_c = departMap.find("策划");
    cout << "策划部门：" << endl;
    while(it_c != departMap.end() && n_c > 0){
        cout << "姓名：" << (it_c->second).e_name << "薪资：" << (it_c->second).e_salary << endl;
        n_c--;
        it_c++;
    }
    cout << "====================" << endl;

    multimap<string,Employee>::iterator it_m = departMap.find("美术");
    cout << "美术部门：" << endl;
    while(it_m != departMap.end() && n_m > 0){
        cout << "姓名：" << (it_m->second).e_name << "薪资：" << (it_m->second).e_salary << endl;
        n_m--;
        it_m++;
    }
    cout << "====================" << endl;

    multimap<string,Employee>::iterator it_y = departMap.find("研发");
    cout << "研发部门：" << endl;
    while(it_y != departMap.end() && n_y > 0){
        cout << "姓名：" << (it_y->second).e_name << "薪资：" << (it_y->second).e_salary << endl;
        n_y--;
        it_y++;
    }


    return 0;
}