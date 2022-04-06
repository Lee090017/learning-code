/*
 * @Author: your name
 * @Date: 2022-04-06 17:39:29
 * @LastEditTime: 2022-04-06 21:00:34
 * @LastEditors: Please set LastEditors
 * @Description: 数组
 * @FilePath: \learningCode\project_01\arrayTest.cpp
 */

#include<iostream>
using namespace std;
int main(){
      
      //一维数组的数组名
      /*
        1. 可以统计整个数组在内存中的长度
        2.可以获取数组在内存中的首地址
      */
    int arr1[5] = {1,2,3,4,5};

    cout << sizeof(arr1[0]) << endl; // 4
    cout << sizeof(arr1) << endl; // 4*5=20
    cout << &arr1[0] << endl;
    cout << arr1 << endl;
    cout << "====================" << endl;

    //数组元素逆置
    int length = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0, j = length-1; i < j; i++, j--){
        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }
    for (int i = 0;i < length;i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "====================" << endl;

    //冒泡排序

    //产生随机数 要取得[0,n)  就是rand（）%n     表示 从0到n-1的数
    //要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 

    int l2 = 100;
    int arr2[l2];
    for (int i = 0;i < l2;i++){
        arr2[i] = rand() % (200) - 100;
    }

    for(int i=l2-1; i>=0; i--){
        bool flag = 0;
        for(int j=0; j<i; j++){
            if(arr2[j] > arr2[j+1]){
                int temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;//未发生交换
    }
    for (int i = 0;i < l2;i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "====================" << endl;

    //二维数组
    /*
        1.可以查看二维数组所占用的内存空间
        2.可以获取二维数组在内存中的首地址
    */
    int arr3[2][3] = {{1,2,3},{4,5,6}};
    cout << sizeof(arr3) << endl;
    cout << sizeof(arr3[0]) << endl;
    cout << arr3 << endl;
    cout << &arr3[0] << endl;
    cout << &arr3[0][0] << endl;
    //计算二维数组的行和列
    int rows = sizeof(arr3)/sizeof(arr3[0]);
    int cols = sizeof(arr3[0])/sizeof(arr3[0][0]);
    cout << "rows = " << rows <<endl;
    cout << "cols = " << cols <<endl;
    cout << "====================" << endl;

    //分别输出三名同学的总成绩
    int arr4[3][3] = {{100,100,100},{90,50,100},{60,70,80}};
    for(int i=0;i < 3 ; i++){
        int sum = 0;
        for(int j = 0;j<3;j++){
            sum += arr4[i][j];
        }
        cout << "sum of socre is "<< sum << endl;
    }
      
    return 0;
}
