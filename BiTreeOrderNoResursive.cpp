#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000

//########################################数据结构定义#########################################
// 二叉树定义
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef BiTNode *ElemType;
//顺序栈
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;
//########################################数据结构定义#########################################
//########################################栈的基本方法#########################################
//初始化栈
void InitStack(SqStack &S) { S.top = -1; }

//判断栈是否空
bool IsEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack &S, ElemType e)
{
    if (S.top == MAXSIZE - 1) // 栈满
        return false;
    else
    {
        S.data[++S.top] = e; // 指针先加1 再入栈
        return true;
    }
}

//出栈
bool Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1) //栈空，无法出栈
        return false;
    else
        e = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, ElemType &e)
{
    if (S.top == -1)
        return false;
    else
        e = S.data[S.top];
    return true;
}
//########################################栈的基本方法#########################################

//########################################二叉树的基本方法#########################################
// 中序遍历的非递归实现
void InOrder_no_recursive(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTNode *p = T;
    while (p || !IsEmpty(S))
    { // 当p不空和栈不空均成立是结束循环
        if (p)
        {
            Push(S, p);    //根节点进栈
            p = p->lchild; // 沿和左孩子依次入栈，直到为Null
        }
        else
        {                          //根节点为空
            Pop(S, p);             // 出栈
            printf("%c", p->data); // 访问
            p = p->rchild;         // 向右子树走
        }
    }
}

// 先序遍历的非递归实现
void PreOrderNoRecursive(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTNode *p = T;
    while (p || !IsEmpty(S))
    { // 当p不空和栈不空均成立是结束循环
        if (p)
        {
            printf("%c", p->data); // 访问
            Push(S, p);            //根节点进栈
            p = p->lchild;         // 沿和左孩子依次入栈，直到为Null
        }
        else
        {                  //根节点为空
            Pop(S, p);     // 出栈
            p = p->rchild; // 向右子树走
        }
    }
}

// BUG: 先序遍历的非递归实现[我写的]
void MyPreOrderNoRecursive(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTNode *p = T;
    while (p || !IsEmpty(S))
    {
        if (p)
        {
            printf("%c", p->data);
            if (p->rchild)
            {
                Push(S, p);
            }
            p = p->lchild;
        }
        else
        {
            Pop(S, p);
            if (p->rchild)
            {
                Push(S, p->rchild);
            }
            p = p->lchild;
        }
    }
}

// 后序遍历的非递归实现
void PostOrderNoRecursive(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTNode *p = T, *pre = T; // pre指向前驱结点
    while (p || !IsEmpty(S))
    {
        // @1
        if (p)
        { // p不为空，沿左孩子依次将根节点入栈
            Push(S, p);
            p = p->lchild;
        }
        // @2
        else
        {
            GetTop(S, p); // 读栈顶元素
            if (p->rchild &&
                p->rchild !=
                    pre)
            { // 栈顶元素右孩子存在且不等于前驱结点，则转入其右子树执行@1
                p = p->rchild;
            }
            else
            {                          // 右孩子不存在，则出栈，继续执行@2
                Pop(S, p);             //  出栈
                printf("%c", p->data); //  访问出栈元素
                pre = p;               //  更新前驱结点指针
                p = NULL;              //  将p置为NULL，保证下一次循环继续执行@2操作
            }
        }
    }
}

// 先序遍历构造二叉树
void PreOrderCreatBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = ch;
        PreOrderCreatBiTree(T->lchild);
        PreOrderCreatBiTree(T->rchild);
    }
}

int main()
{
    BiTree T;
    PreOrderCreatBiTree(T);  //先序建立二叉树  ABC##DE#G##F###
    PostOrderNoRecursive(T); // ABC##DE#G##F###
    return 0;
}