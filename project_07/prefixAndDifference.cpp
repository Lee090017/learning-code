/*
 * @Author: lishu 455938969@qq.com
 * @Date: 2022-07-02 17:29:56
 * @LastEditors: lishu 455938969@qq.com
 * @LastEditTime: 2022-07-02 22:37:27
 * @FilePath: \learningCode\project_07\prefixAndDifference.cpp
 * @Description: 前缀和差分
 */
#include<iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N];

/*
1.前缀和
(1)一维：
S[i] = a[1] + a[2] + ... a[i]
a[l] + ... + a[r] = S[r] - S[l - 1]
(2)二维
S[i, j] = 第i行j列格子左上部分所有元素的和
s[i][j] += s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]

*/

// acwing 795.前缀和
void test01(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int l,r;
    for(int i = 0; i<m;i++){
        cin >> l >> r;
        cout << a[r] - a[l-1] << endl;
    }
}

//acwing 796.子矩阵的和
/*
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4

17
27
21
*/
const int  X = 1010;
int s[X][X],b[X][X];//大数据要定义在全局变量上

void test02(){
    int n,m,x;
    cin >> n >> m >> x;//n为行 m为列 q为执行语句
    
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= m; j++){
            cin >> b[i][j];
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1] + b[i][j];//第i行j列格子左上部分所有元素的和
        }
    }

    int x1,x2,y1,y2;

    while(x--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << endl;
    }

}

/*
2.差分
(1)一维
由于 b[i] = a[i] - a[i-1]
而 a[l] ... a[r] + c
b[l]:a[l] + c - a[l-1] = b[l] + c
b[r+1]: a[r+1] - a[r] -c = b[r+1] - c
a[i] = b[i] + b[i-1] + ... + b[0]
给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c

(2)二维
给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c

*/

// acwing 797.差分
/*
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1

3 4 5 3 4 2
*/
int a1[N],b1[N];
void test03(){
    int n,m;//n个数m个操作
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        scanf("%d",&a1[i]);
        b1[i] = a1[i] - a1[i-1];//获取差分数组
    }
    int l,r,c;//将序列[l,c]的数字都加c
    for(int i = 0; i < m; i++){
        cin >> l >> r >> c;
        b1[l] += c;
        b1[r+1] -= c;
    }

    for(int i = 1; i <= n; i++){
        b1[i] += b1[i-1];//前i项b1数组求和 如 a1[1] = b1[1] + b1[0] = a1[1] - a1[0] + a1[0]
        cout << b1[i] << " ";
    }
    cout << endl;
}

//acwing 798.差分矩阵
/*
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1

2 3 4 1
4 3 4 1
2 2 2 2
*/
int a2[X][X],b2[X][X];

void change(int x1,int y1,int x2,int y2,int add){
    b2[x1][y1] += add;
    b2[x1][y2+1] -= add;
    b2[x2+1][y1] -= add;
    b2[x2+1][y2+1] += add;
}

void test04(){
    int n,m,x;
    cin >> n >> m >>x;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ ){
            scanf("%d", &a2[i][j]);
            change(i,j,i,j,a2[i][j]);
        }
        
    int x1,x2,y1,y2,add;
    for (int i = 0; i < x; i ++ ){
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &add);
        change(x1, y1, x2, y2, add);
    }
    cout << endl;
    for (int i = 1; i <= n; i ++ ){
        for (int j = 1; j <= m; j ++ ){
            b2[i][j] += b2[i-1][j]+b2[i][j-1]-b2[i-1][j-1];
            cout << b2[i][j] << ' ';
        }
        cout << endl;
    }
}


int main(){
    test04();

    return 0;
}