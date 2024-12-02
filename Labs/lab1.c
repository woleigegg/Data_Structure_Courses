#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;

struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *next;
};

Polynomial PolyCreatePolynomial(int n);
void PolyPrint(Polynomial p);
Polynomial PolyAdd(Polynomial p1, Polynomial p2);
Polynomial Polydiff(Polynomial p1, Polynomial p2);
void PolyDestroy(Polynomial p);

Polynomial PolyCreatePolynomial(int n){
    Polynomial head, p, tail;
    int coef, expon;

    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    tail = head;

    for(int i = 0; i < n; i++){
        scanf("%d %d", &coef, &expon);
        p = (Polynomial)malloc(sizeof(struct PolyNode));
        p->coef = coef;
        p->expon = expon;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}

int main(){
    int n1, n2;

    scanf("%d", &n1);
    scanf("%d", &n2);

    Polynomial p1 = PolyCreatePolynomial(n1);
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