#include <stdlib.h>
#include <stdio.h>
#define NODEDATA struct tree*
struct tree{
    char data;
    struct tree * left;
    struct tree * right;
};

struct two_way_node{
    NODEDATA data;
    struct two_way_node * prev;
    struct two_way_node * next;
};

struct stack{
    int stack_size;
    struct two_way_node * base;
    struct two_way_node * top;
};

struct stack * InitStack(){
    struct stack * pstack = malloc(sizeof(struct stack));
    pstack->stack_size = 0;
    pstack->base = malloc(sizeof(struct two_way_node));
    pstack->top = pstack->base;
    pstack->base->prev = NULL;
    pstack->base->next = NULL;
    return pstack;
}

void Push(NODEDATA data, struct stack* pstack){
    pstack->top->next = malloc(sizeof(struct two_way_node));
    pstack->top->next->prev = pstack->top;
    pstack->top = pstack->top->next;
    pstack->top->next = NULL;
    pstack->top->data = data;
    pstack->stack_size++;
}

NODEDATA Pop(struct stack*pstack){
    if (pstack->top == pstack->base){
        printf("empty stack, can't pop!");
        return NULL;
    }
    pstack->stack_size --;
    NODEDATA tempdata = pstack->top->data;
    pstack->top = pstack->top->prev;
    pstack->top->next = NULL;
    free(pstack->top->next);
    return tempdata;
}

struct tree * Merge(char data,struct tree *ptreeleft, struct tree *ptreeright){
    struct tree * retptr = malloc(sizeof(struct tree));
    retptr->data = data;
    retptr->left = ptreeleft;
    retptr->right = ptreeright;
    return retptr;
}

struct tree* ReadtoTree(struct stack * pstack, char* expression){
    struct tree * ptree = malloc(sizeof(struct tree));
    for (;*expression!='\0'; expression++){
        if (*expression == '+' || *expression == '-' || *expression == '*' || *expression == '/'){
            struct tree * tempptr = Merge(*expression, Pop(pstack),Pop(pstack));
            Push(tempptr, pstack);
        }
        else {
            struct tree * tempptr = malloc(sizeof(struct tree));
            tempptr->data = *expression;
            tempptr->left = NULL;
            tempptr->right = NULL;
            Push(tempptr, pstack);
        }
    }
    return ptree;
}

int main(){
    char expression[] = "ab+cde+**";
    struct stack* pstack = InitStack();
    ReadtoTree(pstack, expression);
}
