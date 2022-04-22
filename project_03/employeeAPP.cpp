/*
 * @Author: your name
 * @Date: 2022-04-22 15:13:45
 * @LastEditTime: 2022-04-22 21:40:48
 * @LastEditors: Please set LastEditors
 * @Description: ������Ա����Ϣ����
 * @FilePath: \learningCode\project_03\employeeAPP.cpp
 */
/*
����ְ������ͨԱ���������ϰ壬��ʾ��Ϣʱ��ְ����š�ְ��������ְ����λ��ְ��



*/
#include<iostream>
#include<string>
#include<fstream>//�����Ϣ���ļ�
using namespace std;

#define MAX_NUM 20 //Ա������
// #define EmployeeJob "��ɾ�����������"
// #define ManageJob "����ϰ彻�����Σ����·������Ա��"
// #define BossJob "����˾��������"

//������������
const string c_department[3] = {"��ͨԱ��","����","�ϰ�"};
//����ְ��
const string c_position[3] = {"��ɾ�����������","����ϰ彻�����Σ����·������Ա��","����˾��������"};

//������
class EmployeeBase{
public:
    int id;//Ա�����
    string name;//����
    int department_id;//���ű��
    string department;//����
    string position;//ְ��

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

//��ͨԱ��
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

//����
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

//�ϰ�
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

//ְ��������
class EmployeeAPP{
public:
    EmployeeBase ** empArr;//ά��ְ������ָ��
    int numOfEmp;//Ա���ĸ���
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

    //�ļ�����
    //���ļ�Ա������������ʼ������
    void inti_numOfEmp(){
        //��ȡ�����ļ�
        ifstream ifs;
        ifs.open("init_employee.txt",ios::in);
        if(!ifs.is_open()){//�����ļ��Ƿ����
            return;
        }
        //ͳ��Ա������
        string buff;
        while(getline(ifs, buff)){
            numOfEmp++;
        }
        //��ʼ�����飬�����¿ռ�
        empArr = new EmployeeBase *[numOfEmp];
        cout << "����" << numOfEmp << "������" << endl;
        ifs.close();
    }

    //�ļ���ʼ��
    void init(){
        //��ȡ�����ļ�
        ifstream ifs;
        ifs.open("init_employee.txt",ios::in);
        if(!ifs.is_open()){//�����ļ��Ƿ����
            cout << "�����ļ�������" << endl;
            return;
        }
        int id;
        string name;
        int department_id;
        int index = 0;//ͳ���ļ���Ա������
        EmployeeBase * temp = NULL;
        while (ifs >> id && ifs >> name && ifs >> department_id) 
        {
            // cout << id << "," << name << "," << department_id << endl;//��ӡÿ�ζ��������
            if(department_id == 1){//��ͨԱ��
                temp = new Employee(id,name,department_id);
            }else if(department_id == 2){//����
                temp = new Mannage(id,name,department_id);
            }else{
                temp = new Boss(id,name,department_id);
            }
            empArr[index] = temp;
            index++;
        }
        ifs.close();
        cout << "��ʼ���ɹ�" << endl;
    }

    //����ļ���Ϣ
    void clearAll(){
        ofstream ofs;
        ofs.open("employee.txt",ios::out | ios::trunc);//����ļ�������ɾ���ٴ���
        ofs << "���" << "\t����" << "\t���ű��" << "\tְ����Ϣ" << endl;
        ofs.close();
    }

    //д�ļ����ı�
    void addEmployeeToFile(EmployeeBase *emp){
        ofstream ofs;
        ofs.open("employee.txt",ios::app | ios::out);//׷�ӵ���β
        ofs << emp->id << "\t" << emp->name << "\t" << emp->department_id << "\t" << emp->department <<endl;
        ofs.close();
    }

    //����ÿ�ε��ļ�
    void refreshFile(){
        clearAll();
        if(numOfEmp == 0){//����ļ�
            return;
        }
        EmployeeBase * temp = NULL;//ָ������Ӷ������ʱָ��
        for(int i = 0; i < numOfEmp;i++){
            temp = empArr[i];
            addEmployeeToFile(temp);
        }
    }

    //���������Ϣ
    void clearInfo(){
        cout << "�Ƿ����������Ϣ��" << endl;
        cout << "1.��/0.��" << endl;
        bool flag = 0;
        cin >> flag;
        if(flag){
            delete [] empArr;
            numOfEmp = 0;
            clearAll(); 
        }  
    }

    //���Ա��
    void addEmployee(){
        cout << "���������ӵ�ְ��������" << endl;
        int addNum = 0;
        cin >> addNum;
        if (addNum > 0){
            int newSize = numOfEmp + addNum;//��Ա������
            //�����¿ռ�
            EmployeeBase ** newSpace = new EmployeeBase *[newSize];
            //��ԭ�ռ��ŵ��¿ռ�
            for(int i = 0; i < numOfEmp; i++){
               newSpace[i] = empArr[i];
            }
            //����������
            for(int i = 0; i < addNum; i++){
                cout << "�������" << i+1 << "����ְ����ţ�" <<endl;
                int id = 0;
                cin >> id;
                cout << "�������" << i+1 << "����ְ��������" <<endl;
                string name;
                cin >> name;
                cout << "��ѡ���ְ����λ��" <<endl;
                cout << "1����ְͨ����" <<endl;
                cout << "2������" <<endl;
                cout << "3���ϰ壺" <<endl;
                int department_id;
                cin >> department_id;

                EmployeeBase * temp = NULL;//ָ������Ӷ������ʱָ��
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
                        cout << "�����λ��Ŵ��������������Ա��" <<endl;
                        i--;
                        break;
                }
                newSpace[numOfEmp+i] = temp;
                // //��ӳ�Ա���ļ�
                // addEmployeeToFile(temp);
    
            }
            //�ͷ�ԭ�пռ�
            delete [] empArr;
            //���¿ռ�͸���
            empArr = newSpace;
            numOfEmp = newSize;
        }else{
            cout << "��������"  <<endl;
        }
        
    }

