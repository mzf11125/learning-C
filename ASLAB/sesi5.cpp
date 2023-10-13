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

void pushTail(int value){
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



// void printAll(){
//     if(head == NULL){
//         printf("No Data!\n");
//         return;
//     }else {
//         struct Data* curr = tail;
//         while(curr != NULL){
//             printf("%d\n", curr -> value);
//             curr = curr->prev;//Descending
//         }
//     }
// }



void pushMid(int value){
    struct Data *node = newNode(value);
    if(head == NULL){
        head = tail = node;
    }
    else if (head -> value > value){
        pushHead(value);
    }
    else if(tail -> value <= value){
        pushTail(value);
    }
    else {
        struct Data *curr = head;
        while(curr -> next -> value < value){
            curr = curr->next;
        }
        node -> next = curr-> next;
        curr -> next -> prev = node;
        curr -> next = node;
        node -> prev = curr;
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

void popTail(){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        head = tail = NULL;
        free(head);
        free(tail);
    }
    else{
        struct Data *temp = tail; 
        tail = temp -> prev;
        tail -> next = NULL;
        free(temp);
    }
}

void popMid(int value){
    if(head == NULL){
        return;
    }
    else if(head == tail){
        head = tail = NULL;
        free(head);
        free(tail);
    }
    else if(head -> value == value){
        popHead();
    }
    else if(tail -> value == value){
        popTail();
    }
    else{
        struct Data *curr = head;
        while(curr -> next -> value != value){
            curr = curr -> next;
        }
        struct Data *temp = curr -> next;
        curr -> next = temp -> next;
        temp -> next -> prev = curr; 
        temp -> next = NULL;
        temp -> prev = NULL;
        temp = NULL;
        free(temp);
    }
}

void Search(int value){
    if(head == NULL){
        printf("Data kosong\n");
        return;
    }
    else{
        struct Data *curr = head;
        while(curr -> value != value && curr -> next != NULL){
            curr = curr -> next;
        }
        if(curr -> value == value){
            printf("Data ketemu!\n");
        } 
        else{
            printf("Data nggak ketemu\n");
        }
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

int main(){
    pushMid(10);
    pushTail(10);
    pushMid(10);
    pushMid(10);
    pushMid(10);
    pushMid(10);
    pushTail(10);
    Search(3);
    pushTail(1);
    pushTail(10);
    popMid(2);
    printAll();

    return 0;
}


