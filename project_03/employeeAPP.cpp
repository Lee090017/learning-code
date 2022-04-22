/*
 * @Author: your name
 * @Date: 2022-04-22 15:13:45
 * @LastEditTime: 2022-04-22 21:40:48
 * @LastEditors: Please set LastEditors
 * @Description: 案例：员工信息管理
 * @FilePath: \learningCode\project_03\employeeAPP.cpp
 */
/*
三类职工：普通员工、经理、老板，显示信息时：职工编号、职工姓名、职工岗位、职责



*/
#include<iostream>
#include<string>
#include<fstream>//添加信息到文件
using namespace std;

#define MAX_NUM 20 //员工上限
// #define EmployeeJob "完成经理交给的任务"
// #define ManageJob "完成老板交给的任，并下发任务给员工"
// #define BossJob "管理公司所有事务"

//部门名称数组
const string c_department[3] = {"普通员工","经理","老板"};
//部门职责
const string c_position[3] = {"完成经理交给的任务","完成老板交给的任，并下发任务给员工","管理公司所有事务"};

//抽象类
class EmployeeBase{
public:
    int id;//员工编号
    string name;//姓名
    int department_id;//部门编号
    string department;//部门
    string position;//职责

    void changeId(int id){
        this->id = id;
    }

    void changeName(string name){
        this->name = name;
    }

    void changeDepartment(int department_id){
        this->department_id = department_id;
        this->department = c_department[department_id-1];
        this->position = c_position[department_id-1];
    }
    
};

//普通员工
class Employee : public EmployeeBase{
public:
    Employee(int id,string name,int department_id){
        this->id = id;
        this->name = name;
        this->department_id = department_id;
        this->department = c_department[department_id-1];
        this->position = c_position[department_id-1];
    }
};

//经理
class Mannage : public EmployeeBase{
public:
   Mannage(int id,string name,int department_id){
        this->id = id;
        this->name = name;
        this->department_id = department_id;
        this->department = c_department[department_id-1];
        this->position = c_position[department_id-1];
    }
};

//老板
class Boss : public EmployeeBase{
public:
    Boss(int id,string name,int department_id){
        this->id = id;
        this->name = name;
        this->department_id = department_id;
        this->department = c_department[department_id-1];
        this->position = c_position[department_id-1];
    }
};

//职工管理类
class EmployeeAPP{
public:
    EmployeeBase ** empArr;//维护职工数组指针
    int numOfEmp;//员工的个数
    // EmployeeBase * p_emp;

    EmployeeAPP(){
        numOfEmp = 0;
        empArr = NULL;
    }

    ~EmployeeAPP(){
        if(empArr != NULL){
            delete [] empArr;
            empArr = NULL;
        }
    }

    //文件操作
    //读文件员工个数，并初始化数组
    void inti_numOfEmp(){
        //读取现有文件
        ifstream ifs;
        ifs.open("init_employee.txt",ios::in);
        if(!ifs.is_open()){//本地文件是否存在
            return;
        }
        //统计员工数量
        string buff;
        while(getline(ifs, buff)){
            numOfEmp++;
        }
        //初始化数组，开辟新空间
        empArr = new EmployeeBase *[numOfEmp];
        cout << "导入" << numOfEmp << "组数据" << endl;
        ifs.close();
    }

    //文件初始化
    void init(){
        //读取现有文件
        ifstream ifs;
        ifs.open("init_employee.txt",ios::in);
        if(!ifs.is_open()){//本地文件是否存在
            cout << "本地文件不存在" << endl;
            return;
        }
        int id;
        string name;
        int department_id;
        int index = 0;//统计文件的员工个数
        EmployeeBase * temp = NULL;
        while (ifs >> id && ifs >> name && ifs >> department_id) 
        {
            // cout << id << "," << name << "," << department_id << endl;//打印每次读入的数据
            if(department_id == 1){//普通员工
                temp = new Employee(id,name,department_id);
            }else if(department_id == 2){//经理
                temp = new Mannage(id,name,department_id);
            }else{
                temp = new Boss(id,name,department_id);
            }
            empArr[index] = temp;
            index++;
        }
        ifs.close();
        cout << "初始化成功" << endl;
    }

