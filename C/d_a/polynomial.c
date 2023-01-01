#include <stdio.h>
#include <stdlib.h>

struct node {
    int Coefficient; 
    int Exponent;
    struct node *next;
};

struct node * Insert (struct node *head, int Coefficient, int Exponent){
    while (head -> next != NULL && head -> next -> Exponent > Exponent){
        head = head -> next;
    }
    if (head -> next != NULL && head -> next -> Exponent == Exponent){
        head -> next -> Coefficient += Coefficient;
        return head -> next;
    }
    struct node *insertnode = malloc(sizeof(struct node));
    insertnode->Coefficient = Coefficient;
    insertnode->Exponent = Exponent;
    insertnode->next = head->next;
    head->next = insertnode;
    return head -> next;
}

void PrintPolynomial(struct node *head){
    struct node * tmp = head;
    for (; head != NULL; head = head->next){
        printf("%5d", head->Exponent);
    }
    putchar('\n');
    for (head = tmp; head != NULL; head = head->next){
        printf("%3dx^", head->Coefficient);
    }
}
struct node * Multiply (struct node *Nodex, struct node *Nodey){
    /* 首先给头节点赋值 */
    struct node * pos = malloc(sizeof(struct node *));
    struct node * retnode = pos;
    struct node * xpos = Nodex;
    struct node * ypos = Nodey;
    /* xpos[0] * ypos[1], xpos[0] * ypos[1] ...
     * xpos[0] * ypos[size - 1] , x[1] * ypos[0] .....
     * xpos[xsize - 1] * ypos[0], ... xpos[xsize - 1] * ypos[ysize - 1]*/
    pos -> Coefficient = xpos->Coefficient * ypos->Coefficient;
    pos -> Exponent = xpos ->Exponent + ypos -> Exponent;
    ypos = ypos->next; // reason is same as the line below
    while (xpos != NULL){
        while (ypos != NULL){
            pos = Insert(pos, xpos->Coefficient * ypos->Coefficient, xpos->Exponent + ypos->Exponent);
            ypos = ypos -> next;
        }
        pos = retnode; // homing
        xpos = xpos -> next; // if before situation is x[i] * y[ysize - 1], now it become to that: x[i+1] * y[0]
        ypos = Nodey;
    }
    return retnode;
}

struct node * Generate(int CoeExpArray[][2], int size){
    struct node * head = malloc(sizeof(struct node *));
    struct node * rethead = head;
    head -> Coefficient = CoeExpArray[0][0];
    head -> Exponent = CoeExpArray[0][1];
    for (int i = 1; i < size; i++){
        head -> next = malloc(sizeof(struct node *));
        head = head -> next;
        head -> Coefficient = CoeExpArray[i][0];
        head -> Exponent = CoeExpArray[i][1];
    }
    return rethead;
}

int main(){
    int CoeExpArray1[3][2] = {{2,4},{3,3},{10,1}};
    int CoeExpArray2[4][2] = {{2,5},{4,4},{6,3},{2,1}};
    struct node * p1 = Generate(CoeExpArray1, 3);
    struct node * p2 = Generate(CoeExpArray2, 4);
    PrintPolynomial(Multiply(p1, p2));
    return 0;
}