    //��ʾְ����Ϣ
    void display(){
        // cout << "ְ����ţ�" << id << " ְ��������" << name << "    ��λ��" << department << "  ��λְ��" << endl;
        if(numOfEmp == 0){
            cout << "Ա����Ϣ��Ϊ��" << endl;
            return;
        }
        cout << "==========����" << numOfEmp  << "��Ա��==========" <<endl;
        for(int i=0; i< numOfEmp; i++){
            cout << "ְ����ţ�" << empArr[i]->id << "\tְ��������" << empArr[i]->name << "\t��λ��" << empArr[i]->department << "\t��λְ��" << empArr[i]->position << endl;
        }
    }

    //ɾ����ְԱ��
    void deleteEmp(){
        cout << "������Ҫɾ����Ա����ţ�" << endl;
        int id;
        cin >> id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //����Ա��
        for(int i=0; i< numOfEmp; i++){
            if(empArr[i]->id == id){
                flag = true;//�ҵ���Ա��
                // del = empArr[i];//��¼��ǰ�����ַ
                delete empArr[i];//�ͷŵ�ǰ�ռ�
            }
            if(flag){//ɾ����Ա��
                if(i+1 < numOfEmp){
                    empArr[i] = empArr[i+1];
                }else{
                    empArr[i] = NULL;
                    numOfEmp--;
                }
            }
        }
        if(!flag){
            cout << "���Ϊ" << id << "��Ա��������" << endl;
        }
    }

    //�޸�ְ����Ϣ
    void changeInfo(){
        cout << "�������޸�Ա���ı�ţ�" << endl;
        int id;
        cin >> id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //����Ա��
        for(int i=0; i< numOfEmp; i++){
            if(empArr[i]->id == id){
                flag = true;//�ҵ���Ա��
                cout << "�鵽��" << id << "��Ա��"<< endl;
                cout << "��������ְ���ţ�" << endl;
                int n_id;
                cin >> n_id;
                empArr[i]->changeId(n_id);
                cout << "��������������" << endl;
                string n_name;
                cin >> n_name;
                empArr[i]->changeName(n_name);
                cout << "�������λ��" << endl;
                cout << "1����ְͨ����" <<endl;
                cout << "2������" <<endl;
                cout << "3���ϰ壺" <<endl;
                int n_department_id;
                cin >> n_department_id;
                empArr[i]->changeDepartment(n_department_id);
                cout << "�޸ĳɹ�" << endl;
                break;
            }
        }
        if(!flag){
            cout << "���Ϊ" << id << "��Ա��������" << endl;
        }

    }


    //����Ա����Ϣ
    void findEmployee(){
        cout << "������Ҫ����Ա���ı�Ż�������" << endl;
        string name_id;
        cin >> name_id;
        bool flag = false;
        // EmployeeBase * del = NULL;
        //����Ա��
        for(int i=0; i< numOfEmp; i++){
            string s = "";
            string idStr = s + to_string(empArr[i]->id);//to_string()����ת��Ϊ�ַ���
            if(idStr == name_id || empArr[i]->name == name_id){
                flag = true;//�ҵ���Ա��
                cout << "ְ����ţ�" << empArr[i]->id << "\tְ��������" << empArr[i]->name << "\t��λ��" << empArr[i]->department << "\t��λְ��" << empArr[i]->position << endl;
                break;
            }
        }
        if(!flag){
            cout << "Ա��������" << endl;
        }
    }


    //Ա����Ϣ�����˳������
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

    
    //�˵�����ʵ��
    int menu(){
        cout << "*****************************"  << endl;
        cout << "******��ӭʹ��ְ������ϵͳ*****"  << endl;
        cout << "********0.�˳��������*******"  << endl;
        cout << "********1.����ְ����Ϣ*******"  << endl;
        cout << "********2.��ʾְ����Ϣ*******"  << endl;
        cout << "********3.ɾ��ְ����Ϣ*******"  << endl;
        cout << "********4.�޸�ְ����Ϣ*******"  << endl;
        cout << "********5.����ְ����Ϣ*******"  << endl;
        cout << "********6.���ձ������*******"  << endl;
        cout << "********7.��������ĵ�*******"  << endl;
        cout << "*****************************"  << endl;
        cout << endl;
        cout << "���������ѡ��" << endl;
        int choice;
        cin >> choice;
        return choice;
    }

    //�˳���ǰϵͳ
    bool exit(){
        cout << "�Ƿ��˳�ϵͳ��" << endl;
        cout << "1.��/0.��" << endl;
        bool flag = 0;
        cin >> flag;
        return flag;
    }

};

int main(){
    EmployeeAPP app;
    //ϵͳ��ʼ��
    app.inti_numOfEmp();//��ʼ������
    app.init();//���ļ����ݶ�������
    app.refreshFile();
    while(1){
        int choose;
        choose = app.menu();
        switch(choose){
            case 0:
                if(app.exit()){
                    cout << "�ɹ��˳�" << endl;
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
            case 6://����
                app.sort();
                app.refreshFile();
                break;
            case 7:
                app.clearInfo();
                break;

            default:
                cout << "�������" << endl;
                break;
        }
        system("pause");
    }

    return 0;
}