#include <stdio.h>
#include <stdlib.h>




typedef struct node{
    struct node *(next[26]);
}Node;

void PrintChild(Node *head);

Node* init()
{
    Node *head = malloc(sizeof(Node));
    return head;
}

int letter_to_num(const char letter) {
    return (int)letter - 97; // ascii of 'a' is 97
}

/* 这里的const 表示*word 的值不能被修改 */
void add_node(const char *word, Node *head) 
{
    while (*word != '\0')
    {
        int index = letter_to_num(*word);
        head->next[index] = malloc(sizeof(Node));
        head = head->next[index];
        word++;
    }
}

_Bool find(const char *word, Node *head)
{
    while (*word != '\0'){
        printf("%d", letter_to_num(*word));
        puts("debug1:");
        PrintChild(head);
        if (head->next[letter_to_num(*word)] != NULL){
            head = head->next[letter_to_num(*word)];
            word++;
            printf("%d", *word);
        }
        else {return -1;}
    }
    return 1;
}

void PrintTree(Node *head)
{
    for (int i = 0; i < 26; i++){
        if (head->next[i] == NULL)
            continue;
        else {
            printf("%c\n", (char)(i+97));
            PrintTree(head->next[i]);
        }
    }
}

void PrintChild(Node *head)
{
    for (int i = 0; i < 26; i++)
    {
        if (head->next[i])
        {
            printf("%d:%c\t", i, (char)(i+97));
        }
    }
}

int main(int argc, char *(argv[])){
    /* FILE *fp;
    fp = fopen("/home/hzf/Downloads/popular.txt", "r");
    char *ptstr = malloc(sizeof(char) * STRLEN);
    while(fgets(ptstr, STRLEN, fp))
    {
        printf("%s", ptstr);
    }

    fclose(fp); */
    Node *head = init();
    add_node("jio", head);
    if (find("ni", head)){
        printf("yes");
    }
    return 0;
}
