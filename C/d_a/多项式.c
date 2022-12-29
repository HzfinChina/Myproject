#include <stdio.h>
#include <stdlib.h>

struct node {
    int Coefficient; 
    int Exponent;
    struct node *next;
};

void Insert (struct node *head, int Coefficient, int Exponent){
    if (head == NULL){
        head -> Coefficient = Coefficient;
        head -> Exponent = Exponent;
        return;
    }
    //when hext -> next is not NULL
    while (!head -> next && Exponent <= head -> next -> Exponent){ 
        head = head -> next;
    }
    if (head->next == NULL); // do nothing;
    else if (Exponent == head->next->Exponent){
        head->next->Coefficient += Coefficient;
        return;
    }
    struct node *insertnode = malloc(sizeof(struct node));
    insertnode->Coefficient = Coefficient;
    insertnode->Exponent = Exponent;
    insertnode->next = head->next;
    head->next = insertnode;
}

void PrintPolynomial(struct node *head){
    struct node *pos = head;
    while (pos != NULL){
        printf(" %5d", pos->Exponent);
        pos = pos->next;
    }
    putchar('\n');
    pos = head;
    while (pos != NULL){
        printf("%4dx^", pos ->Coefficient);
    }
}
struct node * Multiply (struct node *Nodex, struct node *Nodey){
    struct node * retnode = NULL;
    struct node * ypos = Nodey;
    struct node * xpos = Nodex;
    while (xpos != NULL){
        while (ypos != NULL){
            Insert(retnode, xpos->Coefficient * ypos->Coefficient, xpos->Exponent + ypos->Exponent);
        }
        ypos = Nodey;
        xpos = xpos->next;
    }
    return retnode;
}
