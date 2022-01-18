#include<stdio.h>
#include<stdlib.h>

//单链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//尾插法构建单链表
void InitLinkList(LinkList &L,int n){
    int i = 0;
    L = (LinkList)malloc(sizeof(LNode)); //L为头指针
    LNode *s,*rear = L;//s指向新节点，rear为尾指针，指向当前链表最后一个节点
    while(i < n){
        s = (LNode*)malloc(sizeof(LNode));//申请一个新节点
        printf("请输入新节点的值：");
        scanf("%d",&s->data);
        rear->next = s;
        rear = s;
        i++;
    }
    rear->next = NULL;
}

void OutputLinkList(LinkList L){
    LNode *p = L->next;
    printf("单链表：");
    while(p){
        printf("%d",p->data);
        if(p->next != NULL) printf("->");
        p = p->next;
    }
}

int main(){
    LinkList L;
    int n;
    printf("请输入单链表的节点个数：");
    scanf("%d",&n);
    InitLinkList(L,n);
    OutputLinkList(L);

    return 0;
}