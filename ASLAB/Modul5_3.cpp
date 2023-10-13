#include<stdio.h>
#include<stdlib.h>

//Modul 5 - 13 Oktober 2023
//Queue => itu fifo, first in first out

struct Data{
	int value;
	struct Data*next;
	struct Data*prev;//sama seperti linked list namun ditambakan pointer prev
}*head = NULL, *tail = NULL;

struct Data *newNote(int value){
	struct Data *node = (struct Data*) malloc(sizeof(struct Data));
	node -> value = value;
	node -> next = NULL;
	node -> prev = NULL;
	return node;//node berfungsi sebagai tempat menaruh head yang baru
}

void enqueue(int value){
	struct Data *node = newNote(value);
	if(head == NULL){
		head = tail = node;
	}else{
		tail -> next = node;
		node -> prev = tail;
		tail = node;//konsep next, prev double linked list
		//Dari struct lama, pointer next struct lama disambungkan ke struct baru , pointer prev struct baru disambungkan ke struct lama,struct baru menjadi tail selanjutnya.
	}
}

void dequeue(){
	if(head == NULL){
		return;
	}else if(head == tail){
		head = tail = NULL;
		free(head);//oleh karena itu head dan tail dihilangkan
		free(tail);//kondisi ini digunakan jika struct hanya 1 yang berarti dia merupakan head sekaligus tail
	}else{
		struct Data *temp = head;
		head = temp -> next;
		head -> prev = NULL;
		free(temp);
	}
}

void peek(){
	if(head == NULL){
		printf("Data Kosong\n");
	}else{
		printf("Data teratas : %d\n", head->value);
	}
}

int main(){
	enqueue(10);
	enqueue(20);
	peek();
	return 0;
}
