#include<bits/stdc++.h>
using namespace std;

//使用简单的冒泡排序算法，返回递增排列和递减排序的两个四位数
int bubble_sort(int &num,int &ascend_num, int &decrease_num){
    // 求出个十百千
    int NUM[4] = {0};
    NUM[3] = num % 10;
    NUM[2] = (num % 100) / 10;
    NUM[1] = (num % 1000) / 100;
    NUM[0] = num / 1000;
    if(NUM[0]==NUM[1] && NUM[1]==NUM[2] && NUM[2]==NUM[3]) {
        cout << num << "-" << num << "=" << 0000 <<endl;
        return 0;
    }
    //冒泡排序,按递增
    // BUG:输入9621时排序错误
    int k = 0;
    for(int i=0;i<4;i++){
        for(int j =0;j<4-i;i++)
        {
            if (NUM[i] > NUM[i+1])
            {
                // swap 交换位置
                k        =NUM[i];
                NUM[i] = NUM[i+1];
                NUM[i+1]   = k;   
            }
        }
    }

    ascend_num = NUM[0] * 1000 + NUM[1] * 100 + NUM[2] * 10 + NUM[3] * 1;
    decrease_num = NUM[0] * 1 + NUM[1] * 10 + NUM[2] * 100 + NUM[3] * 1000;
    num = decrease_num - ascend_num;
    return 0;
}

int main(){
    int result,ascend_num,decrease_num;
    cin >> result;
   
    bubble_sort(result,ascend_num,decrease_num);
    
    while(result != 6174){
        bubble_sort(result,ascend_num,decrease_num);
        
        cout << decrease_num << "-" << ascend_num << "=" << result <<endl;
    }
    return 0;
}