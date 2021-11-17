#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

struct mooncake{
    double num,total_price,price;
};

bool cmp(mooncake a,mooncake b){
    return a.price > b.price;
}

int main(){
    int N = 0; // 月饼的种类
    int D = 0; // 市场最大需求量
    cin >> N >> D;
    mooncake *MOONCAKE = new mooncake[N]; // 每种月饼的库存量
    for(int i=0;i<N;i++){
        cin >> MOONCAKE[i].num;
    }
    for(int i=0;i<N;i++){
        cin >> MOONCAKE[i].total_price;
        MOONCAKE[i].price = MOONCAKE[i].total_price / MOONCAKE[i].num;
    }
    sort(MOONCAKE,MOONCAKE + N,cmp);
    double income = 0;
    for(int i=0;i<N;i++){
        if(MOONCAKE[i].num <= D){
            income = income + MOONCAKE[i].price * MOONCAKE[i].num;
            D = D - MOONCAKE[i].num;
        }
        else{
            income = income + MOONCAKE[i].price * D;
            break;
        }
    }
    cout << fixed << setprecision(2) << income;
    
    return 0;
}
