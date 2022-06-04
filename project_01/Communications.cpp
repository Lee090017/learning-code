/*
 * @Author: your name
 * @Date: 2022-04-11 17:12:01
 * @LastEditTime: 2022-04-11 20:38:52
 * @LastEditors: Please set LastEditors
 * @Description: ͨѶ¼����ϵͳ
 * @FilePath: \learningCode\project_01\Communications.cpp
 */

#include<iostream>
#include<string>
using namespace std;

struct CommunicationsStruct
{
    /* data */
    string name;
    string sex;
    int age;
    string phone;
    string address;
};


void menu();
void addLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman);
void displayLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman);
void deleteLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman);
void initCommunications(struct CommunicationsStruct * comArr,int * numOfLinkman);
void findLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman);
void changeLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman);
void clearLinkman(int * numOfLinkman);

int main(){

    struct CommunicationsStruct communicationArr[1000];//�������Դ�����ݵ�����
    int numOfLinkman = 0;//ͨѶ¼����ϵ�˵ĸ���
    //��ʼ��ͨѶ¼
    initCommunications(communicationArr,&numOfLinkman);

    bool flag = 1;
    while(flag){
        menu();
        int choose;
        cout << "���������(0~6):";
        cin >> choose;
        switch(choose){
            case 0: 
                flag = 0;
                break;
            case 1:
                addLinkman(communicationArr,&numOfLinkman);
                break;
            case 2:
                displayLinkman(communicationArr,&numOfLinkman);
                break;
            case 3:
                deleteLinkman(communicationArr,&numOfLinkman);
                break;
            case 4:
                findLinkman(communicationArr,&numOfLinkman);
                break;
            case 5:
                changeLinkman(communicationArr,&numOfLinkman);
                break;
            case 6:
                clearLinkman(&numOfLinkman);
                break;
            default:
                cout << "������Ŵ���"<< endl;
                break;

        }


    }

    return 0;
}

//���˵�����
void menu(){
    cout << "********************************" << endl;
    cout << "********  1.�����ϵ��  ********" << endl;
    cout << "********  2.��ʾ��ϵ��  ********" << endl;
    cout << "********  3.ɾ����ϵ��  ********" << endl;
    cout << "********  4.������ϵ��  ********" << endl;
    cout << "********  5.�޸���ϵ��  ********" << endl;
    cout << "********  6.�����ϵ��  ********" << endl;
    cout << "********  0.�˳�ͨѶ¼  ********" << endl;
    cout << "********************************" << endl;
}

//��ʼ��ͨѶ¼
void initCommunications(struct CommunicationsStruct * comArr,int * numOfLinkman){
    comArr[0] = {"����","��",25,"15871459396","�����ʵ��ѧ"};
    comArr[1] = {"����","��",23,"13998563214","�����ʵ��ѧ"};
    comArr[2] = {"����","Ů",19,"13886601800","�����ʵ��ѧ"};
    *numOfLinkman = 3;
}

//�����ϵ��
void addLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    cout << *numOfLinkman << endl;
    string name;
    string sex;
    int sex_id;
    int age;
    string phone;
    string address;
    cout << "������������" << endl;
    cin >> name;
    cout << "�������Ա�" << endl;
    cout << "1 -- ��" << endl;
    cout << "2 -- Ů" << endl;
    cin >> sex_id;
    if(sex_id == 1){
        sex = "��";
    }else{
        sex = "Ů";
    }
    cout << "���������䣺" << endl;
    cin >> age;
    cout << "��������ϵ�绡��" << endl;
    cin >> phone;
    cout << "�������ͥסַ��" << endl;
    cin >> address;
    comArr[*numOfLinkman].name = name;
    comArr[*numOfLinkman].sex = sex;
    comArr[*numOfLinkman].age = age;
    comArr[*numOfLinkman].phone = phone;
    comArr[*numOfLinkman].address = address;
    *numOfLinkman = *numOfLinkman + 1;
    // cout << *numOfLinkman << endl;
}

//�����ϵ��
void clearLinkman(int * numOfLinkman){
    cout << "���Ƿ���Ҫ���ͨѶ¼?[y/n]" <<endl;
    char info;
    cin >> info;
    if(info == 'y'){
        *numOfLinkman = 0;
        cout << "ͨѶ¼�����" << endl;
    }else if(info == 'n'){
        cout << "ȡ����ղ���" << endl;
    }else{
        cout << "�������" << endl;
    }
}

//������ϵ��
void findLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"������������"<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            cout << "������" << comArr[i].name << " �Ա�" << comArr[i].sex << "   ���䣺" << comArr[i].age << "   �绰��"<< comArr[i].phone << "  סַ��" << comArr[i].address << endl;
            f = 1;//
        }
    }
    if(f == 0){
        cout << "����ϵ�˲�����" << endl;
    }
}

//�޸���ϵ��
void changeLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"������������"<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            //�����޸�
            string name;
            string sex;
            int sex_id;
            int age;
            string phone;
            string address;
            cout << "������������" << endl;
            cin >> name;
            cout << "�������Ա�" << endl;
            cout << "1 -- ��" << endl;
            cout << "2 -- Ů" << endl;
            cin >> sex_id;
            if(sex_id == 1){
                sex = "��";
            }else{
                sex = "Ů";
            }
            cout << "���������䣺" << endl;
            cin >> age;
            cout << "��������ϵ�绡��" << endl;
            cin >> phone;
            cout << "�������ͥסַ��" << endl;
            cin >> address;
            comArr[i].name = name;
            comArr[i].sex = sex;
            comArr[i].age = age;
            comArr[i].phone = phone;
            comArr[i].address = address;
            f = 1;//
        }
    }
    if(f == 0){
        cout << "����ϵ�˲�����" << endl;
    }
}

//ɾ����ϵ��
void deleteLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"������������"<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            for(int j= i; j<*numOfLinkman; j++){
                comArr[j] = comArr[j+1];
            }
            *numOfLinkman = *numOfLinkman - 1;
            f = 1;//ɾ���ɹ�
        }
    }
    if(f == 0){
        cout << "����ϵ�˲�����" << endl;
    }

}

//��ʾ��ϵ��
void displayLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    if(*numOfLinkman == 0){
        cout << "ͨѶ¼Ϊ��" << endl;
        return;
    }
    for(int i= 0;i < *numOfLinkman;i++){
        cout << "������" << comArr[i].name << " �Ա�" << comArr[i].sex << "   ���䣺" << comArr[i].age << "   �绰��"<< comArr[i].phone << "  סַ��" << comArr[i].address << endl;
    }
}
