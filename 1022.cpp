/*实现十进制转k（1~10）进制的数
    *[input]输入在一行中依次给出 3 个整数 A、B 和 D。
    *[output]输出 A+B 的 D 进制数。*/
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000


//顺序栈
typedef struct {
    int data[MAXSIZE];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top = -1;
}

//判断栈是否空
bool IsEmpty(SqStack S){
    if (S.top == -1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack &S,int e){
    if(S.top == MAXSIZE -1) // 栈满
        return false;
    else{
        S.data[++S.top] = e; // 指针先加1 再入栈
        return true; 
    }
}

//出栈
bool Pop(SqStack &S,int &e){
    if(S.top == -1) //栈空，无法出栈
        return false;
    else
        e = S.data[S.top--];
        return true;
}

//读栈顶元素
bool GetTop(SqStack S,int &e){
    if(S.top == -1) return false;
    else
        e = S.data[S.top];
        return true;
}

int main(){
    int sum,A,B,D;
   
    cin >> A >> B >> D;
    sum = A + B;

    SqStack S;
    InitStack(S);

    //当sum = 0 时 直接输出
    do{
        Push(S,sum % D);
        sum /= D;
    }while(sum);

    int e;
    while(!IsEmpty(S)){
        Pop(S,e);
        cout << e;
    }

    return 0;
}