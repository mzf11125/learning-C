#include <stdio.h>
#include <stdlib.h>

struct Data{
    int value;
    struct Data *next;
    struct Data *prev;
}*head = NULL, *tail = NULL;

struct Data *newNode(int value){
    struct Data *node = (struct Data*) malloc(sizeof(struct Data));
    node -> value = value;
    node -> next = NULL;
    node -> prev = NULL;
    return node;
}

void enqueu(int value){
    struct Data *node = newNode(value);
    if(head == NULL){
        head = tail = node;
    }
    else {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
}

void dequeu(){
    if(head == NULL){
        return;
    }
    else if (head == tail){
        head = tail = NULL;
        free(head);
        free(tail);
    }
    else{
        struct Data *temp = head;
        head = temp -> next;
        head -> prev = NULL;
        free(temp);
    }
}

void peek(){
    if(head == NULL){
        printf("Data kosong\n");
    }else{
        printf("Data teratas: %d\n", head -> value);
    }
}

void printAll(){
    if(head == NULL){
        printf("No Data!\n");
        return;
    }else {
        struct Data* curr = head;
        while(curr != NULL){
            printf("%d\n", curr -> value);
            curr = curr->next;//Ascending
        }
    }
}

// qneueu -> push tail 
// deque -> pophead

int main()
{
    enqueu(10);
    dequeu();
    enqueu(30);
    printAll();
    return 0;
}

