#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cout << "请输入人数：";
    cin >> N;
    int a[N] = {0};
    // 将数组全部赋值为1，退出时为0
    for(int i=0;i<N;i++){
        a[i] = 1;
    }
    int count_bs = 0; // 报数计数
    int count_in = N; // 数组中还未退出的元素数量
    int i = 0;
    while (count_in != 1) // 当数组中只剩最后一个元素时停止报数
    {
        // 此时数组下标越界，从头开始报数
        if(i == N) i = 0; 
        // 值为0时跳过当前元素
        if(a[i] == 0){
            i++;
            continue;
        }
        count_bs++;
        // 报数到3，此时将值置为0，重置计数=0，保留的元素-1
        if(count_bs == 3){
            a[i] = 0;
            count_bs = 0;
            count_in--;
        }
        i++;
    }
    //依次扫描数组，读到值为1时打印
    for(i = 0;i < N;i++){
        if(a[i] == 1){
            cout << "最后留下的元素的数组下标为：" << i << endl;
            break;
        }
    }
    
    return 0;
}