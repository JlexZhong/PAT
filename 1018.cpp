#include<bits/stdc++.h>
using namespace std;

// 剪刀J 石头S 布B

int count1 = 0;  // 甲赢
int count2 = 0;  // 乙赢
int count3 = 0;  // 平局
int JIA_act[3] = {0},YI_act[3] = {0}; // 下标J=0,S=1,B=2

void judge(char JIA ,char YI )
{
    if (JIA == YI) count3++;
    // 甲win
    else if ((JIA == 'J' && YI == 'B') || (JIA == 'C' && YI == 'J') || (JIA == 'B' && YI == 'C')) {
        count1++;
        switch (JIA)
        {
        case 'B':
            JIA_act[0]++;
            break;
        case 'C':
            JIA_act[1]++;
            break;
        case 'J':
            JIA_act[2]++;
            break;
        default:
            break;
        }
        // cout << " 甲赢了" << endl;
        }
    // 乙win
    else {
        count2++;
        switch (YI)
        {
        case 'B':
            YI_act[0]++;
            break;
        case 'C':
            YI_act[1]++;
            break;
        case 'J':
            YI_act[2]++;
            break;
        default:
            break;
        }
        // cout << " 乙赢了" << endl;
    }
}

int main(){
    int N = 0;
    char JIA,YI;
    cin >> N;
    for(int i=0;i < N;i++){
        cin >> JIA >> YI;
        judge(JIA,YI);
    }
    cout << count1 << " " << count3 << " " << count2 << endl;
    cout << count2 << " " << count3 << " " << count1 << endl;
    // 接下来找出胜数最多的手势的下标
    int JIA_max = 0, YI_max = 0;
    for(int i = 1; i < 3;i++){
        if(JIA_act[i] > JIA_act[JIA_max]) JIA_max = i;
        if(YI_act[i] > YI_act[YI_max]) YI_max = i;
    }
    string A = "BCJ";
    cout << A[JIA_max] << " " << A[YI_max] << endl; 
    // cout << "判断完毕" << endl;
    return 0;
}