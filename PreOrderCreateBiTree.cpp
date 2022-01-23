#include <malloc.h>
#include <stdio.h>

typedef struct bitnode {
    char data;
    struct bitnode *lchild, *rchild;
} bitnode, *bitree;

void creatbitree(bitree& T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else {
        T = (bitnode*)malloc(sizeof(bitnode));
        T->data = ch;
        creatbitree(T->lchild);
        creatbitree(T->rchild);
    }
}

void InOrderTraverse(bitree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        printf("%c\n", T->data);
        InOrderTraverse(T->rchild);
    }
}
int main() {
    bitree T;
    creatbitree(T);      //先序建立二叉树
    InOrderTraverse(T);  //中序遍历二叉树
    return 0;
}
