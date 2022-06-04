/*
 * @Author: your name
 * @Date: 2022-04-11 17:12:01
 * @LastEditTime: 2022-04-11 20:38:52
 * @LastEditors: Please set LastEditors
 * @Description: 通讯录管理系统
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

    struct CommunicationsStruct communicationArr[1000];//创建可以存放数据的数组
    int numOfLinkman = 0;//通讯录中联系人的个数
    //初始化通讯录
    initCommunications(communicationArr,&numOfLinkman);

    bool flag = 1;
    while(flag){
        menu();
        int choose;
        cout << "请输入序号(0~6):";
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
                cout << "输入序号错误"<< endl;
                break;

        }


    }

    return 0;
}

//主菜单界面
void menu(){
    cout << "********************************" << endl;
    cout << "********  1.添加联系人  ********" << endl;
    cout << "********  2.显示联系人  ********" << endl;
    cout << "********  3.删除联系人  ********" << endl;
    cout << "********  4.查找联系人  ********" << endl;
    cout << "********  5.修改联系人  ********" << endl;
    cout << "********  6.清空联系人  ********" << endl;
    cout << "********  0.退出通讯录  ********" << endl;
    cout << "********************************" << endl;
}

//初始化通讯录
void initCommunications(struct CommunicationsStruct * comArr,int * numOfLinkman){
    comArr[0] = {"张三","男",25,"15871459396","重庆邮电大学"};
    comArr[1] = {"李四","男",23,"13998563214","重庆邮电大学"};
    comArr[2] = {"王五","女",19,"13886601800","重庆邮电大学"};
    *numOfLinkman = 3;
}

//添加联系人
void addLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    cout << *numOfLinkman << endl;
    string name;
    string sex;
    int sex_id;
    int age;
    string phone;
    string address;
    cout << "请输入姓名：" << endl;
    cin >> name;
    cout << "请输入性别：" << endl;
    cout << "1 -- 男" << endl;
    cout << "2 -- 女" << endl;
    cin >> sex_id;
    if(sex_id == 1){
        sex = "男";
    }else{
        sex = "女";
    }
    cout << "请输入年龄：" << endl;
    cin >> age;
    cout << "请输入联系电弧：" << endl;
    cin >> phone;
    cout << "请输入家庭住址：" << endl;
    cin >> address;
    comArr[*numOfLinkman].name = name;
    comArr[*numOfLinkman].sex = sex;
    comArr[*numOfLinkman].age = age;
    comArr[*numOfLinkman].phone = phone;
    comArr[*numOfLinkman].address = address;
    *numOfLinkman = *numOfLinkman + 1;
    // cout << *numOfLinkman << endl;
}

//清空联系人
void clearLinkman(int * numOfLinkman){
    cout << "你是否需要清空通讯录?[y/n]" <<endl;
    char info;
    cin >> info;
    if(info == 'y'){
        *numOfLinkman = 0;
        cout << "通讯录已清空" << endl;
    }else if(info == 'n'){
        cout << "取消清空操作" << endl;
    }else{
        cout << "输入错误" << endl;
    }
}

//查找联系人
void findLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"请输入姓名："<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            cout << "姓名：" << comArr[i].name << " 性别：" << comArr[i].sex << "   年龄：" << comArr[i].age << "   电话："<< comArr[i].phone << "  住址：" << comArr[i].address << endl;
            f = 1;//
        }
    }
    if(f == 0){
        cout << "该联系人不存在" << endl;
    }
}

//修改联系人
void changeLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"请输入姓名："<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            //重新修改
            string name;
            string sex;
            int sex_id;
            int age;
            string phone;
            string address;
            cout << "请输入姓名：" << endl;
            cin >> name;
            cout << "请输入性别：" << endl;
            cout << "1 -- 男" << endl;
            cout << "2 -- 女" << endl;
            cin >> sex_id;
            if(sex_id == 1){
                sex = "男";
            }else{
                sex = "女";
            }
            cout << "请输入年龄：" << endl;
            cin >> age;
            cout << "请输入联系电弧：" << endl;
            cin >> phone;
            cout << "请输入家庭住址：" << endl;
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
        cout << "该联系人不存在" << endl;
    }
}

//删除联系人
void deleteLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    string name;
    cout <<"请输入姓名："<< endl;
    cin >> name;
    bool f = 0;
    for(int i= 0;i < *numOfLinkman;i++){
        if(comArr[i].name == name){
            for(int j= i; j<*numOfLinkman; j++){
                comArr[j] = comArr[j+1];
            }
            *numOfLinkman = *numOfLinkman - 1;
            f = 1;//删除成功
        }
    }
    if(f == 0){
        cout << "该联系人不存在" << endl;
    }

}

//显示联系人
void displayLinkman(struct CommunicationsStruct * comArr,int * numOfLinkman){
    if(*numOfLinkman == 0){
        cout << "通讯录为空" << endl;
        return;
    }
    for(int i= 0;i < *numOfLinkman;i++){
        cout << "姓名：" << comArr[i].name << " 性别：" << comArr[i].sex << "   年龄：" << comArr[i].age << "   电话："<< comArr[i].phone << "  住址：" << comArr[i].address << endl;
    }
}