    //清除文件信息
    void clearAll(){
        ofstream ofs;
        ofs.open("employee.txt",ios::out | ios::trunc);//如果文件存在先删除再创建
        ofs << "编号" << "\t姓名" << "\t部门编号" << "\t职工信息" << endl;
        ofs.close();
    }

    //写文件到文本
    void addEmployeeToFile(EmployeeBase *emp){
        ofstream ofs;
        ofs.open("employee.txt",ios::app | ios::out);//追加到结尾
        ofs << emp->id << "\t" << emp->name << "\t" << emp->department_id << "\t" << emp->department <<endl;
        ofs.close();
    }

    //更新每次的文件
    void refreshFile(){
        clearAll();
        if(numOfEmp == 0){//清空文件
            return;
        }
        EmployeeBase * temp = NULL;//指向新添加对象的临时指针
        for(int i = 0; i < numOfEmp;i++){
            temp = empArr[i];
            addEmployeeToFile(temp);
        }
    }

    //清除所有信息
    void clearInfo(){
        cout << "是否清除所有信息？" << endl;
        cout << "1.是/0.否" << endl;
        bool flag = 0;
        cin >> flag;
        if(flag){
            delete [] empArr;
            numOfEmp = 0;
            clearAll(); 
        }  
    }

    //添加员工
    void addEmployee(){
        cout << "请输入增加的职工数量：" << endl;
        int addNum = 0;
        cin >> addNum;
        if (addNum > 0){
            int newSize = numOfEmp + addNum;//新员工个数
            //开辟新空间
            EmployeeBase ** newSpace = new EmployeeBase *[newSize];
            //将原空间存放到新空间
            for(int i = 0; i < numOfEmp; i++){
               newSpace[i] = empArr[i];
            }
            //输入新数据
            for(int i = 0; i < addNum; i++){
                cout << "请输入第" << i+1 << "个新职工编号：" <<endl;
                int id = 0;
                cin >> id;
                cout << "请输入第" << i+1 << "个新职工姓名：" <<endl;
                string name;
                cin >> name;
                cout << "请选择该职工岗位：" <<endl;
                cout << "1、普通职工：" <<endl;
                cout << "2、经理：" <<endl;
                cout << "3、老板：" <<endl;
                int department_id;
                cin >> department_id;

                EmployeeBase * temp = NULL;//指向新添加对象的临时指针
                switch(department_id){
                    case 1:
                        temp = new Employee(id,name,1);
                        break;
                    case 2:
                        temp = new Mannage(id,name,2);
                        break;
                    case 3:
                        temp = new Boss(id,name,3);
                        break;
                    default:
                        cout << "输入岗位编号错误，请重新添加新员工" <<endl;
                        i--;
                        break;
                }
                newSpace[numOfEmp+i] = temp;
                // //添加成员到文件
                // addEmployeeToFile(temp);
    
            }
            //释放原有空间
            delete [] empArr;
            //更新空间和个数
            empArr = newSpace;
            numOfEmp = newSize;
        }else{
            cout << "输入有误"  <<endl;
        }
        
    }

    //显示职工信息
    void display(){
        // cout << "职工编号：" << id << " 职工姓名：" << name << "    岗位：" << department << "  岗位职责：" << endl;
        if(numOfEmp == 0){
            cout << "员工信息表为空" << endl;
            return;
        }
        cout << "==========共有" << numOfEmp  << "名员工==========" <<endl;
        for(int i=0; i< numOfEmp; i++){
            cout << "职工编号：" << empArr[i]->id << "\t职工姓名：" << empArr[i]->name << "\t岗位：" << empArr[i]->department << "\t岗位职责：" << empArr[i]->position << endl;
        }
    }

    //删除离职员工
    void deleteEmp(){
        cout << "请输入要删除的员工编号：" << endl;
        int id;
        cin >> id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //查找员工
        for(int i=0; i< numOfEmp; i++){
            if(empArr[i]->id == id){
                flag = true;//找到该员工
                // del = empArr[i];//记录当前对象地址
                delete empArr[i];//释放当前空间
            }
            if(flag){//删除该员工
                if(i+1 < numOfEmp){
                    empArr[i] = empArr[i+1];
                }else{
                    empArr[i] = NULL;
                    numOfEmp--;
                }
            }
        }
        if(!flag){
            cout << "编号为" << id << "的员工不存在" << endl;
        }
    }

