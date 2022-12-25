#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char nowdata; //现在是什么字母
    struct node *next[26];
}Node;

void AddNode(Node *head, const char *str);

void read_to_tree(Node *head) {
    FILE *fp = fopen("/home/hzf/Downloads/popular.txt", "r");
    for (int i = 0;; i++){
        char *str = malloc(sizeof(char) * 20);
        if (fgets(str, 20, fp) == NULL)
            break;
        str[strlen(str)-1] = '\0'; // remove \n at the end
        AddNode(head, str);
    }
    fclose(fp);
}

void AddNode(Node *head, const char *str){
    Node *debugwatchhead = head;
    for (; *str != '\0'; str++)
    {
        int index = *str - 97; // 'a' ascii is 97
        if (head->next[index] == NULL){ 
            head->next[index] = malloc(sizeof(Node));
            head = head->next[index];
            head -> nowdata = *str;
        }
        else {
            head = head->next[index];
        }
    }
}

_Bool check_in_tree(const char *str, Node *head)
{
    for (; *str != '\0'; str++)
    {
        int index = *str - 97;
        if (head -> next[index] != NULL){
            head = head->next[index];
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    Node *head = malloc(sizeof(Node));
    read_to_tree(head);
    if(check_in_tree("zoo", head))
        puts("in");
    else 
        puts("not in ");
}
