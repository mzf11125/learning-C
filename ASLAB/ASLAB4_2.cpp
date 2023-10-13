#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the struct and typedef it
struct Person {
    int age;
    char name[101];
    struct Person *next; // Corrected the pointer type
};

struct Person *head = NULL;
struct Person *tail = NULL;

// Function to create a new person
struct Person *createNewPerson(int age, char name[]) {
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person)); // Allocate memory to the struct Person
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->next = NULL; // Initialize next pointer to NULL
    return newPerson; // Return the newly created person
}

// Function to push a new person to the head of the list
void pushHead(int age, char name[]) {
    struct Person *newPerson = createNewPerson(age, name); // Create a new person
    if (head == NULL) {
        head = tail = newPerson;
    } else {
        newPerson->next = head;
        head = newPerson;
    }
}

// Function to print the data of all persons in the list
void printData() {
    struct Person *curr = head;
    while (curr != NULL) {
        printf("Nama: %s, Umur: %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void pushTail(int age, char name[]){
    Person* newPerson = createNewPerson(age, name);
    if(head == NULL){
        head = tail = newPerson;
    }
    else{
        tail -> next = newPerson;
        tail = newPerson;
    }
}

//Pushmid akan menambahkan data ke tengah
void pushMid(int age, char name[]){
    Person* newPerson = createNewPerson(age, name);
    if (head == NULL){
        head = tail = newPerson;
    }
    else if(age <=head->age){
        newPerson->next = head;
        head = newPerson;
    }
    else {
        Person* curr = head;
        while(curr->next != NULL && age > curr->next->age){
            curr = curr->next;
        }
        newPerson->next = curr->next;
        curr->next = newPerson;
    }
}

void popHead(){
    if(head == NULL){
        return;
    }
    else if (head == tail){
        head = tail - NULL;
        free(head);
    }
    else {
        Person* temp = head;
        head = head->next;
        free(temp);
    }
}

void popTail(){
    if(head == NULL){
        return;
    }
    else if (head == tail){
        head = tail = NULL;
        free(head);
    }
    else {
        Person* temp = head;
        while (temp->next->next != NULL){
            temp = temp->next;

        }
        temp->next = NULL;
        free(temp->next);
        tail = temp;
    }
}

int main() {
    pushMid(12, "Budi");
    pushMid(15, "Andi");
    pushMid(17, "Jojo");
    pushMid(10, "Antoni");
    pushMid(12, "Cici");
    
    popHead();//Menghilankan head atau 
    popTail();//Menghilangkan tail

    printData();

    return 0;
}


