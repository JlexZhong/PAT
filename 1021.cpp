#include<iostream>
using namespace std;

int main(){
   
    string num;
    cin >> num;
    //将字符型转换为整数
    int len = num.length();
    for(int i=0;i<len;i++){
        num[i] = num[i] - '0';
    }
    // 统计出现次数
    int b[10] = {0};
    for(int k=0;k<len;k++){
        b[num[k]]++;
    }
    for(int j=0;j<10;j++){
        if(b[j] != 0){
            cout << j << ":" << b[j] << endl;
        }
    }
    return 0;
}