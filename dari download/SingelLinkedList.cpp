#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    Node *next;
}*head = NULL, *tail = NULL;

Node *createNode(int val){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

void pushHead(int val){
    Node *temp = createNode(val);
    if(head == NULL){
        head = tail = temp;
    }else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int val){
    Node *temp = createNode(val);
    if(tail == NULL){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void pushMid(int val){
    Node *temp = createNode(val);
    if(head == NULL){
        pushHead(val);
    }else if(val < head->val){
        pushHead(val);
    }else if(val > tail->val){
        pushTail(val);
    }else{
        Node *jalan = head;
        while(jalan != NULL){
            if(jalan->next->val > val){
                temp->next = jalan->next;
                jalan->next = temp;
                return;
            }
            jalan = jalan ->next;
        }
    }
}

void popHead(){
    if(head == NULL){
        printf("Tidak ada data!\n");
        return;
    }else if(head == tail){
        head = tail = NULL;
    }else{
        Node *temp = head;
        head = temp ->next;
        free(temp);
    }
}

void popTail(){
    if(tail == NULL){
        printf("Tidak ada data!\n");
        return;
    }else if(head == tail){
        head = tail = NULL;
    }else{
        Node *temp = head;
        while(temp ->next->next != NULL){
            temp = temp -> next;
        }
        // 1->2->3->4->5->NULL
        Node *hapus = temp->next;
        tail = temp;
        tail->next = NULL;
        free(hapus);
    }
}

void popMid(int val){
    if(head->val == val){
        popHead();
    }else if(tail->val == val){
        popTail();
    }else{
        Node *temp = head;
        while(temp->next != NULL){
            if(temp->next->val == val){
                Node *hapus = temp->next;
                temp->next = hapus->next;
                free(hapus);
                return;
            }
            temp = temp ->next;
        }
        printf("No data Match!\n");
        return;
    }
}

void printAll(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d->",temp->val);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    pushMid(18);
    pushMid(1);
    pushMid(100);
    pushMid(24);
    pushMid(27);
    printAll();
    popMid(99);
    printAll();
    return 0;
}