/*
https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num[10];//代表0~9每个数字的个数
    int i = 0 ,sum= 0;
    while(i<9){
        cin >> num[i];
        sum+=num[i++];      
    }
    if(sum<=50){
        int result[sum];
        for(i = 0;i<sum;i++){
            if(i==0){
                for(int j=1;j<9;j++){
                    if(num[j] != 0){
                        result[i] = j;
                        num[j]--; 
                        break;
                    }
                }
            }
            else{
                for(int j=0;j<9;j++){
                    if(num[j] != 0) {
                        result[i] = j;
                        num[j]--;
                        break;
                    }
                }
            }
        }
        for(i = 0;i<sum;i++) cout << result[i];
    }
    return 0;
}