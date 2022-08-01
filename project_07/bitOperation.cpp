/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-04 16:19:54
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-04 17:16:36
 * @FilePath: \learningCode\project_07\weiyunsuan.cpp
 * @Description: 位运算
 */
#include<iostream>
#include<bitset> //bitset需要指定的头文件

using namespace std;

const int N = 100010;

int a[N];

//n的二进制表示中第k位是多少
/*
（1）将第k位位移到最后一位，n>>k
（2）看个位为多少 x&1
 n >> k & 1
*/
void test01(){
    int n = 10;

    for(int k = 3; k >= 0; k--) cout << (n >> k & 1); //1010
}

//lowbit(x) 返回x的最后一位1  原理 x&-x   -x = ~x + 1
/*
    如10 = 1010  ->  10 = 2
*/

//案例：统计数的二进制1的个数
void test02(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int count = 0;
        while(a[i] !=0 ){
            a[i] -= (a[i] & -a[i]);
            count++;
        }
        cout << count << " ";

    }


}

/*
原码  00...00 1010
反码  11...11 0101
补码  11...11 0110

*/

//输出二进制的操作
void binaryPrintf(int a){
    string str = "";
    for(int i = 10; i >= 0; i--){
        int n = (a >> i & 1);
        str = str + to_string(n);
    }
    int s = str.length(),i = 0;
    while(i < s && str[i++] == '0'){
        str.erase(0,1); 
        cout << str << endl;
    }
    cout << str[i] << endl;
}

int main(){
    // test02();

    int x = 10;

    // binaryPrintf(x);

    cout<<"x = "<<x<<endl;
	cout<<"x 10 = "<<dec<<x<<endl;
	cout<<"x 8 = "<<oct<<x<<endl;//八进制 
	cout<<"x 16 = "<<hex<<x<<endl;	//十六进制 
	cout<<"x 2 = "<<bitset<16>(x)<<endl; //输出为十六位二进制数 

    return 0;
}