    //修改职工信息
    void changeInfo(){
        cout << "请输入修改员工的编号：" << endl;
        int id;
        cin >> id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //查找员工
        for(int i=0; i< numOfEmp; i++){
            if(empArr[i]->id == id){
                flag = true;//找到该员工
                cout << "查到：" << id << "号员工"<< endl;
                cout << "请输入新职工号：" << endl;
                int n_id;
                cin >> n_id;
                empArr[i]->changeId(n_id);
                cout << "请输入新姓名：" << endl;
                string n_name;
                cin >> n_name;
                empArr[i]->changeName(n_name);
                cout << "请输入岗位：" << endl;
                cout << "1、普通职工：" <<endl;
                cout << "2、经理：" <<endl;
                cout << "3、老板：" <<endl;
                int n_department_id;
                cin >> n_department_id;
                empArr[i]->changeDepartment(n_department_id);
                cout << "修改成功" << endl;
                break;
            }
        }
        if(!flag){
            cout << "编号为" << id << "的员工不存在" << endl;
        }

    }


    //查找员工信息
    void findEmployee(){
        cout << "请输入要查找员工的编号或姓名：" << endl;
        string name_id;
        cin >> name_id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //查找员工
        for(int i=0; i< numOfEmp; i++){
            string s = "";
            string idStr = s + to_string(empArr[i]->id);//to_string()将其转换为字符串
            if(idStr == name_id || empArr[i]->name == name_id){
                flag = true;//找到该员工
                cout << "职工编号：" << empArr[i]->id << "\t职工姓名：" << empArr[i]->name << "\t岗位：" << empArr[i]->department << "\t岗位职责：" << empArr[i]->position << endl;
                break;
            }
        }
        if(!flag){
            cout << "员工不存在" << endl;
        }
    }


    //员工信息按编号顺序排列
    void sort(){
        for(int i=numOfEmp-1; i>0; i--){
            for(int j=0; j<i;j++){
                if(empArr[j]->id > empArr[j+1]->id){
                    EmployeeBase * temp = empArr[j];
                    empArr[j] = empArr[j+1];
                    empArr[j+1] = temp;
                }
            }
        }
    }

    
    //菜单功能实现
    int menu(){
        cout << "*****************************"  << endl;
        cout << "******欢迎使用职工管理系统*****"  << endl;
        cout << "********0.退出管理程序*******"  << endl;
        cout << "********1.增加职工信息*******"  << endl;
        cout << "********2.显示职工信息*******"  << endl;
        cout << "********3.删除职工信息*******"  << endl;
        cout << "********4.修改职工信息*******"  << endl;
        cout << "********5.查找职工信息*******"  << endl;
        cout << "********6.按照编号排序*******"  << endl;
        cout << "********7.清空所有文档*******"  << endl;
        cout << "*****************************"  << endl;
        cout << endl;
        cout << "请输入你的选择：" << endl;
        int choice;
        cin >> choice;
        return choice;
    }

    //退出当前系统
    bool exit(){
        cout << "是否退出系统？" << endl;
        cout << "1.是/0.否" << endl;
        bool flag = 0;
        cin >> flag;
        return flag;
    }

};

int main(){
    EmployeeAPP app;
    //系统初始化
    app.inti_numOfEmp();//初始化数组
    app.init();//将文件数据读入数组
    app.refreshFile();
    while(1){
        int choose;
        choose = app.menu();
        switch(choose){
            case 0:
                if(app.exit()){
                    cout << "成功退出" << endl;
                    return 0;
                }
                break;
            case 1:
                app.addEmployee();
                app.refreshFile();
                break;
            case 2:
                app.display();
                break;
            case 3:
                app.deleteEmp();
                app.refreshFile();
                break;
            case 4:
                app.changeInfo();
                app.refreshFile();
                break;
            case 5:
                app.findEmployee();
                break;
            case 6://排序
                app.sort();
                app.refreshFile();
                break;
            case 7:
                app.clearInfo();
                break;

            default:
                cout << "输入错误" << endl;
                break;
        }
        system("pause");
    }

    return 0;
}