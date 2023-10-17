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

void pushHead(int value){
    struct Data *node = newNode(value);
    if(head == NULL){
        head = tail = node;
    }
    else {
        node -> next = head;
        head -> prev = node;
        head = node;
    }
}

void popHead(){
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



int main()
{
    pushHead(10);
    pushHead(30);
    pushHead(50);
    pushHead(100);
    popHead();
    peek();

    return 0;
}

