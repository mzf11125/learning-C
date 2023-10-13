
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person{
    int age;
    char name[101];
    Person *next;
}*head, *tail;

// person *head;//Sama denga *head
// person *tail;//Sama dengan *tail

Person *createNewPerson(int age, char name[]){
    Person *newPerson = (Person*)malloc(sizeof(Person));//Allocate memory to the empty struct person
    strcpy(newPerson->name, name);
    newPerson ->age = age;
}

void pushHead(int age, char name[]){
    Person* newPerson;
    if(head == NULL){
        head = tail = newPerson;
    }
    else {
        newPerson->next = head;
        head = newPerson;
    }
}
void printData(){
    Person* curr = head;
    while (curr != NULL){
        printf("Nama: %s, Umur: %d\n", curr->name, curr->age);
        curr= curr->next;
    }
    //Struct *curr = curr->next (a123)
    //*curr= curr->next
}


int main()
{
    pushHead(12, "Budi");
    pushHead(15, "Andi");
    pushHead(17, "jojo");
    
    printData();

    return 0;
}
