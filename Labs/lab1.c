#include <stdio.h>
#include <stdlib.h>

// 定义多项式节点的结构体
typedef struct PolyNode *Polynomial;

struct PolyNode {
    int coef; // 系数
    int expon; // 指数
    struct PolyNode *next; // 指向下一个节点的指针
};

// 函数声明
Polynomial PolyCreatePolynomial(int n);
void PolyPrint(Polynomial p);
Polynomial PolyAdd(Polynomial p1, Polynomial p2);
Polynomial Polydiff(Polynomial p1, Polynomial p2);
void PolyDestroy(Polynomial p);

// 创建多项式
Polynomial PolyCreatePolynomial(int n){
    Polynomial head, p, tail;
    int coef, expon;

    head = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建头节点
    head->next = NULL;
    tail = head;

    for(int i = 0; i < n; i++){
        scanf("%d %d", &coef, &expon); // 输入系数和指数
        p = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
        p->coef = coef;
        p->expon = expon;
        p->next = NULL;
        tail->next = p; // 将新节点连接到链表
        tail = p;
    }
    return head;
}

// 打印多项式
void PolyPrint(Polynomial p){
    Polynomial q = p->next;
    if(q == NULL){
        printf("0");
        return;
    }
    int first = 1;
    while(q != NULL){
        if(q->coef > 0 && !first) printf("+");
        printf("%d", q->coef);
        if(q->expon > 0) printf("x(%d)", q->expon);
        q = q->next;
        first = 0;
    }
    printf("\n");
}

// 多项式相加
Polynomial PolyAdd(Polynomial p1, Polynomial p2){
    Polynomial head, p, q, tail;
    head = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建头节点
    head->next = NULL;
    tail = head;
    p = p1->next;
    q = p2->next;

    while(p != NULL && q != NULL){
        if(p->expon < q->expon){
            tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
            tail->next->coef = p->coef;
            tail->next->expon = p->expon;
            tail->next->next = NULL;
            tail = tail->next;
            p = p->next;
        }
        else if(p->expon > q->expon){
            tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
            tail->next->coef = q->coef;
            tail->next->expon = q->expon;
            tail->next->next = NULL;
            tail = tail->next;
            q = q->next;
        }
        else{
            int sum = p->coef + q->coef;
            if(sum != 0){
                tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
                tail->next->coef = sum;
                tail->next->expon = p->expon;
                tail->next->next = NULL;
                tail = tail->next;
            }
            p = p->next;
            q = q->next;
        }
    }
    while(p != NULL){
        tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
        tail->next->coef = p->coef;
        tail->next->expon = p->expon;
        tail->next->next = NULL;
        tail = tail->next;
        p = p->next;
    }
    while(q != NULL){
        tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
        tail->next->coef = q->coef;
        tail->next->expon = q->expon;
        tail->next->next = NULL;
        tail = tail->next;
        q = q->next;
    }
    tail->next = NULL;
    return head;
}

// 多项式相减
Polynomial Polydiff(Polynomial p1, Polynomial p2){
    Polynomial head, p, q, tail;
    head = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建头节点
    head->next = NULL;
    tail = head;
    p = p1->next;
    q = p2->next;

    while(p != NULL && q != NULL){
        if(p->expon < q->expon){
            tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
            tail->next->coef = p->coef;
            tail->next->expon = p->expon;
            tail->next->next = NULL;
            tail = tail->next;
            p = p->next;
        }
        else if(p->expon > q->expon){
            tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
            tail->next->coef = -q->coef;
            tail->next->expon = q->expon;
            tail->next->next = NULL;
            tail = tail->next;
            q = q->next;
        }
        else{
            int diff = p->coef - q->coef;
            if(diff != 0){
                tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
                tail->next->coef = diff;
                tail->next->expon = p->expon;
                tail->next->next = NULL;
                tail = tail->next;
            }
            p = p->next;
            q = q->next;
        }
    }

    while(p != NULL){
        tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
        tail->next->coef = p->coef;
        tail->next->expon = p->expon;
        tail->next->next = NULL;
        tail = tail->next;
        p = p->next;
    }
    while(q != NULL){
        tail->next = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建新节点
        tail->next->coef = -q->coef;
        tail->next->expon = q->expon;
        tail->next->next = NULL;
        tail = tail->next;
        q = q->next;
    }
    tail->next = NULL;
    return head;
}

// 销毁多项式
void PolyDestroy(Polynomial p){
    Polynomial q;
    while(p != NULL){
        q = p;
        p = p->next;
        free(q); // 释放内存
    }
}

int main(){
    int n1, n2;

    scanf("%d", &n1); // 输入多项式1的项数
    Polynomial p1 = PolyCreatePolynomial(n1);
    scanf("%d", &n2); // 输入多项式2的项数
    Polynomial p2 = PolyCreatePolynomial(n2);

    printf("一元多项式1： ");
    PolyPrint(p1);
    printf("一元多项式2： ");
    PolyPrint(p2);

    Polynomial p3 = PolyAdd(p1, p2);
    printf("加的结果：");
    PolyPrint(p3);

    Polynomial p4 = Polydiff(p1, p2);
    printf("减的结果："); 
    PolyPrint(p4);

    PolyDestroy(p1);
    PolyDestroy(p2);
    PolyDestroy(p3);
    PolyDestroy(p4);

    return 0;
}