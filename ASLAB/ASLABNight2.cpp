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

int main() {
    pushHead(12, "Budi");
    pushHead(15, "Andi");
    pushHead(17, "jojo");

    printData();

    return 0;
}

